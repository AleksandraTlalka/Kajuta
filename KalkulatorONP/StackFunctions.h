#ifndef STACK_H
#define STACK_H


#include <stdio.h>
#include <stdlib.h>

/**Funkcja skupia w sobie wszystkie operacje zwi¹zane ze stosem dla danego typu znaku (dok³adniej opisane w innych funkcjach)
@param pStack adres pierwszego elementu stosu
@param pTail adres ostatniego elementu przekonwertowanego na ONP równania
@param type typ danego znaku lub liczby
@return adres aktualnej struktury Pair
*/
struct Pair* stackAction(struct Stack* pStack, struct Onp* pTail, enum Type type);

/**Funkcja skupia w sobie usuwanie danych ze stosu, dodawnie ich do przekonwertowanego na ONP równania oraz dodawanie nowych danych na stos
@param pStack adres pierwszego elementu stosu
@param pTail adres ostatniego elementu przekonwertowanego na ONP równania
@param type typ danego znaku lub liczby
@return adres aktualnej struktury Pair
*/
struct Pair* modyfyStack(struct Stack* pStack, struct Onp* pTail, enum Type type);

/**Funkcja s³u¿y do dodawania znaku na pocz¹tek stosu
@param pStack adres pierwszego elementu stosu
@param type typ dodawanego znaku
@param prioryty prorytet przypisany dodawemu znakowi
@return adres pierwszego elementu stosu
*/
struct Stack* addToStack(struct Stack* pStack, enum Type type, double prioryty);

/**Funkcja s³u¿y do przenoszenia znków, które pozosta³y na stosie po odczytaniu wszystkich wprowadzonych znaków, na koniec przekonwertowanego na ONP równania
@param pTail adres ostatniego elementu przekonwertowanego na ONP równania
@param pStack adres pierwszego elementu stosu
@return nowy adres ostatniego elementu przekonwertowanego na ONP równania
*/
struct Onp* emptyStack(struct Onp* pTail, struct Stack* pStack);

/**Funkcja s³u¿y do usuwania znaku z poczatku stosu
@param pStack adres pierwszego elementu stosu
@return adres aktualnego pierwszego elementu stosu po usuniêciu poprzedniego
*/
struct Stack* removeFromStack(struct Stack* pStack);

#endif STACK_H
