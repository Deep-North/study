#include <string>
#include "myString.h" 
#include <cstdarg> 
#include <cstring> 
#include <iostream>

using namespace std;

//
MyString::MyString() {
	this->pStr = nullptr;
};

// ����������� ������������.
MyString::MyString(const  MyString &s) {
	this->pStr = Counter::head.GetCounter(s.GetString());
	this->pStr->IncrementOwner();
};

//
MyString::MyString(const char *c) {
	this->pStr = Counter::head.GetCounter(c);
	this->pStr->IncrementOwner();
};

MyString::MyString(MyString &&s) {
	this->pStr = s.pStr;
	s.pStr = nullptr;
}

// ����������� �����������.
MyString::~MyString() {
	if (this->pStr) {
		this->pStr->DecrementOwner();
	}
};

const char* MyString::GetString() const {
	if (this->pStr) {
		return this->pStr->GetString();
	}
	return nullptr;
};

void MyString::PrintAllString() {
	Counter::PrintAllString();
}

void MyString::ChnageRegisterAllString() {
	Counter::ChnageRegisterAllString();
}

MyString& MyString::operator=(const MyString& s) {
	if (this->pStr) {
		this->pStr->DecrementOwner();
	}
	this->pStr = Counter::head.GetCounter(s.GetString());
	this->pStr->IncrementOwner();
	return *this;
}

MyString& MyString::operator=(const char *c) {
	if (this->pStr) {
		this->pStr->DecrementOwner();
	}
	this->pStr = Counter::head.GetCounter(c);
	this->pStr->IncrementOwner();
	return *this;
}

MyString& MyString::operator=(MyString&& s) {
	if (this->pStr) {
		this->pStr->DecrementOwner();
	}
	this->pStr = s.pStr;
	s.pStr = nullptr;
	return *this;
}

void MyString::ChnageSortAllString() {
	Counter::ChnageSortAllString();
}

std::ostream& operator<<(std::ostream& stream, const MyString& s) {
	stream << s.GetString();
	return stream;
}