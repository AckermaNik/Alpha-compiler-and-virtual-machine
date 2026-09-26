/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 4 "src/bison/parser.y"

    #include "../../utils/alpha_bison_utilities.h"
    #include "../../utils/alpha_target_utilities.h"
    #include <stdio.h>
    #include <stdlib.h>

    extern int alpha_yylex(void* ylval);
    int yylex();
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

#line 91 "src/bison/parser.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_FOR = 6,                        /* FOR  */
  YYSYMBOL_FUNCTION = 7,                   /* FUNCTION  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_BREAK = 9,                      /* BREAK  */
  YYSYMBOL_CONTINUE = 10,                  /* CONTINUE  */
  YYSYMBOL_AND = 11,                       /* AND  */
  YYSYMBOL_NOT = 12,                       /* NOT  */
  YYSYMBOL_OR = 13,                        /* OR  */
  YYSYMBOL_LOCAL = 14,                     /* LOCAL  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_NIL = 17,                       /* NIL  */
  YYSYMBOL_EQUAL = 18,                     /* EQUAL  */
  YYSYMBOL_PLUS = 19,                      /* PLUS  */
  YYSYMBOL_MINUS = 20,                     /* MINUS  */
  YYSYMBOL_MULTIPLY = 21,                  /* MULTIPLY  */
  YYSYMBOL_DIV = 22,                       /* DIV  */
  YYSYMBOL_MODULO = 23,                    /* MODULO  */
  YYSYMBOL_EQUAL_EQUAL = 24,               /* EQUAL_EQUAL  */
  YYSYMBOL_NOT_EQUAL = 25,                 /* NOT_EQUAL  */
  YYSYMBOL_PLUS_PLUS = 26,                 /* PLUS_PLUS  */
  YYSYMBOL_MINUS_MINUS = 27,               /* MINUS_MINUS  */
  YYSYMBOL_GREATER_THAN = 28,              /* GREATER_THAN  */
  YYSYMBOL_LESS_THAN = 29,                 /* LESS_THAN  */
  YYSYMBOL_GREATER_EQUAL = 30,             /* GREATER_EQUAL  */
  YYSYMBOL_LESS_EQUAL = 31,                /* LESS_EQUAL  */
  YYSYMBOL_LEFT_BRACE = 32,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 33,               /* RIGHT_BRACE  */
  YYSYMBOL_LEFT_BRACKET = 34,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 35,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_PARENTHESIS = 36,          /* LEFT_PARENTHESIS  */
  YYSYMBOL_RIGHT_PARENTHESIS = 37,         /* RIGHT_PARENTHESIS  */
  YYSYMBOL_SEMICOLON = 38,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 39,                     /* COMMA  */
  YYSYMBOL_COLON = 40,                     /* COLON  */
  YYSYMBOL_DOUBLE_COLON = 41,              /* DOUBLE_COLON  */
  YYSYMBOL_FULL_STOP = 42,                 /* FULL_STOP  */
  YYSYMBOL_DOTS = 43,                      /* DOTS  */
  YYSYMBOL_UNDEFINED_TOKEN = 44,           /* UNDEFINED_TOKEN  */
  YYSYMBOL_STR = 45,                       /* STR  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_NUMBER = 47,                    /* NUMBER  */
  YYSYMBOL_LIB = 48,                       /* LIB  */
  YYSYMBOL_UMINUS = 49,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 50,                  /* $accept  */
  YYSYMBOL_program = 51,                   /* program  */
  YYSYMBOL_stmt_loop = 52,                 /* stmt_loop  */
  YYSYMBOL_stmt = 53,                      /* stmt  */
  YYSYMBOL_fun_block = 54,                 /* fun_block  */
  YYSYMBOL_expr = 55,                      /* expr  */
  YYSYMBOL_boolexpr = 56,                  /* boolexpr  */
  YYSYMBOL_57_1 = 57,                      /* $@1  */
  YYSYMBOL_58_2 = 58,                      /* $@2  */
  YYSYMBOL_59_3 = 59,                      /* $@3  */
  YYSYMBOL_60_4 = 60,                      /* $@4  */
  YYSYMBOL_assignexpr = 61,                /* assignexpr  */
  YYSYMBOL_lvalue = 62,                    /* lvalue  */
  YYSYMBOL_id = 63,                        /* id  */
  YYSYMBOL_num_expr = 64,                  /* num_expr  */
  YYSYMBOL_term = 65,                      /* term  */
  YYSYMBOL_funcname = 66,                  /* funcname  */
  YYSYMBOL_funcprefix = 67,                /* funcprefix  */
  YYSYMBOL_funcargs = 68,                  /* funcargs  */
  YYSYMBOL_69_5 = 69,                      /* $@5  */
  YYSYMBOL_funcdef = 70,                   /* funcdef  */
  YYSYMBOL_lib = 71,                       /* lib  */
  YYSYMBOL_lib_func = 72,                  /* lib_func  */
  YYSYMBOL_idlist = 73,                    /* idlist  */
  YYSYMBOL_74_6 = 74,                      /* $@6  */
  YYSYMBOL_nonempty_idlist = 75,           /* nonempty_idlist  */
  YYSYMBOL_76_7 = 76,                      /* $@7  */
  YYSYMBOL_returnstmt = 77,                /* returnstmt  */
  YYSYMBOL_validate = 78,                  /* validate  */
  YYSYMBOL_ifstmt = 79,                    /* ifstmt  */
  YYSYMBOL_ifprefix = 80,                  /* ifprefix  */
  YYSYMBOL_elseprefix = 81,                /* elseprefix  */
  YYSYMBOL_loopstart = 82,                 /* loopstart  */
  YYSYMBOL_loopend = 83,                   /* loopend  */
  YYSYMBOL_break = 84,                     /* break  */
  YYSYMBOL_continue = 85,                  /* continue  */
  YYSYMBOL_block = 86,                     /* block  */
  YYSYMBOL_87_8 = 87,                      /* $@8  */
  YYSYMBOL_stmt_block = 88,                /* stmt_block  */
  YYSYMBOL_89_9 = 89,                      /* $@9  */
  YYSYMBOL_whilestart = 90,                /* whilestart  */
  YYSYMBOL_whilecond = 91,                 /* whilecond  */
  YYSYMBOL_whilestmt = 92,                 /* whilestmt  */
  YYSYMBOL_N = 93,                         /* N  */
  YYSYMBOL_M = 94,                         /* M  */
  YYSYMBOL_forprefix = 95,                 /* forprefix  */
  YYSYMBOL_forstmt = 96,                   /* forstmt  */
  YYSYMBOL_elist = 97,                     /* elist  */
  YYSYMBOL_nonempty_elist = 98,            /* nonempty_elist  */
  YYSYMBOL_primary = 99,                   /* primary  */
  YYSYMBOL_call = 100,                     /* call  */
  YYSYMBOL_callsuffix = 101,               /* callsuffix  */
  YYSYMBOL_normcall = 102,                 /* normcall  */
  YYSYMBOL_methodcall = 103,               /* methodcall  */
  YYSYMBOL_objectdef = 104,                /* objectdef  */
  YYSYMBOL_indexed = 105,                  /* indexed  */
  YYSYMBOL_indexlist = 106,                /* indexlist  */
  YYSYMBOL_indexedelem = 107,              /* indexedelem  */
  YYSYMBOL_member = 108,                   /* member  */
  YYSYMBOL_num = 109,                      /* num  */
  YYSYMBOL_constant = 110                  /* constant  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   611

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  132
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  236

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   155,   155,   158,   171,   173,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   198,   202,   203,   204,   205,
     208,   209,   217,   225,   233,   241,   241,   260,   260,   279,
     279,   296,   296,   319,   322,   346,   370,   391,   409,   412,
     413,   414,   415,   416,   419,   422,   429,   436,   443,   450,
     457,   464,   465,   475,   483,   491,   501,   504,   518,   521,
     522,   525,   542,   542,   544,   558,   559,   561,   568,   575,
     575,   576,   577,   579,   579,   580,   583,   608,   610,   615,
     635,   657,   663,   666,   669,   678,   687,   687,   693,   693,
     703,   707,   712,   729,   742,   743,   745,   764,   780,   802,
     827,   848,   873,   874,   875,   876,   877,   880,   885,   911,
     921,   922,   925,   934,   946,   957,   968,   969,   972,   973,
     974,   976,   980,   983,   995,  1003,  1014,  1023,  1026,  1027,
    1028,  1029,  1030
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "FOR", "FUNCTION", "RETURN", "BREAK", "CONTINUE", "AND", "NOT", "OR",
  "LOCAL", "TRUE", "FALSE", "NIL", "EQUAL", "PLUS", "MINUS", "MULTIPLY",
  "DIV", "MODULO", "EQUAL_EQUAL", "NOT_EQUAL", "PLUS_PLUS", "MINUS_MINUS",
  "GREATER_THAN", "LESS_THAN", "GREATER_EQUAL", "LESS_EQUAL", "LEFT_BRACE",
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_PARENTHESIS",
  "RIGHT_PARENTHESIS", "SEMICOLON", "COMMA", "COLON", "DOUBLE_COLON",
  "FULL_STOP", "DOTS", "UNDEFINED_TOKEN", "STR", "ID", "NUMBER", "LIB",
  "UMINUS", "$accept", "program", "stmt_loop", "stmt", "fun_block", "expr",
  "boolexpr", "$@1", "$@2", "$@3", "$@4", "assignexpr", "lvalue", "id",
  "num_expr", "term", "funcname", "funcprefix", "funcargs", "$@5",
  "funcdef", "lib", "lib_func", "idlist", "$@6", "nonempty_idlist", "$@7",
  "returnstmt", "validate", "ifstmt", "ifprefix", "elseprefix",
  "loopstart", "loopend", "break", "continue", "block", "$@8",
  "stmt_block", "$@9", "whilestart", "whilecond", "whilestmt", "N", "M",
  "forprefix", "forstmt", "elist", "nonempty_elist", "primary", "call",
  "callsuffix", "normcall", "methodcall", "objectdef", "indexed",
  "indexlist", "indexedelem", "member", "num", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-201)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-121)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -201,     9,   229,  -201,  -201,   -15,  -201,   -14,   -22,  -201,
      -9,    -5,   398,   -19,  -201,  -201,  -201,   421,   -11,   -11,
    -201,   315,   352,   -40,  -201,  -201,  -201,  -201,  -201,   447,
    -201,  -201,    21,    13,   384,  -201,     5,  -201,     6,  -201,
    -201,  -201,   277,  -201,  -201,  -201,    14,  -201,  -201,  -201,
    -201,    -8,  -201,    31,  -201,  -201,   398,   398,  -201,  -201,
     398,  -201,  -201,  -201,    34,   -19,   375,   -40,  -201,  -201,
    -201,    46,   141,    -8,   141,  -201,  -201,   398,   167,    24,
      17,    27,    22,   580,    32,    36,   129,    39,    42,  -201,
      50,  -201,  -201,  -201,  -201,   398,   398,   398,   398,  -201,
    -201,  -201,   398,   398,   -19,   -19,  -201,  -201,  -201,   398,
     421,   421,   421,   421,   421,  -201,    49,   398,    67,   398,
    -201,   398,   398,   398,   -19,   398,   510,    47,   468,   398,
    -201,   129,  -201,    54,    53,    59,  -201,   398,  -201,     4,
    -201,  -201,  -201,  -201,    61,   398,  -201,  -201,   398,   398,
     103,   103,   103,   103,   541,    69,  -201,    62,   580,    80,
      80,  -201,  -201,  -201,   -19,  -201,  -201,    71,  -201,   277,
     520,   277,    72,   549,    78,  -201,   580,  -201,  -201,  -201,
     580,    61,  -201,   277,   398,   188,  -201,    77,   398,   580,
     398,   398,   179,   179,  -201,  -201,   398,    81,    82,    88,
    -201,  -201,  -201,  -201,  -201,  -201,  -201,   398,  -201,   570,
       4,    85,   346,   130,    92,    86,  -201,  -201,  -201,  -201,
     489,  -201,  -201,  -201,  -201,   -19,   277,  -201,   107,  -201,
    -201,   117,  -201,   -19,  -201,  -201
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     1,    14,     0,    91,     0,    60,    77,
       0,     0,    20,     0,   131,   132,   130,     0,     0,     0,
      86,     0,    20,     0,   129,    44,   127,    65,     3,     0,
      18,    17,   102,    39,    16,    19,     0,    13,    68,    43,
      10,     8,     0,    11,    12,     6,     0,     7,    94,     9,
      56,   103,   104,    42,   128,   106,    20,    20,    59,    61,
      20,    84,    85,    57,    40,     0,     0,     0,    39,    50,
      42,     0,    53,     0,    54,    90,   122,    20,    99,     0,
       0,     0,   117,     0,    18,    17,    16,    19,     0,    66,
      41,    29,    31,    25,    27,    20,    20,    20,    20,     5,
      52,    55,    20,    20,     0,     0,   108,   110,   111,    20,
       0,     0,     0,     0,     0,    62,     0,    20,    78,    20,
      82,    20,    20,    20,     0,    20,     0,     0,     0,    20,
      40,     0,    41,     0,    88,     0,   114,    20,   115,     0,
      33,    38,    51,    58,   105,    20,    95,    95,    20,    20,
      22,    24,    21,    23,     0,     0,   123,     0,    34,    45,
      46,    47,    48,    49,    72,    90,    64,     0,    81,     0,
       0,     0,     0,     0,     0,   125,    37,    80,    95,    76,
      35,     0,    87,     0,    20,    98,   116,   119,    20,    36,
      20,    20,    26,    28,   124,   112,    20,    69,     0,    88,
      67,    79,    92,    83,    94,   126,   107,    20,    89,     0,
       0,     0,    30,    32,     0,     0,    63,    15,    93,    82,
       0,   121,   118,   109,   113,     0,     0,    96,    73,    70,
      83,     0,    94,     0,    97,    74
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -201,  -201,  -201,   -41,  -201,    -2,   135,  -201,  -201,  -201,
    -201,   140,    -7,     0,    60,   143,  -201,  -201,  -201,  -201,
     -20,  -201,  -201,  -201,  -201,   -70,  -201,  -201,  -201,  -201,
    -201,  -201,   -51,   -54,  -201,  -201,  -201,  -201,    25,  -201,
    -201,  -201,  -201,  -200,  -140,  -201,  -201,   -43,  -201,  -201,
      -3,  -201,  -201,  -201,  -201,  -201,   -31,   165,    26,  -201,
    -201
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    28,   166,    78,    30,   148,   149,   146,
     147,    31,    32,    33,    34,    35,    59,    36,   116,   164,
      37,    38,    39,   198,   215,   229,   231,    40,    60,    41,
      42,   169,   171,   218,    43,    44,    45,    75,   134,   183,
      46,   120,    47,   121,   190,    48,    49,    79,    80,    50,
      51,   106,   107,   108,    52,    81,   186,   187,    53,    54,
      55
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   118,    88,    65,   219,    76,    25,   191,    89,     3,
      63,    72,    74,    64,   127,    73,    73,    68,    68,    68,
      83,    56,    57,    90,    58,    71,   122,    25,   123,    61,
      67,   109,   234,    62,   124,    25,    77,    27,   207,  -120,
      29,   115,   117,    70,    70,    70,    88,   100,   101,   125,
     119,   133,   129,     8,   126,   102,   137,   103,   128,   136,
     155,   139,   138,   104,   105,   130,    68,   132,   145,   140,
      91,   168,    92,   141,   167,   135,   143,    69,   172,   144,
     174,   165,    86,    93,    94,   178,   182,    95,    96,    97,
      98,   181,    70,   150,   151,   152,   153,   188,   196,   184,
     154,   112,   113,   114,   156,   157,   195,   158,   200,   204,
      68,    68,    68,    68,    68,   206,   210,   170,   -71,   216,
     173,   217,   223,   176,   175,   225,   131,   180,   201,   224,
     203,  -121,  -121,  -121,  -121,   185,    70,    70,    70,    70,
      70,    91,   208,   189,   -75,   211,   192,   193,   110,   111,
     112,   113,   114,   214,    93,    94,   233,    84,    95,    96,
      97,    98,    85,   235,   197,    87,   142,    29,   226,    29,
     159,   160,   161,   162,   163,   102,   232,   103,    91,   222,
      92,    29,   209,   104,   105,   230,    82,     0,   212,   213,
     199,    93,    94,     0,     0,    95,    96,    97,    98,    91,
       0,    92,     0,  -121,  -121,   220,  -101,    95,    96,    97,
      98,     0,    93,    94,     0,     0,    95,    96,    97,    98,
       0,     0,     0,     0,    29,   228,     0,  -100,     0,    -2,
       4,     0,     5,   228,     6,     7,     8,     9,    10,    11,
     -20,    12,   -20,    13,    14,    15,    16,     0,     0,    17,
       0,     0,     0,   -20,   -20,    18,    19,   -20,   -20,   -20,
     -20,    20,     0,    21,     0,    22,     0,   -20,     0,     0,
      23,     0,     0,     0,    24,    25,    26,    27,     4,     0,
       5,     0,     6,     7,     8,     9,    10,    11,   -20,    12,
     -20,    13,    14,    15,    16,     0,     0,    17,     0,     0,
       0,   -20,   -20,    18,    19,   -20,   -20,   -20,   -20,    20,
       0,    21,     0,    22,     0,   -20,    76,     0,    23,     0,
       0,     0,    24,    25,    26,    27,   -20,    12,   -20,    13,
      14,    15,    16,     0,     0,    17,     0,     0,     0,   -20,
     -20,    18,    19,   -20,   -20,   -20,   -20,    77,     0,    21,
     -20,    22,     0,     0,   -20,     0,    23,     0,     0,     8,
      24,    25,    26,    27,    12,     0,    13,    14,    15,    16,
      93,    94,    17,     0,    95,    96,    97,    98,    18,    19,
       0,     0,     8,     0,     0,     0,    21,     0,    22,    65,
      14,    15,    16,    23,     0,    17,     0,    24,    25,    26,
      27,    18,    19,   110,   111,   112,   113,   114,     0,    21,
      12,    66,    13,    14,    15,    16,    67,     0,    17,     0,
      24,    25,    26,    27,    18,    19,     0,     0,     0,     0,
       0,     0,    21,     0,    22,    65,    14,    15,    16,    23,
       0,    17,     0,    24,    25,    26,    27,    18,    19,     0,
       0,     0,     0,     0,     0,    21,     0,    66,    91,     0,
      92,     0,    67,     0,     0,     0,    24,    25,    26,    27,
       0,    93,    94,     0,     0,    95,    96,    97,    98,    91,
       0,    92,     0,     0,     0,    99,     0,     0,     0,     0,
       0,     0,    93,    94,     0,     0,    95,    96,    97,    98,
      91,     0,    92,     0,     0,     0,   179,     0,     0,     0,
       0,     0,     0,    93,    94,     0,     0,    95,    96,    97,
      98,    91,     0,    92,     0,     0,     0,   227,     0,     0,
       0,    91,     0,    92,    93,    94,     0,     0,    95,    96,
      97,    98,     0,     0,    93,    94,     0,   177,    95,    96,
      97,    98,    91,     0,    92,     0,     0,   202,     0,     0,
      91,     0,    92,     0,     0,    93,    94,     0,     0,    95,
      96,    97,    98,    93,    94,     0,   194,    95,    96,    97,
      98,    91,     0,    92,   205,     0,     0,     0,     0,     0,
       0,    91,     0,    92,    93,    94,     0,     0,    95,    96,
      97,    98,     0,   221,    93,    94,     0,     0,    95,    96,
      97,    98
};

static const yytype_int16 yycheck[] =
{
       2,    42,    22,    14,   204,     1,    46,   147,    48,     0,
      12,    18,    19,    13,    57,    18,    19,    17,    18,    19,
      22,    36,    36,    23,    46,    36,    34,    46,    36,    38,
      41,    18,   232,    38,    42,    46,    32,    48,   178,    35,
      42,    36,    36,    17,    18,    19,    66,    26,    27,    18,
      36,    71,    18,     7,    56,    34,    39,    36,    60,    35,
     103,    39,    35,    42,    43,    65,    66,    67,    18,    37,
      11,     4,    13,    37,   117,    77,    37,    17,   121,    37,
     123,    32,    22,    24,    25,    38,    33,    28,    29,    30,
      31,    37,    66,    95,    96,    97,    98,    36,    36,    40,
     102,    21,    22,    23,   104,   105,    37,   109,    37,    37,
     110,   111,   112,   113,   114,    37,    39,   119,    37,    37,
     122,    33,    37,   125,   124,    39,    66,   129,   169,    37,
     171,    28,    29,    30,    31,   137,   110,   111,   112,   113,
     114,    11,   183,   145,    37,   188,   148,   149,    19,    20,
      21,    22,    23,   196,    24,    25,    39,    22,    28,    29,
      30,    31,    22,   233,   164,    22,    37,   169,   219,   171,
     110,   111,   112,   113,   114,    34,   230,    36,    11,   210,
      13,   183,   184,    42,    43,   226,    21,    -1,   190,   191,
     165,    24,    25,    -1,    -1,    28,    29,    30,    31,    11,
      -1,    13,    -1,    24,    25,   207,    39,    28,    29,    30,
      31,    -1,    24,    25,    -1,    -1,    28,    29,    30,    31,
      -1,    -1,    -1,    -1,   226,   225,    -1,    39,    -1,     0,
       1,    -1,     3,   233,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    20,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    34,    -1,    36,    -1,    38,    -1,    -1,
      41,    -1,    -1,    -1,    45,    46,    47,    48,     1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    20,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    34,    -1,    36,    -1,    38,     1,    -1,    41,    -1,
      -1,    -1,    45,    46,    47,    48,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    36,    -1,    -1,    39,    -1,    41,    -1,    -1,     7,
      45,    46,    47,    48,    12,    -1,    14,    15,    16,    17,
      24,    25,    20,    -1,    28,    29,    30,    31,    26,    27,
      -1,    -1,     7,    -1,    -1,    -1,    34,    -1,    36,    14,
      15,    16,    17,    41,    -1,    20,    -1,    45,    46,    47,
      48,    26,    27,    19,    20,    21,    22,    23,    -1,    34,
      12,    36,    14,    15,    16,    17,    41,    -1,    20,    -1,
      45,    46,    47,    48,    26,    27,    -1,    -1,    -1,    -1,
      -1,    -1,    34,    -1,    36,    14,    15,    16,    17,    41,
      -1,    20,    -1,    45,    46,    47,    48,    26,    27,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    -1,    36,    11,    -1,
      13,    -1,    41,    -1,    -1,    -1,    45,    46,    47,    48,
      -1,    24,    25,    -1,    -1,    28,    29,    30,    31,    11,
      -1,    13,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    -1,    -1,    28,    29,    30,    31,
      11,    -1,    13,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    -1,    -1,    28,    29,    30,
      31,    11,    -1,    13,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    11,    -1,    13,    24,    25,    -1,    -1,    28,    29,
      30,    31,    -1,    -1,    24,    25,    -1,    37,    28,    29,
      30,    31,    11,    -1,    13,    -1,    -1,    37,    -1,    -1,
      11,    -1,    13,    -1,    -1,    24,    25,    -1,    -1,    28,
      29,    30,    31,    24,    25,    -1,    35,    28,    29,    30,
      31,    11,    -1,    13,    35,    -1,    -1,    -1,    -1,    -1,
      -1,    11,    -1,    13,    24,    25,    -1,    -1,    28,    29,
      30,    31,    -1,    33,    24,    25,    -1,    -1,    28,    29,
      30,    31
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    51,    52,     0,     1,     3,     5,     6,     7,     8,
       9,    10,    12,    14,    15,    16,    17,    20,    26,    27,
      32,    34,    36,    41,    45,    46,    47,    48,    53,    55,
      56,    61,    62,    63,    64,    65,    67,    70,    71,    72,
      77,    79,    80,    84,    85,    86,    90,    92,    95,    96,
      99,   100,   104,   108,   109,   110,    36,    36,    46,    66,
      78,    38,    38,    55,    63,    14,    36,    41,    63,    64,
     108,    36,    62,   100,    62,    87,     1,    32,    55,    97,
      98,   105,   107,    55,    56,    61,    64,    65,    70,    48,
      63,    11,    13,    24,    25,    28,    29,    30,    31,    38,
      26,    27,    34,    36,    42,    43,   101,   102,   103,    18,
      19,    20,    21,    22,    23,    36,    68,    36,    53,    36,
      91,    93,    34,    36,    42,    18,    55,    97,    55,    18,
      63,    64,    63,    70,    88,    55,    35,    39,    35,    39,
      37,    37,    37,    37,    37,    18,    59,    60,    57,    58,
      55,    55,    55,    55,    55,    97,    63,    63,    55,    64,
      64,    64,    64,    64,    69,    32,    54,    97,     4,    81,
      55,    82,    97,    55,    97,    63,    55,    37,    38,    38,
      55,    37,    33,    89,    40,    55,   106,   107,    36,    55,
      94,    94,    55,    55,    35,    37,    36,    63,    73,    88,
      37,    53,    37,    53,    37,    35,    37,    94,    53,    55,
      39,    97,    55,    55,    97,    74,    37,    33,    83,    93,
      55,    33,   106,    37,    37,    39,    82,    38,    63,    75,
      53,    76,    83,    39,    93,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    50,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    57,    56,    58,    56,    59,
      56,    60,    56,    56,    61,    61,    61,    61,    61,    62,
      62,    62,    62,    62,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    65,    65,    66,
      66,    67,    69,    68,    70,    71,    71,    72,    72,    74,
      73,    73,    73,    76,    75,    75,    77,    78,    79,    79,
      80,    81,    82,    83,    84,    85,    87,    86,    89,    88,
      88,    90,    91,    92,    93,    94,    95,    96,    97,    97,
      98,    98,    99,    99,    99,    99,    99,   100,   100,   100,
     101,   101,   102,   103,   104,   104,   105,   105,   106,   106,
     106,   107,   107,   108,   108,   108,   108,   109,   110,   110,
     110,   110,   110
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       0,     3,     3,     3,     3,     0,     4,     0,     4,     0,
       5,     0,     5,     3,     3,     4,     4,     3,     3,     1,
       2,     2,     1,     1,     1,     3,     3,     3,     3,     3,
       2,     3,     2,     2,     2,     2,     1,     2,     3,     1,
       0,     2,     0,     4,     3,     1,     2,     4,     1,     0,
       4,     1,     0,     0,     4,     1,     4,     0,     2,     4,
       4,     1,     0,     0,     2,     2,     0,     4,     0,     3,
       0,     1,     3,     5,     0,     0,     7,     9,     3,     1,
       3,     1,     1,     1,     1,     3,     1,     4,     2,     6,
       1,     1,     3,     5,     3,     3,     3,     1,     3,     1,
       0,     5,     1,     3,     4,     3,     4,     1,     1,     1,
       1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* stmt_loop: stmt_loop stmt  */
