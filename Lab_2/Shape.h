#pragma once
class Shape
{
public:
	enum eColor { RED, GREEN, BLUE };
	Shape(eColor color=RED);
	virtual ~Shape();
	eColor GetColor();
	
	//void WhereAmI();
	virtual void WhereAmI();

	virtual void Inflate(int) = 0;
private:
	eColor m_color;
};

