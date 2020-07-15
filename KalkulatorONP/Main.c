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
		started = true;

		struct Onp* pHead = onpBuilder(result, input, rewrite);
		rewrite = true;

		if (pHead->type == done) {
			freeOnp(pHead);
			pHead = NULL;
			free(input);
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
			printf("\nResult:%5.2f\n", result);
			addResultToFile(result);
			manual();
			printf("%5.2f", result);
		}
		freeOnp(pHead);
		pHead = NULL;
		free(input);
	}
	//Memory leak detector:
	_CrtDumpMemoryLeaks();
	return 0;
}