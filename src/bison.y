%{
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
%}
%token	I_CONSTANT F_CONSTANT STRING_LITERAL
%token 	SCENE EYE AMBIENT_LIGHTING BACKGROUND
%token	LIGHT INTENSITY POSITION LIGHT_C1 LIGHT_C2 LIGHT_C3
%token 	TEXTURE COLOR TEXTURE_FILE DIFFUSE_COEFFICIENT AMBIENT_LIGHTING_COEFFICIENT SPECULAR_COEFFICIENT STAIN_LEVEL_KN
%token  SPHERE RADIUS CENTER
%token  POLYGON POINT

%token	BOOL CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE VOID

%start translation_unit
%%

object_expression
	: SPHERE {is_in_object = 1; create_sphere(); create_object(SPHERE); } compound_statement_object { is_in_object = 0; process_object(SPHERE); insert_object(current_object, scene); };
	| POLYGON {is_in_object = 1; create_polygon(); create_object(POLYGON); } compound_statement_object { is_in_object = 0; process_object(POLYGON); insert_object(current_object, scene); };
	| LIGHT { create_light(); } compound_statement_light { insert_light(light_aux, scene); }
	;

constant
	: I_CONSTANT		{ }/* includes character_constant */
	| F_CONSTANT
	;


/*string
	: STRING_LITERAL
	;	*/


assignment_expression
	: EYE assignment_operator '[' constant { load_scene_eye_x(current_token); }
							  ',' constant { load_scene_eye_y(current_token); }
							  ',' constant { load_scene_eye_z(current_token); } ']'
	| AMBIENT_LIGHTING assignment_operator constant { add_ambient_lighting(current_token); }
	| BACKGROUND assignment_operator '[' constant { add_background_colorR(current_token); } ','
										 constant { add_background_colorG(current_token); } ','
										 constant { add_background_colorB(current_token); } ']'
	;

assignment_expression_object
	: RADIUS assignment_operator constant { add_sphere_radius(current_token); }
	| CENTER assignment_operator '[' constant { add_sphere_center_x(current_token); }
								 ',' constant { add_sphere_center_y(current_token); }
								 ',' constant { add_sphere_center_z(current_token); } ']'

	| POINT assignment_operator '[' constant { add_polygon_point_x(current_token); }
								 ',' constant { add_polygon_point_y(current_token); }
								 ',' constant { add_polygon_point_z(current_token); } ']'

	| COLOR assignment_operator '[' constant { load_object_colorR(current_token); }
								 ',' constant { load_object_colorG(current_token); }
								 ',' constant { load_object_colorB(current_token); }  ']'

	| TEXTURE assignment_operator TEXTURE_FILE { load_object_texture(current_token); }
	| DIFFUSE_COEFFICIENT assignment_operator constant { add_diffuse_coefficient(current_token); }
	| AMBIENT_LIGHTING_COEFFICIENT assignment_operator constant { add_ambient_lighting_coefficient(current_token); }
	| SPECULAR_COEFFICIENT assignment_operator constant{ add_specular_coefficient(current_token); }
	| STAIN_LEVEL_KN assignment_operator constant { add_object_kn(current_token); }
	;

assignment_expression_light
	: POSITION assignment_operator '[' constant { add_light_position_x(current_token); }
								 ',' constant { add_light_position_y(current_token); }
								 ',' constant { add_light_position_z(current_token); } ']'

	| INTENSITY assignment_operator constant { add_light_intensity(current_token); }

	| COLOR assignment_operator '[' constant { load_light_colorR(current_token); }
								 ',' constant { load_light_colorG(current_token); }
								 ',' constant { load_light_colorB(current_token); }  ']'
	| LIGHT_C1 assignment_operator constant { add_light_c1(current_token); }
	| LIGHT_C2 assignment_operator constant { add_light_c2(current_token); }
	| LIGHT_C3 assignment_operator constant { add_light_c3(current_token); }
	;


assignment_operator
	: '=' {}
	;

expression
	: assignment_expression
	;

expression_object
	: assignment_expression_object
	;

expression_light
	: assignment_expression_light
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
	: SCENE { create_scene(); }
	;


statement
	: compound_statement
	| expression_statement
	;

statement_object
	: compound_statement_object
	| expression_statement_object
	;


statement_light
	: compound_statement_light
	| expression_statement_light
	;


compound_statement
	: '{' '}'
	| '{' { } block_item_list '}' { }
	//| '{'  error					{ yyerrok; }
	;

compound_statement_object
	: '{' '}'
	| '{' { } block_item_list_object '}' { }
	//| '{'  error					{ yyerrok; }
	;

compound_statement_light
	: '{' '}'
	| '{' { } block_item_list_light '}' { }
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

block_item_list_object
	: block_item_object
	| block_item_list_object block_item_object
	;


block_item_object
	: statement_object
	;

block_item_list_light
	: block_item_light
	| block_item_list_light block_item_light
	;


block_item_light
	: statement_light
	;


expression_statement
	: expression ';' 		{  }
	//| error ';'		       { yyerrok; }//err
	| expression error 		{  yyerrok; }
	;

expression_statement_object
	: expression_object ';' 		{  }
	//| error ';'		       { yyerrok; }//err
	| expression_object error 		{  yyerrok; }
	;

expression_statement_light
	: expression_light ';' 		{  }
	//| error ';'		       { yyerrok; }//err
	| expression_light error 		{  yyerrok; }
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	;

function_definition
	: declaration_specifiers declarator { }  compound_statement { ray_tracer();	 }
	| declarator  compound_statement { printf("Doing Ray Tracing...\n"); ray_tracer(); }
	;

%%
#include "process_data.c"
