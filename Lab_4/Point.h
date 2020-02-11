#pragma once

class Circle;

class Point
{
	int m_x, m_y;
public:
	Point(int x = 0, int y = 0);			// онструктор с параметрами по-умолчанию
	Point(const Point& value);
	Point(Point &&p);
	virtual ~Point();

	void Print_Point();

	Point& operator+=(const int&);
	Point& operator+=(const Point&);
	Point& operator-=(const int&);
	Point& operator-=(const Point&);
	Point& operator=(const Point&);
	Point& operator=(Point&&);
	Point& operator=(int);

	Point operator+(const int&);
	Point operator+(const Point&);
	Point operator-(const int&);
	Point operator-(const Point&);

	Point& operator-();
	Point& operator+();

	int getX() const;
	int getY() const;

	friend Circle;
	friend bool operator==(const Point&, const Point&);
};

Point operator+(const int&, const Point&);
Point operator-(const int&, const Point&);
bool operator==(const Point&, const Point&);