#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"
#include "Functions.h"

#include <cstring>
#include <iostream>

extern BOOK * pBook;
extern int KolichestvoKnig;


int Menu()
{
	char MenuItem[3];
	int MenuCounter;

	enum
	{
		SHOW_ALL = 1,
		SHOW_ONE,
		CREATE_NEW,
		DELETE_OLD,
		SAVE_TO_FILE,
		LOAD_FROM_FILE,
		SORT,
		EXIT
	};

	printf("\n\nМеню: \n1-Печать картотеки. 2-Вывести книгу. 3-Ввести новую книгу. \n4-удалить старую книгу. 5-Сохранить картотеку в файл. \n6-Считать содержимое из файла в картотеку. 7-Вывести отсортированную картотеку. 8-Выход из программы.\n\nВыберите действие: ");
	scanf("%2s", MenuItem);
	fflush(stdin);
	sscanf(MenuItem, "%d", &MenuCounter);
	fflush(stdin);

	switch (MenuCounter)
	{
	case SHOW_ALL:
		printf("\nВсе книги:\n");
		ShowBooks();
		break;

	case SHOW_ONE:
		printf("\nВведите номер книги\n");
		int numBooks;
		scanf("%d", &numBooks);
		fflush(stdin);
		if ((numBooks <= KolichestvoKnig) && (numBooks >0))
		{
			printBOOK(&pBook[numBooks - 1]);
		}
		else
		{
			printf("\nТакой книги нет\n");
		}
		break;

	case CREATE_NEW:
		AddNewBook();
		break;

	case DELETE_OLD:
		printf("\nВведите номер книги для удаления.\n");
		int numBookd;
		scanf("%d", &numBookd);
		fflush(stdin);
		if ((numBookd <= KolichestvoKnig) && (numBookd >0))
		{
			DeleteBook(numBookd);
		}
		else
		{
			printf("\nТакой книги нет.\n");
		}
		break;

	case SAVE_TO_FILE:
		SaveToFile();
		break;

	case LOAD_FROM_FILE:
		LoadFromFile();
		break;

	case SORT:
		SortMenu();
		break;

	case EXIT:
		return (0);
		break;

	default:
		printf("\nОшибка! Выберите правильный пункт меню.\n");
		break;
	}
	return 1;
}

void ShowBooks()
{
	printf("\n");
	for (int i = 0; i < KolichestvoKnig; i++)
	{
		printf("№%d ", i + 1);
		printBOOK(&pBook[i]);
	}
}

void AddNewBook()
{
	KolichestvoKnig++;
	BOOK * tmppBook = new BOOK[KolichestvoKnig];
	memcpy(tmppBook, pBook, sizeof(BOOK)*(KolichestvoKnig));
	delete pBook;
	pBook = tmppBook;
	tmppBook = 0;
	ScanBook(&pBook[KolichestvoKnig - 1]);
}

void DeleteBook(int num)
{
	KolichestvoKnig--;
	BOOK * tmppBook = new BOOK[KolichestvoKnig];
	memcpy(tmppBook, pBook, sizeof(BOOK)*(num - 1));
	memcpy(&tmppBook[num - 1], &pBook[num], sizeof(BOOK)*(KolichestvoKnig - num + 1));
	delete pBook;
	pBook = tmppBook;
	tmppBook = 0;
}

void SaveToFile()
{
	FILE * file = fopen("MyBooks_add.txt", "w");
	const char * massCategory[] = { "Nauka", "Lingvistika", "Proza", "Poesiya", "Hudozhestvennaya" };
	if (file)
	{
		for (int i = 0; i < KolichestvoKnig; i++)
		{
			BOOK * b = &pBook[i];
			fprintf(file, "%4.2f %d %s %s %s\n", b->price, b->year, b->title, b->author, massCategory[b->category-1]);
		}
		fclose(file);
		printf("Файл записан");
	}
	else
	{
		printf("Не удалось открыть файл. Возможно его не существует");
	}
}

void LoadFromFile()
{
	FILE * file = fopen("MyBooks.txt", "r");
	char Mcategory[5][17] = { "Nauka", "Lingvistika", "Proza", "Poesiya", "Hudozhestvennaya" };
	int newKK = 0;
	int counter = 0;
	char eof[50];
	char eof1[50];
	char tmpcategory[17];

	if (file)
	{
		do          //считаю количество строк в файле, который буду открывать
		{
			strcpy(eof1, eof);
			counter++;
			fscanf(file, "%s", eof);
		} while (strcmp(eof1, eof));

		newKK = KolichestvoKnig + (counter - 1) / 5; // количество строк
		BOOK * pnewBook = new BOOK[newKK];
		memcpy(pnewBook, pBook, sizeof(BOOK)*(KolichestvoKnig));
		delete pBook;
		fclose(file); //закрываю, т.к. мы теперь находимся в конце файла и не можем считывать строки 

		FILE * file = fopen("MyBooks.txt", "r");
		if (file)
		{

			for (int i = KolichestvoKnig; i < newKK; i++)
			{
				BOOK * b = &pnewBook[i];
				fscanf(file, "%4.2f %d %s %s %s\n", b->price, b->year, b->title, b->author, tmpcategory);

				for (int j = 0; j < 5; j++)
				{
					if (!strcmp(tmpcategory, &Mcategory[j][0]))
					{
						b->category = static_cast<eCategory>(j);
					}
				}

			}
			KolichestvoKnig = newKK;

			pBook = pnewBook;
			pnewBook = 0;
		}
		fclose(file);
	}
	else
	{
		printf("Не удалось открыть файл. Возможно его не существует");
	}

}

