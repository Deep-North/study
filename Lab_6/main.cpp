/*
Второй семестр. RTTI
Практическое занятие
Задание:
Создать класс, реализующий объектно-ориентированный список для объектов, производных от одного и того же базового класса.
1.	Создайте базовый класс Shape и производные от него классы Rect, Circle…
Подумайте, какие методы и переменные должны быть определены (переопределены) в каждом из этих классе.
Обратите внимание на спецификаторы доступа и «виртуальность» методов.
Предусмотрите возможность вычисления площади для объекта каждого производного класса.
2.	Механизм RTTI
Так как объекты могут быть разного типа, Вам понадобиться определение действительного типа объекта во время выполнения.
2.1.	Понятие RTTI
Run-Time Type Information (RTTI) – динамическая идентификация типа объекта: при компиляции программы не всегда есть
возможность выяснить, на объект какого типа на самом деле указывает указатель на базовый класс.
Механизм RTTI позволяет для полиморфных (то есть только при наличие в базовом классе виртуальных функций) определять
тип объекта во время выполнения программы. Для обеспечения этого механизма в стандартизованных версиях С++ существуют
следующие понятия:
1)	оператор dynamic_cast – для преобразования типа указателя (или ссылки) полиморфных типов;
2)	оператор typeid – для идентификации точного типа объекта
3)	класс type_info – тип объекта, возвращаемого typeid-оператором.

2.2.	Для обеспечения работы механизма RTTI:
1)	в опциях проекта Project/Settings/C/C++/Category/C++ Language – проверьте, что  Enable RTTI установлен
2)	#include <typeinfo>

2.3.	Пример использования оператора dynamic_cast
Оператор dynamic_cast возвращает приведенный к указанному типу указатель, если объект соответствует запрашиваемому типу,
иначе нулевое значение.
void SomeFunc(CShape* p)
{
	if(Rect* pr = dynamic_cast<Rect*>(p))//если не нулевое значение, значит объект типа Rect
	{
		pr->...		//имеем право использовать приведенный указатель для обращения к членам производного
		класса Rect (например, к невиртуальным методам производного класса)
	}
}

3.	Разработаем двухсвязный список, элементы которого будут являться копиями наших объектов
Замечание: так как в списке будут фигурировать копии объектов – нам все равно, каким образом объекты-оригиналы
были созданы (глобальные, локальные, динамические, автоматические неименованные) => манипулируя списком,
мы несем ответственность только за уничтожение копий, а оригиналы создаются и уничтожаются независимо.
Список реализуется двумя классами:
3.1.	Вспомогательный класс для хранения данных и связей между объектами.
1) Модифицируйте объявление вспомогательного класса Node:
class Node
{
	Node* pPrevious;	//указатель на предыдущий элемент
	Node* pNext;		//указатель на следующий элемент
	//подумайте: каким образом следует “хранить” данное???

public:
	//…
};


2) Модифицируйте реализацию методов класса Node. Подумайте: какие ранее разработанные Вами методы и каким
образом следует изменить???

3.2.	Основной класс, реализующий список
Теперь вспомогательный класс Node можно использовать при создании связного списка из объектов, производных от
Shape - создадим еще один класс для реализации списка – List.

1)	Модифицируйте объявление класса
2)	Модифицируйте реализацию методов


Подсказка: скорее всего Вам понадобится для реализации метода Remove() в классе Shape и производных классах перегрузить
оператор == или != (возможно следует сделать его виртуальным!)

4.	Сортировка
Напишите для класса List сортировку по возрастанию площади объекта (по цвету, по удалению от начала координат…).
5.	Вывод списка в файл и чтение из файла

1) Результаты сортировки выведите в файл. Для файловых операций воспользуйтесь потоком ofstream.
Пример вывода в файл:

#include <fstream>
…
{
	cout<<"Enter Output File Name  - " ;
	char ar[80];
	cin>>ar;
	ofstream fout(ar);
	fout<<100<<endl;
	fout.close();}

*/

#include <fstream>
#include <typeinfo>
#include "Point.h"
#include "Circle.h" 
#include "Shape.h"
#include "Rect.h"
#include "Node.h"
#include "List.h"

#define	  stop 

//
int main(int argc, char* argv[])
{

    {
        Circle c1 (0,0, 1);
        Rect r1  (1,4,1,4); 
        Rect r2  (1,43,1,42);
        Rect *pR3 = new Rect(1,1,1,1);
        
        List list; 
        list.AddToHead(&r1);
        list.AddToHead(&r2);
        list.AddToHead(&c1);  
        list.AddToHead(pR3);
        delete pR3;
        pR3 = nullptr;
        
        std::cout << list << std::endl;   
        
        list.SortBySquare();
        std::cout << list << std::endl;
        
    }

    {
        
        Circle c1(0,0, 1);
        Circle c2(0,0, 2);
        Rect r1(0,0, 3,0);
        Circle c4(0,0, 4);
        Circle c5(0,0, 5);
        
        List min;
        min.AddToTail(&c1);
        min.AddToTail(&c1);
        min.AddToTail(&r1);
        min.AddToTail(&r1);
        List big; 
        big.AddToTail(&c2);
        big.AddToTail(&r1);
        big.AddToTail(&c4);
        big.AddToTail(&c5);
        
       
        
        min = big;
        std::cout << "minCopy = bigCopy >>> " << std::endl;
        std::cout << "Min copy\n" << min << std::endl;
        std::cout << "Big copy\n" << big << std::endl;
        //std::cout << "Big copy\n" << bigCopy << std::endl;
        //return 0;
        
        List minCopy = min;
        std::cout << "testMoveList" << std::endl;
        minCopy = testMoveList();
        List bigCopy = List(big);
        
    
        std::cout << "Min copy\n" << minCopy << std::endl;
        //std::cout << "Big copy\n" << bigCopy << std::endl;
       
        minCopy = bigCopy;
        std::cout << "minCopy = bigCopy >>> " << std::endl;
        std::cout << "Min copy\n" << minCopy << std::endl;
        //std::cout << "Big copy\n" << bigCopy << std::endl;
        //return 0;
        
        std::cout << "Min copy\n" << min << std::endl;
        std::cout << "Big copy\n" << big << std::endl;
         
        big = min;
        std::cout << "min = big >>> " << std::endl;
        std::cout << "Min copy\n" << min << std::endl;
        std::cout << "Big copy\n" << big << std::endl; 
        

    }

    
    //1. сортировку по возрастанию площади объекта.
    {
    
        
        List list;
        for (int i = 0; i < 8; i ++) {
            Circle c(0,0, i*i);
            if (i % 2 == 0) {
                list.AddToTail(&c);
            } else {
                list.AddToHead(&c);
            } 
        }
        
        for (int i = 10; i < 18; i ++) {
            Rect r(0,i, 0, i, i % 2 == 0 ? Shape::BLUE : Shape::RED);
            if (i % 2 == 0) {                
                list.AddToTail(&r);
            } else {
                list.AddToHead(&r);
            } 
        }
        
        
       // std::cout << list << std::endl;
        
        
        list.SortBySquare();
      
        
        std::cout << list << std::endl;

        { 
            std::cout << "Enter Output File Name  - " ;
            char ar[80] = "test.txt";
            //std::cin >> ar;
            std::cout << "Save data to - "  << ar << "\n";
            std::ofstream fout(ar);
            fout << list;
            fout.close();
            
            //LOAD
            std::cout << "Load data from - "  << ar << "\n";
            List nList;
            std::ifstream fin(ar, std::ifstream::in);           
            nList << fin;            
            fin.close();
            
            std::cout << nList;
          
        } 
    }	
    return 0;
}

