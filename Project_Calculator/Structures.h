#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

typedef enum {
	false,
	true
} bool;

enum Type
{
	number, dot, begin, end, plus, minus, mulipy, divide, power, percentage, sinus, cosinus, logarithm, negation, clear, done, unn
};

struct Onp
{
	double value;
	enum Type type;
	struct Onp* pPrev;
	struct Onp* pNext;
};

struct Stack {
	double prioryty;
	enum Type type;
	struct Stack* pPrev;
};

struct Pair {
	struct Stack* pStack;
	struct Onp* pOnp;
};

#endif STRUCTURE_H
