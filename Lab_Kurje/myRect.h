#pragma once
class Rect{
private:
	int m_left, m_right, m_top, m_bottom;

public:
	Rect(int left = 0, int right = 0, int top = 0, int bottom = 0); //Просто конструктор
	//Rect();

	void Print_Rect();											//Метод печати
	void Normalize();											//Метод нормализации

	void InflateRect(int dl, int dr, int dt, int db);			//Метод увеличения с четырьмя параметрами
	void InflateRect(int dx = 1, int dy = 1);					//Метод увеличения с двумя параметрами
	Rect(const Rect & other);									//Конструктор копирования
	
	void SetAll(int left, int right, int top, int bottom);		//Метод записи значений
	void GetAll(int &left, int &right, int &top, int &bottom) const;	//Метод считывания значений

	~Rect();													//Деструктор
};

Rect BoundingRect(Rect, Rect);									//Метод вписки в прямоугольник по значению
Rect BoundingRect2(const Rect &R1, const Rect &R2);							//Метод вписки в прямоугольник по ссылке