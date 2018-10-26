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
    BACKGROUND = 264,
    LIGHT = 265,
    INTENSITY = 266,
    POSITION = 267,
    LIGHT_C1 = 268,
    LIGHT_C2 = 269,
    LIGHT_C3 = 270,
    TEXTURE = 271,
    COLOR = 272,
    TEXTURE_FILE = 273,
    DIFFUSE_COEFFICIENT = 274,
    AMBIENT_LIGHTING_COEFFICIENT = 275,
    SPECULAR_COEFFICIENT = 276,
    STAIN_LEVEL_KN = 277,
    SPHERE = 278,
    RADIUS = 279,
    CENTER = 280,
    POLYGON = 281,
    POINT = 282,
    BOOL = 283,
    CHAR = 284,
    SHORT = 285,
    INT = 286,
    LONG = 287,
    SIGNED = 288,
    UNSIGNED = 289,
    FLOAT = 290,
    DOUBLE = 291,
    VOID = 292
  };
#endif
/* Tokens.  */
#define I_CONSTANT 258
#define F_CONSTANT 259
#define STRING_LITERAL 260
#define SCENE 261
#define EYE 262
#define AMBIENT_LIGHTING 263
#define BACKGROUND 264
#define LIGHT 265
#define INTENSITY 266
#define POSITION 267
#define LIGHT_C1 268
#define LIGHT_C2 269
#define LIGHT_C3 270
#define TEXTURE 271
#define COLOR 272
#define TEXTURE_FILE 273
#define DIFFUSE_COEFFICIENT 274
#define AMBIENT_LIGHTING_COEFFICIENT 275
#define SPECULAR_COEFFICIENT 276
#define STAIN_LEVEL_KN 277
#define SPHERE 278
#define RADIUS 279
#define CENTER 280
#define POLYGON 281
#define POINT 282
#define BOOL 283
#define CHAR 284
#define SHORT 285
#define INT 286
#define LONG 287
#define SIGNED 288
#define UNSIGNED 289
#define FLOAT 290
#define DOUBLE 291
#define VOID 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
