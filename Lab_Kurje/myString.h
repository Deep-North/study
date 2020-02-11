#pragma once
class MyString
{
    char* m_pStr;							//строка-член класса

public:
 	MyString(const char * pStr = "null");	//конструктор MyString
	~MyString();							//деструктор MyString
	MyString(const MyString & other);		//конструктор копирования

	const char * GetString();				//метод GetString(), который обеспечивает доступ к хранящейся строке

	void SetNewString(const char *);		//метод SetNewString, который заменяет строку на новую

	void Print_MyString();					//Метод печати

	MyString& operator = (const MyString& refMS);
};

MyString Skleyka(const char *s1, ...);
