/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_BISON_PARSER_H_INCLUDED
# define YY_YY_SRC_BISON_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    FOR = 261,                     /* FOR  */
    FUNCTION = 262,                /* FUNCTION  */
    RETURN = 263,                  /* RETURN  */
    BREAK = 264,                   /* BREAK  */
    CONTINUE = 265,                /* CONTINUE  */
    AND = 266,                     /* AND  */
    NOT = 267,                     /* NOT  */
    OR = 268,                      /* OR  */
    LOCAL = 269,                   /* LOCAL  */
    TRUE = 270,                    /* TRUE  */
    FALSE = 271,                   /* FALSE  */
    NIL = 272,                     /* NIL  */
    EQUAL = 273,                   /* EQUAL  */
    PLUS = 274,                    /* PLUS  */
    MINUS = 275,                   /* MINUS  */
    MULTIPLY = 276,                /* MULTIPLY  */
    DIV = 277,                     /* DIV  */
    MODULO = 278,                  /* MODULO  */
    EQUAL_EQUAL = 279,             /* EQUAL_EQUAL  */
    NOT_EQUAL = 280,               /* NOT_EQUAL  */
    PLUS_PLUS = 281,               /* PLUS_PLUS  */
    MINUS_MINUS = 282,             /* MINUS_MINUS  */
    GREATER_THAN = 283,            /* GREATER_THAN  */
    LESS_THAN = 284,               /* LESS_THAN  */
    GREATER_EQUAL = 285,           /* GREATER_EQUAL  */
    LESS_EQUAL = 286,              /* LESS_EQUAL  */
    LEFT_BRACE = 287,              /* LEFT_BRACE  */
    RIGHT_BRACE = 288,             /* RIGHT_BRACE  */
    LEFT_BRACKET = 289,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 290,           /* RIGHT_BRACKET  */
    LEFT_PARENTHESIS = 291,        /* LEFT_PARENTHESIS  */
    RIGHT_PARENTHESIS = 292,       /* RIGHT_PARENTHESIS  */
    SEMICOLON = 293,               /* SEMICOLON  */
    COMMA = 294,                   /* COMMA  */
    COLON = 295,                   /* COLON  */
    DOUBLE_COLON = 296,            /* DOUBLE_COLON  */
    FULL_STOP = 297,               /* FULL_STOP  */
    DOTS = 298,                    /* DOTS  */
    UNDEFINED_TOKEN = 299,         /* UNDEFINED_TOKEN  */
    STR = 300,                     /* STR  */
    ID = 301,                      /* ID  */
    NUMBER = 302,                  /* NUMBER  */
    LIB = 303,                     /* LIB  */
    UMINUS = 304                   /* UMINUS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IF 258
#define ELSE 259
#define WHILE 260
#define FOR 261
#define FUNCTION 262
#define RETURN 263
#define BREAK 264
#define CONTINUE 265
#define AND 266
#define NOT 267
#define OR 268
#define LOCAL 269
#define TRUE 270
#define FALSE 271
#define NIL 272
#define EQUAL 273
#define PLUS 274
#define MINUS 275
#define MULTIPLY 276
#define DIV 277
#define MODULO 278
#define EQUAL_EQUAL 279
#define NOT_EQUAL 280
#define PLUS_PLUS 281
#define MINUS_MINUS 282
#define GREATER_THAN 283
#define LESS_THAN 284
#define GREATER_EQUAL 285
#define LESS_EQUAL 286
#define LEFT_BRACE 287
#define RIGHT_BRACE 288
#define LEFT_BRACKET 289
#define RIGHT_BRACKET 290
#define LEFT_PARENTHESIS 291
#define RIGHT_PARENTHESIS 292
#define SEMICOLON 293
#define COMMA 294
#define COLON 295
#define DOUBLE_COLON 296
#define FULL_STOP 297
#define DOTS 298
#define UNDEFINED_TOKEN 299
#define STR 300
#define ID 301
#define NUMBER 302
#define LIB 303
#define UMINUS 304

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "src/bison/parser.y"

    char*   stringVal;
    int     intVal;
    double  realVal;
    struct expr* exprVal;
    struct {
        int break_list;
        int cont_list;
    } stmtVal;

#line 176 "src/bison/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SRC_BISON_PARSER_H_INCLUDED  */
