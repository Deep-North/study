#include "Hex.h"
#include <iostream>



int Hex::Show()
{
	unsigned int h0 = m_hex0;
	unsigned int h1 = m_hex1;

	std::cout << std::hex << "����������������� �������: " << h1 << " " << h0  << std::endl;
	return 0;
}

int Hex::ShowPos(int pos)
{
	unsigned int h0 = m_hex0;
	unsigned int h1 = m_hex1;
	
	switch (pos)
	{
	case 1:
		std::cout << std::hex << pos << "-� ����������������� ����� � �������: " << h0 << std::endl;
		break;
	case 2:
		std::cout << std::hex << pos << "-� ����������������� ����� � �������: " << h1 << std::endl;
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
		std::cout << std::hex << pos << "-� ����������������� ����� �������� ��: " << h0 << std::endl;
		break;
	case 2:
		m_hex1 = val;
		std::cout << std::hex << pos << "-� ����������������� ����� �������� ��: " << h1 << std::endl;
		break;
	default:
		break;
	}
	return 0;
}