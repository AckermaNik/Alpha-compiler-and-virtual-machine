

%{
   #include "../bison/parser.h"
   #include "../../utils/alpha_utilities.h"
   

    //#define YY_DECL int alpha_yylex(YYSTYPE yylval)
    
    int alpha_yylex(void* ylval);

   //Declarations
   void parseMultilineComment();
   void printMultilineComment(struct alpha_token_t*,int);
   extern struct alpha_token_list_t token_list;

   int yytokencount = 0;
   char* modified_string="\0";
   char ptr;
   char* text;
   int flag=0;
%}

%option yylineno
/*%option outfile = "./scanner.c"*/

DIGIT               [0-9]
ID                  [a-zA-Z][a-zA-Z_0-9]*
NUMBER                ({DIGIT}*\.[0-9](e|E)?{DIGIT}*)|{DIGIT}+|{DIGIT}+\.
LINE_COMMENT        "//".*
MULTILINE_COMMENT   "/*"
NEWLINE             "\n"

%%

if {yytokencount++;yylval.stringVal = strdup(yytext);return IF;}
else {yytokencount++;yylval.stringVal = strdup(yytext);return ELSE;}
while {yytokencount++;yylval.stringVal = strdup(yytext);return WHILE;}
for {yytokencount++;yylval.stringVal = strdup(yytext);return FOR;}
function {yytokencount++;yylval.stringVal = strdup(yytext);return FUNCTION;}
return {yytokencount++;yylval.stringVal = strdup(yytext);return RETURN;}
break {yytokencount++;yylval.stringVal = strdup(yytext);return BREAK;}
continue {yytokencount++;yylval.stringVal = strdup(yytext);return CONTINUE;}
and {yytokencount++;yylval.stringVal = strdup(yytext);return AND;}
not {yytokencount++;yylval.stringVal = strdup(yytext);return NOT;}
or {yytokencount++;yylval.stringVal = strdup(yytext);return OR;}
local {yytokencount++;yylval.stringVal = strdup(yytext);return LOCAL;}
true {yytokencount++;yylval.stringVal = strdup(yytext);return TRUE;}
false {yytokencount++;yylval.stringVal = strdup(yytext);return FALSE;}
nil {yytokencount++;yylval.stringVal = strdup(yytext);return NIL;}

