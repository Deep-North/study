#pragma once
class Oct
{
	unsigned char m_oct0 : 3;	//0-2
	unsigned char m_oct1 : 3;	//3-5
	unsigned char m_oct2 : 2;	//6-7
public:
	int Show();						//������� ��� ������������ �����
	int ShowPos(int pos);			//������� ����� � �������
	int Edit(int pos, int val);		//�������� ����� � �������
	
	friend union MyByte;
};

