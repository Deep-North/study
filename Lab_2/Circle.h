#pragma once
#include "Shape.h"
#include "Rect2.h"

class Circle :
	public Shape
{
	int m_x, m_y, m_rad;
public:
	Circle();													//Конструктор по-умолчанию
	Circle(int x, int y, int rad, Shape::eColor color);			//Конструктор с параметрами
	Circle(const Circle & other);								//Конструктор копирования
	Circle(const Rect2 & other);								//Метод вписания в прямоугольник
	virtual ~Circle();											//Деструктор (виртуальный в базовом классе)
	void Print_Circle();										//Метод печати на экран
	virtual void WhereAmI();									//Метод определения вызова
	virtual void Inflate(int);									//Метод Inflate для производного класса
};

