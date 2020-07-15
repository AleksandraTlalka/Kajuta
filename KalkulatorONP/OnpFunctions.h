#ifndef ONP_H
#define ONP_H


#include <stdio.h>
#include <stdlib.h>

/**Funkcja s³u¿y do przekonwertowania równania ze standardowej notacji do odwrotnej notacji polskiej
@param result wynik poprzedniego równania
@param input adres ³añcucha znaków zawieraj¹cego otrzymane od urzytkownika równanie
@param rewrite warunek przepisania wyniku poprzedniego równania do nowego
@return adres pierwszego elementu przekonwertowanego na ONP równania
*/
struct Onp* onpBuilder(double result, char* input, bool rewrite);

/**Funkcja s³u¿y do dodawania liczby lub znaku do przekonwertowanego na ONP równania
@param tail adres ostatniego elementu przekonwertowanego na ONP równania
@param type typ dodawnaego znaku lub liczby
@param value wartoœæ dodawanego znaku lub liczby
@return adres ostatniego elementu przekonwertowanego na ONP równania
*/
struct Onp* addToOnp(struct Onp* tail, enum Type type, double value);

/**Funkcja s³u¿y uaktualniania stanu ostatniego elementu przekonwertowanego na ONP równania i stosu
@param pTail adres ostatniego elementu przekonwertowanego na ONP równania
@param pStack adres pierwszego elementu stosu
@return adres aktualnej struktury Pair
*/
struct Pair* addToPair(struct Onp* pTail, struct Stack* pStack);

/**Funkcja znajduje pierwszy element listy jednokierunkowej
@param pTail adres ostatniego elementu przekonwertowanego na ONP równania
@return adres pierwszego elementu przekonwertowanego na ONP równania
*/
struct Onp* findOnpHead(struct Onp* pTail);

/**Funkcja ustala czy kalkulator powinien zakoñczyæ dzia³anie lub wyczyœciæ wyœwietlacz
@param type typ napotkanego znaku
@return true albo false w zale¿noœci co zostanie ustalone
*/
bool setState(enum Type type);

/**Funkcja sprawdza czy kalkulator spe³nia warunki do kontynuowania pracy w niezmienionym stanie
@param pTail adres ostatniego elementu przekonwertowanego na ONP równania
@param toClear warunek usuniêcia z wyœwietlacza wszystkich danych
@param toStop warunek zakoñczenia pracy kalkulatora
@return adres pierwszego elementu przekonwertowanego na ONP równania
*/
struct Onp* stateControl(struct Onp* pTail, bool toClear, bool toStop);

/** Funkcja usuwa od pocz¹tku listê jednokierunkow¹ przekonwertowanego na ONP równania
@param pHead wskaŸnik na pierwszy element listy – po usuniêciu listy jest równy nullptr.
*/
void freeOnp(struct Onp* pHead);

#endif ONP_H
