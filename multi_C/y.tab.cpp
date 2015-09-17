/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "multiC.y"

//=======================================================================
//최종 갱신일 2014.11.24
//-----------------------------------------------------------------------
////갱신 기록
////2014.10.10
////2014.10.12 treeDrawer적용(추가 수정 필요), 비교연산 적용중
////2014.10.13 비교 연산 완료. statement, statmentlist 제작, 서브루틴 중첩 구성중
////2014.10.31 treeDrawer 제거, expression 계층구소 완성
////2014.11.1  변수 선언문 90%완성. 함수부분 완성 후 VarList초기화 수정할 것
////2014.11.2  루프문 완성. if문 dangling else 문제 해결할 것
////2014.11.23 수 연산 부분에 AST 구현.
////2014.11.24 dangling else 해결, IOStmt추가, FuncDefine 수정
////2014 11.24 SYMTAB 구성중(변수명은 10자까지 가능)
////2014.11.24 if-else 충돌 재발생 <- 해결
////2014.11.30 c++적용(전방 선언), ast완성, 함수 문법 추가
//=======================================================================
#include <stdio.h>
#include "CodeGenerator.h"
#include "AST.h"

//시작 SCOPE
int scope = 0;

int yylex();
int yyparse();
int yywrap();
int yyerror(const char *msg) { fputs(msg, stderr); return -1; }

struct _node* ASTRoot;



/* Line 189 of yacc.c  */
#line 106 "y.tab.cpp"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     num = 258,
     id = 259,
     shiftL = 260,
     shiftR = 261,
     equal = 262,
     nEqual = 263,
     lEqual = 264,
     gEqual = 265,
     _and = 266,
     _or = 267,
     addAcc = 268,
     subAcc = 269,
     mulAcc = 270,
     divAcc = 271,
     modAcc = 272,
     bAndAcc = 273,
     bOrAcc = 274,
     bXOrAcc = 275,
     shlAcc = 276,
     shrAcc = 277,
     tInt = 278,
     tChar = 279,
     tVoid = 280,
     tStr = 281,
     _if = 282,
     _else = 283,
     _for = 284,
     _while = 285,
     _do = 286,
     _return = 287,
     bOpen = 288,
     bClose = 289,
     _ifx = 290
   };
#endif
/* Tokens.  */
#define num 258
#define id 259
#define shiftL 260
#define shiftR 261
#define equal 262
#define nEqual 263
#define lEqual 264
#define gEqual 265
#define _and 266
#define _or 267
#define addAcc 268
#define subAcc 269
#define mulAcc 270
#define divAcc 271
#define modAcc 272
#define bAndAcc 273
#define bOrAcc 274
#define bXOrAcc 275
#define shlAcc 276
#define shrAcc 277
#define tInt 278
#define tChar 279
#define tVoid 280
#define tStr 281
#define _if 282
#define _else 283
#define _for 284
#define _while 285
#define _do 286
#define _return 287
#define bOpen 288
#define bClose 289
#define _ifx 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 34 "multiC.y"

	struct _node* pVal;
	char cVal;
	int iVal;
	char *sVal;



