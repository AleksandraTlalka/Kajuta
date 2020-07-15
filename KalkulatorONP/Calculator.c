#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Constans.h"
#include "Structures.h"
#include "ConvertFunctions.h"
#include "StackFunctions.h"
#include "Calculator.h"



double calculator(struct Onp* pHead) {
	struct Stack* stack = NULL;
	struct Stack* tmp = NULL;
	double result = 0;

	while (pHead != NULL) {
		if (pHead->type == number) {
			stack = addToStack(stack, number, pHead->value);
		}
		else if (stack != NULL && pHead->type > MULTI_ARGUMENTS) {
			result = getSingleResult(pHead->type, stack->prioryty);
			stack->prioryty = result;
		}
		else if (stack != NULL && stack->pPrev != NULL) {
			result = getMultiResult(pHead->type, stack->prioryty, stack->pPrev->prioryty);
			tmp = stack->pPrev;
			free(stack);
			stack = tmp;
			stack->prioryty = result;
		}
		pHead = pHead->pNext;
	}
	if (stack != NULL) {
		result = stack->prioryty;
	}
	free(stack);
	return result;
}

double getMultiResult(enum Type type, double head, double prev) {
	switch (type)
	{
	case dot: return prev + getFraction(head);
	case plus: return prev + head;
	case minus: return prev - head;
	case mulipy: return prev * head;
	case divide: return prev / head;
	case power: return pow(prev, head);
	}
}

double getSingleResult(enum Type type, double head) {
	switch (type)
	{
	case percentage: return head / 100;
	case sinus: return sin(head);
	case cosinus: return cos(head);
	case logarithm: return log(head);
	case negation: return -head;
	}
}

void FreeMemory(struct Onp* pHead, char* input) {
	freeOnp(pHead);
	pHead = NULL;
	free(input);
}