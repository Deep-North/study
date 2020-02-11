#include "Oct.h"
#include <iostream>



int Oct::Show()
{
	unsigned int o0 = m_oct0;
	unsigned int o1 = m_oct1;
	unsigned int o2 = m_oct2;

	std::cout << std::oct << "Восьмеричная система: " << o2 << " " << o1 << " " << o0 << std::endl;
	return 0;
}

int Oct::ShowPos(int pos)
{
	unsigned int o0 = m_oct0;
	unsigned int o1 = m_oct1;
	unsigned int o2 = m_oct2;
	
	switch (pos)
	{
	case 1:
		std::cout << std::oct << pos << "-е восьмеричное число в позиции: " << o0 << std::endl;
		break;
	case 2:
		std::cout << std::oct << pos << "-е восьмеричное число в позиции: " << o1 << std::endl;
		break;
	case 3:
		std::cout << std::oct << pos << "-е восьмеричное число в позиции: " << o2 << std::endl;
		break;
	default:
		break;
	}
	return 0;
}

int Oct::Edit(int pos, int val)
{
	unsigned int o0 = m_oct0;
	unsigned int o1 = m_oct1;
	unsigned int o2 = m_oct2; 
	
	switch (pos)
	{
	case 1:
		m_oct0 = val;
		std::cout << std::oct << pos << "-е восьмеричное число заменено на: " << o0 << std::endl;
		break;
	case 2:
		m_oct1 = val;
		std::cout << std::oct << pos << "-е восьмеричное число заменено на: " << o1 << std::endl;
		break;
	case 3:
		m_oct2 = val;
		std::cout << std::oct << pos << "-е восьмеричное число заменено на: " << o2 << std::endl;
		break;
	default:
		break;
	}
	return 0;
}