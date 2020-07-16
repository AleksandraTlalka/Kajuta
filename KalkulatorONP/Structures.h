#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdio.h>
#include <stdlib.h>


/**
 * Typy znak�w wyst�puj�cych w r�wnaniu
 */
enum Type
{
	number, dot, begin, end, plus, minus, mulipy, divide, power, percentage, sinus, cosinus, logarithm, negation, clear, done, unn
};

/**
 * Stuktura danych reprezentuj�ca r�wnanie przedstawione w odwrotnej notacji polskiej.
 */
struct Onp
{
	double value;			///< warto�� elementu ONP
	enum Type type;			///< typ znaku w r�wnaniu
	struct Onp* pPrev;		///< adres poprzedniego elementu r�wnania 
	struct Onp* pNext;		///< adres nast�pniego elementu r�wnania
};

/**
 * Stuktura danych reprezentuj�ca stos, na kt�rym sk�adowne s� warto�ci i znaki przy tworzeniu odwrotnej notacji polskiej
 */
struct Stack {
	double prioryty;		///< priorytet elementu na stosie
	enum Type type;			///< typ znaku na stosie
	struct Stack* pPrev;	///< adres poprzedniego elementu stosu
};

/**
 * Stuktura danych reprezentuj�ca aktualny stan stosu i przekszta�conego r�wnania
 */
struct Pair {
	struct Stack* pStack;	///< adres g�owy stosu
	struct Onp* pOnp;		///< adres ogona przekszta�conego r�wnania
};

#endif STRUCTURE_H
