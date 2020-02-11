#include "Circle.h"
#include <iostream>

Circle::Circle() : m_p() {
	m_radius = 1;
}

Circle::Circle(int x, int y, int radius) : m_p(x, y) {
	m_radius = radius;
}

Circle::Circle(const Circle& value) : m_p(value.m_p) {
	m_radius = value.m_radius;
}

Circle::Circle(const Circle&& value) : m_p(value.m_p) {
	m_radius = value.m_radius;

}

Circle::~Circle() {
}

int Circle::GetSquare() const {
	return (3.1415 * m_radius  * m_radius);
}

int Circle::GetRadius() const {
	return m_radius;
}

bool Circle::operator==(const Circle& c) {
	return (c.m_radius == m_radius && c.m_p == m_p);
}

bool operator==(const Circle& b, const Circle& a) {
	return (a.m_radius == b.m_radius && b.m_p == a.m_p);
}

Circle& Circle::operator=(const Circle& c) {
	m_radius = c.GetRadius();
	m_p.m_x = c.m_p.m_x;
	m_p.m_y = c.m_p.m_y;
	return *this;
}


void Circle::Inflate(int size) {
	m_radius += size;
	std::cout << "Radius of circle inflated on " << size << "\n";
}

void Circle::WhereAmI() {
	std::cout << "Now I am in class Circle\n";
};

std::ostream& operator<< (std::ostream& stream, const Circle& c) {
	stream << "coordinates: x " << c.m_p.getX() << ", y " << c.m_p.getY() << ", radius " << c.m_radius << "\n";
	return stream;
}