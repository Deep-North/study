#include "Shape.h"
#include <iostream>



Shape::Shape(eColor color):m_color(color)
{
	//m_color = color; вместо этого мы написали :m_color(color)
	Shape::WhereAmI();
}


Shape::~Shape()
{
	std::cout << "Now I am in Shape's destructor!\n";
}

Shape::eColor Shape::GetColor()
{
	return m_color;
}

void Shape::WhereAmI()			//virtual
{
	std::cout << "Now I am in class Shape\n";
}

void Shape::Inflate(int)		//virtual
{

}