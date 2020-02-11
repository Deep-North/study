#pragma once
//#include "Book.h"

int Menu();//вывод меню.
void printBOOK(BOOK * b);//вывод экземпл€ра в консоль.
void ScanBook(BOOK * a); //заполнение полей экземпл€ра.
void printBOOKinLine(BOOK * a); //вывод книги в одну строчку.
void ShowBooks();// вывод текущей картотеки.
void AddNewBook(); //добавление нового экземпл€ра в библиотеку.
void DeleteBook(int num);//удаление книги.
void SaveToFile();//сохранение картотеки в файл.
void LoadFromFile();//загрузка картотеки из файла.
void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(BOOK*, BOOK*), int(*Compare)(void*, void*));//сортировка.
void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(BOOK*, BOOK*), double(*Compare)(void*, void*));
void SwapBookS(BOOK* p1, BOOK* p2);//мен€ет местами две книги.
int CmpStr(void* p1, void* p2);//сравнивает две строки.
int CmpInt(void* p1, void* p2);
int CmpD(void* p1, void* p2);
void SortMenu();//меню сортировки.