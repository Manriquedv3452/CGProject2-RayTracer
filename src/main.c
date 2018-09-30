#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

int is_numeric(char character);
int verify_argument(char *argument);



int main(int argc, char *argv[])
{
	
	return 1;


}


//return -1 if the argument is invalid
//else return the integer value.
int verify_argument(char *argument){	

    for (int i = 0; argument[i] != '\0'; i++){
        if (!is_numeric(argument[i]))
            return -1;


    }
    return atoi(argument);

}

//return 0 (False) if a char is not numeric.
int is_numeric(char character){
	if (character >= 48 && character <= 57)
		return 1;

	return 0;
}

