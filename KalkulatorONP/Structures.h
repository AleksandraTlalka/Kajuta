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

/**
 * Stuktura danych reprezentuj¹ca równanie przedstawione w odwrotnej notacji polskiej.
 */
struct Onp
{
	double value;			///< value of the number
	enum Type type;			///< type of the operator in the equation
	struct Onp* pPrev;		///< pointer to the previous unit in the equation
	struct Onp* pNext;		///< pointer to the next unit in the equation
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
