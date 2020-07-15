#ifndef CONVERT_H
#define CONVERT_H


#include <stdio.h>
#include <stdlib.h>


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

#endif CONVERT_H
