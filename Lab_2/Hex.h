#pragma once
class Hex
{
	unsigned char m_hex0 : 4;	//0-3
	unsigned char m_hex1 : 4;	//4-7
public:
	int Show();						//выводим все шестнадцатеричные цифры
	int ShowPos(int pos);			//выводим цифру в позиции
	int Edit(int pos, int val);		//изменяем цифру в позиции
	
	friend union MyByte;
};