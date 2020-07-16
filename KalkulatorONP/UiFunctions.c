#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Constans.h"
#include "Structures.h"
#include "FileFunctions.h"
#include "UiFunctions.h"
#include "ConvertFunctions.h"


char* getUserChoice(char* argv) {
	char* input;
	printf("\n If you just entered the flie name press F, if else please press any other button\n");
	if (getc(stdin) == 'F') {
		input = readFile(argv);
	}
	else {
		input = _strdup(argv);
	}
	return input;
}

char* getUserInput() {
	char input[INPUT_SIZE];
	fseek(stdin, 0, SEEK_END);
	gets(input);
	return _strdup(input);
}

void printOnp(struct Onp* pHead) {
	while (pHead != NULL) {
		if (pHead->type == number) {
			printf(" > %5.2f", pHead->value);
		}
		else {
			printf(" > %s", getOperation(pHead->type));
		}
		pHead = pHead->pNext;
	}
}

void manual() {
	printf("\nCalcuator manual:\n");
	printf("1. Calcutaror allows commands: '(',')','+','-','^','*','/','N'(negation),'%%','ln','sin','cos' and decimal floating-point numbers\n");
	printf("3. To clear already existing numbers and commands press 'C'\n");
	printf("3. To exit calculator press 'E'\n");
	printf("\nEnter the equation\n");
}

void divideByZero(char* input) {
	char* tmp, *tmp2;
	tmp = strstr(input, "/0");
	if (tmp != NULL) {
		if (strncmp(tmp, "/0.", 3) != 0 && strncmp(tmp, "/0,", 3) != 0) {
			printf("\nError: You shouldn't try to divide by 0!\n");
		}
	}
}