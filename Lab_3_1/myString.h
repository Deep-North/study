#pragma once
#include <iostream>

class MyString
{
    char* m_pStr;									//строка-член класса

public:
 	explicit MyString(const char * pStr = "null");	//конструктор MyString
	~MyString();									//деструктор MyString
	MyString(const MyString & other);				//конструктор копирования

	const char * GetString();						//метод GetString(), который обеспечивает доступ к хранящейся строке

	void SetNewString(const char *);				//метод SetNewString, который заменяет строку на новую

	void Print_MyString();							//Метод печати

	bool Compare(const char*);

	MyString& operator = (const MyString & refMS);
	MyString& operator = (const char * str);

	MyString operator + (const MyString&);
	MyString& operator += (const MyString&);
	
	friend std::ostream& operator<<(std::ostream&, const MyString);
};

MyString Skleyka(const char *s1, ...);