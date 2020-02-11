#pragma once

#include <iostream>
#include "myString.h" 
#include "MyData.h" 
#include "Pair.h"

class BD
{
	size_t m_size;
	size_t m_capacity;
	Pair **m_pBase;

public:
	BD();
	~BD();

	BD(const BD& bd);
	MyData& operator[](const char * key);
	friend std::ostream& operator<<(std::ostream& os, const BD &bd);
};

std::ostream& operator<< (std::ostream&, const BD&);

