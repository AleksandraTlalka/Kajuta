#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Constans.h"
#include "Structures.h"
#include "Functions.h"


enum Type getType(char input) {
	switch (input)
	{
	case '.': return dot;
	case ',': return dot;
	case '(': return begin;
	case ')': return end;
	case '+': return plus;
	case '-': return minus;
	case '*': return mulipy;
	case '/': return divide;
	case '^': return power;
	case '%': return percentage;
	case 's': return sinus;
	case 'c': return cosinus;
	case 'l': return logarithm;
	case 'N': return negation;
	case 'C': return clear;
	case 'E': return done;
	default: return unn;
	}
}

int getPriority(enum Type type) {
	switch (type)
	{
	case dot: return 6;
	case begin: return 0;
	case end: return 0;
	case plus: return 1;
	case minus: return 1;
	case mulipy: return 2;
	case divide: return 2;
	case power: return 3;
	case percentage: return 3;
	case sinus: return 4;
	case cosinus: return 4;
	case logarithm: return 4;
	case negation: return 5;
	}
}

char* getOperation(enum Type type) {
	switch (type)
	{
	case dot: return ".";
	case begin: return "(";
	case end: return ")";
	case plus: return "+";
	case minus: return "-";
	case mulipy: return "*";
	case divide: return "/";
	case power: return "^";
	case percentage: return "%";
	case sinus: return "sin";
	case cosinus: return "cos";
	case logarithm: return "ln";
	case negation: return "N";
	}
}

int charToDigit(char character)
{
	return character - 48;
}

double getFraction(double number) {
	while (number >= 1) {
		number = number / 10;
	}
	return number;
}