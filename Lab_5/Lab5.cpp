
/*************************************************************
	������������ ������� �5. 
	"������" ��������� ������� ����������� ����������
	��������� �� �������
	���������
*************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <tchar.h>
#include <iostream>
//#include <cstdio>
#include "other.h"


#define	  stop __asm nop

BOOK globalBOOK;

int _tmain()
{
	setlocale(LC_ALL, "Russian");

	////////////////////////////////////////////////////////////////////	
		//���� "������" ��������� ������� ����������� ����������
	{
		//������� 1. � ������� ������� scanf ����������� ��� ������������: A,B,C
		std::cout << "====================================================================\n\n������� 5.1.\n\n";
		int A, B, C;

		scanf("%d%d%d%*c", &A, &B, &C);
		std::cout << "A: " << A << "\n" << "B: " << B << "\n" << "C: " << C << "\n";

		//������� 2. �������� (�������!) ������� �������� y=A*x*x + B*x + C
		//��� ��������� x � ��������� -2 �� +2 � ����� 0.5

		float x, y;
		for (x = -2; x <= 2; x += 0.5)
		{
			y = (A * x*x + B * x + C);
			printf("y = %d * (%5.1f * %5.1f) + ( %d * %5.1f ) + %d = %3.1f\n", A, x, x, B, x, C, y);
		}

		stop
	}

	///////////////////////////////////////////////////////////////////
		//���� ��������� �� �������
	{
		std::cout << "====================================================================\n\n������� 5.2.\n\n";
		//������� 1. ��������� �� �������. "�����������".
		//�������� �������:
		//1)Sum - ��������� ��� �������� double � ���������� �����
		//���� ��������
		//2)Sub- ��������� ��� �������� double � ���������� ��������
		//���� ��������
		//3)Mul - *
		//4)Div - /
		//5)� ��� ���������� � ������� ������ ������������ ������� ����������� ����������
		//		- pow(). ��������� 1: �������� ������� ��������� � <cmath>.
		//		��������� 2: ����������� ���������� ������������� ��������� �������������
		//		��������� ���� �������, � ��� ����������� ������������ ��������� �� 
		//		double pow(double, double);

		//������������ ������������	��������� �����������:
		//���� ������������ ����� ������������ �������� ������ ������������,
		//�� ����� ������� ��� �������� � ���� ��������
		//� �� �������� ���������. ��������� ��������� ����������� ������
		//��������������� ����� ������� �� ���������.
		//������������� ����������� ����� ������������������ ����� ��������

		printf("Vybor(1, 1, +) = %f\n", Vybor(1, 1, PLUS));
		printf("Vybor(1, 1, -) = %f\n", Vybor(1, 1, MINUS));
		printf("Vybor(3, 2.1, *) = %f\n", Vybor(3, 2.1, MUL));
		printf("Vybor(3, 1.5, /) = %f\n", Vybor(3, 1.5, DIV));
		printf("Vybor(2, 8, **) = %f\n", Vybor(2, 8, POW));
		printf("Vybor(10.3, 0.5, ?) = %f\n", Vybor(10.3, 0.5, EF));

		stop
	}
	{
		std::cout << "====================================================================\n\n������� 5.3.\n\n";
		//������� 3. ��������� �� ������� � �������� ���������.
		//���� ��������� ������� ���������� ����� �������� - Sort.
		//������� ��������� ��������� ���������:
		//1) ��������� �� ������ ����������� �������
		//2) ���������� ����������� ���������
		//3) ������ �������� � ������
		//4) ��������� �� ������� ������������ ���������
		//5) ��������� �� ������� ��������� ���������

		//3a. �������� ������� ������������ ���� ����� �������� -
		// SwapInt, ������� ��������� ��� void ��������� � 
		//������ �������� �������

		//�������� ������� ��������� ���� ����� �������� -
		// CmpInt, ������� ��������� ��� void ��������� �
		//���������� int ��������� ���������: 
		//<0 - ������ ������� ������, ��� ������
		//=0 - �����
		//>0 - ������ ������� ������, ��� ������

		int nAr[] = { 10, 25, 3, -4, 11, -100 };	//������ ��� ����������

		//������ ��������� �������
		std::cout << "������ ���� int:\n";
		for (int i = 0; i < sizeof(nAr) / sizeof(nAr[0]); i++)
		{
			std::cout << nAr[i] << ' ';
		}
		std::cout << "\n";

		//����� ����������
		std::cout << "��������������� ������ ���� int:\n";
		int nTotal = (sizeof(nAr) / sizeof(nAr[0]));			//���������� ��������� � �������
		Sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), SwapInt, CmpInt);

		//������ ����������� ����������
		for (int i = 0; i < sizeof(nAr) / sizeof(nAr[0]); i++)
		{
			std::cout << nAr[i] << ' ';
		}
		std::cout << "\n";

		stop


			//������� 3�. �� �������� � 8� �������� ���������������
			//������� - SwapDouble � CmpDouble � �������� ������� Sort
			//��� ���������� ������� ������������ ��������.
			std::cout << "\n������ ���� double:\n";
		double dAr[] = { 40.1, 15.2, 8.3, -22.44, 71.5, -95.8 };	//������ ��� ����������

		//������ ��������� �������
		for (int i = 0; i < sizeof(dAr) / sizeof(dAr[0]); i++)
		{
			std::cout << dAr[i] << ' ';
		}
		std::cout << "\n";

		//����� ����������
		int dTotal = (sizeof(dAr) / sizeof(dAr[0]));			//���������� ��������� � �������
		Sort(reinterpret_cast<char*>(&dAr[0]), dTotal, sizeof(double), SwapDouble, CmpDouble);
		std::cout << "��������������� ������ ���� double:\n";
		//������ ����������� ����������
		for (int i = 0; i < sizeof(dAr) / sizeof(dAr[0]); i++)
		{
			std::cout << dAr[i] << ' ';
		}
		std::cout << "\n";

		stop

			//������� 3�*. �� �������� � 8� �������� ���������������
			//������� - SwapStr � CmpStr � �������� ������� Sort
			//��� ���������� ������� ���������� �� ������.
			std::cout << "\n������ ���� str:\n";
		char s[] = "QWERTY";
		const char* arStr[5] = { "WWW", "SDF", "ABC", &s[0], "BDE" };
		for (int i = 0; i < 5; i++)
		{
			std::cout << arStr[i] << " ";
		}
		std::cout << "\n";
		int cTotal = 5;
		Sort(reinterpret_cast<char*>(&arStr[0]), cTotal, sizeof(char*), SwapStr, CmpStr);
		for (int i = 0; i < 5; i++)
		{
			std::cout << arStr[i] << " ";
		}
		std::cout << "\n";

		stop
	}

	{
	//������� 4. ������� ���������� �� �������.
	std::cout << "====================================================================\n\n������� 5.4.\n\n";
	//�������� ��������� ������� ����
	//const char* GetString1();
	//const char* GetString2();
	//		...., ������ �� ������� ���������� ��������� �� ���� ������
	//(��������� - ����� ����� �� ������ ����� ���������� �� �������)


	//�������� � ������������������ ������ ���������� �� �������
	//GetString1,GetString2...
	const char* (*MUF[5])() = { &GetString1, &GetString2, &GetString3, &GetString4, &GetString5 };

	//������� ����� �������, ������� �� ������ �������:
	int n = 4;

	//�������� ������� 
	const char* r = MUF[n]();

	//������������ ���������
	printf("%s \n", r);
	stop
	}
//////////////////////////////////////////////////////////////////////////////////////

	//����. ��������� �.
	std::cout << "====================================================================\n\n������� 5.5.\n\n";
	//������� 5. �������� ��������� BOOK, ����������� �����
	//(�����, ��������, ��� �������, ����, ����������).
	//���������: ������ ���� ����� ���� ���� ���������.
	//���������: ���������� ��������� ������������� ��������
	//� ������������ ����.

	//��. � other.h


	//������� 6. �������� ������� ��������� (����������, ���������, �����������,
	//������������) ���������� (�������) ���� BOOK (��� �������������).
	//���������� - ������� ������ ������� ���������� ��� ������
	//����� ������. ��� ���������������� (��� �� ����������������) ����
	//���������. ���������: �� ���� ������� ����� ���������� ������?

	static BOOK staticBook;
	BOOK *pbook = new BOOK();
	BOOK book1;


	//������� 7. ��������� ���� ��������� ��������.
	//���������: ���� ��� �������� ������ ������������ ������, ����������
	//������������� "������" �� ������ �� ������� �������.

	book1.year = 1984;
	book1.price = 500.00;
	BookSetTitle(book1, "����������");
	BookSetAuthor(book1, "������");
	BookSetCategory(book1, "������ �����");
	
	pbook->year = 2000;
	pbook->price = 500.00;
	BookSetTitle(*pbook, "������� ����");
	BookSetAuthor(*pbook, "������");
	BookSetCategory(*pbook, "�����������");

	globalBOOK.year = 1999;
	globalBOOK.price = 500.00;
	BookSetTitle(globalBOOK, "������");
	BookSetAuthor(globalBOOK, "�������");
	BookSetCategory(globalBOOK, "������ �����");

	staticBook.year = 2010;
	staticBook.price = 500.00;
	BookSetTitle(staticBook, "�����");
	BookSetAuthor(staticBook, "��������");
	BookSetCategory(staticBook, "������ �����");


	printf("������ ����������� �����: %lu \n", sizeof(staticBook));
	//printBOOK(staticBook);
	printf("������ ���������� �����: %lu \n", sizeof(globalBOOK));
	//printBOOK(globalBOOK);
	printf("������ ��������� �����: %lu \n", sizeof(book1));
	//printBOOK(book1);
	printf("������ ������������ �����: %lu \n", sizeof(*pbook));
	//printBOOK(*pbook);
	
	stop
		//������� 8. �������� �������, ��������� �� ����� ��������� �����.
		//���������: ��� ����������� ���������� ��������� BOOK � �������.
		//��� ������ �� ������� ����������� ������� ����������� ����������
		//printf

	printBOOK(staticBook);
	printBOOK(globalBOOK);
	printBOOK(book1);
	printBOOK(*pbook);
	
	stop
	//������� 9. �������� ������� ��� ������������ ����� ���������.
	//��� ����� ����������� ������� ����������� ���������� scanf
	//���������: ������� �������� � ����� ������� ����������� ��������
	//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
	//������, ���... (��� ��������� ������������), ��������� ������������
	//������ �������� �� ������������, ���� �� ����� ���� �������������...

	BOOK *book2 = makeBook();
	printBOOK(*book2);
	delete book2;
	
	stop
	return 0;
	
}//main

