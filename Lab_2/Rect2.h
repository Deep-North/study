#pragma once
#include "Shape.h"

class Rect2 :
	public Shape {

	int m_left, m_right, m_top, m_bottom;

public:
	//Rect2(int left = 0, int right = 0, int top = 0, int bottom = 0);		//������ �����������
	Rect2();																//����������� ��-���������.
	Rect2(int left, int right, int top, int bottom, Shape::eColor color);	//����������� � ������
	//void WhereAmI();
	virtual void WhereAmI();

	void Print_Rect();											//����� ������
	void Normalize();											//����� ������������

	void InflateRect(int dl, int dr, int dt, int db);			//����� ���������� � �������� �����������
	void InflateRect(int dx = 1, int dy = 1);					//����� ���������� � ����� �����������
	Rect2(const Rect2 & other);									//����������� �����������

	void SetAll(int left, int right, int top, int bottom);		//����� ������ ��������
	void GetAll(int &left, int &right, int &top, int &bottom) const;	//����� ���������� ��������

	virtual ~Rect2();											//����������

	virtual void Inflate(int);									//����� Inflate ��� ������������ ������
};

Rect2 BoundingRect(Rect2, Rect2);									//����� ������ � ������������� �� ��������
Rect2 BoundingRect(const Rect2 &R1, const Rect2 &R2);				//����� ������ � ������������� �� ������