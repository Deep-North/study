#include "Point.h"
#include <iostream>

Point::Point(int x, int y) {
	m_x = x;
	m_y = y;
	this->Print_Point();
}

Point::Point(const Point& value) {
	m_x = value.m_x;
	m_y = value.m_y;
}

Point::Point(Point &&p) {
	m_x = p.m_x;
	m_y = p.m_y;
}

Point::~Point() {
}

void Point::Print_Point() {
	std::cout << "Это метод Print_Point\n" << "(" << m_x << ", " << m_y << ")" << "\n";
}

Point& Point::operator+=(const int& value) {
	m_x += value;
	m_y += value;
	return *this;
}
Point& Point::operator+=(const Point& value) {
	m_x += value.m_x;
	m_y += value.m_y;
	return *this;
}
Point& Point::operator-=(const int& value) {
	m_x -= value;
	m_y -= value;
	return *this;
}
Point& Point::operator-=(const Point& value) {
	m_x -= value.m_x;
	m_y -= value.m_y;
	return *this;
}

Point& Point::operator=(const Point& value) {
	m_x = value.m_x;
	m_y = value.m_y;
	return *this;
}
Point& Point::operator=(int i) {
	m_x = i;
	m_y = i;
	return *this;
}
Point& Point::operator=(Point&& value) {
	m_x = value.m_x;
	m_y = value.m_y;
	return *this;
}

Point Point::operator+(const Point& value) {
	return Point(m_x + value.m_x, m_y + value.m_y);
}
Point Point::operator+(const int& value) {
	return Point(m_x + value, m_y + value);
}
Point Point::operator-(const Point& value) {
	return Point(m_x - value.m_x, m_y - value.m_y);
}
Point Point::operator-(const int& value) {
	return Point(m_x - value, m_y - value);
}

Point& Point::operator-() {
	m_x *= -1;
	m_y *= -1;
	return *this;
}
Point& Point::operator+() {
	return *this;
}

int Point::getX() const {
	return m_x;
}
int Point::getY() const {
	return m_y;
}

//Глобальные функции
Point operator+(const int& value, const Point& p) {
	return Point(p) + value;
}
Point operator-(const int& value, const Point& p) {
	return Point(p) - value;
}
bool operator==(const Point& a, const Point& b) {
	return a.m_x == b.m_x && a.m_y == b.m_y;
}