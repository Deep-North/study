#pragma once
class Hex
{
	unsigned char m_hex0 : 4;	//0-3
	unsigned char m_hex1 : 4;	//4-7
public:
	int Show();						//������� ��� ����������������� �����
	int ShowPos(int pos);			//������� ����� � �������
	int Edit(int pos, int val);		//�������� ����� � �������
	
	friend union MyByte;
};