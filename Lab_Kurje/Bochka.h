#pragma once
class Bochka
{
private:
	float m_volume, m_concentration;
public:
	Bochka(float volume = 200.0, float concentration = 0.0);	// Конструктор для бочки
	~Bochka();													// Деструктор для бочки
	void GetAll(float & volume, float & concentration) const;
	float GetConcentration() const;
	void SetAll(float volume, float concentration);
	void Print_Bochka();
	void Pereliv(Bochka);
};