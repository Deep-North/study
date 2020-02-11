#pragma once
class MyString
{
    char* m_pStr;							//������-���� ������

public:
 	MyString(const char * pStr = "null");	//����������� MyString
	~MyString();							//���������� MyString
	MyString(const MyString & other);		//����������� �����������

	const char * GetString();				//����� GetString(), ������� ������������ ������ � ���������� ������

	void SetNewString(const char *);		//����� SetNewString, ������� �������� ������ �� �����

	void Print_MyString();					//����� ������

	MyString& operator = (const MyString& refMS);
};

MyString Skleyka(const char *s1, ...);
