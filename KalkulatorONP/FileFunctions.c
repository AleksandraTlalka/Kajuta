#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Constans.h"
#include "Structures.h"
#include "Functions.h"


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