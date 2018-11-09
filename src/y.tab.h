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
    MIRROR = 265,
    MIRROR_LEVEL = 266,
    LIGHT = 267,
    INTENSITY = 268,
    POSITION = 269,
    LIGHT_C1 = 270,
    LIGHT_C2 = 271,
    LIGHT_C3 = 272,
    TEXTURE = 273,
    COLOR = 274,
    TEXTURE_FILE = 275,
    DIFFUSE_COEFFICIENT = 276,
    AMBIENT_LIGHTING_COEFFICIENT = 277,
    SPECULAR_COEFFICIENT = 278,
    STAIN_LEVEL_KN = 279,
    SPHERE = 280,
    RADIUS = 281,
    CENTER = 282,
    CYLINDER = 283,
    AXIS = 284,
    ANCHOR = 285,
    D1 = 286,
    D2 = 287,
    DISC = 288,
    CONE = 289,
    ELIPSE = 290,
    QUADRATIC_SURFACE = 291,
    POLYGON = 292,
    POINT = 293,
    BOOL = 294,
    CHAR = 295,
    SHORT = 296,
    INT = 297,
    LONG = 298,
    SIGNED = 299,
    UNSIGNED = 300,
    FLOAT = 301,
    DOUBLE = 302,
    VOID = 303
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
#define MIRROR 265
#define MIRROR_LEVEL 266
#define LIGHT 267
#define INTENSITY 268
#define POSITION 269
#define LIGHT_C1 270
#define LIGHT_C2 271
#define LIGHT_C3 272
#define TEXTURE 273
#define COLOR 274
#define TEXTURE_FILE 275
#define DIFFUSE_COEFFICIENT 276
#define AMBIENT_LIGHTING_COEFFICIENT 277
#define SPECULAR_COEFFICIENT 278
#define STAIN_LEVEL_KN 279
#define SPHERE 280
#define RADIUS 281
#define CENTER 282
#define CYLINDER 283
#define AXIS 284
#define ANCHOR 285
#define D1 286
#define D2 287
#define DISC 288
#define CONE 289
#define ELIPSE 290
#define QUADRATIC_SURFACE 291
#define POLYGON 292
#define POINT 293
#define BOOL 294
#define CHAR 295
#define SHORT 296
#define INT 297
#define LONG 298
#define SIGNED 299
#define UNSIGNED 300
#define FLOAT 301
#define DOUBLE 302
#define VOID 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