#line 158 "src/bison/parser.y"
                           {
            reset_counter_temp();
            // printf("break_list for $1 before if is %d\n", $1->break_list);
            // printf("break_list for $2 before if is %d\n", $2->break_list);
            if ((yyvsp[-1].exprVal)!=NULL && (yyvsp[0].exprVal)!=NULL && !((yyvsp[-1].exprVal)->break_list == 0 && (yyvsp[-1].exprVal)->cont_list == 0 && (yyvsp[0].exprVal)->break_list == 0 && (yyvsp[0].exprVal)->cont_list == 0)) {
                if(!error_found) {
                    (yyval.exprVal)->break_list = mergelist((yyvsp[-1].exprVal)->break_list, (yyvsp[0].exprVal)->break_list);
                    (yyval.exprVal)->cont_list = mergelist((yyvsp[-1].exprVal)->cont_list, (yyvsp[0].exprVal)->cont_list);
                }
            } else {
                (yyval.exprVal) = (yyvsp[0].exprVal);
            }
        }
#line 1449 "src/bison/parser.c"
    break;

  case 4: /* stmt_loop: %empty  */
#line 171 "src/bison/parser.y"
            { (yyval.exprVal) = NULL; }
#line 1455 "src/bison/parser.c"
    break;

  case 5: /* stmt: expr SEMICOLON  */
