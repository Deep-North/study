#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "myString.h"
#include <stdarg.h>
//using namespace std;


// ����������� ������������.
MyString::MyString(const char * pStr)
{
	m_pStr = new char [strlen (pStr) + 1];
	strcpy(m_pStr, pStr);
	std::cout << "��� ����������� MyString\n";
}

// ����������� �����������.
MyString::~MyString()
{
	delete[] m_pStr;
	std::cout << "��� ���������� MyString\n";
}

// ����������� GetString()
const char * MyString::GetString()
{
	return m_pStr;
}

// ����������� ������������ �����������
MyString::MyString(const MyString & other)
{
	m_pStr = new char[strlen(other.m_pStr) + 1];
	strcpy(m_pStr, other.m_pStr);
}

// ����������� SetNewString()
void MyString::SetNewString(const char * str)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(str) + 1];
	strcpy(m_pStr, str);
	std::cout << m_pStr << std::endl;
}

//����������� ������� char * Skleyka(), ��������� �������� ������ ���� 0.
MyString Skleyka(const char * s1, ...)
{
	va_list p;
	va_start(p, s1);
	int len = strlen(s1);
	while (const char * k = va_arg(p, const char *))
	{
		len += strlen(k);
	}
	va_end(p);

	char * s = new char[len + 1];
	strcpy(s, s1);
	//s[0] = 0;
	va_start(p, s1);
	while (const char * k = va_arg(p, const char *))
	{
		strcat(s, k);
	}
	MyString tmp(s);
	delete[] s;
	return std::move(tmp);
}

void MyString::Print_MyString()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "��� ����� Print_MyString()\n" << m_pStr << std::endl;
}

//���������� ��������� "="
MyString& MyString::operator = (const MyString& refMS)
{
	delete[] m_pStr;
	m_pStr = new char[strlen(refMS.m_pStr) + 1];
	strcpy(m_pStr, refMS.m_pStr);
	return *this;
}