void SortMenu()
{
	char MenuItem[3];
	int MenuCounter;
	enum
	{
		AUTHOR = 1,
		TITLE,
		YEAR,
		PRICE,
		CATEGORY,
		YEAR2,
		EXIT
	};

	printf("\n\nСортировка по: \n1-автору. 2-названию. 3-году. 4-цене. 5-категории. 6-году*. 7-выход.\n\nВведите номер пункта: ");
	scanf("%2s", MenuItem);
	fflush(stdin);
	sscanf(MenuItem, "%d", &MenuCounter);
	fflush(stdin);


	switch (MenuCounter)
	{
	case AUTHOR:
		Sort(reinterpret_cast<char*>(&pBook[0].author), KolichestvoKnig, sizeof(BOOK), SwapBookS, CmpStr);
		break;
	case TITLE:
		Sort(reinterpret_cast<char*>(&pBook[0].title), KolichestvoKnig, sizeof(BOOK), SwapBookS, CmpStr);
		break;
	case YEAR:
		Sort(reinterpret_cast<char*>(&pBook[0].year), KolichestvoKnig, sizeof(BOOK), SwapBookS, CmpInt);
		break;
	case PRICE:
		Sort(reinterpret_cast<char*>(&pBook[0].price), KolichestvoKnig, sizeof(BOOK), SwapBookS, CmpD);
		break;
	case CATEGORY:
		Sort(reinterpret_cast<char*>(&pBook[0].category), KolichestvoKnig, sizeof(BOOK), SwapBookS, CmpInt);
		break;
	case YEAR2:
		SortByYearBooks();
		break;
	case EXIT:
		break;
	}
	ShowBooks();
}

void Sort(char* pcFirst, int nNumber, int size,
	void (*Swap)(BOOK*, BOOK*), int(*Compare)(void*, void*))
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
				(*Swap)((&pBook[j - 1]), (&pBook[j]));
			}
		}
	}
}

void Sort(char* pcFirst, int nNumber, int size,
	void(*Swap)(BOOK*, BOOK*), double(*Compare)(void*, void*))
{
	int i;
	for (i = 1; i<nNumber; i++)
		for (int j = nNumber - 1; j >= i; j--)
		{
			char* pCurrent = pcFirst + j * size;
			char* pPrevious = pcFirst + (j - 1)*size;
			if ((*Compare)(pPrevious, pCurrent) > 0)//требуется переставить
			{
				(*Swap)((&pBook[j - 1]), (&pBook[j]));
			}

		}
}

void SwapBookS(BOOK* p1, BOOK* p2)
{
	BOOK ptmp = *p2;
	*p2 = *p1;
	*p1 = ptmp;
}

int CmpStr(void* p1, void* p2)
{
	return strcmp(*static_cast<char**>(p1), *static_cast<char**>(p2));
}

int CmpInt(void* p1, void* p2)
{
	int nResult = *(static_cast<int*>(p1)) - *(static_cast<int*>(p2));
	return nResult;
}

double CmpD(void* p1, void* p2)
{
	double dResult = *static_cast<double*>(p1) - *static_cast<double*>(p2);
	return dResult < 0 ? -1 : (dResult > 0 ? 1 : 0);
}

void SortByYearBooks()
{
	int tmpmin = 3000;//минимальное значение из еще не упорядоченных значений
	int nummin = -1; //номер в (массиве книг) манимального значения из неупорядоченных.

	BOOK ** SortedpBooks = new BOOK *[KolichestvoKnig];
	bool * Flags = new bool[KolichestvoKnig];	// Создем флаги на случай, если у нас есть разные книги с одним годом. 
												// Тогда направляем указатель на какую-нибудь книгу
												// выставляется флаг в 0, и она больше в поиске минимального значения не участвует.
	for (int i = 0; i < KolichestvoKnig; i++)
	{
		Flags[i] = true;
	}
	for (int i = 0; i < KolichestvoKnig; i++)
	{
		tmpmin = 3000;
		for (int j = 0; j < KolichestvoKnig; j++)
		{
			BOOK * a = &pBook[j];

			if (Flags[j])
			{
				if (a->year < tmpmin)
				{
					tmpmin = a->year;
					nummin = j;
				}
			}
		}
		SortedpBooks[i] = &pBook[nummin];
		Flags[nummin] = false;
	}
	for (int i = 0; i < KolichestvoKnig; i++)
	{
		printf("№%2d ", i + 1);
		printBOOKinLine(SortedpBooks[i]);
	}
	delete[] Flags;
	delete[] SortedpBooks;
}