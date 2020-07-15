#ifndef FILE_H
#define FILE_H


#include <stdio.h>
#include <stdlib.h>

/** Funkcja odczytuje równanie podane w pliku (podanym z lini poleceñ)
@param argv1 adres nazwy pliku do odczytu
@return równanie podne w pliku
*/
char* readFile(char* argv1);

/** Funkcja zapisuje wynik równania do pliku
@param result wynik rónania
*/
void addResultToFile(double result);

/** Funkcja zapisuje kolejne elementu równania w odwrotnej notacji polskiej do pliku
@param pHead wskaŸnik na pierszy element równania
*/
void addOnpToFile(struct Onp* pHead);

#endif FILE_H

