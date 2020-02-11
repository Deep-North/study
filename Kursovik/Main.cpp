#define _CRT_SECURE_NO_WARNINGS

#define	  stop __asm nop
#include <iostream>
#include "Functions.h"

unsigned char * p;
size_t string_lenght;

void main()
{
	setlocale(LC_ALL, "Russian");
	char mass[1000] = {0};
	
	input(mass);
	
	translation(mass);

	BigInteger bimass;
	bimass.p = p;
	bimass.n = string_lenght;

	print_oct(bimass.p, bimass.n);
	print_binary(bimass.p, bimass.n);

	delete [] bimass.p;

	system("pause");
	stop
}