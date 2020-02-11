#pragma once
struct BigInteger {
	unsigned char* p;		//��������� �� ������������ ������ ���������� �������� ������������� ��������� ������, ��������� �������
	size_t n;				//���������� ������ � �������� �������������
};

int input(char * mass);
void translation(char * mass);
bool get_bit(unsigned char i, unsigned int index);
void print_oct(unsigned char * arr, size_t count);
void print_binary(unsigned char * arr, size_t count);