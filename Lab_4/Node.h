#pragma once

#include <iostream>
#include "Circle.h"

class List;


class Node {

public:
	enum N_TYPE { HEAD, TAIL, NODE };

private:

	Node * m_pPrev;		//указатель на предыдущий элемент
	Node * m_pNext;		//указатель на следующий элемент
	Circle m_Data;
	N_TYPE m_type;

	Node();
	Node(N_TYPE);
	Node(const Node& value);
	Node(const Node&& value);
	Node(const Circle *);
	~Node();

	bool isHead() const;
	bool isTail() const;
	Node *GetNext() const;
	Node *GetPrev() const;
	Node& operator=(const Node&);

	friend List;
	friend std::ostream& operator<<(std::ostream&, const Node&);
	friend std::ostream& operator<<(std::ostream&, const List&);
	friend bool operator< (const Node&, const Node&);
	friend bool operator> (const Node&, const Node&);
};


std::ostream& operator<< (std::ostream&, const Node&);
bool operator< (const Node&, const Node&);
bool operator> (const Node&, const Node&);