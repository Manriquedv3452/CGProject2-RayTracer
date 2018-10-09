#include <stdlib.h>
#include <stdio.h>

extern void ray_tracer(void);
extern int yyparse(void);
extern FILE* yyin;

int scanner(char* fileName);

char* tokenType;
FILE* FileTemp;

int scanner(char* fileName)
{
	FileTemp = fopen(fileName, "r");

	if (FileTemp != NULL){
		yyin = FileTemp;

		yyparse();
		//ray_tracer();
		fclose(FileTemp);
	}
	return 1;

}

