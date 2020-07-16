#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Constans.h"
#include "Structures.h"
#include "FileFunctions.h"
#include "UiFunctions.h"
#include "ConvertFunctions.h"

char* readFile(char* argv1) {
	char input[INPUT_SIZE];
	char name[INPUT_SIZE];
	int i = 0;
	char c;
	
	strcpy(name, argv1);
	FILE* plik = fopen(name, "r");
	if (plik)
	{
		fgets(input,100,plik);
		fclose(plik);
		return _strdup(input);
	}
	else {
		printf("Error: Can't find the file. Please enter the equation manualy\n");
		return getUserInput();
	}
}


void addResultToFile(double result) {
	FILE* plik = fopen("history.txt", "a");
	if (plik)
	{
		fprintf(plik, "\t=%5.2f\n", result);
		fclose(plik);
	}
}

void addOnpToFile(struct Onp* pHead) {
	FILE* plik = fopen("history.txt", "a");
	if (plik)
	{
		while (pHead != NULL) {
			if (pHead->type == number) {
				fprintf(plik, " > %5.2f", pHead->value);
			}
			else {
				fprintf(plik, " > %s", getOperation(pHead->type));
			}
			pHead = pHead->pNext;
		}
		fclose(plik);
	}
}