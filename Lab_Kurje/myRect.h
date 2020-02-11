#pragma once
class Rect{
private:
	int m_left, m_right, m_top, m_bottom;

public:
	Rect(int left = 0, int right = 0, int top = 0, int bottom = 0); //������ �����������
	//Rect();

	void Print_Rect();											//����� ������
	void Normalize();											//����� ������������

	void InflateRect(int dl, int dr, int dt, int db);			//����� ���������� � �������� �����������
	void InflateRect(int dx = 1, int dy = 1);					//����� ���������� � ����� �����������
	Rect(const Rect & other);									//����������� �����������
	
	void SetAll(int left, int right, int top, int bottom);		//����� ������ ��������
	void GetAll(int &left, int &right, int &top, int &bottom) const;	//����� ���������� ��������

	~Rect();													//����������
};

Rect BoundingRect(Rect, Rect);									//����� ������ � ������������� �� ��������
Rect BoundingRect2(const Rect &R1, const Rect &R2);							//����� ������ � ������������� �� ������