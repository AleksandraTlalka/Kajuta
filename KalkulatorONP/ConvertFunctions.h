#ifndef CONVERT_H
#define CONVERT_H


#include <stdio.h>
#include <stdlib.h>


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

#endif CONVERT_H
