#include "Bin.h"
#include <iostream>



int Bin::Show()
{
	unsigned int b0 = m_bin0;
	unsigned int b1 = m_bin1;
	unsigned int b2 = m_bin2;
	unsigned int b3 = m_bin3;
	unsigned int b4 = m_bin4;
	unsigned int b5 = m_bin5;
	unsigned int b6 = m_bin6;
	unsigned int b7 = m_bin7;

	std::cout << "�������� �������: " << b7 << b6 << b5 << b4 << b3 << b2 << b1 << b0 << std::endl;
	return 0;
}

int Bin::ShowPos(int pos)
{
	unsigned int b0 = m_bin0;
	unsigned int b1 = m_bin1;
	unsigned int b2 = m_bin2;
	unsigned int b3 = m_bin3;
	unsigned int b4 = m_bin4;
	unsigned int b5 = m_bin5;
	unsigned int b6 = m_bin6;
	unsigned int b7 = m_bin7;

	switch (pos)
	{
	case 1:
		
		std::cout << pos << "-� �������� ����� � �������: " << b0 << std::endl;
		break;
	case 2:
		std::cout << pos << "-� �������� ����� � �������: " << b1 << std::endl;
		break;
	case 3:
		std::cout << pos << "-� �������� ����� � �������: " << b2 << std::endl;
		break;
	case 4:
		std::cout << pos << "-� �������� ����� � �������: " << b3 << std::endl;
		break;
	case 5:
		std::cout << pos << "-� �������� ����� � �������: " << b4 << std::endl;
		break;
	case 6:
		std::cout << pos << "-� �������� ����� � �������: " << b5 << std::endl;
		break;
	case 7:
		std::cout << pos << "-� �������� ����� � �������: " << b6 << std::endl;
		break;
	case 8:
		std::cout << pos << "-� �������� ����� � �������: " << b7 << std::endl;
		break;
	default:
		break;
	}
	return 0;
}

int Bin::Edit(int pos, int val)
{
	unsigned int b0 = m_bin0;
	unsigned int b1 = m_bin1;
	unsigned int b2 = m_bin2;
	unsigned int b3 = m_bin3;
	unsigned int b4 = m_bin4;
	unsigned int b5 = m_bin5;
	unsigned int b6 = m_bin6;
	unsigned int b7 = m_bin7;
	
	switch (pos)
	{
	case 1:
		m_bin0 = val;
		std::cout << pos << "-� �������� ����� �������� ��: " << b0 << std::endl;
		break;
	case 2:
		m_bin1 = val;
		std::cout << pos << "-� �������� ����� �������� ��: " << b1 << std::endl;
		break;
	case 3:
		m_bin2 = val;
		std::cout << pos << "-� �������� ����� �������� ��: " << b2 << std::endl;
		break;
	case 4:
		m_bin3 = val;
		std::cout << pos << "-� �������� ����� �������� ��: " << b3 << std::endl;
		break;
	case 5:
		m_bin4 = val;
		std::cout << pos << "-� �������� ����� �������� ��: " << b4 << std::endl;
		break;
	case 6:
		m_bin5 = val;
		std::cout << pos << "-� �������� ����� �������� ��: " << b5 << std::endl;
		break;
	case 7:
		m_bin6 = val;
		std::cout << pos << "-� �������� ����� �������� ��: " << b6 << std::endl;
		break;
	case 8:
		m_bin7 = val;
		std::cout << pos << "-� �������� ����� �������� ��: " << b7 << std::endl;
		break;
	default:
		break;
	}
	return 0;
}