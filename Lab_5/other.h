#define _CRT_SECURE_NO_WARNINGS

#include <cmath>
#include <string.h>
#include <cstdio>
#include <iostream>

enum VyborOperacii {
	PLUS,
	MINUS,
	MUL,
	DIV,
	POW,
	EF
};

double Vybor(double a, double b, VyborOperacii);

double Sum(double a, double b);
double Sub(double a, double b);
double Mul(double a, double b);
double Div(double a, double b);
double Pow(double a, double b);
double ErrFunc(double a, double b);


//Прототипы используемых в данном задании функций:

void SwapInt(void* p1, void* p2);

int CmpInt(void* p1, void* p2);

void SwapDouble(void* p1, void* p2);

int CmpDouble(void* p1, void* p2);

void SwapStr(void* p1, void* p2);

int CmpStr(void* p1, void* p2);

void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(void*, void*), int(*Compare)(void*, void*));

const char* GetString1();
const char* GetString2();
const char* GetString3();
const char* GetString4();
const char* GetString5();

const int max_dlina_stroki = 256;
const int god_poyavleniya_pismennosti = 1700;

struct BOOK
{
	int year; //год издания
	float price; //цена

	char title[max_dlina_stroki]; //заглавие
	char author[max_dlina_stroki]; //автор
	char category[max_dlina_stroki];//категория 
};

void BookSetTitle(BOOK &b, const char *t);
void BookSetAuthor(BOOK &b, const char *t);
void BookSetCategory(BOOK &b, const char *t);
void fill(char(&s)[max_dlina_stroki], const char *);

void printBOOK(const BOOK &b);
BOOK * makeBook();