%e  1019
%p  2807
%n  371
%k  284
%a  1213
%o  1117

O   [0-7]
D   [0-9]
NZ  [1-9]
L   [a-zA-Z_]
A   [a-zA-Z_0-9]
H   [a-fA-F0-9]
HP  (0[xX])
E   ([Ee][+-]?{D}+)
P   ([Pp][+-]?{D}+)
FS  (f|F|l|L)
IS  (((u|U)(l|L|ll|LL)?)|((l|L|ll|LL)(u|U)?))
CP  (u|U|L)
SP  (u8|u|U|L)
ES  (\\(['"\?\\abfnrtv]|[0-7]{1,3}|x[a-fA-F0-9]+))
WS  [ \t\v\f]
EOL [\n]

%option noyywrap
%option yylineno

%{	#include <studio.h>

	#include "y.tab.h"
	#define MAXLEN 100

#define CNRM  "\x1B[0m"
#define CRED  "\x1B[31;1m"
#define CGRN  "\x1B[32;1m"
#define CYEL  "\x1B[33m"
#define CBLU  "\x1B[34m"
#define CMAG  "\x1B[35m"
#define CCYN  "\x1B[36m"
#define CWHT  "\x1B[0m"
#define CWHTN  "\x1B[1m"

extern void yyerror(const char *);  /* prints grammar violation message */
static void comment(void);
void count(void);


int previousColumn = 0;
int column = 0;
int cursorPos = 0;

%}


/*Taken from https://www.lysator.liu.se/c/ANSI-C-grammar-l.html*/
%%
"/*"                                    { comment(); }
"//".*                                  { column = 0; /* consume //-comment */ }
\n		{/*yylineno = ++lineNum;*/}
[ \t\v\f]	{/*DO NOTHING*/}


"textures/"{L}{A}*".avs"				{ return TEXTURE_FILE; }
{HP}{H}+{IS}?				{  return I_CONSTANT; }
{NZ}{D}*{IS}?				{  return I_CONSTANT; }
"0"{O}*{IS}?				{  return I_CONSTANT; }
{CP}?"'"([^'\\\n]|{ES})+"'"		{  return I_CONSTANT; }


"-"{HP}{H}+{IS}?				{  return I_CONSTANT; }
"-"{NZ}{D}*{IS}?				{  return I_CONSTANT; }
"-""0"{O}*{IS}?				{  return I_CONSTANT; }
"-"{CP}?"'"([^'\\\n]|{ES})+"'"		{  return I_CONSTANT; }


{D}+{E}{FS}?				{  return F_CONSTANT; }
{D}*"."{D}+{E}?{FS}?			{  return F_CONSTANT; }
{D}+"."{E}?{FS}?			{  return F_CONSTANT; }
{HP}{H}+{P}{FS}?			{  return F_CONSTANT; }
{HP}{H}*"."{H}+{P}{FS}?			{  return F_CONSTANT; }
{HP}{H}+"."{P}{FS}?			{ return F_CONSTANT; }

({SP}?\"([^"\\\n]|{ES})*.avs\"({WS}|{EOL})*)+	{ return STRING_LITERAL; }

"Scene"	{ return SCENE; }
"Light" { return LIGHT; }
"intensity" { return INTENSITY; }
"position" { return POSITION; }
"Sphere" { return SPHERE; }
"eye" { return EYE; }
"radius" { return RADIUS; }
"center" { return CENTER; }
"texture" { return TEXTURE; }
"color" {return COLOR; }
"diffuse_coefficient" {return DIFFUSE_COEFFICIENT; }
"ambient_lighting"	{ return AMBIENT_LIGHTING; }
"ambient_lighting_coefficient" {	return AMBIENT_LIGHTING_COEFFICIENT; }
"background"	{ return BACKGROUND; }
"c1" { return LIGHT_C1; }
"c2" { return LIGHT_C2; }
"c3" { return LIGHT_C3; }
"=" { return '='; }
";" { return ';'; }
"," { return ','; }
"(" { return '('; }
")" { return ')'; }
"{" { return '{'; }
"}" { return '}'; }
"[" { return '['; }
"]" { return ']'; }

{WS}+					{ }

({SP}?\"([^"\\\n]|{ES})*\"({WS}|{EOL})*)+	{ yyerror("SHOULD HAVE EXTENSION .avs"); }
. 			{ yyerror("LEXICAL ERROR"); }
%%


void yyerror(const char *s)
{
	printf("%sError%s in line %d: %s\n", CRED, CWHT, yylineno , s);
	exit(1);
}
static void comment(void)
{
	int c;

	while ((c = input()) != EOF)
	{
		cursorPos++;
		if (c == '*')
		{
			while ((c = input()) == '*')
			{
				cursorPos++;
			}

			cursorPos++;
			if (c == '/')
				return;

			if (c == EOF)
				break;
		}
	}
}


void count(void)
{
	previousColumn = column;

	int i;
	for (i = 0; yytext[i] != '\0'; i++)
	{
		if (yytext[i] == '\n')
			column = 0;
		else
			column++;

		cursorPos++;
	}

	//ECHO;
}


