#include <stdlib.h>
#include <stdio.h>

#include "factorial.h"

char* factorial(const int aNumber) {
	// init array
	char* result = (char*)malloc(aNumber*3*sizeof(char));
	result[0] = 1;

	// init fire_control
	int _length = 1;

	// start calculating
	for (int multiplier=2; multiplier <= aNumber; multiplier++) {
		
		_length = multiply(multiplier, result, _length);

		// debug
		// printf("* %d => ", multiplier);
		// debug_print(result, _length, 0);
		// debug
	}
	if ( aNumber < 20 ) {
		printf("   Final result: ");
		debug_print(result, _length, 1);
	}
	else {
		debug_print(result, _length, 2);
	}
}


int multiply(int multiplier, char* result, int _size)  { 
    int carry = 0;  // Initialize carry 
    int product;
  
    // One by one multiply n with individual digits of result[] 
    for (int i=0; i<_size; i++) { 
        product = (int)result[i] * multiplier + carry; 
  
        // Store last digit of 'product' in result[]   
        result[i] = (char)(product % 10);
  
        // Put rest in carry 
        carry  = product / 10;     
    } 
  
    // Put carry in res and increase result size 
    while (carry) { 
        result[_size] = (char)(carry % 10); 
        carry = carry / 10; 
        _size++; 
    } 
    return _size; 
} 
  


void debug_print(char* array, int _length, int flag) {
	if (flag == 0) {
		printf("[ ");
		for (int i=0; i < _length; i++) {
			printf("%d ", array[i]);
		}
		printf("]\n\n");
	}

	if (flag == 1) {
		for (int i = _length-1 ; i >= 0 ; i--) {
			printf("%d", array[i]);
			if (i % 3 == 0) printf(" ");
		}
	}

	if (flag == 2) {
		int number_of_digits = 4;
		printf("%d.", array[_length-1]);

		for (int i = _length-2 ; i >= _length-5 ; i--) {
			printf("%d", array[i]);
		}

		for (int i = _length-6 ; i > 0 ; i--) {
			number_of_digits++;
		}
		printf("E+%d", number_of_digits);

	}
}