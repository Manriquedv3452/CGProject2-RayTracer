/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    I_CONSTANT = 258,
    F_CONSTANT = 259,
    STRING_LITERAL = 260,
    SCENE = 261,
    EYE = 262,
    AMBIENT_LIGHTING = 263,
    LIGHT = 264,
    INTENSITY = 265,
    POSITION = 266,
    LIGHT_C1 = 267,
    LIGHT_C2 = 268,
    LIGHT_C3 = 269,
    TEXTURE = 270,
    COLOR = 271,
    TEXTURE_FILE = 272,
    DIFFUSE_COEFFICIENT = 273,
    AMBIENT_LIGHTING_COEFFICIENT = 274,
    SPHERE = 275,
    RADIUS = 276,
    CENTER = 277,
    BOOL = 278,
    CHAR = 279,
    SHORT = 280,
    INT = 281,
    LONG = 282,
    SIGNED = 283,
    UNSIGNED = 284,
    FLOAT = 285,
    DOUBLE = 286,
    VOID = 287
  };
#endif
/* Tokens.  */
#define I_CONSTANT 258
#define F_CONSTANT 259
#define STRING_LITERAL 260
#define SCENE 261
#define EYE 262
#define AMBIENT_LIGHTING 263
#define LIGHT 264
#define INTENSITY 265
#define POSITION 266
#define LIGHT_C1 267
#define LIGHT_C2 268
#define LIGHT_C3 269
#define TEXTURE 270
#define COLOR 271
#define TEXTURE_FILE 272
#define DIFFUSE_COEFFICIENT 273
#define AMBIENT_LIGHTING_COEFFICIENT 274
#define SPHERE 275
#define RADIUS 276
#define CENTER 277
#define BOOL 278
#define CHAR 279
#define SHORT 280
#define INT 281
#define LONG 282
#define SIGNED 283
#define UNSIGNED 284
#define FLOAT 285
#define DOUBLE 286
#define VOID 287

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
