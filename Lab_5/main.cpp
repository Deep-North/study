/*
—татические члены класса
«адание: требуетс€ реализовать класс MyString таким образом, чтобы все строки хранились в единственном экземпл€ре.
Ёто можно сделать так (посредством односв€зного списка):

тут должна быть картинка


¬спомогательный класс Counter
€вл€етс€ "оберткой" дл€ строки и содержит вспомогательные данные, которые в частности позвол€т избежать дублировани€ данных.
ѕеременные (обычные):
Х	указатель на динамически создаваемую строку Ц m_pStr
Х	счетчик пользователей данной строки - m_nOwners
Х	указатель на следующий Counter Ц pNext
ћетоды:
Х	конструктор (конструкторы)
Х	деструктор
Х	добавить пользовател€
Х	убрать пользовател€ (что делать, если это был последний пользователь, и строка больше никому не нужна?)
Х	Е

ƒл€ того, чтобы обеспечить хранение строки в единственном экземпл€ре,
в классе Counter должен хранитьс€ в единственном экземпл€ре перечень всех вспомогательных оберток,
(таким образом, в любой момент выполнени€ программы можно получить перечень всех используемых строк).
¬ведем статические данные:
static Counter* Head;
ј также счетчик указателей:
static unsigned int m_curCounters;
—ледует предусмотреть определение и инициализацию статических данных.

ќсновной класс MyString
содержит единственное данное Ц указатель на "свой" Counter Ц
Counter* m_pMyCounter
¬ведите необходимые на ¬аш взгл€д методы (Ђджентльменский наборї дл€ сложного класса)..

ƒл€ манипул€ции всеми строками введите в класс статические методы:
Х	распечатать все строки
Х	во всех объектах MyString изменить регистр
Х	вывести строки по алфавиту
Х	Е

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