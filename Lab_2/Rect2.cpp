#include "Rect2.h"
#include <iostream>

void Rect2::Print_Rect()
{
	std::cout << "Это метод Print_Rect\n" << "(" << m_left << ", " << m_right << ", " << m_top << ", " << m_bottom << ", " << Shape::GetColor() << ")\n";
}

void Rect2::Normalize()
{
	int tmp;
	if (m_left > m_right)
	{
		tmp = m_left;
		m_left = m_right;
		m_right = tmp;
		std::cout << "\nЭто метод Normalize по оси X\n";
	}
	if (m_top > m_bottom)
	{
		tmp = m_bottom;
		m_bottom = m_top;
		m_top = tmp;
		std::cout << "\nЭто метод Normalize по оси Y\n";
	}
}

//Rect2::Rect2(int left, int right, int top, int bottom) /*:Shape()*/
//{
//	m_left = left;
//	m_right = right;
//	m_top = top;
//	m_bottom = bottom;
//	//std::cout << "(" << left << ", " << right << ", " << top << ", " << bottom << ")"<< "\n";
//	std::cout << "Это просто конструктор Rect\n" << "\n";
//	this->Normalize();
//	this->Print_Rect();
//}

Rect2::Rect2(int left, int right, int top, int bottom, Shape::eColor color):Shape(color)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	//m_color = color;
	std::cout << "Это просто конструктор Rect2\n" << "\n";
	this->Normalize();
	this->Print_Rect();
	this->WhereAmI();
}

Rect2::Rect2() : Shape(Shape::RED)
{
	m_left = 0; m_right = 0; m_top = 0; m_bottom = 0;
	//initialize (0, 0, 0, 0);
}

void Rect2::WhereAmI()
{
	std::cout <<"Now I am in class Rect2\n";
}

void Rect2::InflateRect(int dl, int dr, int dt, int db)
{
	// TODO: Add your implementation code here.
	std::cout << "Метод InflateRect с четырьмя параметрами.\nПараметры до приращения: ";
	this->Print_Rect();
	m_left -= dl;
	m_right += dr;
	m_top -= dt;
	m_bottom += db;
	std::cout << "после приращения: ";
	this->Normalize();
	this->Print_Rect();
	//return 0;
}

void Rect2::InflateRect(int dx, int dy)
{
	// TODO: Add your implementation code here.
	std::cout << "Метод InflateRect с двумя параметрами.\nПараметры до приращения :";
	this->Print_Rect();
	m_left -= dx;
	m_right += dx;
	m_top -= dy;
	m_bottom += dy;
	std::cout << "после приращения :";
	this->Normalize();
	this->Print_Rect();
	//return 0;
}

void Rect2::Inflate(int incr)
{
	m_left -= incr;
	m_right += incr;
	m_top -= incr;
	m_bottom += incr;
	this->Normalize();
	this->Print_Rect();
}

Rect2::Rect2(const Rect2 & other):Shape(other) //конструктор копирования
{
	m_left = other.m_left;
	m_right = other.m_right;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
	this->Print_Rect();
	std::cout << "\nЭто конструктор копирования Rect2\n";
}

void Rect2::SetAll(int left, int right, int top, int bottom)
{
	m_left = left;
	m_right = right;
	m_top = top;
	m_bottom = bottom;
	Normalize();
	std::cout << "\nЭто метод SetAll\n";
	Print_Rect();
}

void Rect2::GetAll(int &left, int &right, int &top, int &bottom) const
{
	left = m_left;
	right = m_right;
	top = m_top;
	bottom = m_bottom;
	std::cout << "\nЭто метод GetAll\n";
}

Rect2 BoundingRect(Rect2 R1, Rect2 R2)
{
	int left1, right1, top1, bottom1;
	int left2, right2, top2, bottom2;
	int left_out, right_out, top_out, bottom_out;


	R1.GetAll(left1, right1, top1, bottom1);
	R2.GetAll(left2, right2, top2, bottom2);
	R1.Normalize();
	R2.Normalize();

	left_out = (left1 < left2) ? left1 : left2;
	right_out = (right1 > right2) ? right1 : right2;
	top_out = (top1 < top2) ? top1 : top2;
	bottom_out = (bottom1 > bottom2) ? bottom1 : bottom2;
	//Rect tmp;
	//tmp.SetAll(left_out, right_out, top_out, bottom_out);
	std::cout << "\nЭто метод BoundingRect\n";
	return Rect2(left_out, right_out, top_out, bottom_out, Shape::BLUE);
}

Rect2 BoundingRect(const Rect2 &R1, const Rect2 &R2)
{
	int left1, right1, top1, bottom1;
	int left2, right2, top2, bottom2;
	int left_out, right_out, top_out, bottom_out;
	//Rect tmp;

	R1.GetAll(left1, right1, top1, bottom1);
	R2.GetAll(left2, right2, top2, bottom2);


	left_out = (left1 < left2) ? left1 : left2;
	right_out = (right1 > right2) ? right1 : right2;
	top_out = (top1 < top2) ? top1 : top2;
	bottom_out = (bottom1 > bottom2) ? bottom1 : bottom2;

	//tmp.SetAll(left_out, right_out, top_out, bottom_out);
	std::cout << "\nЭто метод BoundingRect\n";
	return Rect2(left_out, right_out, top_out, bottom_out, Shape::BLUE);
}

Rect2::~Rect2()
{
	std::cout << "Now I am in Rect's destructor!\n";
}