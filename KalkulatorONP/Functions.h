#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdio.h>
#include <stdlib.h>


//--------------------------------------------------------------------------------------------------------------------
// -------------------------------------------------------------------------------------------------------UI Functions

/**Funkcja otrzymuje r�wnanie od u�ytkownika.
@return adres �a�cucha znak�w (otrzymanego r�wnania)
*/
char* getUserInput();

/**Funkcja wy�wietla r�wnanie przekonwertowane na odwrotn� notacje polsk�
@param pHead wska�nik pierwszy element przekonwertowanego r�wnania
*/
void printOnp(struct Onp* pHead);

/**Funkcja wy�wietla instrukcj� dla u�ytkownika*/
void manual();


//--------------------------------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------------Convert Functions

/**Funkcja zwraca typ podanego znaku
@param input pojedy�czy znak r�wnania
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

/**Funkcja zamienia cyfr� zapisan� jako znak typu char na jej warto�� typu int
@param character cyfra zapisan� jako znak
@return warto�� tej liczby
*/
int charToDigit(char character);

/**Funkcja s�u�y do tworzenia cz�ci u�amkowej liczby zmiennoprzecinkowej
@param number licznba wyst�puj�ca po znku '.' lub ','
@return u�amek dziesi�tny
*/
double getFraction(double number);


//--------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------ONP Functions

/**Funkcja s�u�y do przekonwertowania r�wnania ze standardowej notacji do odwrotnej notacji polskiej 
@param result wynik poprzedniego r�wnania
@param input adres �a�cucha znak�w zawieraj�cego otrzymane od urzytkownika r�wnanie
@return adres pierwszego elementu przekonwertowanego na ONP r�wnania
*/
struct Onp* onpBuilder(double result, char* input);

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


//--------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------Stack Functions

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

/**Funkcja s�u�y do usuwania znaku z poczatku stosu
@param pStack adres pierwszego elementu stosu
@return adres pierwszego elementu stosu
*/
struct Stack* removeFromStack(struct Stack* pStack);


//--------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------Calculator

/**Funkcja s�u�y do obliczania wyniku r�wnania przekonwertowanego na ONP
@param pHead adres pierwszego elementu listy jednokierunkowej przekonwertowanego na ONP r�wnania
@return wynik r�wnania
*/
double calculator(struct Onp* pHead);

/**Funkcja s�u�y do obliczania wyniku pojedy�czej operacji sk�adaj�cej sie z dw�ch liczb i operatora dwuelementowego
@param type typ operatora dwuelementowego
@param head pierwsza liczba (bli�sza pierwszego elementu stosu - znaku)
@param prev druga liczba (liczba poprzedzajaca pierwsz�)
@return wynik operacji
*/
double getMultiResult(enum Type type, double head, double prev);

/**Funkcja s�u�y do obliczania wyniku pojedy�czej operacji sk�adaj�cej sie z liczby i operatora jednoelementowego
@param type typ operatora jednoelementowego
@param head liczba najbli�sza pierwszego elementu stosu - znaku
@return wynik operacji
*/
double getSingleResult(enum Type type, double head);


//--------------------------------------------------------------------------------------------------------------------
// -----------------------------------------------------------------------------------------------------File functions

/** Funkcja zapisuje wynik r�wnania do pliku
@param result wynik r�nania
*/
void addResultToFile(double result);

/** Funkcja zapisuje kolejne elementu r�wnania w odwrotnej notacji polskiej do pliku
@param pHead wska�nik na pierszy element r�wnania
*/
void addOnpToFile(struct Onp* pHead);

#endif FUNCTIONS_H
