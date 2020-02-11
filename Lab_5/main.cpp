/*
����������� ����� ������
�������: ��������� ����������� ����� MyString ����� �������, ����� ��� ������ ��������� � ������������ ����������.
��� ����� ������� ��� (����������� ������������ ������):

��� ������ ���� ��������


��������������� ����� Counter
�������� "��������" ��� ������ � �������� ��������������� ������, ������� � ��������� �������� �������� ������������ ������.
���������� (�������):
�	��������� �� ����������� ����������� ������ � m_pStr
�	������� ������������� ������ ������ - m_nOwners
�	��������� �� ��������� Counter � pNext
������:
�	����������� (������������)
�	����������
�	�������� ������������
�	������ ������������ (��� ������, ���� ��� ��� ��������� ������������, � ������ ������ ������ �� �����?)
�	�

��� ����, ����� ���������� �������� ������ � ������������ ����������,
� ������ Counter ������ ��������� � ������������ ���������� �������� ���� ��������������� �������,
(����� �������, � ����� ������ ���������� ��������� ����� �������� �������� ���� ������������ �����).
������ ����������� ������:
static Counter* Head;
� ����� ������� ����������:
static unsigned int m_curCounters;
������� ������������� ����������� � ������������� ����������� ������.

�������� ����� MyString
�������� ������������ ������ � ��������� �� "����" Counter �
Counter* m_pMyCounter
������� ����������� �� ��� ������ ������ (��������������� ����� ��� �������� ������)..

��� ����������� ����� �������� ������� � ����� ����������� ������:
�	����������� ��� ������
�	�� ���� �������� MyString �������� �������
�	������� ������ �� ��������
�	�

*/


#include <iostream>
#include "myString.h"

using namespace std;

#define	  stop


int main(int argc, char* argv[])
{

	std::cout << "Ok\n";
	MyString s("test");

	{

		MyString s("test");
		MyString s1("test");
		MyString s2("test");
		MyString s3("test");
		std::cout << s << "\n";
	} //see desctructr

	{
		MyString s1("xyz");
		MyString s22("xyz");
		MyString s133("xyz");
		MyString s2("abc");
		MyString s3("def");
		MyString s4("abx");
		MyString s7("test");

		s2 = s7;

		std::cout << s1 << " - " << s2 << " " << s3 << "\n";

		MyString::PrintAllString();
		MyString::ChnageRegisterAllString();
		MyString::PrintAllString();
		MyString::ChnageSortAllString();
		MyString::PrintAllString();
	}

	{
		MyString s3 = MyString("some string");
		MyString s7("test");
		MyString s8("some string");
		MyString s4("abx");
		s3 = "u765";
		MyString::PrintAllString();
		MyString::ChnageRegisterAllString();
		MyString::ChnageSortAllString();
		MyString::PrintAllString();
	}

	{
		MyString s2("enm");
		MyString s3("xyz");
		MyString s1("abc");
		MyString::PrintAllString();
		// MyString::ChnageRegisterAllString();
		MyString::ChnageSortAllString();
		MyString::PrintAllString();
	}

	//before delete 
	MyString::PrintAllString();

	return 0;
}