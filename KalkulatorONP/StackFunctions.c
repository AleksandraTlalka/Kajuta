#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "Constans.h"
#include "Structures.h"
#include "ConvertFunctions.h"
#include "StackFunctions.h"


struct Pair* stackAction(struct Stack* pStack, struct Onp* pTail, enum Type type)
{
	struct Pair* pair = NULL;
	int prioryty = getPriority(type);

	if (pStack != NULL) {
		if (prioryty == 0) {
			if (type == begin) {
				pStack = addToStack(pStack, type, prioryty);
			}
			else {
				while (pStack->prioryty != 0) {
					pTail = addToOnp(pTail, pStack->type, UNDEFINED);
					pStack = removeFromStack(pStack);
				}
				pStack = removeFromStack(pStack);
			}
		}
		else if (pStack->prioryty >= prioryty) {
			pair = modyfyStack(pStack, pTail, type);
		}
		else {
			pStack = addToStack(pStack, type, prioryty);
		}
	}
	else {
		pStack = addToStack(pStack, type, prioryty);
	}
	if (pair == NULL) {
		return addToPair(pTail, pStack);
	}
	else {
		return pair;
	}
}

struct Pair* modyfyStack(struct Stack* pStack, struct Onp* pTail, enum Type type) {
	int prioryty = getPriority(type);

	while (pStack != NULL && pStack->prioryty >= prioryty)
	{
		pTail = addToOnp(pTail, pStack->type, UNDEFINED);
		pStack = removeFromStack(pStack);
	}
	pStack = addToStack(pStack, type, prioryty);
	return addToPair(pTail, pStack);
}

struct Stack* addToStack(struct Stack* pStack, enum Type type, double prioryty)
{
	struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack));
	node->type = type;
	node->prioryty = prioryty;
	node->pPrev = pStack;
	return node;
}

struct Onp* emptyStack(struct Onp* pTail, struct Stack* pStack) {
	while (pStack != NULL) {
		pTail = addToOnp(pTail, pStack->type, UNDEFINED);
		pStack = removeFromStack(pStack);
	}
	return pTail;
}

struct Stack* removeFromStack(struct Stack* pStack) {
	struct Stack* tmp = NULL;
	tmp = pStack->pPrev;
	free(pStack);
	pStack = NULL;
	return tmp;
}
