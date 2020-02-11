#include "Circle.h"
#include <iostream>

Circle::Circle()
{
}

//Circle::Circle(int x, int y, int rad)
//{
//	m_x = x;
//	m_y = y;
//	m_rad = rad;
//	std::cout << "Это просто конструктор Circle\n" << "\n";
//}

Circle::Circle(int x, int y, int rad, Shape::eColor color):Shape(color)
{
	m_x = x;
	m_y = y;
	m_rad = rad;
	//m_color = color;
	std::cout << "Это просто конструктор Circle с цветом\n" << "\n";
	Circle::WhereAmI();
}

Circle::~Circle()
{
	std::cout << "Now I am in Circle's destructor!\n";
}

void Circle::Print_Circle()
{
	std::cout << "Это метод Print_Circle\n" << "(" << m_x << ", " << m_y << ", " << m_rad << ", " << Shape::GetColor() << ")\n";
}

void Circle::WhereAmI()
{
	std::cout << "Now I am in class Circle\n";
}

Circle::Circle(const Circle & other) :Shape(other)
{
	m_x = other.m_x;
	m_y = other.m_y;
	m_rad = other.m_rad;
	this->Print_Circle();
	std::cout << "\nЭто конструктор копирования Circle\n";
}

Circle::Circle(const Rect2 & other) :Shape(other)
{
	int left, right, top, bottom;
	other.GetAll(left, right, top, bottom);
	m_x = (left + right) / 2;
	m_y = (top + bottom) / 2;
	m_rad = right - left > bottom - top ? bottom - top : right - left;

	//this->Print_Rect();
	std::cout << "\nЭто конструктор копирования Circle to Rect\n";
}

void Circle::Inflate(int incr)
{
	m_rad += incr;
	this->Print_Circle();
}