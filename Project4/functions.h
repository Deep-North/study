#pragma once


extern int& ref;
//������� 2
int IncByValue(int x);
void IncByPointer(int *x);
void IncByReference(int &x);

//������� 2.�
void Swap(int &a, int &b);
void Swap(int *a, int *b);

//������� 3.�1
int Min(int* mass, int n, int m);
//������� 3.�2
int Min(int** mass, int n, int m);

//������� 3.�
int MyStrCmp(const char * s1, const char * s2);

//������� 4
int DayOfYear(int d, int m, int y, int(&ar)[2][12]);
void DayOfMonth(int y, int d, int(&ar1)[2][12], int(&ar2)[2]);

//������� 5
void SymbolAddition(int* p1, int n);

//������� 6
int RecursiveSum(int n);

//������� 7.A
void VarArgs(int first, ...);

//������� 7.�
void VarArgsStd(int first, ...);

//������� 8
int* MyMin(int ar[], int n);