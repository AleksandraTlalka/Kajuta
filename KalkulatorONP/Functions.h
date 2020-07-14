#ifndef FUNCTIONS_H
#define FUNCTIONS_H


#include <stdio.h>
#include <stdlib.h>


// UI functions
char* getUserInput();
void printOnp(struct Onp* pHead);
void manual();


// Convert functions
enum Type getType(char input);
int getPriority(enum Type type);
char* getOperation(enum Type type);
int charToDigit(char character);
double getFraction(double number);


// Onp functions
struct Onp* onpBuilder(double result, char* input);
struct Onp* addToOnp(struct Onp* tail, enum Type type, double value);
struct Onp* addToPair(struct Onp* pTail, struct Stack* pStack);
struct Onp* findOnpHead(struct Onp* pTail);
struct Onp* stateControl(struct Onp* pTail, bool toClear, bool toStop);
void freeOnp(struct Onp* pHead);


// Stack functions
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
