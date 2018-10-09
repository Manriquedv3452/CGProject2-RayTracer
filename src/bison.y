%{

/* Taken from http://www.quut.com/c/ANSI-C-grammar-y.html*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
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

#define yylex getToken
#define YYERROR_VERBOSE 1

int errorFound = FALSE;
int inContext = FALSE;
int unDecleared = FALSE;
int inFor = FALSE;
char* actualFunction = "";
int current_token;
int is_in_object = 0;


%}
%token	I_CONSTANT F_CONSTANT STRING_LITERAL 
%token 	SCENE EYE
%token 	TEXTURE COLOR
%token  SPHERE RADIUS CENTER

%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID

%start translation_unit
%%

primary_expression
	: TEXTURE		
	;

vector_expression
	: EYE {if (is_in_object){yyerror("");}}
	;

object_expression
	: SPHERE {is_in_object = 1; } compound_statement { is_in_object = 0; };
	;

constant
	: I_CONSTANT		{ }/* includes character_constant */
	| F_CONSTANT
	;


string
	: STRING_LITERAL
	;	


postfix_expression
	: primary_expression 				{ yyerrok; }
	;


unary_expression
	: postfix_expression							{ yyerrok; }
	;	


assignment_expression
	: unary_expression assignment_operator constant {}
	| vector_expression assignment_operator '[' constant ',' constant ',' constant ']' 
	| unary_expression assignment_operator string
	;

assignment_operator
	: '=' {}
	;

expression
	: assignment_expression	 
	;

declaration_specifiers
	: type_specifier
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| BOOL
	;



declarator
	: direct_declarator
	;

direct_declarator
	: SCENE 
	;


statement
	: compound_statement
	| expression_statement				
	;


compound_statement
	: '{' '}'
	| '{' { } block_item_list '}' { }
	//| '{'  error					{ yyerrok; }
	;

block_item_list
	: block_item
	| block_item_list block_item						
	;	

block_item
	: statement
	| object_expression
	;

expression_statement
	: expression ';' 		{  }
	//| error ';'		       { yyerrok; }//err
	| expression error 		{  yyerrok; }
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	;

function_definition
	: declaration_specifiers declarator { }  compound_statement { }	
	| declarator  compound_statement 			
	;

%%

#include "process_data.h"

