


%{
    #include "../../utils/alpha_bison_utilities.h"
    #include "../../utils/alpha_target_utilities.h"
    #include <stdio.h>
    #include <stdlib.h>

    /*
     * Forward declaration of the lexer function called by Bison. Flex
     * generates yylex(), and the parser calls it whenever it needs the next
     * token from the input stream.
     */
    int yylex();

    /*
     * Bison calls yyerror() when it encounters a syntax error. This version
     * deliberately returns 0 without printing the supplied message; the
     * grammar's own error handling is responsible for the visible output.
     */
    int yyerror(char* yaccProvidedMessage){return 0;};
    void printHelp(char*);
    extern int lineno;
    extern char* yytext;
    extern FILE* yyin;
    extern FILE* yyout;
    char* in_filename;
    extern int inner_counter_for_temp;
    extern int total_new_temps_used_in_stmt;
    extern bool error_found;
%}


%union {
    char*   stringVal;
    int     intVal;
    double  realVal;
    struct expr* exprVal;
    struct {
        int break_list;
        int cont_list;
    } stmtVal;
}

%start program

%token IF
%token ELSE
%token WHILE
%token FOR
%token <exprVal> FUNCTION
%token RETURN
%token BREAK
%token CONTINUE
%token AND
%token NOT
%token OR
%token LOCAL
%token TRUE
%token FALSE
%token NIL
%token EQUAL
%token PLUS
%token MINUS
%token MULTIPLY
%token DIV
%token MODULO
%token <exprVal> EQUAL_EQUAL
%token <exprVal> NOT_EQUAL
%token <exprVal> PLUS_PLUS
%token <exprVal> MINUS_MINUS
%token <exprVal> GREATER_THAN
%token <exprVal> LESS_THAN
%token <exprVal> GREATER_EQUAL
%token <exprVal> LESS_EQUAL
%token LEFT_BRACE
%token RIGHT_BRACE
%token LEFT_BRACKET
%token RIGHT_BRACKET
%token LEFT_PARENTHESIS
%token RIGHT_PARENTHESIS
%token SEMICOLON
%token COMMA
%token COLON
%token DOUBLE_COLON
%token FULL_STOP
%token DOTS
%token UNDEFINED_TOKEN
%token <stringVal> STR
%token <stringVal> ID
%token <realVal> NUMBER
%token <stringVal> LIB

%right EQUAL
%left COMMA
%left OR
%left AND
%nonassoc EQUAL_EQUAL NOT_EQUAL
%nonassoc GREATER_THAN GREATER_EQUAL LESS_THAN LESS_EQUAL
%left PLUS MINUS
%left MULTIPLY DIV MODULO
%right NOT PLUS_PLUS MINUS_MINUS 
%left FULL_STOP DOTS
%nonassoc UMINUS
%left LEFT_BRACKET RIGHT_BRACKET
%left LEFT_PARENTHESIS RIGHT_PARENTHESIS


%type <exprVal> stmt_loop
%type <exprVal> num_expr
%type <exprVal> num
%type <exprVal> stmt
%type <exprVal> ifstmt
%type <exprVal> whilestmt
%type <intVal> whilestart
%type <intVal> whilecond
%type <exprVal> expr
%type <exprVal> block
%type <exprVal> assignexpr
%type <exprVal> term
%type <exprVal> boolexpr
%type <exprVal> lvalue
%type <exprVal> forstmt
%type <exprVal> elist
%type <exprVal> funcdef
%type <exprVal> nonempty_elist
%type <exprVal> returnstmt
%type <exprVal> idlist
%type <exprVal> nonempty_idlist
%type <exprVal> primary
%type <exprVal> call
%type <exprVal> callsuffix
%type <exprVal> member
%type <exprVal> normcall
%type <exprVal> methodcall
%type <exprVal> objectdef
%type <exprVal> indexed
%type <exprVal> indexedelem
%type <exprVal> indexlist
%type <exprVal> constant
%type <exprVal> lib_func
%type <exprVal> stmt_block
%type <stringVal> validate
%type <exprVal> loopstart
%type <exprVal> loopend
%type <exprVal> id
%type <exprVal> fun_block
%type <stringVal> funcname
%type <exprVal> funcprefix
%type <exprVal> lib
%type <intVal> ifprefix
%type <intVal> elseprefix
%type <exprVal> break
%type <exprVal> continue
%type <exprVal> forprefix
%type <intVal> M
%type <intVal> N


%%

 //Expressions

