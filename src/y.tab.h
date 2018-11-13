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
    ANTIALIASING = 267,
    LIGHT = 268,
    INTENSITY = 269,
    POSITION = 270,
    LIGHT_C1 = 271,
    LIGHT_C2 = 272,
    LIGHT_C3 = 273,
    TEXTURE = 274,
    COLOR = 275,
    TEXTURE_FILE = 276,
    DIFFUSE_COEFFICIENT = 277,
    AMBIENT_LIGHTING_COEFFICIENT = 278,
    SPECULAR_COEFFICIENT = 279,
    STAIN_LEVEL_KN = 280,
    SPHERE = 281,
    RADIUS = 282,
    CENTER = 283,
    CYLINDER = 284,
    AXIS = 285,
    ANCHOR = 286,
    D1 = 287,
    D2 = 288,
    DISC = 289,
    ELIPSE = 290,
    QUADRATIC_SURFACE = 291,
    CONE = 292,
    ANGLE = 293,
    POLYGON = 294,
    POINT = 295,
    BOOL = 296,
    CHAR = 297,
    SHORT = 298,
    INT = 299,
    LONG = 300,
    SIGNED = 301,
    UNSIGNED = 302,
    FLOAT = 303,
    DOUBLE = 304,
    VOID = 305
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
#define ANTIALIASING 267
#define LIGHT 268
#define INTENSITY 269
#define POSITION 270
#define LIGHT_C1 271
#define LIGHT_C2 272
#define LIGHT_C3 273
#define TEXTURE 274
#define COLOR 275
#define TEXTURE_FILE 276
#define DIFFUSE_COEFFICIENT 277
#define AMBIENT_LIGHTING_COEFFICIENT 278
#define SPECULAR_COEFFICIENT 279
#define STAIN_LEVEL_KN 280
#define SPHERE 281
#define RADIUS 282
#define CENTER 283
#define CYLINDER 284
#define AXIS 285
#define ANCHOR 286
#define D1 287
#define D2 288
#define DISC 289
#define ELIPSE 290
#define QUADRATIC_SURFACE 291
#define CONE 292
#define ANGLE 293
#define POLYGON 294
#define POINT 295
#define BOOL 296
#define CHAR 297
#define SHORT 298
#define INT 299
#define LONG 300
#define SIGNED 301
#define UNSIGNED 302
#define FLOAT 303
#define DOUBLE 304
#define VOID 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
