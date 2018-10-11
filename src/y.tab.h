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
    TEXTURE = 267,
    COLOR = 268,
    TEXTURE_FILE = 269,
    DIFFUSE_COEFFICIENT = 270,
    AMBIENT_LIGHTING_COEFFICIENT = 271,
    SPHERE = 272,
    RADIUS = 273,
    CENTER = 274,
    BOOL = 275,
    CHAR = 276,
    SHORT = 277,
    INT = 278,
    LONG = 279,
    SIGNED = 280,
    UNSIGNED = 281,
    FLOAT = 282,
    DOUBLE = 283,
    VOID = 284
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
#define TEXTURE 267
#define COLOR 268
#define TEXTURE_FILE 269
#define DIFFUSE_COEFFICIENT 270
#define AMBIENT_LIGHTING_COEFFICIENT 271
#define SPHERE 272
#define RADIUS 273
#define CENTER 274
#define BOOL 275
#define CHAR 276
#define SHORT 277
#define INT 278
#define LONG 279
#define SIGNED 280
#define UNSIGNED 281
#define FLOAT 282
#define DOUBLE 283
#define VOID 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