print {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
input {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
objectmemberkeys {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
objecttotalmembers {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
objectcopy {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
totalarguments {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
argument {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
typeof {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
strtonum {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
sqrt {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
cos {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}
sin {yytokencount++;yylval.stringVal = strdup(yytext); return LIB;}




"=" {yytokencount++;yylval.stringVal = strdup(yytext);return EQUAL;}
"+" {yytokencount++;yylval.stringVal = strdup(yytext);return PLUS;}
"-" {yytokencount++;yylval.stringVal = strdup(yytext);return MINUS;}
"*" {yytokencount++;yylval.stringVal = strdup(yytext);return MULTIPLY;}
"/" {yytokencount++;yylval.stringVal = strdup(yytext);return DIV;}
"%" {yytokencount++;yylval.stringVal = strdup(yytext);return MODULO;}
"==" {yytokencount++;yylval.stringVal = strdup(yytext);return EQUAL_EQUAL;}
"!=" {yytokencount++;yylval.stringVal = strdup(yytext);return NOT_EQUAL;}
"++" {yytokencount++;yylval.stringVal = strdup(yytext);return PLUS_PLUS;}
"--" {yytokencount++;yylval.stringVal = strdup(yytext);return MINUS_MINUS;}
">" {yytokencount++;yylval.stringVal = strdup(yytext);return GREATER_THAN;}
"<" {yytokencount++;yylval.stringVal = strdup(yytext);return LESS_THAN;}
">=" {yytokencount++;yylval.stringVal = strdup(yytext);return GREATER_EQUAL;}
"<=" {yytokencount++;yylval.stringVal = strdup(yytext);return LESS_EQUAL;}

"{" {yytokencount++;yylval.stringVal = strdup(yytext);return LEFT_BRACE;}
"}" {yytokencount++;yylval.stringVal = strdup(yytext);return RIGHT_BRACE;}
"[" {yytokencount++;yylval.stringVal = strdup(yytext);return LEFT_BRACKET;}
"]" {yytokencount++;yylval.stringVal = strdup(yytext);return RIGHT_BRACKET;}
"(" {yytokencount++;yylval.stringVal = strdup(yytext);return LEFT_PARENTHESIS;}
")" {yytokencount++;yylval.stringVal = strdup(yytext);return RIGHT_PARENTHESIS;}
";" {yytokencount++;yylval.stringVal = strdup(yytext);return SEMICOLON;}
"," {yytokencount++;yylval.stringVal = strdup(yytext);return COMMA;}
":" {yytokencount++;yylval.stringVal = strdup(yytext);return COLON;}
"::" {yytokencount++;yylval.stringVal = strdup(yytext);return DOUBLE_COLON;}
"." {yytokencount++;yylval.stringVal = strdup(yytext);return FULL_STOP;}
".." {yytokencount++;yylval.stringVal = strdup(yytext);return DOTS;}

(\"([^"\\]|\\.)*\\([^"\\]|\\.)*\")|(\"([^"\\]|\\(.|\n))*\") {
    yytokencount++;
    char* final_string = find_special_chars(yytext);
    fprintf(yyout,"%d: #%d  %s %s\t%s<-%s\n",yylineno,yytokencount,yytext,"STRING",final_string,"char*");
    struct alpha_token_t* new_token = new_alpha_token(yylineno,0,yytokencount,final_string,"STRING","char*");
    // alpha_token_list_insert(&token_list,new_token);
    // setup_alpha_token((struct alpha_token_t*)yylval,yylineno,0,yytokencount,final_string,"STRING","char*");
    yylval.stringVal = strdup(final_string);
    return STR;
}

(\"([^"\\]|\\.)*\")|\"  {
    text=malloc(sizeof(char)*strlen(yytext)+1);
    strcpy(text,yytext);
    if(text[0]=='"'){
        flag=0;
        ptr=input();
        while( ptr!='\0' && ptr !='\n'){
            if(ptr=='"'){
                flag=1;
                break;
            }
            ptr=input();
        }

        if(ptr =='\n'){
            yylineno--;
        }

        if(flag==0){
            fprintf(yyout,"Unclosed string \"%s\" in line %d\n", yytext, yylineno);
        }else{
            yytokencount++;
            char* final_string = find_special_chars(yytext);
            fprintf(yyout,"%d: #%d  %s %s\t%s<-%s\n",yylineno,yytokencount,yytext,"STRING",final_string,"char*");
            struct alpha_token_t* new_token = new_alpha_token(yylineno,0,yytokencount,final_string,"STRING","char*");
            free(final_string);
            alpha_token_list_insert(&token_list,new_token);
        }
    }else{
        fprintf(yyout,"Unclosed string \"%s\" in line %d\n", yytext, yylineno);
    }
    free(text);
}

{ID} {
    yytokencount++;
    fprintf(yyout,"%d: #%d \"%s\" %s\t\"%s\" <-%s\n",yylineno,yytokencount,yytext,"IDENT",yytext,"char*");
    struct alpha_token_t* new_token = new_alpha_token(yylineno,0,yytokencount,yytext,"IDENT","char*");
    // alpha_token_list_insert(&token_list,new_token);
    // setup_alpha_token((struct alpha_token_t*)yylval,yylineno,0,yytokencount,yytext,"IDENT","char*");
    yylval.stringVal = strdup(yytext);
    return ID;
}


{NUMBER} {
    yytokencount++;
    fprintf(yyout,"%d: #%d \"%s\" %s\t%s <-%s\n",yylineno,yytokencount,yytext,"REALCONST",yytext,"REAL");
    struct alpha_token_t* new_token = new_alpha_token(yylineno,0,yytokencount,yytext,"REALCONST","real");
    // alpha_token_list_insert(&token_list,new_token);
    // setup_alpha_token((struct alpha_token_t*)yylval,yylineno,0,yytokencount,yytext,"REALCONST","real");
    yylval.realVal = atof(yytext);

    return NUMBER;
}


{LINE_COMMENT} {
    yytokencount++;
    fprintf(yyout,"%d: #%d \"%s\" %s\t%s <-%s\n",yylineno,yytokencount,"","COMMENT","LINE_COMMENT","enumerated");
    struct alpha_token_t* new_token = new_alpha_token(yylineno,0,yytokencount,"COMMENT","LINE_COMMENT","enumerated");
    alpha_token_list_insert(&token_list,new_token);
}

{MULTILINE_COMMENT} {
    parseMultilineComment();
}


[ \t\n]                 {/*Ignore whitespaces*/}

.                       {fprintf(yyout,"Undefined token \"%s\" in line %d\n", yytext, yylineno); return UNDEFINED_TOKEN;}
%%


int yywrap() {}

void parseMultilineComment()
{
    int total_comment_count = 1;
    int open_comment_count = 1;
    int closed_comment_count = 0;
    int line_count = yylineno;
    int ch = input();

    struct alpha_token_list_t comment_list = {NULL,NULL};

    yytokencount++;

    struct alpha_token_t* new_token = new_alpha_token(line_count,0,yytokencount,"COMMENT","MULTILINE_COMMENT","enumerated");
    alpha_token_list_insert(&comment_list,new_token);

    while (open_comment_count > 0 && (ch != EOF) && (ch != '\0'))
    {
        switch(ch)
        {
            case '/'://Possibly nested comment
            if ((ch = input()) == '*'){
                open_comment_count++;
                total_comment_count++;
                yytokencount++;

                //Create new token
                struct alpha_token_t* new_token = new_alpha_token(line_count,0,yytokencount,"COMMENT","MULTILINE_COMMENT","enumerated");
                alpha_token_list_insert(&comment_list,new_token);
            }else
                unput(ch);
            break;
            case '*'://Possibly end of comment
            if ((ch = input()) == '/'){
                open_comment_count--;

                //Move comment to actual token list
                struct alpha_token_t* tail_comment = comment_list.tail;
                alpha_token_list_unlink(&comment_list,tail_comment);
                alpha_list_insert_ordered(&token_list,tail_comment);
                if (tail_comment!=NULL) tail_comment->linespan = line_count-tail_comment->lineno;
                closed_comment_count++;
            }else
                unput(ch);
            break;
            case '\n'://Count new line
            line_count++;
            break;
        }

        ch = input();//Read the next character
    }

    if(ch!='\0')unput(ch);

    if (open_comment_count > 0)//Unclosed multiline comment
    {
        struct alpha_token_t* last_comment = comment_list.tail;

        if (last_comment!=NULL)
            fprintf(yyout,"Multiline comment at line %d not closed.\n",last_comment->lineno);

        exit(EXIT_FAILURE);
    }

    struct alpha_token_t* last_comment = alpha_list_seek(token_list.tail,1-total_comment_count);
    do{
        //Find the start of the comment, in order to print the token message
        if (last_comment!=NULL)
        {
            printMultilineComment(last_comment,last_comment->lineno+last_comment->linespan);
            last_comment = alpha_list_seek(last_comment,1);
        }
    }while(last_comment!=NULL&&total_comment_count>0);
}

void printMultilineComment(struct alpha_token_t* token_node,int end_line)
{
   fprintf(yyout,"%d: #%d \"%d-%d\" %s\t%s <-%s\n",
    token_node->lineno,token_node->tokenno,token_node->lineno,end_line,"COMMENT","MULTILINE_COMMENT","enumerated");
}

char* find_special_chars(char* str){

    char *modified_string= (char*)malloc(strlen(str) + 1);
    int position=0;
    char *ptr = str + 1; /* Skip the opening quote*/
   
    while (*ptr != '\0' && *ptr != '\"') {
       
        //memset(temp, 0, strlen(modified_string)); -> bgazei seg fault
        if (*ptr == '\\') {
          
                ptr++; // Skip the escape character
                if((*ptr)=='\n'){
                    modified_string[position]=' ';           
                    //printf("str1: %s\n",modified_string);                    
                }else if((*ptr)=='t'){
                    modified_string[position]='\t';
                }else if((*ptr)=='\\'){
                    modified_string[position]='\\';
                }else if((*ptr)=='\"'){
                    modified_string[position]='\"';
                }else if((*ptr)=='n'){
                    modified_string[position]='\n';
                }else{
                    modified_string="Error Invalid use of token \"\\\"";
                    return modified_string;
                }
        }else{
                modified_string[position]=*ptr;
                // printf("str2: %s\n",modified_string);
        }
        ptr++;
        position++;
    }
    // if((*ptr)!='\0'){
    //     printf("%c: \n",*ptr);
    // }
    
    if((*ptr)!='\"'){
        modified_string="Error/not closing string";
        return modified_string;
    }
    modified_string[position]='\0'; /*mpainei sthn thesh tou "*/
    return modified_string;
}
