/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "ray_tracer.c"
#include "process_data.h"
#define FALSE 0
#define TRUE 1
void yyerror(const char *);
void yynote(char *noteInfo, int line, int column, int writeCode, int cursorPosi);
void yywarning(char *warningInfo, int line, int column, int writeCode, int cursorPosi);
extern int getToken(void);
extern char* yytext;
extern int yylineno;
extern int column;
extern int previousColumn;
extern void print(void);
extern int nextToken;
extern char* previousToken;
extern int cursorPos;
extern int previousTokenCode;
extern char* current_token;
extern int current_token_code;
#define yylex getToken
#define YYERROR_VERBOSE 1
int errorFound = FALSE;
int inContext = FALSE;
int unDecleared = FALSE;
int inFor = FALSE;
char* actualFunction = "";
int is_in_object = 0;
void end_expression(void);


#line 101 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
    VECTORG = 292,
    CONE = 293,
    ANGLE = 294,
    POLYGON = 295,
    POINT = 296,
    BOOL = 297,
    CHAR = 298,
    SHORT = 299,
    INT = 300,
    LONG = 301,
    SIGNED = 302,
    UNSIGNED = 303,
    FLOAT = 304,
    DOUBLE = 305,
    VOID = 306
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
#define VECTORG 292
#define CONE 293
#define ANGLE 294
#define POLYGON 295
#define POINT 296
#define BOOL 297
#define CHAR 298
#define SHORT 299
#define INT 300
#define LONG 301
#define SIGNED 302
#define UNSIGNED 303
#define FLOAT 304
#define DOUBLE 305
#define VOID 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 254 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   331

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  125
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  254

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    53,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    58,
       2,    55,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    52,     2,    54,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,    57,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    51,    51,    51,    52,    52,    53,    53,    54,    54,
      55,    55,    59,    60,    70,    71,    72,    70,    73,    74,
      75,    76,    77,    75,    81,    82,    83,    84,    86,    87,
      88,    86,    91,    92,    93,    91,    95,    95,    96,    97,
      95,    99,   100,   101,    99,   103,   104,   105,   103,   107,
     108,   109,   107,   111,   112,   113,   114,   115,   116,   117,
     121,   122,   123,   121,   125,   127,   128,   129,   127,   130,
     131,   132,   137,   141,   145,   149,   153,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   172,   176,   181,
     182,   186,   187,   192,   193,   198,   199,   199,   204,   205,
     205,   210,   211,   211,   216,   217,   221,   222,   226,   227,
     232,   236,   237,   242,   247,   249,   253,   255,   259,   261,
     265,   266,   270,   274,   274,   275
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "I_CONSTANT", "F_CONSTANT",
  "STRING_LITERAL", "SCENE", "EYE", "AMBIENT_LIGHTING", "BACKGROUND",
  "MIRROR", "MIRROR_LEVEL", "ANTIALIASING", "LIGHT", "INTENSITY",
  "POSITION", "LIGHT_C1", "LIGHT_C2", "LIGHT_C3", "TEXTURE", "COLOR",
  "TEXTURE_FILE", "DIFFUSE_COEFFICIENT", "AMBIENT_LIGHTING_COEFFICIENT",
  "SPECULAR_COEFFICIENT", "STAIN_LEVEL_KN", "SPHERE", "RADIUS", "CENTER",
  "CYLINDER", "AXIS", "ANCHOR", "D1", "D2", "DISC", "ELIPSE",
  "QUADRATIC_SURFACE", "VECTORG", "CONE", "ANGLE", "POLYGON", "POINT",
  "BOOL", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED", "FLOAT",
  "DOUBLE", "VOID", "'['", "','", "']'", "'='", "'{'", "'}'", "';'",
  "$accept", "object_expression", "$@1", "$@2", "$@3", "$@4", "$@5",
  "constant", "assignment_expression", "$@6", "$@7", "$@8", "$@9", "$@10",
  "$@11", "assignment_expression_object", "$@12", "$@13", "$@14", "$@15",
  "$@16", "$@17", "$@18", "$@19", "$@20", "$@21", "$@22", "$@23", "$@24",
  "$@25", "$@26", "$@27", "$@28", "$@29", "$@30",
  "assignment_expression_light", "$@31", "$@32", "$@33", "$@34", "$@35",
  "$@36", "assignment_operator", "expression", "expression_object",
  "expression_light", "declaration_specifiers", "type_specifier",
  "declarator", "direct_declarator", "statement", "statement_object",
  "statement_light", "compound_statement", "$@37",
  "compound_statement_object", "$@38", "compound_statement_light", "$@39",
  "block_item_list", "block_item", "block_item_list_object",
  "block_item_object", "block_item_list_light", "block_item_light",
  "expression_statement", "expression_statement_object",
  "expression_statement_light", "translation_unit", "external_declaration",
  "function_definition", "$@40", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    91,    44,    93,    61,   123,   125,    59
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -5,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,     0,   -59,   -47,   -59,     5,   -59,   -59,   -59,
     -38,   -59,   -59,   -59,   -47,   -59,   201,   -59,   -45,   -45,
     -45,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,     2,
     -59,   -59,   120,   -59,   -59,   -59,   -32,    14,   -31,   -34,
     -33,   -33,   -33,   -33,   -59,   -59,   -59,   -59,    14,   -59,
     -59,   -59,    14,   -28,   -59,   -26,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,    70,   -59,   275,   -21,   -20,   -45,   -45,
     -45,   -45,   -45,   -45,   -59,     6,   -59,   -59,    10,   -59,
     -59,   -59,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -59,   -59,     7,
     -59,   -59,   236,   -59,   -59,    14,    14,    14,   -18,    14,
      14,    14,   -17,   -59,   -59,   -59,   -59,    14,    15,    16,
      14,    14,    14,    14,    14,    18,    19,    25,    14,    14,
      26,    14,   -45,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
      14,   -59,   -59,   -59,    14,   -59,   -59,    14,   -59,   -59,
     -59,   -59,   -59,    14,    14,    14,   -59,   -59,    14,   -59,
      27,    29,    36,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
      14,    14,    14,    38,    40,    41,    42,    44,    45,    47,
     -59,   -59,   -59,    14,    14,    14,    14,    14,    14,    14,
      48,    49,    50,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
      14,   -59,   -59,    55,    56,    58,    59,    60,    61,    62,
     -59,    14,    14,    14,    14,    14,    14,    14,    63,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,    14,    64,    65,    66,
      67,    71,    80,    88,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,    89,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    88,    86,    78,    79,    80,    81,    84,    85,    82,
      83,    77,     0,    76,     0,    87,     0,   120,   122,   123,
      96,   125,     1,   121,     0,    95,     0,   124,     0,     0,
       0,    19,    10,     2,     6,     8,     4,   107,    73,     0,
     106,    89,     0,   104,    90,    72,     0,     0,     0,     0,
       0,     0,     0,     0,   115,   114,    97,   105,     0,    12,
      13,    18,     0,   102,    11,    99,     3,     7,     9,     5,
      14,    20,   101,     0,    98,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,     0,   113,    93,     0,   111,
      94,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    36,    74,     0,
     110,    91,     0,   108,    92,     0,     0,     0,     0,     0,
       0,     0,     0,   119,   118,   103,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,   116,   100,   109,    15,    21,    64,
       0,    69,    70,    71,     0,    59,    53,     0,    54,    55,
      56,    57,    24,     0,     0,     0,    26,    27,     0,    25,
       0,     0,     0,    60,    65,    41,    32,    45,    49,    28,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      37,    16,    22,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    61,    66,    42,    33,    46,    50,    29,
       0,    17,    23,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      67,    43,    34,    47,    51,    30,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    63,    68,    44,    35,    48,
      52,    31,     0,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -58,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
     -59,   -59,   101,   -59,   -59,   -59,   -59,   -59,    90,   -59,
     -59,   -59,   -59,   -12,   -59,   -37,   -59,    68,   -59,   -59,
     102,   -59,    33,   -59,    69,   -59,   -59,   -59,   -59,   131,
     -59,   -59
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    37,    50,    53,    51,    52,    49,    61,    38,    76,
     171,   201,    77,   172,   202,   108,   189,   219,   243,   186,
     216,   240,   142,   200,   228,   252,   185,   215,   239,   187,
     217,   241,   188,   218,   242,    84,   183,   213,   237,   184,
     214,   238,    46,    39,   109,    85,    12,    13,    14,    15,
      40,   110,    86,    41,    26,   111,    75,    87,    73,    42,
      43,   112,   113,    88,    89,    44,   114,    90,    16,    17,
      18,    24
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,     1,    21,    54,    71,    22,     1,   123,   143,    20,
      45,     1,    27,    66,    67,    68,    69,    59,    60,    25,
      58,    62,    63,    65,    78,    79,    80,    81,    82,    72,
      83,    74,   115,   116,   150,   154,   156,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,   147,   148,   149,
      55,   151,   152,   153,   124,   144,    63,   125,   157,   155,
     163,   164,   158,   159,   160,   161,   162,   165,   168,   180,
     166,   167,   181,   169,    78,    79,    80,    81,    82,   182,
      83,   193,   173,   194,   195,   196,   174,   197,   198,   175,
     199,   210,    19,   211,   212,   176,   177,   178,   221,   222,
     179,   223,   224,   225,   226,   227,   236,    64,   245,   246,
     247,   248,   190,   191,   192,   249,    63,    28,    29,    30,
      47,    48,    31,    32,   250,   203,   204,   205,   206,   207,
     208,   209,   251,   253,    57,   146,    33,    23,     0,    34,
       0,     0,   220,     0,     0,     0,     0,   126,    35,     0,
      36,     0,     0,   229,   230,   231,   232,   233,   234,   235,
       0,     0,     0,     0,     0,     0,    20,    56,   244,   117,
     118,   119,   120,   121,   122,     0,     0,     0,     0,     0,
       0,     0,     0,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,    28,    29,
      30,     0,     0,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    33,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,    36,     0,   170,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,    93,    94,    20,    95,    96,
      97,    98,     0,    99,   100,     0,   101,   102,   103,   104,
       0,     0,     0,   105,     0,   106,     0,   107,     0,     0,
       0,     0,     0,     0,     0,    91,    92,     0,     0,     0,
       0,     0,    65,   145,    93,    94,     0,    95,    96,    97,
      98,     0,    99,   100,     0,   101,   102,   103,   104,     0,
       0,     0,   105,     0,   106,     0,   107,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65
};

