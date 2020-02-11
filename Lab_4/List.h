#pragma once

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Node.h"
#include "Circle.h"


class List
{
	Node Head;				// ��������� �������, ������� �������� ��������� ������ ������
	Node Tail;				// ��������� �������, ������� �������� ��������� ����� ������
	unsigned int m_size;	// ���������� ���������

public:
	List();
	List(const List&);
	List(List&&);
	virtual ~List();

	void AddToHead(Circle*);
	void AddToTail(Circle*);

	bool Remove(const Circle*);			//�������� �� ������ ������� ��������, ������ �������� ��������� �� ��������� ���������
	int RemoveAll(const Circle*);		//�������� �� ������ ���� ���������, ������ ������� ��������� �� ��������� ���������
	int RemoveAll(const Circle*, int);
	void Clear();						//������� ������
	
	void Swap(Node*, Node*);
	void SortBySquare();

	List& operator=(const List&);
	List& operator=(List&&);

	friend std::ostream& operator<<(std::ostream&, const List&);
	friend void operator<<(List&, std::istream&);

private:
	void Copy(const List&);				//����������� �����������
};

std::ostream& operator<< (std::ostream&, const List&);
void operator<<(List&, std::istream&);