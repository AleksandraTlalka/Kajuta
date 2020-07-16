#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>


/**
 * Typy znaków wystêpuj¹cych w równaniu
 */
enum Type
{
	number, dot, begin, end, plus, minus, mulipy, divide, power, percentage, sinus, cosinus, logarithm, negation, clear, done, unn
};

/**
 * Stuktura danych reprezentuj¹ca równanie przedstawione w odwrotnej notacji polskiej.
 */
struct Onp
{
	double value;			///< wartoœæ elementu ONP
	enum Type type;			///< typ znaku w równaniu
	struct Onp* pPrev;		///< adres poprzedniego elementu równania 
	struct Onp* pNext;		///< adres nastêpniego elementu równania
};

/**
 * Stuktura danych reprezentuj¹ca stos, na którym sk³adowne s¹ wartoœci i znaki przy tworzeniu odwrotnej notacji polskiej
 */
struct Stack {
	double prioryty;		///< priorytet elementu na stosie
	enum Type type;			///< typ znaku na stosie
	struct Stack* pPrev;	///< adres poprzedniego elementu stosu
};

/**
 * Stuktura danych reprezentuj¹ca aktualny stan stosu i przekszta³conego równania
 */
struct Pair {
	struct Stack* pStack;	///< adres g³owy stosu
	struct Onp* pOnp;		///< adres ogona przekszta³conego równania
};

#endif STRUCTURE_H
