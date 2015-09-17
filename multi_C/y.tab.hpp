/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* Line 1685 of yacc.c  */
#line 34 "multiC.y"

	struct _node* pVal;
	char cVal;
	int iVal;
	char *sVal;



/* Line 1685 of yacc.c  */
#line 130 "y.tab.hpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