#line 173 "src/bison/parser.y"
                      {
            if((yyvsp[-1].exprVal)!=NULL&&(yyvsp[-1].exprVal)->type==boolexpr_e){
                if((yyvsp[-1].exprVal)->sym==NULL){
                    (yyvsp[-1].exprVal)->sym=newTemp();
                }
                patchlist((yyvsp[-1].exprVal)->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, (yyvsp[-1].exprVal), 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist((yyvsp[-1].exprVal)->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, (yyvsp[-1].exprVal), 0);
            }
            (yyval.exprVal) = (yyvsp[-1].exprVal);
        }
#line 1473 "src/bison/parser.c"
    break;

  case 6: /* stmt: block  */
#line 186 "src/bison/parser.y"
             {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1479 "src/bison/parser.c"
    break;

  case 7: /* stmt: whilestmt  */
#line 187 "src/bison/parser.y"
                 {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1485 "src/bison/parser.c"
    break;

  case 8: /* stmt: ifstmt  */
#line 188 "src/bison/parser.y"
              {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1491 "src/bison/parser.c"
    break;

  case 9: /* stmt: forstmt  */
#line 189 "src/bison/parser.y"
               {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1497 "src/bison/parser.c"
    break;

  case 10: /* stmt: returnstmt  */
#line 190 "src/bison/parser.y"
                  {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1503 "src/bison/parser.c"
    break;

  case 11: /* stmt: break  */
#line 191 "src/bison/parser.y"
             {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1509 "src/bison/parser.c"
    break;

  case 12: /* stmt: continue  */
#line 192 "src/bison/parser.y"
                {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1515 "src/bison/parser.c"
    break;

  case 13: /* stmt: funcdef  */
#line 193 "src/bison/parser.y"
               {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1521 "src/bison/parser.c"
    break;

  case 14: /* stmt: error  */
#line 194 "src/bison/parser.y"
             {printf("\033[0;33mError at line %d\033[0m\n", yylineno); exit(1);}
#line 1527 "src/bison/parser.c"
    break;

  case 15: /* fun_block: LEFT_BRACE stmt_block RIGHT_BRACE  */
#line 198 "src/bison/parser.y"
                                              { (yyval.exprVal) = (yyvsp[-1].exprVal); }
#line 1533 "src/bison/parser.c"
    break;

  case 16: /* expr: num_expr  */
#line 202 "src/bison/parser.y"
                 {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1539 "src/bison/parser.c"
    break;

  case 17: /* expr: assignexpr  */
#line 203 "src/bison/parser.y"
                   {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1545 "src/bison/parser.c"
    break;

  case 18: /* expr: boolexpr  */
#line 204 "src/bison/parser.y"
                 {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1551 "src/bison/parser.c"
    break;

  case 19: /* expr: term  */
#line 205 "src/bison/parser.y"
             {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1557 "src/bison/parser.c"
    break;

  case 20: /* boolexpr: %empty  */
#line 208 "src/bison/parser.y"
           {(yyval.exprVal)=NULL;}
#line 1563 "src/bison/parser.c"
    break;

  case 21: /* boolexpr: expr GREATER_EQUAL expr  */
#line 209 "src/bison/parser.y"
                          {
                Check_type((yyvsp[-2].exprVal)); Check_type((yyvsp[0].exprVal)); 
                (yyval.exprVal)=new_Expr(boolexpr_e);
                emit(if_greatereq_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());       
                (yyval.exprVal)->true_list = newlist(nextQuadLabel()-2);     
                (yyval.exprVal)->false_list = newlist(nextQuadLabel()-1);     
            }
#line 1576 "src/bison/parser.c"
    break;

  case 22: /* boolexpr: expr GREATER_THAN expr  */
#line 217 "src/bison/parser.y"
                         {
                Check_type((yyvsp[-2].exprVal)); Check_type((yyvsp[0].exprVal)); 
                (yyval.exprVal)=new_Expr(boolexpr_e);
                emit(if_greater_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());       
                (yyval.exprVal)->true_list = newlist(nextQuadLabel()-2);     
                (yyval.exprVal)->false_list = newlist(nextQuadLabel()-1);                 
            }
#line 1589 "src/bison/parser.c"
    break;

  case 23: /* boolexpr: expr LESS_EQUAL expr  */
#line 225 "src/bison/parser.y"
                       {
                Check_type((yyvsp[-2].exprVal)); Check_type((yyvsp[0].exprVal)); 
                (yyval.exprVal)=new_Expr(boolexpr_e);
                emit(if_lesseq_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());       
                (yyval.exprVal)->true_list = newlist(nextQuadLabel()-2);     
                (yyval.exprVal)->false_list = newlist(nextQuadLabel()-1);                 
            }
#line 1602 "src/bison/parser.c"
    break;

  case 24: /* boolexpr: expr LESS_THAN expr  */
#line 233 "src/bison/parser.y"
                      {
                Check_type((yyvsp[-2].exprVal)); Check_type((yyvsp[0].exprVal)); 
                (yyval.exprVal)=new_Expr(boolexpr_e);
                emit(if_less_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());       
                (yyval.exprVal)->true_list = newlist(nextQuadLabel()-2);     
                (yyval.exprVal)->false_list = newlist(nextQuadLabel()-1);             
            }
#line 1615 "src/bison/parser.c"
    break;

  case 25: /* $@1: %empty  */
#line 241 "src/bison/parser.y"
                   {patchEQNEQOp1((yyvsp[-1].exprVal));}
#line 1621 "src/bison/parser.c"
    break;

  case 26: /* boolexpr: expr EQUAL_EQUAL $@1 expr  */
#line 241 "src/bison/parser.y"
                                             {

                if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                    if((yyvsp[0].exprVal)->sym==NULL){
                        (yyvsp[0].exprVal)->sym=newTemp();
                    }
                    patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
                }

                (yyval.exprVal)=new_Expr(boolexpr_e);
                emit(if_eq_i, (yyvsp[-3].exprVal), (yyvsp[0].exprVal), NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
                (yyval.exprVal)->true_list = newlist(nextQuadLabel()-2);
                (yyval.exprVal)->false_list = newlist(nextQuadLabel()-1);         
            }
#line 1645 "src/bison/parser.c"
    break;

  case 27: /* $@2: %empty  */
#line 260 "src/bison/parser.y"
                 {patchEQNEQOp1((yyvsp[-1].exprVal));}
#line 1651 "src/bison/parser.c"
    break;

  case 28: /* boolexpr: expr NOT_EQUAL $@2 expr  */
#line 260 "src/bison/parser.y"
                                           { 

                if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                    if((yyvsp[0].exprVal)->sym==NULL){
                        (yyvsp[0].exprVal)->sym=newTemp();
                    }
                    patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
                }

                (yyval.exprVal)=new_Expr(boolexpr_e);
                emit(if_noteq_i, (yyvsp[-3].exprVal), (yyvsp[0].exprVal), NULL, nextQuadLabel());
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
                (yyval.exprVal)->true_list = newlist(nextQuadLabel()-2);
                (yyval.exprVal)->false_list = newlist(nextQuadLabel()-1);
            }
#line 1675 "src/bison/parser.c"
    break;

  case 29: /* $@3: %empty  */
#line 279 "src/bison/parser.y"
           {patchANDOp1((yyvsp[-1].exprVal));}
#line 1681 "src/bison/parser.c"
    break;

  case 30: /* boolexpr: expr AND $@3 M expr  */
#line 279 "src/bison/parser.y"
                                     {
                (yyval.exprVal)=new_Expr(boolexpr_e);
                
                if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type!=boolexpr_e){
                    emit(if_eq_i, (yyvsp[0].exprVal), new_constbool(true), NULL,0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
                    (yyvsp[0].exprVal)->true_list = newlist(nextQuadLabel()-2);
                    (yyvsp[0].exprVal)->false_list = newlist(nextQuadLabel()-1);
                }

                if((yyvsp[-4].exprVal)!=NULL&&(yyvsp[-4].exprVal)->type==boolexpr_e){
                    patchlist((yyvsp[-4].exprVal)->true_list, (yyvsp[-1].intVal));
                }

                (yyval.exprVal)->true_list = (yyvsp[0].exprVal)->true_list;
                (yyval.exprVal)->false_list = mergelist((yyvsp[-4].exprVal)->false_list, (yyvsp[0].exprVal)->false_list);
            }
#line 1703 "src/bison/parser.c"
    break;

  case 31: /* $@4: %empty  */
#line 296 "src/bison/parser.y"
          {patchOROp1((yyvsp[-1].exprVal));}
#line 1709 "src/bison/parser.c"
    break;

  case 32: /* boolexpr: expr OR $@4 M expr  */
#line 296 "src/bison/parser.y"
                                   {
                (yyval.exprVal)=new_Expr(boolexpr_e);
                
                if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type!=boolexpr_e){
                    emit(if_eq_i, (yyvsp[0].exprVal), new_constbool(true), NULL,0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
                    (yyvsp[0].exprVal)->true_list = newlist(nextQuadLabel()-2);
                    (yyvsp[0].exprVal)->false_list = newlist(nextQuadLabel()-1);
                }

                if((yyvsp[-4].exprVal)!=NULL&&(yyvsp[-4].exprVal)->type==boolexpr_e){
                    patchlist((yyvsp[-4].exprVal)->false_list, (yyvsp[-1].intVal));
                }

                // printf("printing true list: \n");printlist($5->true_list);
                // printf("printing false list: \n");printlist($5->false_list);

                (yyval.exprVal)->true_list = mergelist((yyvsp[-4].exprVal)->true_list, (yyvsp[0].exprVal)->true_list);
                (yyval.exprVal)->false_list = (yyvsp[0].exprVal)->false_list;

                // printf("printing true list: \n");printlist($$->true_list);
                // printf("printing false list: \n");printlist($$->false_list);
            }
#line 1737 "src/bison/parser.c"
    break;

  case 33: /* boolexpr: LEFT_PARENTHESIS boolexpr RIGHT_PARENTHESIS  */
#line 319 "src/bison/parser.y"
                                              {(yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1743 "src/bison/parser.c"
    break;

  case 34: /* assignexpr: id EQUAL expr  */
#line 322 "src/bison/parser.y"
                           {
                if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                    if((yyvsp[0].exprVal)->sym==NULL){
                        (yyvsp[0].exprVal)->sym=newTemp();
                    }
                    patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
                }
                            
                emit(assign_i, (yyvsp[0].exprVal), NULL, (yyvsp[-2].exprVal), 0); //HERE
                (yyval.exprVal)=new_Expr(assignexpr_e);
                (yyval.exprVal)->sym = newTemp(); 
                (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
                if((yyvsp[-2].exprVal)->sym==NULL){
                    (yyvsp[-2].exprVal)->sym = new_SymbolTableVariable((yyvsp[-2].exprVal)->strConst);
                    SymbolTable_insert(symbol_table, (yyvsp[-2].exprVal)->sym , true);
                }
                if((yyvsp[0].exprVal)->sym)
                    (yyvsp[-2].exprVal)->sym->isTable = (yyvsp[0].exprVal)->sym->isTable;
                emit(assign_i, (yyvsp[-2].exprVal), NULL, (yyval.exprVal), 0);
            }
#line 1772 "src/bison/parser.c"
    break;

  case 35: /* assignexpr: LOCAL id EQUAL expr  */
#line 346 "src/bison/parser.y"
                                 {
                if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                    if((yyvsp[0].exprVal)->sym==NULL){
                        (yyvsp[0].exprVal)->sym=newTemp();
                    }
                    patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
                }

                emit(assign_i, (yyvsp[0].exprVal), NULL, (yyvsp[-2].exprVal), 0);
                (yyval.exprVal)=new_Expr(assignexpr_e);
                (yyval.exprVal)->sym = newTemp(); 
                (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
                if((yyvsp[-2].exprVal)->sym==NULL){
                    (yyvsp[-2].exprVal)->sym = new_SymbolTableVariable((yyvsp[-2].exprVal)->strConst);
                    SymbolTable_insert_local(symbol_table, (yyvsp[-2].exprVal)->sym, true);
                }
                if((yyvsp[0].exprVal)->sym)
                    (yyvsp[-2].exprVal)->sym->isTable = (yyvsp[0].exprVal)->sym->isTable;
                emit(assign_i, (yyvsp[-2].exprVal), NULL, (yyval.exprVal), 0);
            }
#line 1801 "src/bison/parser.c"
    break;

  case 36: /* assignexpr: DOUBLE_COLON id EQUAL expr  */
#line 370 "src/bison/parser.y"
                                        {
                if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                    if((yyvsp[0].exprVal)->sym==NULL){
                        (yyvsp[0].exprVal)->sym=newTemp();
                    }
                    patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
                }

                emit(assign_i, (yyvsp[0].exprVal), NULL, (yyvsp[-2].exprVal), 0);
                (yyval.exprVal)=new_Expr(assignexpr_e);
                (yyval.exprVal)->sym = newTemp(); 
                (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
                SymbolTable_require_global(symbol_table, (yyvsp[-2].exprVal)->strConst);
                emit(assign_i, (yyvsp[-2].exprVal), NULL, (yyval.exprVal), 0);
                if((yyvsp[0].exprVal)->sym)
                    (yyvsp[-2].exprVal)->sym->isTable = (yyvsp[0].exprVal)->sym->isTable;
            }
#line 1827 "src/bison/parser.c"
    break;

  case 37: /* assignexpr: member EQUAL expr  */
#line 391 "src/bison/parser.y"
                               {
                    
                    if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                        if((yyvsp[0].exprVal)->sym==NULL){
                            (yyvsp[0].exprVal)->sym=newTemp();
                        }
                        patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                        emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                        emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                        patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                        emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
                    }

                    (yyvsp[-2].exprVal) = fixAssignedMember((yyvsp[-2].exprVal), (yyvsp[0].exprVal));
                    if((yyvsp[0].exprVal)->sym)
                        (yyvsp[-2].exprVal)->sym->isTable = (yyvsp[0].exprVal)->sym->isTable;
                    (yyval.exprVal) = emitIfTableItem((yyvsp[-2].exprVal)->lastAssignedQuad->arg1);
            }
#line 1850 "src/bison/parser.c"
    break;

  case 38: /* assignexpr: LEFT_PARENTHESIS assignexpr RIGHT_PARENTHESIS  */
#line 409 "src/bison/parser.y"
                                                            {(yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1856 "src/bison/parser.c"
    break;

  case 39: /* lvalue: id  */
#line 412 "src/bison/parser.y"
                                {(yyval.exprVal) = (yyvsp[0].exprVal); if((yyvsp[0].exprVal)->sym==NULL){(yyvsp[0].exprVal)->sym =  new_SymbolTableVariable((yyval.exprVal)->strConst); SymbolTable_insert(symbol_table, (yyvsp[0].exprVal)->sym, false);}}
#line 1862 "src/bison/parser.c"
    break;

  case 40: /* lvalue: LOCAL id  */
#line 413 "src/bison/parser.y"
                                {(yyval.exprVal) = (yyvsp[0].exprVal); if((yyvsp[0].exprVal)->sym==NULL){(yyvsp[0].exprVal)->sym = new_SymbolTableVariable((yyval.exprVal)->strConst); SymbolTable_insert_local(symbol_table, (yyvsp[0].exprVal)->sym, false);}}
#line 1868 "src/bison/parser.c"
    break;

  case 41: /* lvalue: DOUBLE_COLON id  */
#line 414 "src/bison/parser.y"
                                {(yyval.exprVal) = (yyvsp[0].exprVal); SymbolTable_require_global(symbol_table, (yyval.exprVal)->strConst);}
#line 1874 "src/bison/parser.c"
    break;

  case 42: /* lvalue: member  */
#line 415 "src/bison/parser.y"
                                {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 1880 "src/bison/parser.c"
    break;

  case 43: /* lvalue: lib_func  */
#line 416 "src/bison/parser.y"
                                {(yyval.exprVal)=(yyvsp[0].exprVal);}
#line 1886 "src/bison/parser.c"
    break;

  case 44: /* id: ID  */
#line 419 "src/bison/parser.y"
        {(yyval.exprVal)=new_var((yyvsp[0].stringVal)); (yyval.exprVal)->sym = SymbolTable_lookup_chill(symbol_table, (yyvsp[0].stringVal)); if((yyval.exprVal)->sym!=NULL && (yyval.exprVal)->sym->type==TYPE_USERFUNC){(yyval.exprVal)->type = programfunc_e; printf("It is of type %d\n", (yyval.exprVal)->sym->type);} if((yyval.exprVal)->sym==NULL){(yyval.exprVal)->sym = new_SymbolTableVariable((yyvsp[0].stringVal)); SymbolTable_insert(symbol_table, (yyval.exprVal)->sym, false);}}
#line 1892 "src/bison/parser.c"
    break;

  case 45: /* num_expr: num_expr PLUS num_expr  */
#line 422 "src/bison/parser.y"
                                 {
        Check_type((yyvsp[-2].exprVal)); Check_type((yyvsp[0].exprVal)); 
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        emit(add_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), 0);
    }
#line 1904 "src/bison/parser.c"
    break;

  case 46: /* num_expr: num_expr MINUS num_expr  */
#line 429 "src/bison/parser.y"
                              {
        Check_type((yyvsp[-2].exprVal)); Check_type((yyvsp[0].exprVal));
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        emit(sub_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), 0);
    }
#line 1916 "src/bison/parser.c"
    break;

  case 47: /* num_expr: num_expr MULTIPLY num_expr  */
#line 436 "src/bison/parser.y"
                                 {
        Check_type((yyvsp[-2].exprVal)); Check_type((yyvsp[0].exprVal));
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        emit(mul_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), 0);
    }
#line 1928 "src/bison/parser.c"
    break;

  case 48: /* num_expr: num_expr DIV num_expr  */
#line 443 "src/bison/parser.y"
                            {
        Check_type((yyvsp[-2].exprVal)); Check_type((yyvsp[0].exprVal));
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        emit(div_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), 0);
    }
#line 1940 "src/bison/parser.c"
    break;

  case 49: /* num_expr: num_expr MODULO num_expr  */
#line 450 "src/bison/parser.y"
                               {
        Check_type((yyvsp[-2].exprVal)); Check_type((yyvsp[0].exprVal));
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        emit(mod_i, (yyvsp[-2].exprVal), (yyvsp[0].exprVal), (yyval.exprVal), 0);
    }
#line 1952 "src/bison/parser.c"
    break;

  case 50: /* num_expr: MINUS num_expr  */
#line 457 "src/bison/parser.y"
                                  {
        Check_type((yyvsp[0].exprVal));
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        emit(uminus_i, (yyvsp[0].exprVal), 0, (yyval.exprVal), 0);
    }
#line 1964 "src/bison/parser.c"
    break;

  case 51: /* num_expr: LEFT_PARENTHESIS num_expr RIGHT_PARENTHESIS  */
#line 464 "src/bison/parser.y"
                                                  {(yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 1970 "src/bison/parser.c"
    break;

  case 52: /* num_expr: lvalue PLUS_PLUS  */
#line 465 "src/bison/parser.y"
                       {
        Check_type((yyvsp[-1].exprVal));
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        expr* one = new_Expr(constnum_e);
        one->numConst = 1;
        emit(assign_i, (yyvsp[-1].exprVal), NULL, (yyval.exprVal), 0);
        emit(add_i, (yyvsp[-1].exprVal), new_constnum(1), (yyvsp[-1].exprVal), 0);
    }
#line 1985 "src/bison/parser.c"
    break;

  case 53: /* num_expr: PLUS_PLUS lvalue  */
#line 475 "src/bison/parser.y"
                        {
        Check_type((yyvsp[0].exprVal));
        emit(add_i, (yyvsp[0].exprVal), new_constnum(1), (yyvsp[0].exprVal), 0);
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        emit(assign_i, (yyvsp[0].exprVal), NULL, (yyval.exprVal), 0);
    }
#line 1998 "src/bison/parser.c"
    break;

  case 54: /* num_expr: MINUS_MINUS lvalue  */
#line 483 "src/bison/parser.y"
                          {
        Check_type((yyvsp[0].exprVal));
        emit(sub_i, (yyvsp[0].exprVal), new_constnum(1), (yyvsp[0].exprVal), 0);
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        emit(assign_i, (yyvsp[0].exprVal), NULL, (yyval.exprVal), 0);
    }
#line 2011 "src/bison/parser.c"
    break;

  case 55: /* num_expr: lvalue MINUS_MINUS  */
#line 491 "src/bison/parser.y"
                          {
        Check_type((yyvsp[-1].exprVal));
        (yyval.exprVal)=new_Expr(arithexpr_e);
        (yyval.exprVal)->sym = newTemp();
        (yyval.exprVal)->strConst = (yyval.exprVal)->sym->value.varVal->name;
        expr* one = new_Expr(constnum_e);
        one->numConst = 1;
        emit(assign_i, (yyvsp[-1].exprVal), NULL, (yyval.exprVal), 0);
        emit(sub_i, (yyvsp[-1].exprVal), new_constnum(1), (yyvsp[-1].exprVal), 0);
    }
#line 2026 "src/bison/parser.c"
    break;

  case 56: /* num_expr: primary  */
#line 501 "src/bison/parser.y"
              {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 2032 "src/bison/parser.c"
    break;

  case 57: /* term: NOT expr  */
#line 504 "src/bison/parser.y"
                {
        (yyval.exprVal) = new_Expr(boolexpr_e);
        (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;

        if((yyvsp[0].exprVal)->type!=boolexpr_e){
            emit(if_eq_i, new_constbool(true), (yyvsp[0].exprVal), NULL, nextQuadLabel());
            emit(jump_i, NULL, NULL, NULL, nextQuadLabel());
            (yyval.exprVal)->true_list = newlist(nextQuadLabel()-1);
            (yyval.exprVal)->false_list = newlist(nextQuadLabel()-2);
        }else{
            (yyval.exprVal)->true_list = (yyvsp[0].exprVal)->false_list;
            (yyval.exprVal)->false_list = (yyvsp[0].exprVal)->true_list;
        }
}
#line 2051 "src/bison/parser.c"
    break;

  case 58: /* term: LEFT_PARENTHESIS term RIGHT_PARENTHESIS  */
#line 518 "src/bison/parser.y"
                                               { (yyval.exprVal) = (yyvsp[-1].exprVal);}
#line 2057 "src/bison/parser.c"
    break;

  case 59: /* funcname: ID  */
#line 521 "src/bison/parser.y"
              {(yyval.stringVal) = (yyvsp[0].stringVal);}
#line 2063 "src/bison/parser.c"
    break;

  case 60: /* funcname: %empty  */
#line 522 "src/bison/parser.y"
           {(yyval.stringVal) = newAnonymousFunction();}
#line 2069 "src/bison/parser.c"
    break;

  case 61: /* funcprefix: FUNCTION funcname  */
#line 525 "src/bison/parser.y"
                               {
    //printf("PREFIX\n");
    Stack_push(pfunc_jumpstack, 0);
    SymbolTableEntry_t* func = new_SymbolTableFunction((yyvsp[0].stringVal));
    SymbolTable_insert(symbol_table, func, true);
	Stack_push(local_args_stack,get_total_local_vars());
	resetfunctionlocalsoffset();
    (yyval.exprVal)=new_Expr(programfunc_e);
    (yyval.exprVal)->sym = func;
    (yyval.exprVal)->totalLocals=0;
    emit(funcstart_i, (yyval.exprVal), NULL, NULL, 0);
	Stack_push(loop_count_stack,loop_counter); 
	loop_counter=0;
	Stack_push(in_func_block_stack,in_func_block);
	in_func_block=1;
}
#line 2090 "src/bison/parser.c"
    break;

  case 62: /* $@5: %empty  */
#line 542 "src/bison/parser.y"
                            {scope_increase();enter_scope_offset(SCOPE_FUNCTIONAL);}
#line 2096 "src/bison/parser.c"
    break;

  case 64: /* funcdef: funcprefix funcargs fun_block  */
#line 544 "src/bison/parser.y"
                                        {
                Symtable_invalidate_scope(symbol_table); 
				scope_decrease(); exit_scope_offset();
				loop_counter= Stack_pop(loop_count_stack);
				in_func_block= Stack_pop(in_func_block_stack);
                (yyval.exprVal) = (yyvsp[-2].exprVal);
				(yyval.exprVal)->totalLocals = get_total_local_vars();
                //printf("PARSER LOCO:%d \n",$$->totalLocals);
				set_local_var(Stack_pop(local_args_stack));
                emit(funcend_i, (yyval.exprVal), NULL, NULL, 0);
                Stack_pop(pfunc_jumpstack);
            }
#line 2113 "src/bison/parser.c"
    break;

  case 65: /* lib: LIB  */
#line 558 "src/bison/parser.y"
         {(yyval.exprVal)=new_call((yyvsp[0].stringVal));(yyval.exprVal)->sym = SymbolTable_lookup_global(symbol_table, (yyvsp[0].stringVal));}
#line 2119 "src/bison/parser.c"
    break;

  case 66: /* lib: DOUBLE_COLON LIB  */
#line 559 "src/bison/parser.y"
                      {(yyval.exprVal)=new_call((yyvsp[0].stringVal));(yyval.exprVal)->sym = SymbolTable_lookup_global(symbol_table, (yyvsp[0].stringVal));}
#line 2125 "src/bison/parser.c"
    break;

  case 67: /* lib_func: lib LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 561 "src/bison/parser.y"
                                                        {
                (yyvsp[-3].exprVal)->next = (yyvsp[-1].exprVal);
                (yyval.exprVal) = make_call((yyvsp[-3].exprVal), (yyvsp[-1].exprVal));
                set_formal_offset(Stack_pop(formal_args_stack));
                (yyvsp[-3].exprVal)->type = libraryfunc_e;
                // $$->type = callfunc_e;
}
#line 2137 "src/bison/parser.c"
    break;

  case 68: /* lib_func: lib  */
#line 568 "src/bison/parser.y"
               {
            (yyval.exprVal)=new_Expr(libraryfunc_e);
            (yyval.exprVal)->sym = (yyvsp[0].exprVal)->sym;
            (yyval.exprVal)->strConst = (yyvsp[0].exprVal)->strConst;
            }
#line 2147 "src/bison/parser.c"
    break;

  case 69: /* $@6: %empty  */
#line 575 "src/bison/parser.y"
            {if((yyvsp[0].exprVal)->sym&&isOfSameScope((yyvsp[0].exprVal)->sym)){decrease_functionlocalsoffset();}; SymbolTable_delete(symbol_table, (yyvsp[0].exprVal)->strConst); (yyvsp[0].exprVal)->sym = new_SymbolTableFormalVariable((yyvsp[0].exprVal)->strConst); SymbolTable_insert_formal(symbol_table, (yyvsp[0].exprVal)->sym);}
#line 2153 "src/bison/parser.c"
    break;

  case 71: /* idlist: id  */
#line 576 "src/bison/parser.y"
             {if((yyvsp[0].exprVal)->sym&&isOfSameScope((yyvsp[0].exprVal)->sym)){decrease_functionlocalsoffset();}; SymbolTable_delete(symbol_table, (yyvsp[0].exprVal)->strConst); (yyvsp[0].exprVal)->sym = new_SymbolTableFormalVariable((yyvsp[0].exprVal)->strConst); SymbolTable_insert_formal(symbol_table, (yyvsp[0].exprVal)->sym); }
#line 2159 "src/bison/parser.c"
    break;

  case 73: /* $@7: %empty  */
#line 579 "src/bison/parser.y"
                     {if((yyvsp[0].exprVal)->sym&&isOfSameScope((yyvsp[0].exprVal)->sym)){decrease_functionlocalsoffset();}; SymbolTable_delete(symbol_table, (yyvsp[0].exprVal)->strConst); (yyvsp[0].exprVal)->sym = new_SymbolTableFormalVariable((yyvsp[0].exprVal)->strConst); SymbolTable_insert_formal(symbol_table, (yyvsp[0].exprVal)->sym); }
#line 2165 "src/bison/parser.c"
    break;

  case 75: /* nonempty_idlist: id  */
#line 580 "src/bison/parser.y"
                     {if((yyvsp[0].exprVal)->sym&&isOfSameScope((yyvsp[0].exprVal)->sym)){decrease_functionlocalsoffset();}; SymbolTable_delete(symbol_table, (yyvsp[0].exprVal)->strConst); (yyvsp[0].exprVal)->sym = new_SymbolTableFormalVariable((yyvsp[0].exprVal)->strConst); SymbolTable_insert_formal(symbol_table, (yyvsp[0].exprVal)->sym); }
#line 2171 "src/bison/parser.c"
    break;

  case 76: /* returnstmt: RETURN validate expr SEMICOLON  */
#line 583 "src/bison/parser.y"
                                            {
            (yyval.exprVal) = new_Expr(return_e);
            if((yyvsp[-1].exprVal)!=NULL){
                if((yyvsp[-1].exprVal)->type==boolexpr_e){
                    if((yyvsp[-1].exprVal)->sym==NULL){
                        (yyvsp[-1].exprVal)->sym=newTemp();
                    }
                    patchlist((yyvsp[-1].exprVal)->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, (yyvsp[-1].exprVal), 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist((yyvsp[-1].exprVal)->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, (yyvsp[-1].exprVal), 0);
                }
                (yyval.exprVal)->strConst = (yyvsp[-1].exprVal)->strConst;
                (yyval.exprVal)->numConst = (yyvsp[-1].exprVal)->numConst;
                (yyval.exprVal)->boolConst = (yyvsp[-1].exprVal)->boolConst;
                (yyval.exprVal)->sym = (yyvsp[-1].exprVal)->sym;
                emit(ret_i, (yyvsp[-1].exprVal), NULL, NULL, 0);
            }else{
                emit(ret_i, NULL, NULL, NULL, 0);
            }
            
        }
#line 2199 "src/bison/parser.c"
    break;

  case 77: /* validate: %empty  */
#line 608 "src/bison/parser.y"
                    {if(!return_in_func_block_counter()){PRINT_PURPLE("Return not in a function at line %d\n", yylineno);}}
#line 2205 "src/bison/parser.c"
    break;

  case 78: /* ifstmt: ifprefix stmt  */
#line 610 "src/bison/parser.y"
                       {
            reset_counter_temp();
            patchLabel((yyvsp[-1].intVal), nextQuadLabel());
            (yyval.exprVal) = (yyvsp[0].exprVal); //Retrieve break/continue list
       }
#line 2215 "src/bison/parser.c"
    break;

  case 79: /* ifstmt: ifprefix stmt elseprefix stmt  */
#line 615 "src/bison/parser.y"
                                        {
            reset_counter_temp();
            patchLabel((yyvsp[-3].intVal), (yyvsp[-1].intVal) + 1);
            patchLabel((yyvsp[-1].intVal), nextQuadLabel());

            //Retrieve the full break/continue list either as is
            //or through merging if necessary
            (yyval.exprVal) = (yyvsp[-2].exprVal);
            if((yyval.exprVal)==NULL){
                (yyval.exprVal) = (yyvsp[0].exprVal);
            }

            if((yyvsp[-2].exprVal)!=NULL && (yyvsp[0].exprVal)!=NULL){
                (yyval.exprVal) = (yyvsp[-2].exprVal);
                (yyval.exprVal)->break_list = mergelist((yyvsp[-2].exprVal)->break_list, (yyvsp[0].exprVal)->break_list);
                (yyval.exprVal)->cont_list = mergelist((yyvsp[-2].exprVal)->cont_list, (yyvsp[0].exprVal)->cont_list);
            }
       }
#line 2238 "src/bison/parser.c"
    break;

  case 80: /* ifprefix: IF LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 635 "src/bison/parser.y"
                                                      {
            
                if((yyvsp[-1].exprVal)!=NULL&&(yyvsp[-1].exprVal)->type==boolexpr_e){
                    if((yyvsp[-1].exprVal)->sym==NULL){
                        (yyvsp[-1].exprVal)->sym=newTemp();
                    }
                    patchlist((yyvsp[-1].exprVal)->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, (yyvsp[-1].exprVal), 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist((yyvsp[-1].exprVal)->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, (yyvsp[-1].exprVal), 0);
                }

            emit(
                if_eq_i,  (yyvsp[-1].exprVal),
                new_constbool(true), NULL,
                nextQuadLabel() + 2
            );
            (yyval.intVal) = nextQuadLabel();
            emit(jump_i, NULL, NULL, NULL, 0);
        }
#line 2264 "src/bison/parser.c"
    break;

  case 81: /* elseprefix: ELSE  */
#line 657 "src/bison/parser.y"
                  {
            (yyval.intVal) = nextQuadLabel();
            emit(jump_i, NULL, NULL, NULL, 0);
        }
#line 2273 "src/bison/parser.c"
    break;

  case 82: /* loopstart: %empty  */
#line 663 "src/bison/parser.y"
                      {increase_loop_counter();}
#line 2279 "src/bison/parser.c"
    break;

  case 83: /* loopend: %empty  */
#line 666 "src/bison/parser.y"
                     {decrease_loop_counter();}
#line 2285 "src/bison/parser.c"
    break;

  case 84: /* break: BREAK SEMICOLON  */
#line 669 "src/bison/parser.y"
                        {
            if(!return_loop_counter()){PRINT_PURPLE("Break not in a loop at line %d\n", yylineno); return 0;}
            (yyval.exprVal) = new_Expr(loop_e);
            make_stmt((yyval.exprVal));
            (yyval.exprVal)->break_list = newlist(nextQuadLabel());
            emit(jump_i, NULL ,NULL, 0, 0); 
        }
#line 2297 "src/bison/parser.c"
    break;

  case 85: /* continue: CONTINUE SEMICOLON  */
#line 678 "src/bison/parser.y"
                             { 
            if(return_loop_counter()==0){PRINT_PURPLE("Continue not in a loop at line %d\n", yylineno);}
            (yyval.exprVal) = new_Expr(loop_e);
            make_stmt((yyval.exprVal));
            (yyval.exprVal)->cont_list = newlist(nextQuadLabel());
            emit(jump_i, NULL ,NULL, 0, 0); 
        }
#line 2309 "src/bison/parser.c"
    break;

  case 86: /* $@8: %empty  */
#line 687 "src/bison/parser.y"
                   {scope_increase(); enter_scope_offset(SCOPE_BLOCK);}
#line 2315 "src/bison/parser.c"
    break;

  case 87: /* block: LEFT_BRACE $@8 stmt_block RIGHT_BRACE  */
#line 687 "src/bison/parser.y"
                                                                                               {Symtable_invalidate_scope(symbol_table);  scope_decrease(); exit_scope_offset();
            (yyval.exprVal) = (yyvsp[-1].exprVal);
        }
#line 2323 "src/bison/parser.c"
    break;

  case 88: /* $@9: %empty  */
#line 693 "src/bison/parser.y"
                        {reset_counter_temp();}
#line 2329 "src/bison/parser.c"
    break;

  case 89: /* stmt_block: stmt_block $@9 stmt  */
#line 693 "src/bison/parser.y"
                                                     {
                if ((yyvsp[-2].exprVal)!=NULL && (yyvsp[0].exprVal)!=NULL && !((yyvsp[-2].exprVal)->break_list == 0 && (yyvsp[-2].exprVal)->cont_list == 0 && (yyvsp[0].exprVal)->break_list == 0 && (yyvsp[0].exprVal)->cont_list == 0)) {
                    if(!error_found) {
                        (yyval.exprVal)->break_list = mergelist((yyvsp[-2].exprVal)->break_list, (yyvsp[0].exprVal)->break_list);
                        (yyval.exprVal)->cont_list = mergelist((yyvsp[-2].exprVal)->cont_list, (yyvsp[0].exprVal)->cont_list);
                    }
                } else {
                    (yyval.exprVal) = (yyvsp[0].exprVal);
                }
            }
#line 2344 "src/bison/parser.c"
    break;

  case 90: /* stmt_block: %empty  */
#line 703 "src/bison/parser.y"
              {(yyval.exprVal) = NULL;}
#line 2350 "src/bison/parser.c"
    break;

  case 91: /* whilestart: WHILE  */
#line 707 "src/bison/parser.y"
                  {

            (yyval.intVal) = nextQuadLabel();
}
#line 2359 "src/bison/parser.c"
    break;

  case 92: /* whilecond: LEFT_PARENTHESIS expr RIGHT_PARENTHESIS  */
#line 712 "src/bison/parser.y"
                                                   {
                if((yyvsp[-1].exprVal)!=NULL&&(yyvsp[-1].exprVal)->type==boolexpr_e){
                    if((yyvsp[-1].exprVal)->sym==NULL){
                        (yyvsp[-1].exprVal)->sym=newTemp();
                    }
                    patchlist((yyvsp[-1].exprVal)->true_list, nextQuadLabel());
                    emit(assign_i, new_constbool(true), NULL, (yyvsp[-1].exprVal), 0);
                    emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                    patchlist((yyvsp[-1].exprVal)->false_list, nextQuadLabel());
                    emit(assign_i, new_constbool(false), NULL, (yyvsp[-1].exprVal), 0);
                }

            emit(if_eq_i, (yyvsp[-1].exprVal), new_constbool(1), NULL, nextQuadLabel()+2);
            (yyval.intVal) = nextQuadLabel();
            emit(jump_i, NULL, NULL, 0, 0);
}
#line 2380 "src/bison/parser.c"
    break;

  case 93: /* whilestmt: whilestart whilecond loopstart stmt loopend  */
#line 729 "src/bison/parser.y"
                                                         {
            emit(jump_i, NULL, NULL, 0, (yyvsp[-4].intVal));
            patchLabel((yyvsp[-3].intVal), nextQuadLabel());
            if((yyvsp[-1].exprVal)!=NULL){
                patchlist((yyvsp[-1].exprVal)->break_list, nextQuadLabel());
                patchlist((yyvsp[-1].exprVal)->cont_list, (yyvsp[-4].intVal));
                (yyvsp[-1].exprVal)->break_list = 0;
                (yyvsp[-1].exprVal)->cont_list = 0;
            }
            (yyval.exprVal) = (yyvsp[-1].exprVal);
        }
#line 2396 "src/bison/parser.c"
    break;

  case 94: /* N: %empty  */
#line 742 "src/bison/parser.y"
   { (yyval.intVal) = nextQuadLabel(); emit(jump_i,NULL,NULL,NULL,0); }
#line 2402 "src/bison/parser.c"
    break;

  case 95: /* M: %empty  */
#line 743 "src/bison/parser.y"
   { (yyval.intVal) = nextQuadLabel(); }
#line 2408 "src/bison/parser.c"
    break;

  case 96: /* forprefix: FOR LEFT_PARENTHESIS elist SEMICOLON M expr SEMICOLON  */
#line 745 "src/bison/parser.y"
                                                                 {

            if((yyvsp[-1].exprVal)->type==boolexpr_e){
                if((yyvsp[-1].exprVal)->sym==NULL){
                    (yyvsp[-1].exprVal)->sym=newTemp();
                }
                patchlist((yyvsp[-1].exprVal)->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, (yyvsp[-1].exprVal), 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist((yyvsp[-1].exprVal)->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, (yyvsp[-1].exprVal), 0);
            }

    (yyval.exprVal) = new_Expr(for_e);
    (yyval.exprVal)->test = (yyvsp[-2].intVal);
    (yyval.exprVal)->enter = nextQuadLabel();
    emit(if_eq_i, (yyvsp[-1].exprVal), new_constbool(1), NULL, 0);
}
#line 2431 "src/bison/parser.c"
    break;

  case 97: /* forstmt: forprefix N elist RIGHT_PARENTHESIS N loopstart stmt loopend N  */
#line 764 "src/bison/parser.y"
                                                                           {
        reset_counter_temp();
        patchLabel((yyvsp[-8].exprVal)->enter, (yyvsp[-4].intVal)+1);
        patchLabel((yyvsp[-7].intVal), nextQuadLabel()); 
        patchLabel((yyvsp[-4].intVal), (yyvsp[-8].exprVal)->test); 
        patchLabel((yyvsp[0].intVal), (yyvsp[-7].intVal)+1); 
        if((yyvsp[-2].exprVal)!=NULL){
            patchlist((yyvsp[-2].exprVal)->break_list, nextQuadLabel());
            patchlist((yyvsp[-2].exprVal)->cont_list, (yyvsp[-7].intVal)+1);
            (yyvsp[-2].exprVal)->break_list = 0;
            (yyvsp[-2].exprVal)->cont_list = 0;
        }
        (yyval.exprVal) = (yyvsp[-2].exprVal);
    }
#line 2450 "src/bison/parser.c"
    break;

  case 98: /* elist: nonempty_elist COMMA expr  */
#line 780 "src/bison/parser.y"
                                  {
            if((yyvsp[0].exprVal)!=NULL){
                if((yyvsp[0].exprVal)->sym==NULL&&!isConstExpr((yyvsp[0].exprVal))){
                    (yyvsp[0].exprVal)->sym = new_SymbolTableVariable((yyvsp[0].exprVal)->strConst); 
                    SymbolTable_insert(symbol_table, (yyvsp[0].exprVal)->sym, false);
                }
                // increase_functionformalsoffset();
            }
            if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                if((yyvsp[0].exprVal)->sym==NULL){
                    (yyvsp[0].exprVal)->sym=newTemp();
                }
                patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
            }

            (yyval.exprVal)=(yyvsp[0].exprVal); (yyval.exprVal)->next = (yyvsp[-2].exprVal);
            (yyvsp[-2].exprVal)->prev = (yyval.exprVal);
        }
#line 2477 "src/bison/parser.c"
    break;

  case 99: /* elist: expr  */
#line 802 "src/bison/parser.y"
               {
            Stack_push(formal_args_stack,get_total_formal_args());
            resetfunctionformalsoffset();
            if((yyvsp[0].exprVal)!=NULL){
                if((yyvsp[0].exprVal)->sym==NULL&&!isConstExpr((yyvsp[0].exprVal))){
                    (yyvsp[0].exprVal)->sym = new_SymbolTableVariable((yyvsp[0].exprVal)->strConst); 
                    SymbolTable_insert(symbol_table, (yyvsp[0].exprVal)->sym, false);
                }
                // increase_functionformalsoffset();
            }
            if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                if((yyvsp[0].exprVal)->sym==NULL){
                    (yyvsp[0].exprVal)->sym=newTemp();
                }
                patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
            }

            (yyval.exprVal)=(yyvsp[0].exprVal);
        }
#line 2505 "src/bison/parser.c"
    break;

  case 100: /* nonempty_elist: nonempty_elist COMMA expr  */
#line 827 "src/bison/parser.y"
                                           {
            if((yyvsp[0].exprVal)!=NULL){
                if((yyvsp[0].exprVal)->sym==NULL&&!isConstExpr((yyvsp[0].exprVal))){
                    (yyvsp[0].exprVal)->sym = new_SymbolTableVariable((yyvsp[0].exprVal)->strConst); 
                    SymbolTable_insert(symbol_table, (yyvsp[0].exprVal)->sym, false);
                }
                // increase_functionformalsoffset();
            }
            if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                if((yyvsp[0].exprVal)->sym==NULL){
                    (yyvsp[0].exprVal)->sym=newTemp();
                }
                patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
            }
            (yyval.exprVal)=(yyvsp[0].exprVal); (yyval.exprVal)->next = (yyvsp[-2].exprVal);
            (yyvsp[-2].exprVal)->prev = (yyval.exprVal);
        }
#line 2531 "src/bison/parser.c"
    break;

  case 101: /* nonempty_elist: expr  */
#line 848 "src/bison/parser.y"
               {
            Stack_push(formal_args_stack,get_total_formal_args());
            resetfunctionformalsoffset();
            if((yyvsp[0].exprVal)!=NULL){
                if((yyvsp[0].exprVal)->sym==NULL&&!isConstExpr((yyvsp[0].exprVal))){
                    (yyvsp[0].exprVal)->sym = new_SymbolTableVariable((yyvsp[0].exprVal)->strConst); 
                    SymbolTable_insert(symbol_table, (yyvsp[0].exprVal)->sym, false);
                }
                // increase_functionformalsoffset();
            }
            if((yyvsp[0].exprVal)!=NULL&&(yyvsp[0].exprVal)->type==boolexpr_e){
                if((yyvsp[0].exprVal)->sym==NULL){
                    (yyvsp[0].exprVal)->sym=newTemp();
                }
                patchlist((yyvsp[0].exprVal)->true_list, nextQuadLabel());
                emit(assign_i, new_constbool(true), NULL, (yyvsp[0].exprVal), 0);
                emit(jump_i, NULL, NULL, NULL, nextQuadLabel()+2);
                patchlist((yyvsp[0].exprVal)->false_list, nextQuadLabel());
                emit(assign_i, new_constbool(false), NULL, (yyvsp[0].exprVal), 0);
            }
            (yyval.exprVal)=(yyvsp[0].exprVal);
        }
#line 2558 "src/bison/parser.c"
    break;

  case 102: /* primary: lvalue  */
#line 873 "src/bison/parser.y"
                 {(yyval.exprVal)=(yyvsp[0].exprVal);}
#line 2564 "src/bison/parser.c"
    break;

  case 103: /* primary: call  */
#line 874 "src/bison/parser.y"
               {(yyval.exprVal)=(yyvsp[0].exprVal);}
#line 2570 "src/bison/parser.c"
    break;

  case 105: /* primary: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS  */
#line 876 "src/bison/parser.y"
                                                     {(yyval.exprVal)=(yyvsp[-1].exprVal);}
#line 2576 "src/bison/parser.c"
    break;

  case 106: /* primary: constant  */
#line 877 "src/bison/parser.y"
                   {(yyval.exprVal)=(yyvsp[0].exprVal);}
#line 2582 "src/bison/parser.c"
    break;

  case 107: /* call: call LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 880 "src/bison/parser.y"
                                                     {
            set_formal_offset(Stack_pop(formal_args_stack));
            (yyvsp[-3].exprVal)->next = (yyvsp[-1].exprVal);
            (yyval.exprVal) = make_call((yyvsp[-3].exprVal), (yyvsp[-1].exprVal));
        }
#line 2592 "src/bison/parser.c"
    break;

  case 108: /* call: lvalue callsuffix  */
#line 885 "src/bison/parser.y"
                            {
            if ((yyvsp[0].exprVal)->method){
                (yyvsp[-1].exprVal) = emitIfTableItem((yyvsp[-1].exprVal)); //in case it was a table item too

                expr* curr = (yyvsp[0].exprVal);
                while (curr->next!=NULL){
                    curr = curr->next;
                }
                curr->next = (yyvsp[-1].exprVal); //insert first (reversed, so from last)

                (yyvsp[-1].exprVal)->index = new_conststring((yyvsp[0].exprVal)->strConst);
                (yyvsp[-1].exprVal) = emitIfTableItem(member_item((yyvsp[-1].exprVal), (yyvsp[0].exprVal)->strConst));
            } else {
                //SymbolTableEntry_t* t = SymbolTable_lookup_chill(symbol_table, $1->strConst);
                //if ($1->type == tableitem_e) 
                if ((yyvsp[-1].exprVal)->sym&&(yyvsp[-1].exprVal)->sym->isTable) 
                    (yyvsp[-1].exprVal)->type = tableitem_e;
            }
            
            (yyval.exprVal) = make_call((yyvsp[-1].exprVal), (yyvsp[0].exprVal)->next);
            if((yyvsp[0].exprVal)->method||(yyvsp[-1].exprVal)->index!=NULL){
                // printf("TABLE\n");
                (yyvsp[-1].exprVal)->type = tableitem_e;
            }
           
        }
#line 2623 "src/bison/parser.c"
    break;

  case 109: /* call: LEFT_PARENTHESIS funcdef RIGHT_PARENTHESIS LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 911 "src/bison/parser.y"
                                                                                              {
            set_formal_offset(Stack_pop(formal_args_stack));
	        expr* func = new_Expr(programfunc_e);
            func->next = (yyvsp[-1].exprVal);
            func->sym = (yyvsp[-4].exprVal)->sym;
            (yyval.exprVal) = make_call(func, (yyvsp[-1].exprVal));
            printArgs((yyval.exprVal)->next);
        }
#line 2636 "src/bison/parser.c"
    break;

  case 110: /* callsuffix: normcall  */
#line 921 "src/bison/parser.y"
                      {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 2642 "src/bison/parser.c"
    break;

  case 111: /* callsuffix: methodcall  */
#line 922 "src/bison/parser.y"
                     {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 2648 "src/bison/parser.c"
    break;

  case 112: /* normcall: LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 925 "src/bison/parser.y"
                                                    {
            // printf("args: %d\n",get_total_formal_args());
            set_formal_offset(Stack_pop(formal_args_stack));
            // printf("prev args: %d\n",get_total_formal_args());
            (yyval.exprVal) = new_Expr(callfunc_e);
            (yyval.exprVal)->next = (yyvsp[-1].exprVal);
            (yyval.exprVal)->numConst = 0;
            (yyval.exprVal)->strConst = NULL;
        }
#line 2662 "src/bison/parser.c"
    break;

  case 113: /* methodcall: DOTS id LEFT_PARENTHESIS elist RIGHT_PARENTHESIS  */
#line 934 "src/bison/parser.y"
                                                              {
            //increase_functionformalsoffset(); // +1 DUE TO DOTS
            // printf("args: %d\n",get_total_formal_args());
            set_formal_offset(Stack_pop(formal_args_stack));
            // printf("prev args: %d\n",get_total_formal_args());
            (yyval.exprVal) = new_Expr(callfunc_e);
            (yyval.exprVal)->strConst = addStringLiterals((yyvsp[-3].exprVal)->strConst); 
            (yyval.exprVal)->next = (yyvsp[-1].exprVal);
            (yyval.exprVal)->method = true;
        }
#line 2677 "src/bison/parser.c"
    break;

  case 114: /* objectdef: LEFT_BRACKET elist RIGHT_BRACKET  */
#line 946 "src/bison/parser.y"
                                             {
            (yyval.exprVal)=new_Expr(newtable_e);
            (yyval.exprVal)->sym = newTemp();
            (yyval.exprVal)->sym->isTable = true;
            if((yyvsp[-1].exprVal)!=NULL && (yyvsp[-1].exprVal)->type!=constnum_e  && (yyvsp[-1].exprVal)->type!=nil_e && (yyvsp[-1].exprVal)->type!=constbool_e && (yyvsp[-1].exprVal)->type!=conststring_e)(yyvsp[-1].exprVal)->type = tableitem_e;
            emit(tablecreate_i, (yyval.exprVal), NULL, NULL, 0);
            expr* iterator = moveToEnd((yyvsp[-1].exprVal));
            for(int i=0;iterator ; iterator = iterator->prev) {
                emit(tablesetelem_i, (yyval.exprVal), new_constnum(i++), iterator, 0);
            }
        }
#line 2693 "src/bison/parser.c"
    break;

  case 115: /* objectdef: LEFT_BRACKET indexed RIGHT_BRACKET  */
#line 957 "src/bison/parser.y"
                                             {
            (yyval.exprVal)=new_Expr(newtable_e);
            (yyval.exprVal)->sym = newTemp();
            (yyval.exprVal)->sym->isTable = true;
            if((yyvsp[-1].exprVal)!=NULL && (yyvsp[-1].exprVal)->type!=constnum_e  && (yyvsp[-1].exprVal)->type!=nil_e && (yyvsp[-1].exprVal)->type!=constbool_e && (yyvsp[-1].exprVal)->type!=conststring_e)(yyvsp[-1].exprVal)->type = tableitem_e;
            emit(tablecreate_i, (yyval.exprVal), NULL, NULL, 0);
            for(int i = 0; (yyvsp[-1].exprVal)&&(yyvsp[-1].exprVal)->next; (yyvsp[-1].exprVal) = (yyvsp[-1].exprVal)->next->next)
                emit(tablesetelem_i, (yyval.exprVal), (yyvsp[-1].exprVal), (yyvsp[-1].exprVal)->next, 0);
        }
#line 2707 "src/bison/parser.c"
    break;

  case 116: /* indexed: indexedelem COMMA indexlist  */
#line 968 "src/bison/parser.y"
                                      {(yyval.exprVal) = (yyvsp[-2].exprVal); (yyval.exprVal)->next->next = (yyvsp[0].exprVal);}
#line 2713 "src/bison/parser.c"
    break;

  case 117: /* indexed: indexedelem  */
#line 969 "src/bison/parser.y"
                      {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 2719 "src/bison/parser.c"
    break;

  case 118: /* indexlist: indexedelem COMMA indexlist  */
#line 972 "src/bison/parser.y"
                                        {(yyval.exprVal) = (yyvsp[-2].exprVal); (yyval.exprVal)->next->next = (yyvsp[0].exprVal);}
#line 2725 "src/bison/parser.c"
    break;

  case 119: /* indexlist: indexedelem  */
#line 973 "src/bison/parser.y"
                      {(yyval.exprVal) = (yyvsp[0].exprVal);}
#line 2731 "src/bison/parser.c"
    break;

  case 121: /* indexedelem: LEFT_BRACE expr COLON expr RIGHT_BRACE  */
#line 976 "src/bison/parser.y"
                                                     {
                (yyval.exprVal) = (yyvsp[-3].exprVal);
                (yyval.exprVal)->next = (yyvsp[-1].exprVal);
            }
#line 2740 "src/bison/parser.c"
    break;

  case 122: /* indexedelem: error  */
#line 980 "src/bison/parser.y"
                    { yyerrok; yyclearin; }
#line 2746 "src/bison/parser.c"
    break;

  case 123: /* member: lvalue FULL_STOP id  */
#line 983 "src/bison/parser.y"
                             {
            //$1->type=tableitem_e;

            (yyval.exprVal) = new_Expr(tableitem_e);
            (yyval.exprVal)->strConst = (yyvsp[-2].exprVal)->strConst;
            (yyvsp[0].exprVal)->strConst = addStringLiterals((yyvsp[0].exprVal)->strConst);
            (yyvsp[0].exprVal)->type = conststring_e;
            (yyval.exprVal)->index = (yyvsp[0].exprVal);
            (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
            assignParentTable((yyval.exprVal));
            (yyval.exprVal) = member_item((yyval.exprVal), (yyvsp[0].exprVal)->strConst);   
        }
#line 2763 "src/bison/parser.c"
    break;

  case 124: /* member: lvalue LEFT_BRACKET expr RIGHT_BRACKET  */
#line 995 "src/bison/parser.y"
                                                 {
            (yyval.exprVal) = new_Expr(tableitem_e);
            (yyval.exprVal)->strConst = (yyvsp[-3].exprVal)->strConst;
            (yyval.exprVal)->index = (yyvsp[-1].exprVal);
            (yyval.exprVal)->sym = (yyvsp[-3].exprVal)->sym;
            assignParentTable((yyval.exprVal));
            (yyval.exprVal) = member_item((yyval.exprVal), (yyvsp[-1].exprVal)->strConst);
        }
#line 2776 "src/bison/parser.c"
    break;

  case 125: /* member: call FULL_STOP id  */
#line 1003 "src/bison/parser.y"
                            {
            //$3->sym =  new_SymbolTableVariable($3->strConst); SymbolTable_insert(symbol_table, $3->sym, false);
            (yyval.exprVal)=new_Expr(tableitem_e);
            (yyval.exprVal)->strConst = (yyvsp[-2].exprVal)->strConst;
            (yyvsp[0].exprVal)->strConst = addStringLiterals((yyvsp[0].exprVal)->strConst);
            (yyvsp[0].exprVal)->type = conststring_e;
            (yyval.exprVal)->sym = (yyvsp[-2].exprVal)->sym;
            (yyval.exprVal)->index = (yyvsp[0].exprVal);
            (yyvsp[-2].exprVal)->type = tableitem_e;
            (yyval.exprVal) = member_item((yyval.exprVal), (yyvsp[0].exprVal)->strConst);
        }
#line 2792 "src/bison/parser.c"
    break;

  case 126: /* member: call LEFT_BRACKET expr RIGHT_BRACKET  */
#line 1014 "src/bison/parser.y"
                                               {
            (yyval.exprVal)=new_Expr(tableitem_e);
            (yyval.exprVal)->strConst = (yyvsp[-3].exprVal)->strConst;
            (yyval.exprVal)->index = (yyvsp[-1].exprVal);
            (yyval.exprVal)->sym = (yyvsp[-3].exprVal)->sym;
            (yyval.exprVal) = member_item((yyval.exprVal), (yyvsp[-1].exprVal)->strConst);
        }
#line 2804 "src/bison/parser.c"
    break;

  case 127: /* num: NUMBER  */
#line 1023 "src/bison/parser.y"
             {(yyval.exprVal)=new_Expr(constnum_e); (yyval.exprVal)->numConst = (yyvsp[0].realVal); (yyval.exprVal)->strConst = num_to_str((yyvsp[0].realVal));}
#line 2810 "src/bison/parser.c"
    break;

  case 128: /* constant: num  */
#line 1026 "src/bison/parser.y"
               {(yyval.exprVal)=(yyvsp[0].exprVal);}
#line 2816 "src/bison/parser.c"
    break;

  case 129: /* constant: STR  */
#line 1027 "src/bison/parser.y"
               {(yyval.exprVal)=new_Expr(conststring_e); (yyval.exprVal)->strConst = addStringLiterals((yyvsp[0].stringVal));}
#line 2822 "src/bison/parser.c"
    break;

  case 130: /* constant: NIL  */
#line 1028 "src/bison/parser.y"
               {(yyval.exprVal)=new_Expr(nil_e);}
#line 2828 "src/bison/parser.c"
    break;

  case 131: /* constant: TRUE  */
#line 1029 "src/bison/parser.y"
                {(yyval.exprVal)=new_Expr(constbool_e); (yyval.exprVal)->boolConst = true;}
#line 2834 "src/bison/parser.c"
    break;

  case 132: /* constant: FALSE  */
#line 1030 "src/bison/parser.y"
                 {(yyval.exprVal)=new_Expr(constbool_e); (yyval.exprVal)->boolConst = false;}
#line 2840 "src/bison/parser.c"
    break;


#line 2844 "src/bison/parser.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1034 "src/bison/parser.y"
 

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
