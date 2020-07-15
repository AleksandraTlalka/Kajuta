#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "Constans.h"
#include "Structures.h"
#include "Functions.h"


struct Onp* onpBuilder(double result, char* input, bool rewrite) {
	struct Onp* pTail = NULL;
	struct Stack* stack = NULL;
	struct Pair* pair = NULL;

	enum Type type = number;
	int numberIndex = 0;
	bool toStop = false;
	bool toClear = false;

	if (rewrite) {
		pTail = addToOnp(pTail, number, result);
		numberIndex++;
	}
	for (int i = 0; input[i] != 0; i++)
	{
		if (isdigit(input[i])) {
			if (numberIndex == 0) {
				pTail = addToOnp(pTail, number, charToDigit(input[i]));
				numberIndex++;
			}
			else
			{
				pTail->value = pTail->value * 10 + charToDigit(input[i]);
			}
		}
		else
		{
			numberIndex = 0;
			if (!isspace(input[i])) {
				type = getType(input[i]);

				if (type == unn) {
					printf("\nError: Wrong operator!\n\n");
					toClear = true;
					break;
				}
				else if (type == clear) {
					printf("\n");
					toClear = true;
					break;
				}
				else if (type == done) {
					printf("\nCalculator is quiting!\n");
					toStop = true;
					break;
				}
				else
				{
					i = i + strlen(getOperation(type)) - 1;
					pair = stackAction(stack, pTail, type);
					stack = pair->pStack;
					pTail = pair->pOnp;
					free(pair);
				}
			}
		}
	}

	while (stack != NULL) {
		pTail = addToOnp(pTail, stack->type, UNDEFINED);
		stack = removeFromStack(stack);
	}

	return stateControl(pTail, toClear, toStop);
}

struct Onp* addToOnp(struct Onp* pTail, enum Type type, double value)
{
	struct Onp* node = (struct Onp*)malloc(sizeof(struct Onp));
	node->type = type;
	node->value = value;
	node->pPrev = pTail;
	node->pNext = NULL;

	if (pTail != NULL) {
		pTail->pNext = node;
	}
	return node;
}

struct Pair* addToPair(struct Onp* pTail, struct Stack* pStack)
{
	struct Pair* pair = (struct Pair*)malloc(sizeof(struct Pair));
	pair->pOnp = pTail;
	pair->pStack = pStack;
	return pair;
}

struct Onp* findOnpHead(struct Onp* pTail) {
	while (pTail != NULL && pTail->pPrev != NULL) {
		pTail = pTail->pPrev;
	}
	return pTail;
}

struct Onp* stateControl(struct Onp* pTail, bool toClear, bool toStop) {
	if (toStop == true) {
		pTail = findOnpHead(pTail);
		if (pTail != NULL) {
			pTail->type = done;
		}
		else {
			pTail = addToOnp(pTail, done, UNDEFINED);
		}
		return pTail;
	}
	else if (toClear == true) {
		pTail = findOnpHead(pTail);
		if (pTail != NULL) {
			pTail->type = clear;
		}
		else {
			pTail = addToOnp(pTail, clear, UNDEFINED);
		}
		return pTail;
	}
	else {
		return findOnpHead(pTail);
	}
}

void freeOnp(struct Onp* pHead) {
	struct Onp* tmp = NULL;
	while (pHead != NULL) {
		tmp = pHead->pNext;
		free(pHead);
		pHead = tmp;
	}
}
