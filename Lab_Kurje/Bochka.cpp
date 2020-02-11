#include "Bochka.h"
#include <iostream>

Bochka::Bochka(float volume, float concentration)
{
	m_volume = volume;
	m_concentration = concentration;
	std::cout << "Это простой конструктор для бочки\n";
}

Bochka::~Bochka()
{
	//std::cout << "Это деструктор для бочки\n";
}

void Bochka::GetAll(float & volume, float & concentration) const
{
	volume = m_volume;
	concentration = m_concentration;
}

float Bochka::GetConcentration() const
{
	return m_concentration;
}

void Bochka::SetAll(float volume, float concentration)
{
	m_volume = volume;
	m_concentration = concentration;
	std::cout << "Это метод SetAll для бочки\n";
}

void Bochka::Print_Bochka()
{
	std::cout << "Это метод Print_Bochka\n" << "Объем бочки: " << m_volume << ", концентрация спирта: " << m_concentration << "\n";
}

void Bochka::Pereliv(Bochka b_two)
{
	float v2;
	float c2;

	//m_concentration;
	b_two.GetAll(v2, c2);
	if (m_concentration > c2)
	//	if (m_concentration > b_two.m_concentration)
	{
		m_concentration -= (1 / v2)*c2;
	}
	else
	{
		m_concentration += (1 / v2)*c2;
	}
}