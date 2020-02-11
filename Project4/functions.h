#pragma once


extern int& ref;
//Задание 2
int IncByValue(int x);
void IncByPointer(int *x);
void IncByReference(int &x);

//Задание 2.А
void Swap(int &a, int &b);
void Swap(int *a, int *b);

//Задание 3.А1
int Min(int* mass, int n, int m);
//Задание 3.А2
int Min(int** mass, int n, int m);

//Задание 3.Б
int MyStrCmp(const char * s1, const char * s2);

//Задание 4
int DayOfYear(int d, int m, int y, int(&ar)[2][12]);
void DayOfMonth(int y, int d, int(&ar1)[2][12], int(&ar2)[2]);

//Задание 5
void SymbolAddition(int* p1, int n);

//Задание 6
int RecursiveSum(int n);

//Задание 7.A
void VarArgs(int first, ...);

//Задание 7.Б
void VarArgsStd(int first, ...);

//Задание 8
int* MyMin(int ar[], int n);