program : stmt_loop ;

 
stmt_loop : stmt_loop stmt {
            reset_counter_temp();
            // printf("break_list for $1 before if is %d\n", $1->break_list);
            // printf("break_list for $2 before if is %d\n", $2->break_list);
            if ($1!=NULL && $2!=NULL && !($1->break_list == 0 && $1->cont_list == 0 && $2->break_list == 0 && $2->cont_list == 0)) {
                if(!error_found) {
                    $$->break_list = mergelist($1->break_list, $2->break_list);
                    $$->cont_list = mergelist($1->cont_list, $2->cont_list);
                }
            } else {
                $$ = $2;
            }
        }
          | { $$ = NULL; } /* empty*/ ;

stmt : expr SEMICOLON {
            if($1!=NULL&&$1->type==boolexpr_e){
                if($1->sym==NULL){
                    $1->sym=newTemp();
                }
                patchlist($1->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, $1, 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist($1->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, $1, 0);
            }
            $$ = $1;
        }
     | block {$$ = $1;}
     | whilestmt {$$ = $1;}
     | ifstmt {$$ = $1;}
     | forstmt {$$ = $1;} //Make sure to return the necessary break/continue lists...
     | returnstmt {$$ = $1;}
     | break {$$ = $1;}
     | continue {$$ = $1;}
     | funcdef {$$ = $1;}
     | error {printf("\033[0;33mError at line %d\033[0m\n", yylineno); exit(1);}
     ;


fun_block : LEFT_BRACE stmt_block RIGHT_BRACE { $$ = $2; }
      ;


expr  : num_expr {$$ = $1;}
      | assignexpr {$$ = $1;}
      | boolexpr {$$ = $1;}
      | term {$$ = $1;}
      ;

boolexpr : {$$=NULL;}/*empty rule*/
| expr GREATER_EQUAL expr {
                Check_type($1); Check_type($3); 
                $$=new_Expr(boolexpr_e);
                emit(if_greatereq_i, $1, $3, NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());       
                $$->true_list = newlist(nextQuadLabel()-2);     
                $$->false_list = newlist(nextQuadLabel()-1);     
            }   
| expr GREATER_THAN expr {
                Check_type($1); Check_type($3); 
                $$=new_Expr(boolexpr_e);
                emit(if_greater_i, $1, $3, NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());       
                $$->true_list = newlist(nextQuadLabel()-2);     
                $$->false_list = newlist(nextQuadLabel()-1);                 
            }   
| expr LESS_EQUAL expr {
                Check_type($1); Check_type($3); 
                $$=new_Expr(boolexpr_e);
                emit(if_lesseq_i, $1, $3, NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());       
                $$->true_list = newlist(nextQuadLabel()-2);     
                $$->false_list = newlist(nextQuadLabel()-1);                 
            }    
| expr LESS_THAN expr {
                Check_type($1); Check_type($3); 
                $$=new_Expr(boolexpr_e);
                emit(if_less_i, $1, $3, NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());       
                $$->true_list = newlist(nextQuadLabel()-2);     
                $$->false_list = newlist(nextQuadLabel()-1);             
            }      
| expr EQUAL_EQUAL {patchEQNEQOp1($1);} expr {

                if($4!=NULL&&$4->type==boolexpr_e){
                    if($4->sym==NULL){
                        $4->sym=newTemp();
                    }
                    patchlist($4->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, $4, 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist($4->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, $4, 0);
                }

                $$=new_Expr(boolexpr_e);
                emit(if_eq_i, $1, $4, NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
                $$->true_list = newlist(nextQuadLabel()-2);
                $$->false_list = newlist(nextQuadLabel()-1);         
            }    
| expr NOT_EQUAL {patchEQNEQOp1($1);} expr { 

                if($4!=NULL&&$4->type==boolexpr_e){
                    if($4->sym==NULL){
                        $4->sym=newTemp();
                    }
                    patchlist($4->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, $4, 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist($4->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, $4, 0);
                }

                $$=new_Expr(boolexpr_e);
                emit(if_noteq_i, $1, $4, NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
                $$->true_list = newlist(nextQuadLabel()-2);
                $$->false_list = newlist(nextQuadLabel()-1);
            }      
| expr AND {patchANDOp1($1);} M expr {
                $$=new_Expr(boolexpr_e);
                
                if($5!=NULL&&$5->type!=boolexpr_e){
                    emit(if_eq_i, $5, new_constbool(true), NULL,0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
                    $5->true_list = newlist(nextQuadLabel()-2);
                    $5->false_list = newlist(nextQuadLabel()-1);
                }

                if($1!=NULL&&$1->type==boolexpr_e){
                    patchlist($1->true_list, $4);
                }

                $$->true_list = $5->true_list;
                $$->false_list = mergelist($1->false_list, $5->false_list);
            }             
| expr OR {patchOROp1($1);} M expr {
                $$=new_Expr(boolexpr_e);
                
                if($5!=NULL&&$5->type!=boolexpr_e){
                    emit(if_eq_i, $5, new_constbool(true), NULL,0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
                    $5->true_list = newlist(nextQuadLabel()-2);
                    $5->false_list = newlist(nextQuadLabel()-1);
                }

                if($1!=NULL&&$1->type==boolexpr_e){
                    patchlist($1->false_list, $4);
                }

                // printf("printing true list: \n");printlist($5->true_list);
                // printf("printing false list: \n");printlist($5->false_list);

                $$->true_list = mergelist($1->true_list, $5->true_list);
                $$->false_list = $5->false_list;

                // printf("printing true list: \n");printlist($$->true_list);
                // printf("printing false list: \n");printlist($$->false_list);
            }  
| LEFT_PARENTHESIS boolexpr RIGHT_PARENTHESIS {$$ = $2;}            
;

assignexpr : id EQUAL expr {
                if($3!=NULL&&$3->type==boolexpr_e){
                    if($3->sym==NULL){
                        $3->sym=newTemp();
                    }
                    patchlist($3->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, $3, 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist($3->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, $3, 0);
                }
                            
                emit(assign_i, $3, NULL, $1, 0); //HERE
                $$=new_Expr(assignexpr_e);
                $$->sym = newTemp(); 
                $$->strConst = $$->sym->value.varVal->name;
                if($1->sym==NULL){
                    $1->sym = new_SymbolTableVariable($1->strConst);
                    SymbolTable_insert(symbol_table, $1->sym , true);
                }
                if($3->sym)
                    $1->sym->isTable = $3->sym->isTable;
                emit(assign_i, $1, NULL, $$, 0);
            }
           | LOCAL id EQUAL expr {
                if($4!=NULL&&$4->type==boolexpr_e){
                    if($4->sym==NULL){
                        $4->sym=newTemp();
                    }
                    patchlist($4->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, $4, 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist($4->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, $4, 0);
                }

                emit(assign_i, $4, NULL, $2, 0);
                $$=new_Expr(assignexpr_e);
                $$->sym = newTemp(); 
                $$->strConst = $$->sym->value.varVal->name;
                if($2->sym==NULL){
                    $2->sym = new_SymbolTableVariable($2->strConst);
                    SymbolTable_insert_local(symbol_table, $2->sym, true);
                }
                if($4->sym)
                    $2->sym->isTable = $4->sym->isTable;
                emit(assign_i, $2, NULL, $$, 0);
            }
           | DOUBLE_COLON id EQUAL expr {
                if($4!=NULL&&$4->type==boolexpr_e){
                    if($4->sym==NULL){
                        $4->sym=newTemp();
                    }
                    patchlist($4->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, $4, 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist($4->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, $4, 0);
                }

                emit(assign_i, $4, NULL, $2, 0);
                $$=new_Expr(assignexpr_e);
                $$->sym = newTemp(); 
                $$->strConst = $$->sym->value.varVal->name;
                SymbolTable_require_global(symbol_table, $2->strConst);
                emit(assign_i, $2, NULL, $$, 0);
                if($4->sym)
                    $2->sym->isTable = $4->sym->isTable;
            }
           | member EQUAL expr {
                    
                    if($3!=NULL&&$3->type==boolexpr_e){
                        if($3->sym==NULL){
                            $3->sym=newTemp();
                        }
                        patchlist($3->true_list, nextQuadLabel());
                        emit(assign_i, new_constbool(true), NULL, $3, 0);
                        emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                        patchlist($3->false_list, nextQuadLabel());
                        emit(assign_i, new_constbool(false), NULL, $3, 0);
                    }

                    $1 = fixAssignedMember($1, $3);
                    if($3->sym)
                        $1->sym->isTable = $3->sym->isTable;
                    $$ = emitIfTableItem($1->lastAssignedQuad->arg1);
            }
            | LEFT_PARENTHESIS assignexpr RIGHT_PARENTHESIS {$$ = $2;}
           ;

lvalue : id                     {$$ = $1; if($1->sym==NULL){$1->sym =  new_SymbolTableVariable($$->strConst); SymbolTable_insert(symbol_table, $1->sym, false);}}
        | LOCAL id              {$$ = $2; if($2->sym==NULL){$2->sym = new_SymbolTableVariable($$->strConst); SymbolTable_insert_local(symbol_table, $2->sym, false);}}
        | DOUBLE_COLON id       {$$ = $2; SymbolTable_require_global(symbol_table, $$->strConst);}
        | member                {$$ = $1;}
        | lib_func              {$$=$1;}
        ;

id : ID {$$=new_var($1); $$->sym = SymbolTable_lookup_chill(symbol_table, $1); if($$->sym!=NULL && $$->sym->type==TYPE_USERFUNC){$$->type = programfunc_e; printf("It is of type %d\n", $$->sym->type);} if($$->sym==NULL){$$->sym = new_SymbolTableVariable($1); SymbolTable_insert(symbol_table, $$->sym, false);}}
  ;

num_expr: num_expr PLUS num_expr {
        Check_type($1); Check_type($3); 
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        emit(add_i, $1, $3, $$, 0);
    }
    | num_expr MINUS num_expr {
        Check_type($1); Check_type($3);
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        emit(sub_i, $1, $3, $$, 0);
    }             
    | num_expr MULTIPLY num_expr {
        Check_type($1); Check_type($3);
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        emit(mul_i, $1, $3, $$, 0);
    }         
    | num_expr DIV num_expr {
        Check_type($1); Check_type($3);
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        emit(div_i, $1, $3, $$, 0);
    }               
    | num_expr MODULO num_expr {
        Check_type($1); Check_type($3);
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        emit(mod_i, $1, $3, $$, 0);
    }           
    | MINUS num_expr %prec UMINUS {
        Check_type($2);
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        emit(uminus_i, $2, 0, $$, 0);
    }
    | LEFT_PARENTHESIS num_expr RIGHT_PARENTHESIS {$$ = $2;}
    | lvalue PLUS_PLUS {
        Check_type($1);
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        expr* one = new_Expr(constnum_e);
        one->numConst = 1;
        emit(assign_i, $1, NULL, $$, 0);
        emit(add_i, $1, new_constnum(1), $1, 0);
    }
     | PLUS_PLUS lvalue {
        Check_type($2);
        emit(add_i, $2, new_constnum(1), $2, 0);
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        emit(assign_i, $2, NULL, $$, 0);
    }
     | MINUS_MINUS lvalue {
        Check_type($2);
        emit(sub_i, $2, new_constnum(1), $2, 0);
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        emit(assign_i, $2, NULL, $$, 0);
    }
     | lvalue MINUS_MINUS {
        Check_type($1);
        $$=new_Expr(arithexpr_e);
        $$->sym = newTemp();
        $$->strConst = $$->sym->value.varVal->name;
        expr* one = new_Expr(constnum_e);
        one->numConst = 1;
        emit(assign_i, $1, NULL, $$, 0);
        emit(sub_i, $1, new_constnum(1), $1, 0);
    }
    | primary {$$ = $1;}
    ;

term : NOT expr {
        $$ = new_Expr(boolexpr_e);
        $$->sym = $2->sym;

        if($2->type!=boolexpr_e){
            emit(if_eq_i, new_constbool(true), $2, NULL, nextQuadLabel());
            emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
            $$->true_list = newlist(nextQuadLabel()-1);
            $$->false_list = newlist(nextQuadLabel()-2);
        }else{
            $$->true_list = $2->false_list;
            $$->false_list = $2->true_list;
        }
}
     | LEFT_PARENTHESIS term RIGHT_PARENTHESIS { $$ = $2;}
     ;

funcname : ID {$$ = $1;}
         | {$$ = newAnonymousFunction();}
         ;

funcprefix : FUNCTION funcname {
    //printf("PREFIX\n");
    Stack_push(pfunc_jumpstack, 0);
    SymbolTableEntry_t* func = new_SymbolTableFunction($2);
    SymbolTable_insert(symbol_table, func, true);
	Stack_push(local_args_stack,get_total_local_vars());
	resetfunctionlocalsoffset();
    $$=new_Expr(programfunc_e);
    $$->sym = func;
    $$->totalLocals=0;
    emit(funcstart_i, $$, NULL, NULL, 0);
	Stack_push(loop_count_stack,loop_counter); 
	loop_counter=0;
	Stack_push(in_func_block_stack,in_func_block);
	in_func_block=1;
}

funcargs : LEFT_PARENTHESIS {scope_increase();enter_scope_offset(SCOPE_FUNCTIONAL);} idlist RIGHT_PARENTHESIS

funcdef : funcprefix funcargs fun_block {
                Symtable_invalidate_scope(symbol_table); 
				scope_decrease(); exit_scope_offset();
				loop_counter= Stack_pop(loop_count_stack);
				in_func_block= Stack_pop(in_func_block_stack);
                $$ = $1;
				$$->totalLocals = get_total_local_vars();
                //printf("PARSER LOCO:%d \n",$$->totalLocals);
				set_local_var(Stack_pop(local_args_stack));
                emit(funcend_i, $$, NULL, NULL, 0);
                Stack_pop(pfunc_jumpstack);
            }
            ;

lib: LIB {$$=new_call($1);$$->sym = SymbolTable_lookup_global(symbol_table, $1);};
   | DOUBLE_COLON LIB {$$=new_call($2);$$->sym = SymbolTable_lookup_global(symbol_table, $2);};

lib_func : lib LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
                $1->next = $3;
                $$ = make_call($1, $3);
                set_formal_offset(Stack_pop(formal_args_stack));
                $1->type = libraryfunc_e;
                // $$->type = callfunc_e;
}
         | lib {
            $$=new_Expr(libraryfunc_e);
            $$->sym = $1->sym;
            $$->strConst = $1->strConst;
            }
         ;

idlist : id {if($1->sym&&isOfSameScope($1->sym)){decrease_functionlocalsoffset();}; SymbolTable_delete(symbol_table, $1->strConst); $1->sym = new_SymbolTableFormalVariable($1->strConst); SymbolTable_insert_formal(symbol_table, $1->sym);} COMMA nonempty_idlist
        | id {if($1->sym&&isOfSameScope($1->sym)){decrease_functionlocalsoffset();}; SymbolTable_delete(symbol_table, $1->strConst); $1->sym = new_SymbolTableFormalVariable($1->strConst); SymbolTable_insert_formal(symbol_table, $1->sym); }
        | ;

nonempty_idlist : id {if($1->sym&&isOfSameScope($1->sym)){decrease_functionlocalsoffset();}; SymbolTable_delete(symbol_table, $1->strConst); $1->sym = new_SymbolTableFormalVariable($1->strConst); SymbolTable_insert_formal(symbol_table, $1->sym); } COMMA nonempty_idlist
                | id {if($1->sym&&isOfSameScope($1->sym)){decrease_functionlocalsoffset();}; SymbolTable_delete(symbol_table, $1->strConst); $1->sym = new_SymbolTableFormalVariable($1->strConst); SymbolTable_insert_formal(symbol_table, $1->sym); } 
                ;

returnstmt : RETURN validate expr SEMICOLON {
            $$ = new_Expr(return_e);
            if($3!=NULL){
                if($3->type==boolexpr_e){
                    if($3->sym==NULL){
                        $3->sym=newTemp();
                    }
                    patchlist($3->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, $3, 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist($3->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, $3, 0);
                }
                $$->strConst = $3->strConst;
                $$->numConst = $3->numConst;
                $$->boolConst = $3->boolConst;
                $$->sym = $3->sym;
                emit(ret_i, $3, NULL, NULL, 0);
            }else{
                emit(ret_i, NULL, NULL, NULL, 0);
            }
            
        }
        ;

validate: /*empty*/ {if(!return_in_func_block_counter()){PRINT_PURPLE("Return not in a function at line %d\n", yylineno);}}

ifstmt : ifprefix stmt {
            reset_counter_temp();
            patchLabel($1, nextQuadLabel());
            $$ = $2; //Retrieve break/continue list
       }
       | ifprefix stmt elseprefix stmt  {
            reset_counter_temp();
            patchLabel($1, $3 + 1);
            patchLabel($3, nextQuadLabel());

            //Retrieve the full break/continue list either as is
            //or through merging if necessary
            $$ = $2;
            if($$==NULL){
                $$ = $4;
            }

            if($2!=NULL && $4!=NULL){
                $$ = $2;
                $$->break_list = mergelist($2->break_list, $4->break_list);
                $$->cont_list = mergelist($2->cont_list, $4->cont_list);
            }
       }
       ;

ifprefix : IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {
            
                if($3!=NULL&&$3->type==boolexpr_e){
                    if($3->sym==NULL){
                        $3->sym=newTemp();
                    }
                    patchlist($3->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, $3, 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist($3->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, $3, 0);
                }

            emit(
                if_eq_i,  $3,
                new_constbool(true), NULL,
                nextQuadLabel() + 2
            );
            $$ = nextQuadLabel();
            emit(jump_i, NULL, NULL, NULL, 0);
        }

elseprefix : ELSE {
            $$ = nextQuadLabel();
            emit(jump_i, NULL, NULL, NULL, 0);
        }


loopstart : /*empty*/ {increase_loop_counter();}
        ;

loopend: /*loopend*/ {decrease_loop_counter();}
        ;

break : BREAK SEMICOLON {
            if(!return_loop_counter()){PRINT_PURPLE("Break not in a loop at line %d\n", yylineno); return 0;}
            $$ = new_Expr(loop_e);
            make_stmt($$);
            $$->break_list = newlist(nextQuadLabel());
            emit(jump_i, NULL ,NULL, 0, 0); 
        }
        ;

continue: CONTINUE SEMICOLON { 
            if(return_loop_counter()==0){PRINT_PURPLE("Continue not in a loop at line %d\n", yylineno);}
            $$ = new_Expr(loop_e);
            make_stmt($$);
            $$->cont_list = newlist(nextQuadLabel());
            emit(jump_i, NULL ,NULL, 0, 0); 
        }
        ;

block : LEFT_BRACE {scope_increase(); enter_scope_offset(SCOPE_BLOCK);} stmt_block RIGHT_BRACE {Symtable_invalidate_scope(symbol_table);  scope_decrease(); exit_scope_offset();
            $$ = $3;
        }
        
      ;

stmt_block : stmt_block {reset_counter_temp();} stmt {
                if ($1!=NULL && $3!=NULL && !($1->break_list == 0 && $1->cont_list == 0 && $3->break_list == 0 && $3->cont_list == 0)) {
                    if(!error_found) {
                        $$->break_list = mergelist($1->break_list, $3->break_list);
                        $$->cont_list = mergelist($1->cont_list, $3->cont_list);
                    }
                } else {
                    $$ = $3;
                }
            }
            | {$$ = NULL;}
            ;


whilestart: WHILE {

            $$ = nextQuadLabel();
}

whilecond: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS {
                if($2!=NULL&&$2->type==boolexpr_e){
                    if($2->sym==NULL){
                        $2->sym=newTemp();
                    }
                    patchlist($2->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, $2, 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist($2->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, $2, 0);
                }

            emit(if_eq_i, $2, new_constbool(1), NULL, nextQuadLabel()+2);
            $$ = nextQuadLabel();
            emit(jump_i, NULL, NULL, 0, 0);
}

whilestmt : whilestart whilecond loopstart stmt loopend  {
            emit(jump_i, NULL, NULL, 0, $1);
            patchLabel($2, nextQuadLabel());
            if($4!=NULL){
                patchlist($4->break_list, nextQuadLabel());
                patchlist($4->cont_list, $1);
                $4->break_list = 0;
                $4->cont_list = 0;
            }
            $$ = $4;
        }
        ;

N: { $$ = nextQuadLabel(); emit(jump_i,NULL,NULL,NULL,0); }
M: { $$ = nextQuadLabel(); }

forprefix: FOR LEFT_PARENTHESIS elist SEMICOLON M expr SEMICOLON {

            if($6->type==boolexpr_e){
                if($6->sym==NULL){
                    $6->sym=newTemp();
                }
                patchlist($6->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, $6, 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist($6->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, $6, 0);
            }

    $$ = new_Expr(for_e);
    $$->test = $5;
    $$->enter = nextQuadLabel();
    emit(if_eq_i, $6, new_constbool(1), NULL, 0);
}

forstmt : forprefix N elist RIGHT_PARENTHESIS N loopstart stmt loopend N   {
        reset_counter_temp();
        patchLabel($1->enter, $5+1);
        patchLabel($2, nextQuadLabel()); 
        patchLabel($5, $1->test); 
        patchLabel($9, $2+1); 
        if($7!=NULL){
            patchlist($7->break_list, nextQuadLabel());
            patchlist($7->cont_list, $2+1);
            $7->break_list = 0;
            $7->cont_list = 0;
        }
        $$ = $7;
    }       
    ;

elist : nonempty_elist COMMA expr {
            if($3!=NULL){
                if($3->sym==NULL&&!isConstExpr($3)){
                    $3->sym = new_SymbolTableVariable($3->strConst); 
                    SymbolTable_insert(symbol_table, $3->sym, false);
                }
                // increase_functionformalsoffset();
            }
            if($3!=NULL&&$3->type==boolexpr_e){
                if($3->sym==NULL){
                    $3->sym=newTemp();
                }
                patchlist($3->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, $3, 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist($3->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, $3, 0);
            }

            $$=$3; $$->next = $1;
            $1->prev = $$;
        }
        | expr {
            Stack_push(formal_args_stack,get_total_formal_args());
            resetfunctionformalsoffset();
            if($1!=NULL){
                if($1->sym==NULL&&!isConstExpr($1)){
                    $1->sym = new_SymbolTableVariable($1->strConst); 
                    SymbolTable_insert(symbol_table, $1->sym, false);
                }
                // increase_functionformalsoffset();
            }
            if($1!=NULL&&$1->type==boolexpr_e){
                if($1->sym==NULL){
                    $1->sym=newTemp();
                }
                patchlist($1->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, $1, 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist($1->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, $1, 0);
            }

            $$=$1;
        }
        ;

nonempty_elist : nonempty_elist COMMA expr {
            if($3!=NULL){
                if($3->sym==NULL&&!isConstExpr($3)){
                    $3->sym = new_SymbolTableVariable($3->strConst); 
                    SymbolTable_insert(symbol_table, $3->sym, false);
                }
                // increase_functionformalsoffset();
            }
            if($3!=NULL&&$3->type==boolexpr_e){
                if($3->sym==NULL){
                    $3->sym=newTemp();
                }
                patchlist($3->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, $3, 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist($3->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, $3, 0);
            }
            $$=$3; $$->next = $1;
            $1->prev = $$;
        }
        | expr {
            Stack_push(formal_args_stack,get_total_formal_args());
            resetfunctionformalsoffset();
            if($1!=NULL){
                if($1->sym==NULL&&!isConstExpr($1)){
                    $1->sym = new_SymbolTableVariable($1->strConst); 
                    SymbolTable_insert(symbol_table, $1->sym, false);
                }
                // increase_functionformalsoffset();
            }
            if($1!=NULL&&$1->type==boolexpr_e){
                if($1->sym==NULL){
                    $1->sym=newTemp();
                }
                patchlist($1->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, $1, 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist($1->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, $1, 0);
            }
            $$=$1;
        }
        ;


primary : lvalue {$$=$1;}
        | call {$$=$1;}
        | objectdef
        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS {$$=$2;}
        | constant {$$=$1;}
        ;

call : call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
            set_formal_offset(Stack_pop(formal_args_stack));
            $1->next = $3;
            $$ = make_call($1, $3);
        }
        | lvalue callsuffix {
            if ($2->method){
                $1 = emitIfTableItem($1); //in case it was a table item too

                expr* curr = $2;
                while (curr->next!=NULL){
                    curr = curr->next;
                }
                curr->next = $1; //insert first (reversed, so from last)

                $1->index = new_conststring($2->strConst);
                $1 = emitIfTableItem(member_item($1, $2->strConst));
            } else {
                //SymbolTableEntry_t* t = SymbolTable_lookup_chill(symbol_table, $1->strConst);
                //if ($1->type == tableitem_e) 
                if ($1->sym&&$1->sym->isTable) 
                    $1->type = tableitem_e;
            }
            
            $$ = make_call($1, $2->next);
            if($2->method||$1->index!=NULL){
                // printf("TABLE\n");
                $1->type = tableitem_e;
            }
           
        }
        | LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
            set_formal_offset(Stack_pop(formal_args_stack));
	        expr* func = new_Expr(programfunc_e);
            func->next = $5;
            func->sym = $2->sym;
            $$ = make_call(func, $5);
            printArgs($$->next);
        }
        ;

callsuffix : normcall {$$ = $1;}
        | methodcall {$$ = $1;}
        ;

normcall : LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
            // printf("args: %d\n",get_total_formal_args());
            set_formal_offset(Stack_pop(formal_args_stack));
            // printf("prev args: %d\n",get_total_formal_args());
            $$ = new_Expr(callfunc_e);
            $$->next = $2;
            $$->numConst = 0;
            $$->strConst = NULL;
        };
methodcall : DOTS id LEFT_PARENTHESIS elist RIGHT_PARENTHESIS {
            //increase_functionformalsoffset(); // +1 DUE TO DOTS
            // printf("args: %d\n",get_total_formal_args());
            set_formal_offset(Stack_pop(formal_args_stack));
            // printf("prev args: %d\n",get_total_formal_args());
            $$ = new_Expr(callfunc_e);
            $$->strConst = addStringLiterals($2->strConst); 
            $$->next = $4;
            $$->method = true;
        }; // equivalent to lvalue.id(lvalue, elist)


objectdef : LEFT_BRACKET elist RIGHT_BRACKET {
            $$=new_Expr(newtable_e);
            $$->sym = newTemp();
            $$->sym->isTable = true;
            if($2!=NULL && $2->type!=constnum_e  && $2->type!=nil_e && $2->type!=constbool_e && $2->type!=conststring_e)$2->type = tableitem_e;
            emit(tablecreate_i, $$, NULL, NULL, 0);
            expr* iterator = moveToEnd($2);
            for(int i=0;iterator ; iterator = iterator->prev) {
                emit(tablesetelem_i, $$, new_constnum(i++), iterator, 0);
            }
        }
        | LEFT_BRACKET indexed RIGHT_BRACKET {
            $$=new_Expr(newtable_e);
            $$->sym = newTemp();
            $$->sym->isTable = true;
            if($2!=NULL && $2->type!=constnum_e  && $2->type!=nil_e && $2->type!=constbool_e && $2->type!=conststring_e)$2->type = tableitem_e;
            emit(tablecreate_i, $$, NULL, NULL, 0);
            for(int i = 0; $2&&$2->next; $2 = $2->next->next)
                emit(tablesetelem_i, $$, $2, $2->next, 0);
        }
        ;

indexed : indexedelem COMMA indexlist {$$ = $1; $$->next->next = $3;}
        | indexedelem {$$ = $1;}
        ;

indexlist : indexedelem COMMA indexlist {$$ = $1; $$->next->next = $3;}
        | indexedelem {$$ = $1;}
        | ;

indexedelem : LEFT_BRACE expr COLON expr RIGHT_BRACE {
                $$ = $2;
                $$->next = $4;
            }
            | error { yyerrok; yyclearin; }
            ;

member : lvalue FULL_STOP id {
            //$1->type=tableitem_e;

            $$ = new_Expr(tableitem_e);
            $$->strConst = $1->strConst;
            $3->strConst = addStringLiterals($3->strConst);
            $3->type = conststring_e;
            $$->index = $3;
            $$->sym = $1->sym;
            assignParentTable($$);
            $$ = member_item($$, $3->strConst);   
        }
        | lvalue LEFT_BRACKET expr RIGHT_BRACKET {
            $$ = new_Expr(tableitem_e);
            $$->strConst = $1->strConst;
            $$->index = $3;
            $$->sym = $1->sym;
            assignParentTable($$);
            $$ = member_item($$, $3->strConst);
        }
        | call FULL_STOP id {
            //$3->sym =  new_SymbolTableVariable($3->strConst); SymbolTable_insert(symbol_table, $3->sym, false);
            $$=new_Expr(tableitem_e);
            $$->strConst = $1->strConst;
            $3->strConst = addStringLiterals($3->strConst);
            $3->type = conststring_e;
            $$->sym = $1->sym;
            $$->index = $3;
            $1->type = tableitem_e;
            $$ = member_item($$, $3->strConst);
        }
        | call LEFT_BRACKET expr RIGHT_BRACKET {
            $$=new_Expr(tableitem_e);
            $$->strConst = $1->strConst;
            $$->index = $3;
            $$->sym = $1->sym;
            $$ = member_item($$, $3->strConst);
        }
        ;

num : NUMBER {$$=new_Expr(constnum_e); $$->numConst = $1; $$->strConst = num_to_str($1);}
    ; 

constant : num {$$=$1;}
         | STR {$$=new_Expr(conststring_e); $$->strConst = addStringLiterals($1);}
         | NIL {$$=new_Expr(nil_e);}
         | TRUE {$$=new_Expr(constbool_e); $$->boolConst = true;}
         | FALSE {$$=new_Expr(constbool_e); $$->boolConst = false;}
         ;


%% 

int main(int argc, char** argv)
{      
    int i=0;    
    if(argc==2||argc==3)
    {
        /*No optional input file*/
        in_filename = argv[1];
        FILE* in_file = fopen(argv[1],"r");
        if (!in_file) {
            perror("Error opening input file");
            return 1;
        }

        yyin = in_file;

        /*Optional output file*/
        if (argc==3)
        {
            FILE* out_file = fopen(argv[2],"wb");
            if (!out_file) {
                perror("Error opening output file");
                return 1;
            }
            yyout = out_file;
        }
    }
    else
    {
        /*Wrong number of arguments*/
        printHelp(argv[0]);
        exit(EXIT_FAILURE);
    }
     
    symbol_table = new_SymbolTable();
    scope_stack = new_Stack();
    loop_count_stack = new_Stack();
    in_func_block_stack= new_Stack();
    funcstack = new_Funcstack();
    pfunc_jumpstack = new_Stack();

    formal_args_stack=new_Stack();
    local_args_stack=new_Stack();

    for(i=0;i<12;i++){
        SymbolTable_insert(symbol_table, new_SymbolTableLibFunction(library_function_names[i]), true);
    }
    
	
    yyparse();
    printSymbolTableContents(symbol_table);
    if(!error_found){
        printQuads(stdout);
        /* printf("globals2:%d \n",get_global_vars()); */
    }else{
        GENERAL_ERROR("Compilation failed with error(s)\n");
        exit(-1);
    }
    generateTcode(curr_quad);
    curr_quad = 1;
    printInstr(stdout);

    FILE* bfile = fopen("output.ax", "wb");
    if(bfile==NULL){
        perror("Error opening output binary file for writing");
        exit(EXIT_FAILURE);
    }

    generateBinaryFile(bfile);
    fclose(bfile);
    return 0;
}

void printHelp(char* programName)
{
    fprintf(stdout,"Usage: %s <source file> <output file (optional)>\n",programName);
}