/* Line 214 of yacc.c  */
#line 221 "y.tab.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 233 "y.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   285

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  110
/* YYNRULES -- Number of states.  */
#define YYNSTATES  213

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    52,    45,     2,
      37,    38,    50,    48,    39,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      46,    42,    47,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    44,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,    43,    40,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    13,    16,    18,    20,
      23,    26,    32,    38,    44,    48,    50,    53,    56,    60,
      65,    67,    69,    71,    74,    76,    78,    80,    82,    84,
      86,    89,    93,    96,    98,   101,   105,   109,   114,   120,
     128,   136,   142,   150,   152,   154,   157,   160,   163,   166,
     169,   172,   175,   177,   181,   187,   191,   195,   197,   202,
     205,   209,   212,   216,   218,   222,   226,   230,   234,   238,
     242,   246,   250,   254,   258,   262,   264,   268,   270,   274,
     276,   280,   282,   286,   288,   292,   294,   298,   302,   304,
     308,   312,   316,   320,   322,   326,   330,   332,   336,   340,
     342,   346,   350,   354,   356,   358,   362,   364,   369,   373,
     375
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    75,    55,    -1,    75,    -1,    55,    -1,
      55,    56,    -1,    55,    57,    -1,    56,    -1,    57,    -1,
      58,    36,    -1,    58,    67,    -1,    25,     4,    37,    59,
      38,    -1,    63,     4,    37,    59,    38,    -1,    61,     4,
      37,    59,    38,    -1,    59,    39,    60,    -1,    60,    -1,
      63,     4,    -1,    62,    40,    -1,    62,    39,    63,    -1,
      41,    63,    39,    63,    -1,    23,    -1,    24,    -1,    26,
      -1,    64,    65,    -1,    65,    -1,    66,    -1,    67,    -1,
      68,    -1,    69,    -1,    70,    -1,    32,    66,    -1,    37,
      78,    38,    -1,    81,    36,    -1,    36,    -1,    41,    40,
      -1,    41,    75,    40,    -1,    41,    64,    40,    -1,    41,
      75,    64,    40,    -1,    27,    37,    81,    38,    65,    -1,
      27,    37,    81,    38,    65,    28,    65,    -1,    29,    37,
      66,    66,    81,    38,    65,    -1,    30,    37,    81,    38,
      65,    -1,    31,    65,    30,    37,    81,    38,    36,    -1,
      71,    -1,    73,    -1,    72,    33,    -1,    72,    81,    -1,
      34,    81,    -1,    74,    34,    -1,    74,    81,    -1,    33,
      81,    -1,    75,    76,    -1,    76,    -1,    63,    77,    36,
      -1,    77,    39,     4,    42,    82,    -1,    77,    39,     4,
      -1,     4,    42,    82,    -1,     4,    -1,    79,    42,    94,
      36,    -1,    80,    40,    -1,    80,    39,     4,    -1,    41,
       4,    -1,    81,    39,    82,    -1,    82,    -1,    95,    42,
      82,    -1,    95,    13,    82,    -1,    95,    14,    82,    -1,
      95,    15,    82,    -1,    95,    16,    82,    -1,    95,    17,
      82,    -1,    95,    18,    82,    -1,    95,    19,    82,    -1,
      95,    20,    82,    -1,    95,    21,    82,    -1,    95,    22,
      82,    -1,    83,    -1,    83,    12,    84,    -1,    84,    -1,
      84,    11,    85,    -1,    85,    -1,    85,    43,    86,    -1,
      86,    -1,    86,    44,    87,    -1,    87,    -1,    87,    45,
      88,    -1,    88,    -1,    88,     7,    89,    -1,    88,     8,
      89,    -1,    89,    -1,    89,    46,    90,    -1,    89,     9,
      90,    -1,    89,    47,    90,    -1,    89,    10,    90,    -1,
      90,    -1,    90,     5,    91,    -1,    90,     6,    91,    -1,
      91,    -1,    91,    48,    92,    -1,    91,    49,    92,    -1,
      92,    -1,    92,    50,    93,    -1,    92,    51,    93,    -1,
      92,    52,    93,    -1,    93,    -1,     3,    -1,    37,    81,
      38,    -1,    94,    -1,    94,    37,    81,    38,    -1,    94,
      37,    38,    -1,    95,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    57,    57,    58,    59,    62,    63,    64,    65,    68,
      71,    74,    75,    76,    79,    80,    83,    86,    89,    90,
      92,    93,    94,    97,    98,   101,   102,   103,   104,   105,
     106,   107,   110,   111,   114,   115,   116,   117,   120,   121,
     124,   125,   126,   129,   130,   133,   136,   137,   140,   143,
     144,   147,   148,   151,   154,   155,   156,   157,   160,   163,
     166,   167,   170,   171,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   188,   189,   192,   193,
     196,   197,   200,   201,   204,   205,   208,   209,   210,   213,
     214,   215,   216,   217,   220,   221,   222,   225,   226,   227,
     230,   231,   232,   233,   236,   237,   238,   241,   242,   243,
     246
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "num", "id", "shiftL", "shiftR", "equal",
  "nEqual", "lEqual", "gEqual", "_and", "_or", "addAcc", "subAcc",
  "mulAcc", "divAcc", "modAcc", "bAndAcc", "bOrAcc", "bXOrAcc", "shlAcc",
  "shrAcc", "tInt", "tChar", "tVoid", "tStr", "_if", "_else", "_for",
  "_while", "_do", "_return", "bOpen", "bClose", "_ifx", "';'", "'('",
  "')'", "','", "'}'", "'{'", "'='", "'|'", "'^'", "'&'", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "$accept", "Program", "FuncList",
  "FuncDeclare", "FuncDefine", "FuncHeader", "ParamList", "Parameter",
  "TypeList", "TypeListBeg", "Type", "StmtList", "Stmt", "ExprStmt",
  "CompStmt", "CondStmt", "LoopStmt", "IOStmt", "InStmt", "InStmtBeg",
  "OutStmt", "OutStmtBeg", "VarDecList", "VarDeclare", "VarForDec",
  "MAssignStmt", "VarList", "VarListBeg", "Expr", "AssignExpr", "LOrExpr",
  "LAndExpr", "BitOrExpr", "BitExOrExpr", "BitAndExpr", "EqualExpr",
  "CmpExpr", "ShiftExpr", "ArithExpr", "Term", "Factor", "Function",
  "Variable", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    59,    40,    41,    44,
     125,   123,    61,   124,    94,    38,    60,    62,    43,    45,
      42,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      57,    58,    58,    58,    59,    59,    60,    61,    62,    62,
      63,    63,    63,    64,    64,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    67,    67,    67,    68,    68,
      69,    69,    69,    70,    70,    71,    72,    72,    73,    74,
      74,    75,    75,    76,    77,    77,    77,    77,    78,    79,
      80,    80,    81,    81,    82,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    83,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    89,    90,    90,    90,    91,    91,    91,
      92,    92,    92,    92,    93,    93,    93,    94,    94,    94,
      95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     2,     2,     1,     1,     2,
       2,     5,     5,     5,     3,     1,     2,     2,     3,     4,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     1,
       2,     3,     2,     1,     2,     3,     3,     4,     5,     7,
       7,     5,     7,     1,     1,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     5,     3,     3,     1,     4,     2,
       3,     2,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     1,     3,     1,     4,     3,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    20,    21,     0,    22,     0,     0,     4,     7,     8,
       0,     0,     0,     0,     3,    52,     0,     0,     1,     5,
       6,     0,     9,     0,    10,     0,     0,    17,    57,     0,
       2,    51,     0,     0,     0,   104,   110,     0,     0,     0,
       0,     0,     0,     0,    33,     0,    34,     0,     0,    24,
      25,    26,    27,    28,    29,    43,     0,    44,     0,     0,
       0,    63,    75,    77,    79,    81,    83,    85,    88,    93,
      96,    99,   103,   106,   109,     0,    18,     0,     0,    53,
       0,     0,    15,     0,    19,     0,     0,     0,     0,     0,
      30,    50,    47,     0,     0,     0,     0,     0,    57,    36,
      23,    45,    46,    48,    49,    35,     0,    32,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    56,    55,    11,     0,    16,     0,     0,     0,     0,
      61,    31,     0,     0,    59,   105,    37,    62,    76,   109,
      78,    80,    82,    84,    86,    87,    90,    92,    89,    91,
      94,    95,    97,    98,   100,   101,   102,   108,     0,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    64,
      13,    12,     0,    14,     0,     0,     0,     0,     0,    60,
     107,    54,    38,     0,    41,     0,    58,     0,     0,     0,
      39,    40,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    81,    82,    11,    12,
      83,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    14,    15,    29,    94,    95,    96,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int16 yypact[] =
{
      69,   -77,   -77,     9,   -77,    15,    23,    69,   -77,   -77,
     -20,    27,    51,    38,    69,   -77,    70,    49,   -77,   -77,
     -77,   118,   -77,    97,   -77,   116,    15,   -77,   -15,   -30,
      69,   -77,    15,    15,   121,   -77,   -77,   129,   134,   137,
     196,     8,   105,   105,   -77,    26,   -77,   128,   161,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   108,   -77,    31,   146,
     -11,   -77,   143,   135,   138,   145,   151,   107,    89,    91,
      95,    52,   -77,   170,   225,    15,   -77,    15,   105,   -77,
     205,   109,   -77,   220,   -77,   105,     8,   105,   186,   105,
     -77,   192,   192,   230,   224,   223,   112,   165,   226,   -77,
     -77,   -77,   192,   -77,   192,   -77,   181,   -77,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   102,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   105,   105,   167,
     197,   -77,   227,   -77,    15,   -77,   210,     8,   212,   229,
     -77,   -77,   266,   267,   -77,   -77,   -77,   -77,   135,   -77,
     138,   145,   151,   107,    89,    89,    91,    91,    91,    91,
      95,    95,    52,    52,   -77,   -77,   -77,   -77,   214,   -77,
     -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   105,   -77,   196,   105,   196,   105,   183,   -77,
     -77,   -77,   244,   216,   -77,   218,   -77,   196,   196,   237,
     -77,   -77,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   260,    -4,     7,   -77,   -27,   131,   -77,   -77,
      10,   217,   -40,   -22,   268,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,   254,   -13,   -77,   -77,   -77,   -77,   -38,   -76,
     -77,   171,   169,   172,   173,   168,   144,    44,   140,   141,
      -7,   130,   -39
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      88,    31,   141,    19,    91,    92,    79,    97,   100,    80,
      13,    35,    36,    16,    20,    17,    22,    21,   102,    90,
     104,    23,    77,    18,    13,   107,    19,    78,   108,    35,
      36,    25,   157,    47,    35,    36,    76,    20,     1,     2,
      21,     4,    28,    84,    44,    89,    31,   146,   139,   148,
     140,    97,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,    89,   147,   103,   100,    93,    89,    47,
     159,   159,   159,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   159,   159,   159,   159,   159,   159,    33,   178,
      26,    27,     1,     2,     3,     4,   120,   121,   116,   117,
      35,    36,   124,   125,   126,    35,    36,    32,    35,    36,
       5,    35,    36,   159,   114,   115,   201,   174,   175,   176,
       1,     2,    34,     4,    37,   195,    38,    39,    40,    41,
      42,    43,    98,    44,    45,   118,   119,    46,    23,    89,
     177,   101,    89,   122,   123,    89,   110,   143,   144,    35,
      36,   153,   154,    75,   202,   109,   204,   203,    77,   205,
     166,   167,   168,   169,    35,    36,    85,   210,   211,     1,
       2,    86,     4,    37,    87,    38,    39,    40,    41,    42,
      43,   111,    44,    45,    35,    36,   105,    23,    37,   112,
      38,    39,    40,    41,    42,    43,   113,    44,    45,    35,
      36,    99,    23,   155,   108,   190,   144,   127,    37,   142,
      38,    39,    40,    41,    42,    43,   149,    44,    45,   206,
     127,   156,    23,    37,   145,    38,    39,    40,    41,    42,
      43,   108,    44,    45,   150,   191,   144,    23,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   194,   108,
     196,   108,   200,   108,   208,   108,   209,   108,   164,   165,
     170,   171,   151,   172,   173,   152,   197,   138,    78,   192,
      36,   199,   207,   212,    30,   193,   106,    59,    24,   160,
     158,   163,   198,   161,     0,   162
};

