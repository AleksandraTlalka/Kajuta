#ifndef FILE_H
#define FILE_H


#include <stdio.h>
#include <stdlib.h>

/** Funkcja odczytuje r�wnanie podane w pliku (podanym z lini polece�)
@param argv1 adres nazwy pliku do odczytu
@return r�wnanie podne w pliku
*/
char* readFile(char* argv1);

/** Funkcja zapisuje wynik r�wnania do pliku
@param result wynik r�nania
*/
void addResultToFile(double result);

/** Funkcja zapisuje kolejne elementu r�wnania w odwrotnej notacji polskiej do pliku
@param pHead wska�nik na pierszy element r�wnania
*/
void addOnpToFile(struct Onp* pHead);

#endif FILE_H

