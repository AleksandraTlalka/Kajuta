#ifndef UI_H
#define UI_H


#include <stdio.h>
#include <stdlib.h>

/**Funkcja otrzymuje od u¿ytkownika informacjê czy w wierszu linii poleceñ poda³ nazwê pliku czy równanie
@param argv adres ³añcucha znaków (otrzymanego równania lub nazwy pliku)
@return otrzymane od u¿ytkownika lub z pliku równanie
*/
char* getUserChoice(char* argv);

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

/**Funkcja sprawdza czy u¿ytkownik próbuje dzielæ przez 0
@param input podane równanie
*/
void divideByZero(char* input);

#endif UI_H
