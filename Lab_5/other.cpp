#define _CRT_SECURE_NO_WARNINGS
#include "other.h"

///////////////////////////////////////////////////


double Vybor(double a, double b, VyborOperacii operaciya)
{
	double(*func)(double a, double b);

	switch (operaciya)
	{
	case PLUS:
		func = &Sum;
		break;
	case MINUS:
		func = &Sub;
		break;
	case DIV:
		func = &Div;
		break;
	case MUL:
		func = &Mul;
		break;
	case POW:
		func = &Pow;
		break;
	default:
		func = &ErrFunc;
		break;
	}
	return func(a, b);
}

double Sum(double a, double b)
{
	return (a + b);
}
double Sub(double a, double b)
{
	return (a - b);
}
double Mul(double a, double b)
{
	return (a * b);
}
double Div(double a, double b)
{
	return (a / b);
}
double Pow(double a, double b)
{
	return pow (a, b);
}
double ErrFunc(double a, double b)
{
	std::cout << "Введите одну из операций: Sum, Sub, Mul, Div или Pow!\n";
	return 0.0;
}

////////////////////////////////////////////////////////////////////////////////////////

void SwapInt(void* p1, void* p2)
{
	int *a1 = static_cast<int*>(p1);
	int *a2 = static_cast<int*>(p2);

	int tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

int CmpInt(void* p1, void* p2)
{
	return (*static_cast<int*>(p1) - *static_cast<int*>(p2));
}

void SwapDouble(void* p1, void* p2)
{
	double *a1 = static_cast<double*>(p1);
	double *a2 = static_cast<double*>(p2);

	double tmp = *a1;
	*a1 = *a2;
	*a2 = tmp;
}

int CmpDouble(void* p1, void* p2)
{
	double dResult = *static_cast<double*>(p1) - *static_cast<double*>(p2);
	return dResult < 0 ? -1:(dResult > 0 ? 1:0);
}

void SwapStr(void* p1, void* p2)
{
	char **a1 = static_cast<char**>(p1);
	char **a2 = static_cast<char**>(p2);

	char *tmp= *a1;
	*a1 = *a2;
	*a2 = tmp;
}

int CmpStr(void* p1, void* p2)
{
	return strcmp (*static_cast<char**>(p1), *static_cast<char**>(p2));
}

void Sort(char* pcFirst, int nNumber, int size,
	void (*Swap)(void*, void*), int(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i < nNumber; i++)
	{
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//требуется переставить
			{
				(*Swap)(pPrevious, pCurrent);
			}
		}
	}
}
///////////////////////////////////////////////////////////////////////////////////////////

const char* GetString1()
{
	return "Stroka0";
}
const char* GetString2()
{
	return "Stroka1";
}
const char* GetString3()
{
	return "Stroka2";
}
const char* GetString4()
{
	return "Stroka3";
}
const char* GetString5()
{
	return "Stroka4";
}
///////////////////////////////////////////////////////////////////////////////////////////

void fill(char(&s)[max_dlina_stroki], const char *t)
{
	strncpy(&s[0], t, max_dlina_stroki);
}

void BookSetTitle(BOOK &b, const char *t)
{
	fill(b.title, t);
}
void BookSetAuthor(BOOK &b, const char *t)
{
	fill(b.author, t);
}
void BookSetCategory(BOOK &b, const char *t)
{
	fill(b.category, t);
}

void printBOOK(const BOOK &b) {
	printf("Книга\n{\nНазвание: %s,\nАвтор: %s,\nКатегория: %s,\nЦена: %4.2f,\nГод издания: %d. \n}\n\n",
		b.title, b.author, b.category, b.price, b.year);
}

BOOK * makeBook()
{
	BOOK *b = new BOOK();
	printf("Введите автора:\n");
	scanf("%255[^\n]%*c", b->author);
	printf("Введите название:\n");
	scanf("%255[^\n]%*c", &(*b).title[0]);
	printf("Введите категорию:\n");
	scanf("%255[^\n]%*c", &(*b).category[0]);
	printf("Введите год издания:\n");
	scanf("%d", &(*b).year);
	if (b->year < god_poyavleniya_pismennosti) {
		printf("Ошибка! Год издания не может быть меньше года появления письменности!\n");
		b->year = god_poyavleniya_pismennosti;
	}
	printf("Введите цену:\n");
	scanf("%f", &b->price);
	if (b->price < 0) {
		printf("Ошибка! Цена не может быть отрицательной!\n");
		b->price = 0;
	}
	return b;
}