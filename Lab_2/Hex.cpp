#include "Hex.h"
#include <iostream>



int Hex::Show()
{
	unsigned int h0 = m_hex0;
	unsigned int h1 = m_hex1;

	std::cout << std::hex << "Шестнадцатеричная система: " << h1 << " " << h0  << std::endl;
	return 0;
}

int Hex::ShowPos(int pos)
{
	unsigned int h0 = m_hex0;
	unsigned int h1 = m_hex1;
	
	switch (pos)
	{
	case 1:
		std::cout << std::hex << pos << "-е шестнадцатеричное число в позиции: " << h0 << std::endl;
		break;
	case 2:
		std::cout << std::hex << pos << "-е шестнадцатеричное число в позиции: " << h1 << std::endl;
		break;
	default:
		break;
	}
	return 0;
}

int Hex::Edit(int pos, int val)
{
	unsigned int h0 = m_hex0;
	unsigned int h1 = m_hex1;
	
	switch (pos)
	{
	case 1:
		m_hex0 = val;
		std::cout << std::hex << pos << "-е шестнадцатеричное число заменено на: " << h0 << std::endl;
		break;
	case 2:
		m_hex1 = val;
		std::cout << std::hex << pos << "-е шестнадцатеричное число заменено на: " << h1 << std::endl;
		break;
	default:
		break;
	}
	return 0;
}