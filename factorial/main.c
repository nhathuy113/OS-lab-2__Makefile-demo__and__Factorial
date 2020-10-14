#include <stdio.h>
#include <stdbool.h>

#include "factorial.h"

int main() { printf("\n============\n");
	// question 1
	int input;
	printf("Input: ");
	scanf("%d", &input);
	factorial(input);
	
	// make console wait for any key pressed before exit
	int inputstream;
	do {
		inputstream = getchar();
	}
	while(inputstream != '\n' && inputstream != EOF);
    printf("\n\nPress ENTER key to Continue ...");
    getchar();
	
	return 0;
}