static const yytype_int16 yycheck[] =
{
      40,    14,    78,     7,    42,    43,    36,    45,    48,    39,
       0,     3,     4,     4,     7,     5,    36,     7,    56,    41,
      58,    41,    37,     0,    14,    36,    30,    42,    39,     3,
       4,     4,   108,    23,     3,     4,    26,    30,    23,    24,
      30,    26,     4,    33,    36,    37,    59,    85,    75,    87,
      77,    89,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,    37,    86,    34,   106,    41,    37,    59,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,    39,   127,
      39,    40,    23,    24,    25,    26,     5,     6,     9,    10,
       3,     4,    50,    51,    52,     3,     4,    37,     3,     4,
      41,     3,     4,   152,     7,     8,   192,   124,   125,   126,
      23,    24,     4,    26,    27,   147,    29,    30,    31,    32,
      33,    34,     4,    36,    37,    46,    47,    40,    41,    37,
      38,    33,    37,    48,    49,    37,    11,    38,    39,     3,
       4,    39,    40,    37,   194,    12,   196,   195,    37,   197,
     116,   117,   118,   119,     3,     4,    37,   207,   208,    23,
      24,    37,    26,    27,    37,    29,    30,    31,    32,    33,
      34,    43,    36,    37,     3,     4,    40,    41,    27,    44,
      29,    30,    31,    32,    33,    34,    45,    36,    37,     3,
       4,    40,    41,    38,    39,    38,    39,    37,    27,     4,
      29,    30,    31,    32,    33,    34,    30,    36,    37,    36,
      37,    40,    41,    27,     4,    29,    30,    31,    32,    33,
      34,    39,    36,    37,     4,    38,    39,    41,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    38,    39,
      38,    39,    38,    39,    38,    39,    38,    39,   114,   115,
     120,   121,    38,   122,   123,    42,    37,    42,    42,    42,
       4,     4,    28,    36,    14,   144,    59,    23,    10,   110,
     109,   113,   152,   111,    -1,   112
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    23,    24,    25,    26,    41,    54,    55,    56,    57,
      58,    61,    62,    63,    75,    76,     4,    63,     0,    56,
      57,    63,    36,    41,    67,     4,    39,    40,     4,    77,
      55,    76,    37,    39,     4,     3,     4,    27,    29,    30,
      31,    32,    33,    34,    36,    37,    40,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    37,    63,    37,    42,    36,
      39,    59,    60,    63,    63,    37,    37,    37,    65,    37,
      66,    81,    81,    41,    78,    79,    80,    81,     4,    40,
      65,    33,    81,    34,    81,    40,    64,    36,    39,    12,
      11,    43,    44,    45,     7,     8,     9,    10,    46,    47,
       5,     6,    48,    49,    50,    51,    52,    37,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    42,    59,
      59,    82,     4,    38,    39,     4,    81,    66,    81,    30,
       4,    38,    42,    39,    40,    38,    40,    82,    84,    95,
      85,    86,    87,    88,    89,    89,    90,    90,    90,    90,
      91,    91,    92,    92,    93,    93,    93,    38,    81,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
      38,    38,    42,    60,    38,    66,    38,    37,    94,     4,
      38,    82,    65,    81,    65,    81,    36,    28,    38,    38,
      65,    65,    36
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1464 of yacc.c  */
#line 57 "multiC.y"
    { (yyval.pVal) = mknode(PROGRAM, 0, 2, (yyvsp[(1) - (2)].pVal), (yyvsp[(2) - (2)].pVal)); ASTRoot = (yyval.pVal); }
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 58 "multiC.y"
    { (yyval.pVal) = mknode(PROGRAM, 0, 1, (yyvsp[(1) - (1)].pVal)); ASTRoot = (yyval.pVal);}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 59 "multiC.y"
    { (yyval.pVal) = mknode(PROGRAM, 0, 1, (yyvsp[(1) - (1)].pVal)); ASTRoot = (yyval.pVal);}
    break;

  case 5:

/* Line 1464 of yacc.c  */
#line 62 "multiC.y"
    { addSon((yyvsp[(1) - (2)].pVal), (yyvsp[(2) - (2)].pVal)); (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 6:

/* Line 1464 of yacc.c  */
#line 63 "multiC.y"
    { addSon((yyvsp[(1) - (2)].pVal), (yyvsp[(2) - (2)].pVal)); (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 7:

/* Line 1464 of yacc.c  */
#line 64 "multiC.y"
    { (yyval.pVal) = mknode(FUNC_LIST, 0, 1, (yyvsp[(1) - (1)].pVal)); }
    break;

  case 8:

/* Line 1464 of yacc.c  */
#line 65 "multiC.y"
    { (yyval.pVal) = mknode(FUNC_LIST, 0, 1, (yyvsp[(1) - (1)].pVal)); }
    break;

  case 9:

/* Line 1464 of yacc.c  */
#line 68 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 71 "multiC.y"
    { addSon((yyvsp[(1) - (2)].pVal), (yyvsp[(2) - (2)].pVal)); (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 74 "multiC.y"
    { (yyval.pVal) = mknode(FUNC_DEC, 0, 3, mkleaf(VOID, VOID), mkleaf(ID, (int)(yyvsp[(2) - (5)].sVal)), (yyvsp[(4) - (5)].pVal)); }
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 75 "multiC.y"
    { (yyval.pVal) = mknode(FUNC_DEC, 0, 3, (yyvsp[(1) - (5)].pVal), mkleaf(ID, (int)(yyvsp[(2) - (5)].sVal)), (yyvsp[(4) - (5)].pVal)); }
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 76 "multiC.y"
    { (yyval.pVal) = mknode(FUNC_DEC, 0, 3, (yyvsp[(1) - (5)].pVal), mkleaf(ID, (int)(yyvsp[(2) - (5)].sVal)), (yyvsp[(4) - (5)].pVal)); }
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 79 "multiC.y"
    { addBro((yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); (yyval.pVal) = (yyvsp[(1) - (3)].pVal); }
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 80 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 83 "multiC.y"
    { (yyval.pVal) = mknode(PARAM, 0, 2, (yyvsp[(1) - (2)].pVal), mkleaf(ID, (int)(yyvsp[(2) - (2)].sVal))); }
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 86 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 89 "multiC.y"
    { addSon((yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); (yyval.pVal) = (yyvsp[(1) - (3)].pVal); }
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 90 "multiC.y"
    { (yyval.pVal) = mknode(TYPE_LIST, 0, 2, (yyvsp[(2) - (4)].pVal), (yyvsp[(4) - (4)].pVal)); }
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 92 "multiC.y"
    { (yyval.pVal) = mkleaf(TYPE, INT); }
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 93 "multiC.y"
    { (yyval.pVal) = mkleaf(TYPE, CHAR); }
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 94 "multiC.y"
    { (yyval.pVal) = mkleaf(TYPE, STRING); }
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 97 "multiC.y"
    { addBro((yyvsp[(1) - (2)].pVal), (yyvsp[(2) - (2)].pVal)); (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 98 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 101 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 102 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 103 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 104 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 105 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 106 "multiC.y"
    { (yyval.pVal) = mknode(RETURN, 0, 1, (yyvsp[(2) - (2)].pVal)); }
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 107 "multiC.y"
    { (yyval.pVal) = (yyvsp[(2) - (3)].pVal); }
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 110 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 111 "multiC.y"
    { (yyval.pVal) = mkleaf(NIL, 0); }
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 114 "multiC.y"
    { (yyval.pVal) = mknode(STMT, 0, 1, mkleaf(NIL, 0)); }
    break;

  case 35:

/* Line 1464 of yacc.c  */
#line 115 "multiC.y"
    { (yyval.pVal) = mknode(STMT, 0, 1, (yyvsp[(2) - (3)].pVal)); }
    break;

  case 36:

/* Line 1464 of yacc.c  */
#line 116 "multiC.y"
    { (yyval.pVal) = mknode(STMT, 0, 1, (yyvsp[(2) - (3)].pVal)); }
    break;

  case 37:

/* Line 1464 of yacc.c  */
#line 117 "multiC.y"
    { (yyval.pVal) = mknode(STMT, 0, 2, (yyvsp[(2) - (4)].pVal), (yyvsp[(3) - (4)].pVal)); }
    break;

  case 38:

/* Line 1464 of yacc.c  */
#line 120 "multiC.y"
    { (yyval.pVal) = mknode(IF, 0, 2, (yyvsp[(3) - (5)].pVal), (yyvsp[(5) - (5)].pVal)); }
    break;

  case 39:

/* Line 1464 of yacc.c  */
#line 121 "multiC.y"
    { (yyval.pVal) = mknode(IF, 0, 3, (yyvsp[(3) - (7)].pVal), (yyvsp[(5) - (7)].pVal), (yyvsp[(7) - (7)].pVal)); }
    break;

  case 40:

/* Line 1464 of yacc.c  */
#line 124 "multiC.y"
    { (yyval.pVal) = mknode(FOR, 0, 4, (yyvsp[(3) - (7)].pVal), (yyvsp[(4) - (7)].pVal), (yyvsp[(5) - (7)].pVal), (yyvsp[(7) - (7)].pVal)); }
    break;

  case 41:

/* Line 1464 of yacc.c  */
#line 125 "multiC.y"
    { (yyval.pVal) = mknode(WHILE, 0, 2, (yyvsp[(3) - (5)].pVal), (yyvsp[(5) - (5)].pVal)); }
    break;

  case 42:

/* Line 1464 of yacc.c  */
#line 126 "multiC.y"
    { (yyval.pVal) = mknode(DO, 0, 2, (yyvsp[(2) - (7)].pVal), (yyvsp[(5) - (7)].pVal)); }
    break;

  case 43:

/* Line 1464 of yacc.c  */
#line 129 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 44:

/* Line 1464 of yacc.c  */
#line 130 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 45:

/* Line 1464 of yacc.c  */
#line 133 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 46:

/* Line 1464 of yacc.c  */
#line 136 "multiC.y"
    { addSon((yyvsp[(1) - (2)].pVal), (yyvsp[(2) - (2)].pVal)); (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 47:

/* Line 1464 of yacc.c  */
#line 137 "multiC.y"
    { (yyval.pVal) = mknode(INPUT, 0, 1, (yyvsp[(2) - (2)].pVal)); }
    break;

  case 48:

/* Line 1464 of yacc.c  */
#line 140 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 49:

/* Line 1464 of yacc.c  */
#line 143 "multiC.y"
    { addSon((yyvsp[(1) - (2)].pVal), (yyvsp[(2) - (2)].pVal)); (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 50:

/* Line 1464 of yacc.c  */
#line 144 "multiC.y"
    { (yyval.pVal) = mknode(OUTPUT, 0, 1, (yyvsp[(2) - (2)].pVal)); }
    break;

  case 51:

/* Line 1464 of yacc.c  */
#line 147 "multiC.y"
    { addSon((yyvsp[(1) - (2)].pVal), (yyvsp[(2) - (2)].pVal)); (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 52:

/* Line 1464 of yacc.c  */
#line 148 "multiC.y"
    { (yyval.pVal) = mknode(VAR_DEC_LIST, 0, 1, (yyvsp[(1) - (1)].pVal)); }
    break;

  case 53:

/* Line 1464 of yacc.c  */
#line 151 "multiC.y"
    { (yyval.pVal) = mknode(VAR_DEC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(2) - (3)].pVal)); }
    break;

  case 54:

/* Line 1464 of yacc.c  */
#line 154 "multiC.y"
    { addBro((yyvsp[(1) - (5)].pVal), mknode(OP_ASSIGN, 0, 2, mkleaf(VAR, (int)(yyvsp[(3) - (5)].sVal)), (yyvsp[(5) - (5)].pVal))); (yyval.pVal) = (yyvsp[(1) - (5)].pVal); }
    break;

  case 55:

/* Line 1464 of yacc.c  */
#line 155 "multiC.y"
    { addBro((yyvsp[(1) - (3)].pVal), mkleaf(VAR, (int)(yyvsp[(3) - (3)].sVal))); (yyval.pVal) = (yyvsp[(1) - (3)].pVal); }
    break;

  case 56:

/* Line 1464 of yacc.c  */
#line 156 "multiC.y"
    { (yyval.pVal) = mknode(OP_ASSIGN, 0, 2, mkleaf(VAR, (int)(yyvsp[(1) - (3)].sVal)), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 57:

/* Line 1464 of yacc.c  */
#line 157 "multiC.y"
    { (yyval.pVal) = mkleaf(VAR, (int)(yyvsp[(1) - (1)].sVal)); }
    break;

  case 58:

/* Line 1464 of yacc.c  */
#line 160 "multiC.y"
    { (yyval.pVal) = mknode(OP_ASSIGN, 0, 2, (yyvsp[(1) - (4)].pVal), (yyvsp[(3) - (4)].pVal)); }
    break;

  case 59:

/* Line 1464 of yacc.c  */
#line 163 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (2)].pVal); }
    break;

  case 60:

/* Line 1464 of yacc.c  */
#line 166 "multiC.y"
    { addSon((yyvsp[(1) - (3)].pVal), mkleaf(VAR, (int)(yyvsp[(3) - (3)].sVal))); (yyval.pVal) = (yyvsp[(1) - (3)].pVal); }
    break;

  case 61:

/* Line 1464 of yacc.c  */
#line 167 "multiC.y"
    { (yyval.pVal) = mknode(VAR_LIST, 0, 1, mkleaf(VAR, (int)(yyvsp[(2) - (2)].sVal))); }
    break;

  case 62:

/* Line 1464 of yacc.c  */
#line 170 "multiC.y"
    { addBro((yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); (yyval.pVal) = (yyvsp[(1) - (3)].pVal); }
    break;

  case 63:

/* Line 1464 of yacc.c  */
#line 171 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 64:

/* Line 1464 of yacc.c  */
#line 174 "multiC.y"
    { (yyval.pVal) = mknode(OP_ASSIGN, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 65:

/* Line 1464 of yacc.c  */
#line 175 "multiC.y"
    { (yyval.pVal) = mknode(OP_ADD_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 66:

/* Line 1464 of yacc.c  */
#line 176 "multiC.y"
    { (yyval.pVal) = mknode(OP_SUB_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 67:

/* Line 1464 of yacc.c  */
#line 177 "multiC.y"
    { (yyval.pVal) = mknode(OP_MUL_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 68:

/* Line 1464 of yacc.c  */
#line 178 "multiC.y"
    { (yyval.pVal) = mknode(OP_DIV_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 69:

/* Line 1464 of yacc.c  */
#line 179 "multiC.y"
    { (yyval.pVal) = mknode(OP_MOD_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 70:

/* Line 1464 of yacc.c  */
#line 180 "multiC.y"
    { (yyval.pVal) = mknode(OP_BAND_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 71:

/* Line 1464 of yacc.c  */
#line 181 "multiC.y"
    { (yyval.pVal) = mknode(OP_BOR_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 72:

/* Line 1464 of yacc.c  */
#line 182 "multiC.y"
    { (yyval.pVal) = mknode(OP_BXOR_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 73:

/* Line 1464 of yacc.c  */
#line 183 "multiC.y"
    { (yyval.pVal) = mknode(OP_SHL_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 74:

/* Line 1464 of yacc.c  */
#line 184 "multiC.y"
    { (yyval.pVal) = mknode(OP_SHR_ACC, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 75:

/* Line 1464 of yacc.c  */
#line 185 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 76:

/* Line 1464 of yacc.c  */
#line 188 "multiC.y"
    { (yyval.pVal) = mknode(OP_L_OR, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 77:

/* Line 1464 of yacc.c  */
#line 189 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 78:

/* Line 1464 of yacc.c  */
#line 192 "multiC.y"
    { (yyval.pVal) = mknode(OP_L_AND, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 79:

/* Line 1464 of yacc.c  */
#line 193 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 80:

/* Line 1464 of yacc.c  */
#line 196 "multiC.y"
    { (yyval.pVal) = mknode(OP_B_OR, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 81:

/* Line 1464 of yacc.c  */
#line 197 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 82:

/* Line 1464 of yacc.c  */
#line 200 "multiC.y"
    { (yyval.pVal) = mknode(OP_B_XOR, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 83:

/* Line 1464 of yacc.c  */
#line 201 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 84:

/* Line 1464 of yacc.c  */
#line 204 "multiC.y"
    { (yyval.pVal) = mknode(OP_B_AND, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 85:

/* Line 1464 of yacc.c  */
#line 205 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 86:

/* Line 1464 of yacc.c  */
#line 208 "multiC.y"
    { (yyval.pVal) = mknode(OP_EQUAL, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 87:

/* Line 1464 of yacc.c  */
#line 209 "multiC.y"
    { (yyval.pVal) = mknode(OP_NEQUAL, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 88:

/* Line 1464 of yacc.c  */
#line 210 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 89:

/* Line 1464 of yacc.c  */
#line 213 "multiC.y"
    { (yyval.pVal) = mknode(OP_LESS, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 90:

/* Line 1464 of yacc.c  */
#line 214 "multiC.y"
    { (yyval.pVal) = mknode(OP_LESS_EQUAL, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 91:

/* Line 1464 of yacc.c  */
#line 215 "multiC.y"
    { (yyval.pVal) = mknode(OP_GREAT, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 92:

/* Line 1464 of yacc.c  */
#line 216 "multiC.y"
    { (yyval.pVal) = mknode(OP_GREAT_EQUAL, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 93:

/* Line 1464 of yacc.c  */
#line 217 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 94:

/* Line 1464 of yacc.c  */
#line 220 "multiC.y"
    { (yyval.pVal) = mknode(OP_SHL, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal));}
    break;

  case 95:

/* Line 1464 of yacc.c  */
#line 221 "multiC.y"
    { (yyval.pVal) = mknode(OP_SHR, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 96:

/* Line 1464 of yacc.c  */
#line 222 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal);}
    break;

  case 97:

/* Line 1464 of yacc.c  */
#line 225 "multiC.y"
    { (yyval.pVal) = mknode(OP_ADD, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 98:

/* Line 1464 of yacc.c  */
#line 226 "multiC.y"
    { (yyval.pVal) = mknode(OP_SUB, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 99:

/* Line 1464 of yacc.c  */
#line 227 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 100:

/* Line 1464 of yacc.c  */
#line 230 "multiC.y"
    { (yyval.pVal) = mknode(OP_MUL, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 101:

/* Line 1464 of yacc.c  */
#line 231 "multiC.y"
    { (yyval.pVal) = mknode(OP_DIV, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 102:

/* Line 1464 of yacc.c  */
#line 232 "multiC.y"
    { (yyval.pVal) = mknode(OP_MOD, 0, 2, (yyvsp[(1) - (3)].pVal), (yyvsp[(3) - (3)].pVal)); }
    break;

  case 103:

/* Line 1464 of yacc.c  */
#line 233 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 104:

/* Line 1464 of yacc.c  */
#line 236 "multiC.y"
    { (yyval.pVal) = mkleaf(INT, (yyvsp[(1) - (1)].iVal)); }
    break;

  case 105:

/* Line 1464 of yacc.c  */
#line 237 "multiC.y"
    { (yyval.pVal) = (yyvsp[(2) - (3)].pVal); }
    break;

  case 106:

/* Line 1464 of yacc.c  */
#line 238 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 107:

/* Line 1464 of yacc.c  */
#line 241 "multiC.y"
    { setKind((yyvsp[(1) - (4)].pVal), ID); (yyval.pVal) = mknode(FUNCTION, 0, 2, (yyvsp[(1) - (4)].pVal), (yyvsp[(3) - (4)].pVal)); }
    break;

  case 108:

/* Line 1464 of yacc.c  */
#line 242 "multiC.y"
    { setKind((yyvsp[(1) - (3)].pVal), ID); (yyval.pVal) = mknode(FUNCTION, 0, 1, (yyvsp[(1) - (3)].pVal)); }
    break;

  case 109:

/* Line 1464 of yacc.c  */
#line 243 "multiC.y"
    { (yyval.pVal) = (yyvsp[(1) - (1)].pVal); }
    break;

  case 110:

/* Line 1464 of yacc.c  */
#line 246 "multiC.y"
    { (yyval.pVal) = mkleaf(VAR, (int)(yyvsp[(1) - (1)].sVal)); }
    break;



/* Line 1464 of yacc.c  */
#line 2412 "y.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 248 "multiC.y"


int main() {
	CodeGenerator cg;
	yyparse();
	prtree(0, ASTRoot, 0);
	cg.generateCode("outCode.txt", *ASTRoot);
	printf("compile end\n");
	return 0;
}
