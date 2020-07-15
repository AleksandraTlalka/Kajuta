#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <stdio.h>
#include <stdlib.h>


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

/**Funkcja zwalnia pamiêæ po wykonaniu wszystkich operacji
@param pHead adres pierwszego elementu listy jednokierunkowej przekonwertowanego na ONP równania
@param input adres ³añcucha znaków zawieraj¹cego otrzymane od u¿ytkownika równanie
*/
void FreeMemory(struct Onp* pHead, char* input);

#endif CALCULATOR_H