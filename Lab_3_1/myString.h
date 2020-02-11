#pragma once
#include <iostream>

class MyString
{
    char* m_pStr;									//������-���� ������

public:
 	explicit MyString(const char * pStr = "null");	//����������� MyString
	~MyString();									//���������� MyString
	MyString(const MyString & other);				//����������� �����������

	const char * GetString();						//����� GetString(), ������� ������������ ������ � ���������� ������

	void SetNewString(const char *);				//����� SetNewString, ������� �������� ������ �� �����

	void Print_MyString();							//����� ������

	bool Compare(const char*);

	MyString& operator = (const MyString & refMS);
	MyString& operator = (const char * str);

	MyString operator + (const MyString&);
	MyString& operator += (const MyString&);
	
	friend std::ostream& operator<<(std::ostream&, const MyString);
};

MyString Skleyka(const char *s1, ...);