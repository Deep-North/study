#pragma once
#include "Shape.h"

class Rect2 :
	public Shape {

	int m_left, m_right, m_top, m_bottom;

public:
	//Rect2(int left = 0, int right = 0, int top = 0, int bottom = 0);		//Просто конструктор
	Rect2();																//Конструктор по-умолчанию.
	Rect2(int left, int right, int top, int bottom, Shape::eColor color);	//Конструктор с цветом
	//void WhereAmI();
	virtual void WhereAmI();

	void Print_Rect();											//Метод печати
	void Normalize();											//Метод нормализации

	void InflateRect(int dl, int dr, int dt, int db);			//Метод увеличения с четырьмя параметрами
	void InflateRect(int dx = 1, int dy = 1);					//Метод увеличения с двумя параметрами
	Rect2(const Rect2 & other);									//Конструктор копирования

	void SetAll(int left, int right, int top, int bottom);		//Метод записи значений
	void GetAll(int &left, int &right, int &top, int &bottom) const;	//Метод считывания значений

	virtual ~Rect2();											//Деструктор

	virtual void Inflate(int);									//Метод Inflate для производного класса
};

Rect2 BoundingRect(Rect2, Rect2);									//Метод вписки в прямоугольник по значению
Rect2 BoundingRect(const Rect2 &R1, const Rect2 &R2);				//Метод вписки в прямоугольник по ссылке