static const yytype_int16 yycheck[] =
{
      58,     6,    14,     1,    62,     0,     6,     1,     1,    56,
      55,     6,    24,    50,    51,    52,    53,     3,     4,    57,
      52,    52,    56,    56,    14,    15,    16,    17,    18,    57,
      20,    57,    53,    53,    52,    52,    21,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,   115,   116,   117,
      58,   119,   120,   121,    58,    58,    56,    57,    52,   127,
      52,    52,   130,   131,   132,   133,   134,    52,    52,    52,
     138,   139,    53,   141,    14,    15,    16,    17,    18,    53,
      20,    53,   150,    53,    53,    53,   154,    53,    53,   157,
      53,    53,    12,    54,    54,   163,   164,   165,    53,    53,
     168,    53,    53,    53,    53,    53,    53,    49,    54,    54,
      54,    54,   180,   181,   182,    54,    56,     7,     8,     9,
      29,    30,    12,    13,    54,   193,   194,   195,   196,   197,
     198,   199,    54,    54,    42,   112,    26,    16,    -1,    29,
      -1,    -1,   210,    -1,    -1,    -1,    -1,    88,    38,    -1,
      40,    -1,    -1,   221,   222,   223,   224,   225,   226,   227,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,   236,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,     7,     8,
       9,    -1,    -1,    12,    13,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    40,    -1,   142,    -1,    -1,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    56,    22,    23,
      24,    25,    -1,    27,    28,    -1,    30,    31,    32,    33,
      -1,    -1,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    10,    11,    -1,    -1,    -1,
      -1,    -1,    56,    57,    19,    20,    -1,    22,    23,    24,
      25,    -1,    27,    28,    -1,    30,    31,    32,    33,    -1,
      -1,    -1,    37,    -1,    39,    -1,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,   105,   106,   107,   108,   127,   128,   129,   107,
      56,   112,     0,   128,   130,    57,   113,   112,     7,     8,
       9,    12,    13,    26,    29,    38,    40,    60,    67,   102,
     109,   112,   118,   119,   124,    55,   101,   101,   101,    65,
      61,    63,    64,    62,     1,    58,    57,   119,    52,     3,
       4,    66,    52,    56,   116,    56,   114,   114,   114,   114,
      66,    66,    57,   117,    57,   115,    68,    71,    14,    15,
      16,    17,    18,    20,    94,   104,   111,   116,   122,   123,
     126,    10,    11,    19,    20,    22,    23,    24,    25,    27,
      28,    30,    31,    32,    33,    37,    39,    41,    74,   103,
     110,   114,   120,   121,   125,    53,    53,   101,   101,   101,
     101,   101,   101,     1,    58,    57,   123,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,    81,     1,    58,    57,   121,    66,    66,    66,
      52,    66,    66,    66,    52,    66,    21,    52,    66,    66,
      66,    66,    66,    52,    52,    52,    66,    66,    52,    66,
     101,    69,    72,    66,    66,    66,    66,    66,    66,    66,
      52,    53,    53,    95,    98,    85,    78,    88,    91,    75,
      66,    66,    66,    53,    53,    53,    53,    53,    53,    53,
      82,    70,    73,    66,    66,    66,    66,    66,    66,    66,
      53,    54,    54,    96,    99,    86,    79,    89,    92,    76,
      66,    53,    53,    53,    53,    53,    53,    53,    83,    66,
      66,    66,    66,    66,    66,    66,    53,    97,   100,    87,
      80,    90,    93,    77,    66,    54,    54,    54,    54,    54,
      54,    54,    84,    54
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    61,    60,    62,    60,    63,    60,    64,    60,
      65,    60,    66,    66,    68,    69,    70,    67,    67,    67,
      71,    72,    73,    67,    74,    74,    74,    74,    75,    76,
      77,    74,    78,    79,    80,    74,    81,    82,    83,    84,
      74,    85,    86,    87,    74,    88,    89,    90,    74,    91,
      92,    93,    74,    74,    74,    74,    74,    74,    74,    74,
      95,    96,    97,    94,    94,    98,    99,   100,    94,    94,
      94,    94,   101,   102,   103,   104,   105,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   108,   109,
     109,   110,   110,   111,   111,   112,   113,   112,   114,   115,
     114,   116,   117,   116,   118,   118,   119,   119,   120,   120,
     121,   122,   122,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   128,   130,   129,   129
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     3,     0,     3,     0,     3,
       0,     3,     1,     1,     0,     0,     0,    12,     3,     1,
       0,     0,     0,    12,     3,     3,     3,     3,     0,     0,
       0,    12,     0,     0,     0,    12,     0,     0,     0,     0,
      13,     0,     0,     0,    12,     0,     0,     0,    12,     0,
       0,     0,    12,     3,     3,     3,     3,     3,     1,     3,
       0,     0,     0,    12,     3,     0,     0,     0,    12,     3,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     0,     4,     2,     0,
       4,     2,     0,     4,     1,     2,     1,     1,     1,     2,
       1,     1,     2,     1,     2,     2,     2,     2,     2,     2,
       1,     2,     1,     0,     4,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 2:
#line 51 "bison.y" /* yacc.c:1646  */
    {is_in_object = 1; create_sphere(); create_object(SPHERE); }
#line 1544 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 51 "bison.y" /* yacc.c:1646  */
    { is_in_object = 0; process_object(SPHERE); insert_object(current_object, scene); }
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 52 "bison.y" /* yacc.c:1646  */
    {is_in_object = 1; create_polygon(); create_object(POLYGON); }
#line 1556 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 52 "bison.y" /* yacc.c:1646  */
    { is_in_object = 0; process_object(POLYGON); insert_object(current_object, scene); }
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 53 "bison.y" /* yacc.c:1646  */
    {is_in_object = 1; create_cylinder(); create_object(CYLINDER); }
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 53 "bison.y" /* yacc.c:1646  */
    { is_in_object = 0; process_object(CYLINDER); insert_object(current_object, scene); }
#line 1574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 54 "bison.y" /* yacc.c:1646  */
    {is_in_object = 1; create_cone(); create_object(CONE); }
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 54 "bison.y" /* yacc.c:1646  */
    {is_in_object = 0; process_object(CONE); insert_object(current_object, scene); }
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 55 "bison.y" /* yacc.c:1646  */
    { create_light(); }
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 55 "bison.y" /* yacc.c:1646  */
    { insert_light(light_aux, scene); }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 59 "bison.y" /* yacc.c:1646  */
    { }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 70 "bison.y" /* yacc.c:1646  */
    { load_scene_eye_x(current_token); }
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 71 "bison.y" /* yacc.c:1646  */
    { load_scene_eye_y(current_token); }
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 72 "bison.y" /* yacc.c:1646  */
    { load_scene_eye_z(current_token); }
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 73 "bison.y" /* yacc.c:1646  */
    { add_ambient_lighting(current_token); }
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 74 "bison.y" /* yacc.c:1646  */
    { activate_antialiasing(); }
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 75 "bison.y" /* yacc.c:1646  */
    { add_background_colorR(current_token); }
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 76 "bison.y" /* yacc.c:1646  */
    { add_background_colorG(current_token); }
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 77 "bison.y" /* yacc.c:1646  */
    { add_background_colorB(current_token); }
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 81 "bison.y" /* yacc.c:1646  */
    { add_object_radius(current_token); }
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 82 "bison.y" /* yacc.c:1646  */
    { add_cone_angle(current_token); }
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 83 "bison.y" /* yacc.c:1646  */
    { add_object_d1(current_token); }
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 84 "bison.y" /* yacc.c:1646  */
    { add_object_d2(current_token); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 86 "bison.y" /* yacc.c:1646  */
    { add_vectorG_x(current_token); }
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 87 "bison.y" /* yacc.c:1646  */
    {add_vectorG_y(current_token); }
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 88 "bison.y" /* yacc.c:1646  */
    {add_vectorG_z(current_token); }
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 91 "bison.y" /* yacc.c:1646  */
    { add_sphere_center_x(current_token); }
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 92 "bison.y" /* yacc.c:1646  */
    { add_sphere_center_y(current_token); }
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 93 "bison.y" /* yacc.c:1646  */
    { add_sphere_center_z(current_token); }
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 95 "bison.y" /* yacc.c:1646  */
    {create_new_point(); }
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 95 "bison.y" /* yacc.c:1646  */
    { add_polygon_point_x(current_token); }
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 96 "bison.y" /* yacc.c:1646  */
    { add_polygon_point_y(current_token); }
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 97 "bison.y" /* yacc.c:1646  */
    { add_polygon_point_z(current_token); }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 97 "bison.y" /* yacc.c:1646  */
    { insert_polygon_point(); }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 99 "bison.y" /* yacc.c:1646  */
    { load_object_colorR(current_token); }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 100 "bison.y" /* yacc.c:1646  */
    { load_object_colorG(current_token); }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 101 "bison.y" /* yacc.c:1646  */
    { load_object_colorB(current_token); }
#line 1760 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 103 "bison.y" /* yacc.c:1646  */
    { add_object_axis_x(current_token); }
#line 1766 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 104 "bison.y" /* yacc.c:1646  */
    { add_object_axis_y(current_token); }
#line 1772 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 105 "bison.y" /* yacc.c:1646  */
    { add_object_axis_z(current_token); }
#line 1778 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 107 "bison.y" /* yacc.c:1646  */
    { add_object_anchor_x(current_token); }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 108 "bison.y" /* yacc.c:1646  */
    { add_object_anchor_y(current_token); }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 109 "bison.y" /* yacc.c:1646  */
    { add_object_anchor_z(current_token); }
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 111 "bison.y" /* yacc.c:1646  */
    { load_object_texture(current_token); }
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 112 "bison.y" /* yacc.c:1646  */
    { add_diffuse_coefficient(current_token); }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 113 "bison.y" /* yacc.c:1646  */
    { add_ambient_lighting_coefficient(current_token); }
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 114 "bison.y" /* yacc.c:1646  */
    { add_specular_coefficient(current_token); }
#line 1820 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 115 "bison.y" /* yacc.c:1646  */
    { add_object_kn(current_token); }
#line 1826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 116 "bison.y" /* yacc.c:1646  */
    { activate_object_mirror(); }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 117 "bison.y" /* yacc.c:1646  */
    { add_mirror_level(current_token); }
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 121 "bison.y" /* yacc.c:1646  */
    { add_light_position_x(current_token); }
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 122 "bison.y" /* yacc.c:1646  */
    { add_light_position_y(current_token); }
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 123 "bison.y" /* yacc.c:1646  */
    { add_light_position_z(current_token); }
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 125 "bison.y" /* yacc.c:1646  */
    { add_light_intensity(current_token); }
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 127 "bison.y" /* yacc.c:1646  */
    { load_light_colorR(current_token); }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 128 "bison.y" /* yacc.c:1646  */
    { load_light_colorG(current_token); }
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 129 "bison.y" /* yacc.c:1646  */
    { load_light_colorB(current_token); }
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 130 "bison.y" /* yacc.c:1646  */
    { add_light_c1(current_token); }
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 131 "bison.y" /* yacc.c:1646  */
    { add_light_c2(current_token); }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 132 "bison.y" /* yacc.c:1646  */
    { add_light_c3(current_token); }
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 137 "bison.y" /* yacc.c:1646  */
    {}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 176 "bison.y" /* yacc.c:1646  */
    { create_scene(); }
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 199 "bison.y" /* yacc.c:1646  */
    { }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 199 "bison.y" /* yacc.c:1646  */
    { }
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 205 "bison.y" /* yacc.c:1646  */
    { }
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 205 "bison.y" /* yacc.c:1646  */
    { }
#line 1934 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 211 "bison.y" /* yacc.c:1646  */
    { }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 211 "bison.y" /* yacc.c:1646  */
    { }
#line 1946 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 247 "bison.y" /* yacc.c:1646  */
    {  }
#line 1952 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 249 "bison.y" /* yacc.c:1646  */
    {  yyerrok; }
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 253 "bison.y" /* yacc.c:1646  */
    {  }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 255 "bison.y" /* yacc.c:1646  */
    {  yyerrok; }
#line 1970 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 259 "bison.y" /* yacc.c:1646  */
    {  }
#line 1976 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 261 "bison.y" /* yacc.c:1646  */
    {  yyerrok; }
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 274 "bison.y" /* yacc.c:1646  */
    { }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 274 "bison.y" /* yacc.c:1646  */
    { ray_tracer();	 }
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 275 "bison.y" /* yacc.c:1646  */
    { printf("Doing Ray Tracing...\n"); ray_tracer(); }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2004 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  return yyresult;
}
#line 278 "bison.y" /* yacc.c:1906  */

#include "process_data.c"
