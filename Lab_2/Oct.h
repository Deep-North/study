#pragma once
class Oct
{
	unsigned char m_oct0 : 3;	//0-2
	unsigned char m_oct1 : 3;	//3-5
	unsigned char m_oct2 : 2;	//6-7
public:
	int Show();						//выводим все восьмеричные цифры
	int ShowPos(int pos);			//выводим цифру в позиции
	int Edit(int pos, int val);		//изменяем цифру в позиции
	
	friend union MyByte;
};

