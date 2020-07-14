#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdio.h>
#include <stdlib.h>


//--------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------UI Functions

/**Funkcja otrzymuje równanie od u¿ytkownika.
@return adres ³añcucha znaków (otrzymanego równania)
*/
char* getUserInput();

/**Funkcja wyœwietla równanie przekonwertowane na odwrotn¹ notacje polsk¹
@param pHead wskaŸnik pierwszy element przekonwertowanego równania
*/
void printOnp(struct Onp* pHead);

/**Funkcja wyœwietla instrukcjê dla u¿ytkownika*/
void manual();


//--------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------Convert Functions

/**Funkcja zwraca typ podanego znaku
@param input pojedyñczy znak równania
@return typ tego znaku
*/
enum Type getType(char input);

/**Funkcja zwraca priorytet podanego typu znaku
@param type typ znaku
@return prorytet przypisany danemu znakowi
*/
int getPriority(enum Type type);

/**Funkcja zwraca oznaczenie danego typu znaku do wypisania na ekran lub do pliku
@param type typ znaku
@return oznaczenie danego typu znaku
*/
char* getOperation(enum Type type);

/**Funkcja zamienia cyfrê zapisan¹ jako znak typu char na jej wartoœæ typu int
@param character cyfra zapisan¹ jako znak
@return wartoœæ tej liczby
*/
int charToDigit(char character);

/**Funkcja s³u¿y do tworzenia czêœci u³amkowej liczby zmiennoprzecinkowej
@param number licznba wystêpuj¹ca po znku '.' lub ','
@return u³amek dziesiêtny
*/
double getFraction(double number);


//--------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------ONP Functions

/**Funkcja s³u¿y do przekonwertowania równania ze standardowej notacji do odwrotnej notacji polskiej 
@param result wynik poprzedniego równania
@param input adres ³añcucha znaków zawieraj¹cego otrzymane od urzytkownika równanie
@return adres pierwszego elementu przekonwertowanego na ONP równania
*/
struct Onp* onpBuilder(double result, char* input);

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


//--------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------Stack Functions

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

/**Funkcja s³u¿y do usuwania znaku z poczatku stosu
@param pStack adres pierwszego elementu stosu
@return adres pierwszego elementu stosu
*/
struct Stack* removeFromStack(struct Stack* pStack);


//--------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------Calculator

/**Funkcja s³u¿y do obliczania wyniku równania przekonwertowanego na ONP
@param pHead adres pierwszego elementu listy jednokierunkowej przekonwertowanego na ONP równania
@return wynik równania
*/
double calculator(struct Onp* pHead);

/**Funkcja s³u¿y do obliczania wyniku pojedyñczej operacji sk³adaj¹cej sie z dwóch liczb i operatora dwuelementowego
@param type typ operatora dwuelementowego
@param head pierwsza liczba (bli¿sza pierwszego elementu stosu - znaku)
@param prev druga liczba (liczba poprzedzajaca pierwsz¹)
@return wynik operacji
*/
double getMultiResult(enum Type type, double head, double prev);

/**Funkcja s³u¿y do obliczania wyniku pojedyñczej operacji sk³adaj¹cej sie z liczby i operatora jednoelementowego
@param type typ operatora jednoelementowego
@param head liczba najbli¿sza pierwszego elementu stosu - znaku
@return wynik operacji
*/
double getSingleResult(enum Type type, double head);


//--------------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------File functions

/** Funkcja zapisuje wynik równania do pliku
@param result wynik rónania
*/
void addResultToFile(double result);

/** Funkcja zapisuje kolejne elementu równania w odwrotnej notacji polskiej do pliku
@param pHead wskaŸnik na pierszy element równania
*/
void addOnpToFile(struct Onp* pHead);

#endif FUNCTIONS_H
