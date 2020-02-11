#include "Point.h"
#include <iostream>

Point::Point(int x, int y)
{
	m_x = x;
	m_y = y;
	this->Print_Point();
}

Point::~Point()
{
}

void Point::Print_Point()
{
	std::cout << "Это метод Print_Point\n" << "(" << m_x << ", " << m_y << ")" << "\n";
}

Point& Point::operator+=(const int& value)
{
	m_x += value;
	m_y += value;
	return *this;
}
Point& Point::operator+=(const Point& value)
{
	m_x += value.m_x;
	m_y += value.m_y;
	return *this;
}
Point& Point::operator-=(const int& value)
{
	m_x -= value;
	m_y -= value;
	return *this;
}
Point& Point::operator-=(const Point& value)
{
	m_x -= value.m_x;
	m_y -= value.m_y;
	return *this;
}

Point Point::operator+(const Point& value)
{
	return Point(m_x + value.m_x, m_y + value.m_y);
}
Point Point::operator+(const int& value)
{
	return Point(m_x + value, m_y + value);
}
Point Point::operator-(const Point& value)
{
	return Point(m_x - value.m_x, m_y - value.m_y);
}
Point Point::operator-(const int& value)
{
	return Point(m_x - value, m_y - value);
}

Point& Point::operator-()
{
	m_x *= -1;
	m_y *= -1;
	return *this;
}
Point& Point::operator+()
{
	return *this;
}

//Глобальные функции
Point operator+(const int& value, const Point& p) {
	return Point(p) + value;
}
Point operator-(const int& value, const Point& p) {
	return Point(p) - value;
}