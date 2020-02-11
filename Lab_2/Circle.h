#pragma once
#include "Shape.h"
#include "Rect2.h"

class Circle :
	public Shape
{
	int m_x, m_y, m_rad;
public:
	Circle();													//����������� ��-���������
	Circle(int x, int y, int rad, Shape::eColor color);			//����������� � �����������
	Circle(const Circle & other);								//����������� �����������
	Circle(const Rect2 & other);								//����� �������� � �������������
	virtual ~Circle();											//���������� (����������� � ������� ������)
	void Print_Circle();										//����� ������ �� �����
	virtual void WhereAmI();									//����� ����������� ������
	virtual void Inflate(int);									//����� Inflate ��� ������������ ������
};

