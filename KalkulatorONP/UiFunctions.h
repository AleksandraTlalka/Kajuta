#ifndef UI_H
#define UI_H


#include <stdio.h>
#include <stdlib.h>

/**Funkcja otrzymuje od u�ytkownika informacj� czy w wierszu linii polece� poda� nazw� pliku czy r�wnanie
@param argv adres �a�cucha znak�w (otrzymanego r�wnania lub nazwy pliku)
@return otrzymane od u�ytkownika lub z pliku r�wnanie
*/
char* getUserChoice(char* argv);

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

/**Funkcja sprawdza czy u�ytkownik pr�buje dziel� przez 0
@param input podane r�wnanie
*/
void divideByZero(char* input);

#endif UI_H
