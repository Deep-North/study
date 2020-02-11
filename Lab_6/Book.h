#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>


enum eCategory
{
	Nauka = 1,
	Lingvistika,
	Proza,
	Poesiya,
	Hudozhestvennaya,
};

struct BOOK
{
	float price; //цена
	int year; //год издания
	char title[64]; //заглавие
	char author[32]; //автор
	eCategory category;//категория
};

void printBOOKinLine(BOOK * a);
void printBOOK(BOOK &b);
