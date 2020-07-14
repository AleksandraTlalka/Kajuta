#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>

#include "Constans.h"
#include "Structures.h"
#include "Functions.h"


char* getUserInput() {
	char input[INPUT_SIZE];
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
	printf("1. Calcutaror allows commands: '+','-','^','*','/','N'(negation),'ln','sin','cos' and decimal floating-point numbers\n");
	printf("3. To clear already existing numbers and commands press 'C'\n");
	printf("3. To exit calculator press 'E'\n");
	printf("\nEnter the equation\n");
}