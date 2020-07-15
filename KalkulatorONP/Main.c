#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <vld.h>

#include "Constans.h"
#include "Structures.h"
#include "Functions.h"


int main(int argc, char* argv[]) {
	char* input;
	double result = 0;
	bool started = false;
	bool rewrite = false;

	manual();
	if (argv[1] == NULL) {
		input = getUserInput();
	}
	else {
		input = getUserChoice(argv[1]);
		printf("\n Entered exuation: %s\n", input);
	}
	for (;;) {
		if (started==true) {
			input = getUserInput();
		}
		divideByZero(input);
		struct Onp* pHead = onpBuilder(result, input, rewrite);
		started = true;
		rewrite = true;

		if (pHead->type == done) {
			FreeMemory(pHead, input);
			break;
		}
		else if (pHead->type == clear) {
			manual();
			rewrite = false;
		}
		else {
			printOnp(pHead);
			addOnpToFile(pHead);
			result = calculator(pHead);
			printf("\n Result:%5.2f \n", result);
			addResultToFile(result);
			manual();
			printf("%5.2f", result);
		}
		FreeMemory(pHead, input);
	}
	//Memory leak detector:
	_CrtDumpMemoryLeaks();
	return 0;
}