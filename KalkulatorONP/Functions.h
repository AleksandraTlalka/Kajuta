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
struct Onp* findOnpHead(struct Onp* pTail);
struct Onp* stateControl(struct Onp* pTail, bool toClear, bool toStop);
void freeOnp(struct Onp* pHead);


//--------------------------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------Stack Functions

struct Pair* stackAction(struct Stack* head, struct Onp* tail, enum Type type);
struct Pair* modyfyStack(struct Stack* stack, struct Onp* onp, enum Type type);
struct Stack* addToStack(struct Stack* head, enum Type type, double prioryty);
struct Stack* removeFromStack(struct Stack* pStack);


//--------------------------------------------------------------------------------------------------------------------
// ---------------------------------------------------------------------------------------------------------Calculator


double calculator(struct Onp* pHead);
double getMultiResult(enum Type type, double head, double prev);
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
