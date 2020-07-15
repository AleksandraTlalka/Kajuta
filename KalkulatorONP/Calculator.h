#ifndef CALCULATOR_H
#define CALCULATOR_H


#include <stdio.h>
#include <stdlib.h>


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

/**Funkcja zwalnia pami�� po wykonaniu wszystkich operacji
@param pHead adres pierwszego elementu listy jednokierunkowej przekonwertowanego na ONP r�wnania
@param input adres �a�cucha znak�w zawieraj�cego otrzymane od u�ytkownika r�wnanie
*/
void FreeMemory(struct Onp* pHead, char* input);

#endif CALCULATOR_H