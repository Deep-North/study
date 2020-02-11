#include "BD.h"


BD::BD() {										//����������� ��-���������
	m_size = 0;
	m_capacity = 10;
	m_pBase = new Pair*[m_capacity];
}

BD::~BD() {										//����������
	if (m_pBase) {
		for (int i = 0; i < m_size; i++) {
			delete m_pBase[i];
		}
	}
	delete[] this->m_pBase;
}

BD::BD(const BD& bd) {							//����������� �����������
	m_size = bd.m_size;
	m_capacity = bd.m_size;
	m_pBase = new Pair*[m_capacity];

	for (int i = 0; i < m_size; i++) {
		m_pBase[i] = new Pair(*bd.m_pBase[i]);
	}
}

MyData& BD::operator[](const char * key) {		//���������� ��������� "[]"
	for (size_t i = 0; i < m_size; i++) {		//��������� �� ������� ��� ���������� ����������
		if (*m_pBase[i] == key)
			return (*m_pBase[i]).m_data;
	}

	if (m_size >= m_capacity) {					//���������������� ������ 
		m_capacity += 1;
		Pair **ppt = new Pair*[m_capacity];
		for (int i = 0; i < m_size; i++) {
			ppt[i] = m_pBase[i];
		}
		delete[] m_pBase;
		m_pBase = ppt;
	}

	Pair *p = new Pair(key, MyData());
	m_pBase[this->m_size] = p;
	m_size++;
	return p->m_data;
}

std::ostream& operator<< (std::ostream& stream, const BD& bd) {
	stream << "���� ������:\n";
	for (size_t i = 0; i < bd.m_size; i++) {
		stream << "��������� �" << (i + 1) << ". " << *bd.m_pBase[i] << "\n";
	}
	return stream;
}