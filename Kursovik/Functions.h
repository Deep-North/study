#pragma once
struct BigInteger {
	unsigned char* p;		//указатель на динамический массив содержащий двоичное представление «длинного целого», заданного строкой
	size_t n;				//количество байтов в двоичном представлении
};

int input(char * mass);
void translation(char * mass);
bool get_bit(unsigned char i, unsigned int index);
void print_oct(unsigned char * arr, size_t count);
void print_binary(unsigned char * arr, size_t count);