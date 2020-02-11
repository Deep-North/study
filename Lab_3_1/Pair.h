#pragma once

#include <iostream>
#include "myString.h"
#include "MyData.h" 

class Pair
{
public:
	MyString m_key;	//ключ - фамилия
	MyData m_data;	//данные сотрудника
	Pair();
	~Pair();

	Pair(const char *k, const MyData& d);
	Pair(const Pair& other);
	Pair& operator=(const Pair& other);
	bool operator==(const char *k) const;

	friend class Base;
	friend std::ostream& operator<<(std::ostream& os, const Pair& pair);

};

std::ostream& operator<< (std::ostream&, const Pair&);

