#pragma once
class Point
{
	int m_x, m_y;
public:
	Point(int x = 0, int y = 0);			// онструктор с параметрами по-умолчанию
	~Point();

	void Print_Point();

	Point& operator+=(const int&);
	Point& operator+=(const Point&);
	Point& operator-=(const int&);
	Point& operator-=(const Point&);

	Point operator+(const int&);
	Point operator+(const Point&);
	Point operator-(const int&);
	Point operator-(const Point&);

	Point& operator-();
	Point& operator+();
};

Point operator+(const int&, const Point&);
Point operator-(const int&, const Point&);

