#include "Pair.h"



Pair::Pair()
{
}

Pair::~Pair()
{
}

Pair::Pair(const char *k, const MyData& d) {
	m_key = k;
	m_data = d;
}

Pair::Pair(const Pair& other) {
	m_key = other.m_key;
	m_data = other.m_data;
}

Pair& Pair::operator=(const Pair& other) {
	m_key = other.m_key;
	m_data = other.m_data;
	return *this;
}

std::ostream& operator<< (std::ostream& stream, const Pair& p) {
	stream << "Фамилия: " << p.m_key << "| Данные: " << p.m_data << "\n";
	return stream;
}

bool Pair::operator==(const char *k) const {
	MyString s = m_key;
	return s.Compare(k);
}