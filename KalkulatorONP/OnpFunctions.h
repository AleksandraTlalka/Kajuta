#ifndef ONP_H
#define ONP_H


#include <stdio.h>
#include <stdlib.h>

/**Funkcja s�u�y do przekonwertowania r�wnania ze standardowej notacji do odwrotnej notacji polskiej
@param result wynik poprzedniego r�wnania
@param input adres �a�cucha znak�w zawieraj�cego otrzymane od urzytkownika r�wnanie
@param rewrite warunek przepisania wyniku poprzedniego r�wnania do nowego
@return adres pierwszego elementu przekonwertowanego na ONP r�wnania
*/
struct Onp* onpBuilder(double result, char* input, bool rewrite);

/**Funkcja s�u�y do dodawania liczby lub znaku do przekonwertowanego na ONP r�wnania
@param tail adres ostatniego elementu przekonwertowanego na ONP r�wnania
@param type typ dodawnaego znaku lub liczby
@param value warto�� dodawanego znaku lub liczby
@return adres ostatniego elementu przekonwertowanego na ONP r�wnania
*/
struct Onp* addToOnp(struct Onp* tail, enum Type type, double value);

/**Funkcja s�u�y uaktualniania stanu ostatniego elementu przekonwertowanego na ONP r�wnania i stosu
@param pTail adres ostatniego elementu przekonwertowanego na ONP r�wnania
@param pStack adres pierwszego elementu stosu
@return adres aktualnej struktury Pair
*/
struct Pair* addToPair(struct Onp* pTail, struct Stack* pStack);

/**Funkcja znajduje pierwszy element listy jednokierunkowej
@param pTail adres ostatniego elementu przekonwertowanego na ONP r�wnania
@return adres pierwszego elementu przekonwertowanego na ONP r�wnania
*/
struct Onp* findOnpHead(struct Onp* pTail);

/**Funkcja ustala czy kalkulator powinien zako�czy� dzia�anie lub wyczy�ci� wy�wietlacz
@param type typ napotkanego znaku
@return true albo false w zale�no�ci co zostanie ustalone
*/
bool setState(enum Type type);

/**Funkcja sprawdza czy kalkulator spe�nia warunki do kontynuowania pracy w niezmienionym stanie
@param pTail adres ostatniego elementu przekonwertowanego na ONP r�wnania
@param toClear warunek usuni�cia z wy�wietlacza wszystkich danych
@param toStop warunek zako�czenia pracy kalkulatora
@return adres pierwszego elementu przekonwertowanego na ONP r�wnania
*/
struct Onp* stateControl(struct Onp* pTail, bool toClear, bool toStop);

/** Funkcja usuwa od pocz�tku list� jednokierunkow� przekonwertowanego na ONP r�wnania
@param pHead wska�nik na pierwszy element listy � po usuni�ciu listy jest r�wny nullptr.
*/
void freeOnp(struct Onp* pHead);

#endif ONP_H
