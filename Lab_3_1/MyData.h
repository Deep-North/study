#pragma once

#include <iostream>
#include "myString.h" 

class MyData
{
public:
	enum Sex { UNDEF, MALE, FEMALE };	//Выбор пола
private:
	Sex m_sex;							//пол
	unsigned short m_age;				//возраст
	MyString m_job;						//название работы
	float m_salary;						//зарплата

public:
	MyData();															//конструктор по-умолчанию
	MyData(Sex s, unsigned short age, const char* job, float sal);		//конструктор с параметрами
	~MyData();															//деструктор

	MyData(const MyData& d);											//конструктор копирования
	MyData & operator=(const MyData& d);								//перегрузка оператора "="

	friend std::ostream& operator<<(std::ostream& os, const MyData& d);	//перегрузка оператора "<<" внутри класса
};

std::ostream& operator<< (std::ostream&, const MyData&);				//перегрузка оператора "<<" глобальной функцией

