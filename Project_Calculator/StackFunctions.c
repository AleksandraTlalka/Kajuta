#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "Constans.h"
#include "Structures.h"
#include "Functions.h"


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

struct Stack* addToStack(struct Stack* head, enum Type type, double prioryty)
{
	struct Stack* node = (struct Stack*)malloc(sizeof(struct Stack));
	node->type = type;
	node->prioryty = prioryty;
	node->pPrev = head;
	return node;
}

struct Stack* removeFromStack(struct Stack* pStack) {
	struct Stack* tmp = NULL;
	tmp = pStack->pPrev;
	free(pStack);
	pStack = NULL;
	return tmp;
}
