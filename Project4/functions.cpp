#include <iostream>
#include <cstdarg>

//Задание 2.
int IncByValue(int x)
{
	x++;
	return x;
}

void IncByPointer(int *x)
{
	(*x)++;
}

void IncByReference(int &x)
{
	x++;
}

//Задание 2.А
void Swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void Swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

//Задание 3.А1
int Min(int* mass, int n, int m)
{
	int min = *mass;
	for (int i=0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((*(mass + i*m + j)) < min) min = (*(mass + i*m + j));
		}
	}
	return min;
}
//Задание 3.А2
int Min(int** mass, int n, int m)
{
	int min = **mass;
	for (int i = 0; i < n; i++) \
	{
		for (int j = 0; j < m; j++)
		{
			if (mass[i][j] < min) min = mass[i][j];
		}
	}
	return min;
}

//Задание 3.Б
int MyStrCmp(const char * s1, const char * s2)
{
	int diff;

	for (; *s1 && *s1 == *s2; s1++, s2++)
		;
	diff = *s1 - *s2;
	return diff < 0 ? -1 : diff == 0 ? 0 : 1;
}

//Задание 4
int DayOfYear(int d, int m, int y, int (&ar)[2][12])
{
	bool isLeapYear = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	int sum = 0;
	for (int i = 0; i < m-1; i++)
	{
		sum = sum + ar[isLeapYear][i];
	}
	sum = sum + d;
	return sum;
}

void DayOfMonth(int y, int d, int(&ar1)[2][12], int(&ar2)[2])
{
	int mon = 0;
	int sum = 0;
	int day = 0;
	bool isLeapYear = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	while (sum <= d)
	{
		sum = sum + ar1[isLeapYear][mon];
		mon++;
	};
	day = d - sum + ar1[isLeapYear][mon] - 1;
	ar2[0] = day;
	ar2[1] = mon;
}

//Задание 5
void SymbolAddition(int* p1, int n)
{
	std::cout << "Введите новый символ:" << ' ';
	int tmp_n;
	std::cin >> tmp_n;
	bool marker = true;
	for (int i = 0; i < n; i++)
	{
		if (p1[i] == tmp_n) marker = false;
	}
	if (marker)
	{
		int* p2 = new int[n+1];
		memcpy(p2,p1,n*sizeof(int));
		p1 = p2;
		p1[n] = tmp_n;
		//Вывод массива для проверки
		std::cout << '\n';
		for (int i = 0; i < (n+1); i++)
		{
			std::cout << p1[i] << ' ';
		}
	}
	
}

//Задание 6
int RecursiveSum(int n)
{
	if (n == 1)
		return 1;
	else
		return n + RecursiveSum(n - 1);
}

//Задание 7.A
void VarArgs(int first, ...)
{
	int* p = &first;
	while (*p != 0)
	{
		std::cout << *p << ' ';
		p++;
	}
	std::cout << '\n';
}

//Задание 7.Б
void VarArgsStd(int first, ...)
{
	int i = first;
	va_list p;
	va_start(p, first);
	std::cout << "\n";
	while (i != 0)
	{
		std::cout << i << ' ';
		i = va_arg(p, int);
	}
	va_end(p);
}

//Задание 8
int* MyMin(int ar[], int n)
{
	int* p = ar;
	for (int i = 0; i < n; i++)
	{
		if (ar[i]<*p)
		{
			p = &ar[i];
		}
	}
	return p;
}