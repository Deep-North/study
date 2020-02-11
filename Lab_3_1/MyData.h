#pragma once

#include <iostream>
#include "myString.h" 

class MyData
{
public:
	enum Sex { UNDEF, MALE, FEMALE };	//����� ����
private:
	Sex m_sex;							//���
	unsigned short m_age;				//�������
	MyString m_job;						//�������� ������
	float m_salary;						//��������

public:
	MyData();															//����������� ��-���������
	MyData(Sex s, unsigned short age, const char* job, float sal);		//����������� � �����������
	~MyData();															//����������

	MyData(const MyData& d);											//����������� �����������
	MyData & operator=(const MyData& d);								//���������� ��������� "="

	friend std::ostream& operator<<(std::ostream& os, const MyData& d);	//���������� ��������� "<<" ������ ������
};

std::ostream& operator<< (std::ostream&, const MyData&);				//���������� ��������� "<<" ���������� ��������

