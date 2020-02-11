#include "Bochka.h"
#include <iostream>

Bochka::Bochka(float volume, float concentration)
{
	m_volume = volume;
	m_concentration = concentration;
	std::cout << "��� ������� ����������� ��� �����\n";
}

Bochka::~Bochka()
{
	//std::cout << "��� ���������� ��� �����\n";
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
	std::cout << "��� ����� SetAll ��� �����\n";
}

void Bochka::Print_Bochka()
{
	std::cout << "��� ����� Print_Bochka\n" << "����� �����: " << m_volume << ", ������������ ������: " << m_concentration << "\n";
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