#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>

/**Funkcja skupia w sobie wszystkie operacje zwi�zane ze stosem dla danego typu znaku (dok�adniej opisane w innych funkcjach)
@param pStack adres pierwszego elementu stosu
@param pTail adres ostatniego elementu przekonwertowanego na ONP r�wnania
@param type typ danego znaku lub liczby
@return adres aktualnej struktury Pair
*/
struct Pair* stackAction(struct Stack* pStack, struct Onp* pTail, enum Type type);

/**Funkcja skupia w sobie usuwanie danych ze stosu, dodawnie ich do przekonwertowanego na ONP r�wnania oraz dodawanie nowych danych na stos
@param pStack adres pierwszego elementu stosu
@param pTail adres ostatniego elementu przekonwertowanego na ONP r�wnania
@param type typ danego znaku lub liczby
@return adres aktualnej struktury Pair
*/
struct Pair* modyfyStack(struct Stack* pStack, struct Onp* pTail, enum Type type);

/**Funkcja s�u�y do dodawania znaku na pocz�tek stosu
@param pStack adres pierwszego elementu stosu
@param type typ dodawanego znaku
@param prioryty prorytet przypisany dodawemu znakowi
@return adres pierwszego elementu stosu
*/
struct Stack* addToStack(struct Stack* pStack, enum Type type, double prioryty);

/**Funkcja s�u�y do przenoszenia znk�w, kt�re pozosta�y na stosie po odczytaniu wszystkich wprowadzonych znak�w, na koniec przekonwertowanego na ONP r�wnania
@param pTail adres ostatniego elementu przekonwertowanego na ONP r�wnania
@param pStack adres pierwszego elementu stosu
@return nowy adres ostatniego elementu przekonwertowanego na ONP r�wnania
*/
struct Onp* emptyStack(struct Onp* pTail, struct Stack* pStack);

/**Funkcja s�u�y do usuwania znaku z poczatku stosu
@param pStack adres pierwszego elementu stosu
@return adres aktualnego pierwszego elementu stosu po usuni�ciu poprzedniego
*/
struct Stack* removeFromStack(struct Stack* pStack);

#endif STACK_H
