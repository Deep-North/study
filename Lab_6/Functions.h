#pragma once
//#include "Book.h"

int Menu();//����� ����.
void printBOOK(BOOK * b);//����� ���������� � �������.
void ScanBook(BOOK * a); //���������� ����� ����������.
void printBOOKinLine(BOOK * a); //����� ����� � ���� �������.
void ShowBooks();// ����� ������� ���������.
void AddNewBook(); //���������� ������ ���������� � ����������.
void DeleteBook(int num);//�������� �����.
void SaveToFile();//���������� ��������� � ����.
void LoadFromFile();//�������� ��������� �� �����.
void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(BOOK*, BOOK*), int(*Compare)(void*, void*));//����������.
void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(BOOK*, BOOK*), double(*Compare)(void*, void*));
void SwapBookS(BOOK* p1, BOOK* p2);//������ ������� ��� �����.
int CmpStr(void* p1, void* p2);//���������� ��� ������.
int CmpInt(void* p1, void* p2);
int CmpD(void* p1, void* p2);
void SortMenu();//���� ����������.