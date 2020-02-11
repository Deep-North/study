#include "MyData.h"

MyData::MyData()
{
	m_sex = MyData::UNDEF;
}

MyData::~MyData()
{
}

MyData::MyData(Sex sex, unsigned short age, const char* job, float salary) {
	m_sex = sex;
	m_age = age;
	m_job = job;
	m_salary = salary;
}

MyData::MyData(const MyData& d) {
	m_sex = d.m_sex;
	m_age = d.m_age;
	m_job = d.m_job;
	m_salary = d.m_salary;
}

MyData & MyData::operator=(const MyData& d) {
	m_sex = d.m_sex;
	m_age = d.m_age;
	m_job = d.m_job;
	m_salary = d.m_salary;
	return *this;
}

std::ostream& operator<< (std::ostream& stream, const MyData& d) {
	stream << "{Age: " << d.m_age << ", Sex: " << d.m_sex << ", Job: " << d.m_job << ", Salary: " << d.m_salary << "}";
	return stream;
}