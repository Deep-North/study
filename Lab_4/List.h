#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Node.h"
#include "Circle.h"


class List
{
	Node Head;				// фиктивный элемент, который является признаком начала списка
	Node Tail;				// фиктивный элемент, который является признаком конца списка
	unsigned int m_size;	// количество элементов

public:
	List();
	List(const List&);
	List(List&&);
	virtual ~List();

	void AddToHead(Circle*);
	void AddToTail(Circle*);

	bool Remove(const Circle*);			//удаление из списка первого элемента, данное которого совпадает со значением параметра
	int RemoveAll(const Circle*);		//удаление из списка всех элементов, данное которых совпадает со значением параметра
	int RemoveAll(const Circle*, int);
	void Clear();						//Очистка списка
	
	void Swap(Node*, Node*);
	void SortBySquare();

	List& operator=(const List&);
	List& operator=(List&&);

	friend std::ostream& operator<<(std::ostream&, const List&);
	friend void operator<<(List&, std::istream&);

private:
	void Copy(const List&);				//конструктор копирования
};

std::ostream& operator<< (std::ostream&, const List&);
void operator<<(List&, std::istream&);