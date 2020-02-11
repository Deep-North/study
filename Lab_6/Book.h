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
	float price; //����
	int year; //��� �������
	char title[64]; //��������
	char author[32]; //�����
	eCategory category;//���������
};

void printBOOKinLine(BOOK * a);
void printBOOK(BOOK &b);
