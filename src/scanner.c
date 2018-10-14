#include <stdlib.h>
#include <stdio.h>

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
		printf("Reading and interpreting design...\n");
		yyparse();
		fclose(FileTemp);
	}
	return 1;

}

