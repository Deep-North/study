#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

const char * massCategory[] = { "Nauka", "Lingvistika", "Proza", "Poesiya", "Hudozhestvennaya" };

void printBOOKinLine(BOOK * a)
{
	printf("%s %s %s %4.2f %d\n", a->title, a->author, massCategory[a->category], a->price, a->year );
}

void printBOOK(BOOK * b) {
	printf("�����\n{\n��������: %s\n", b->title);
	printf("�����: %s,\n", b->author);
	printf("���������: %s,\n", massCategory[b->category - 1]);
	printf("����: %4.2f,\n", b->price);
	printf("��� �������: %d. \n}\n\n", b->year);
}

void ScanBook(BOOK * a)
{
	printf("\n��������� ���� ��������� \"BOOK\".\n");
	
	printf("������� ������: ");
	scanf("%31s", a->author);
	fflush(stdin);
	
	printf("������� ��������: ");
	fflush(stdin);
	scanf("%63s", a->title);
	fflush(stdin);
	
	printf("������� ��� �������: ");
	int checkd = 0;
	char checks[7];
	do
	{
		scanf("%4s", &checks);
		fflush(stdin);
		sscanf(checks, "%d", &checkd);
		if (checkd <= 1700 || checkd >= 2018)
		{
			printf("������! ��� ������� �� ����� ���� ������ ���� ��������� ������������!\n������� ��������� ����:\n");
		}
		else
		{
			sscanf(checks, "%d", &a->year);
		}
	} while (checkd<=1700 || checkd>=2018);

	printf("������� ����: ");

	double checklf = 0;
	do
	{
		scanf("%11s", &checks);
		fflush(stdin);
		sscanf(checks, "%lf", &checklf);
		if (checklf < 0 || checklf>999999)
		{
			printf("������! ���� �� ����� ���� �������������!\n");
		}
		else
		{
			sscanf(checks, "%f", &a->price);
		}
	} while (checklf < 0 || checklf>999999);
	
	printf("������� ��������� (������� �����) �� �����������.\n");
	printf("�������� ��������� �����:\n 1 - Nauka\n 2 - Lingvistika\n 3 - Proza\n 4 - Poesiya\n 5 - Hudozhestvennaya\n");
	do
	{
		scanf("%2s", &checks);
		fflush(stdin);
		sscanf(checks, "%d", &checkd);
		if (checkd < 1 || checkd>5)
		{
			printf("������! �������� �� ������������ ���������!");
		}
		else
		{
			a->category = static_cast<eCategory>(checkd);
		}
	} while (checkd<1 || checkd>5);

}