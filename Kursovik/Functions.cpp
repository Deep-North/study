#define _CRT_SECURE_NO_WARNINGS
#include <cstring>	// ��� ������� memset
#include <iostream>
#include <cctype>   // ��� ������� isdigit

extern unsigned char * p;
extern size_t string_lenght;

int input(char * mass)
{
	bool tag;
	do
	{
		tag = false;
		printf("������� ������������ �����:\n");
		scanf("%s", mass);
		fflush(stdin);
		for (int i = 0; i < strlen(mass); i++)
		{
			if ((mass[i]>='0') && (mass[i]<='7'))	//����� ������������ ���� ������� ��� �����
			{
				tag = true;
			}
			else
			{
				printf("�������� ����� �� ����� ��� ��� �� ������������!\n");
				tag = false;
				break;
			}
		}
	} while (tag == false);
	return 0;
}

void translation(char * mass)
{
	string_lenght = 0;
	int number_of_octal_digits = strlen(mass);
	string_lenght = (number_of_octal_digits * 3 + 7) / 8;	// ����� ������
	p = new unsigned char[string_lenght];	// �������������� ������
	int i = 0;						// ����� � ������
	int j = 0;						// ����� �������� �����
	int bit = 8 - (string_lenght * 8 - number_of_octal_digits * 3);	// ��� ��� ����� �������� ����� � ���������� ����� ���� �� ������ ������,
															// ������� ����� �� �������� ����� ��� "�������" �����
	memset(p, 0, string_lenght);		// ��������� ������ ��������� ��������� (������). ��� ��� ������ ������������ ����� ������� ��� ��������.

	while (i < number_of_octal_digits)
	{
		if (bit >= 3)
		{// ���� ��� �������� ����� � ������� �����, ��������� ��� ���� (������������ �����) � ��������������� ������
			bit -= 3;	// ��������� ������� ����� �� 3
			p[j] = p[j] | ((mass[i] - '0') << bit);
		}
		else
		{
			// ��� ��� ���� �� ������ ���, ����� �������� ������ ��� ��� ������� ������� � ������� ����, � ���������� � ����� ����
			p[j] = p[j] | (mass[i] - '0') >> (3 - bit);
			j++;
			bit = 8 - (3 - bit);
			p[j] = p[j] | ((mass[i] - '0') << bit);
		}
		i++;
	}
}

bool get_bit(unsigned char i, unsigned int index)
{
	return (i >> index) & 1;
}

void print_oct(unsigned char * arr, size_t count)
{
	std::cout << "������� ����� � ������������ �����:\n";
	if (!count)
		return;

	unsigned int bit = 0;

/*
	���������� bit ���, ����� ���������� ���������� ���� � ������ ����� (����) �������
	����� ����� ����� ��������, ��������� ��������� ����� ��� � ������� ����� ���� �� ������ 3
	��������, ��� �������� ������������� ����� 3 ����������� 1 ���� (���)
	���� ����� ����� ���� 3 ���� � ����� (����):  00000[011], � ������� 5 ��� �� � ���� �� ���������.
	��� �������� ����, ��� ���� - ����������� ����������� �������.
*/
	//���������� ��� ����
	while (!get_bit(arr[0], 7 - bit) && bit < 8)
		bit++;
	//��������� ������, ���� ����� ��������� ����� �� ������  ������� 3 (������� ������������� �����)
	while (((count << 3) - bit) % 3)
		bit--;
	//�������� ������ ����, � �������� ������� ���������� ���� �����
	const int offset = bit;
/*
	��������������� ���������� ��� ���� � �������
	������ 3 ���� ����� � ��������������� ������ ����� octa, ������� octa, �������� � ���������
*/
	while (bit != (count << 3))
	{
		static unsigned char octa;
		static int shft;

		bool bit_value = get_bit(arr[bit >> 3], 7 - bit & 0b111);	//��������� ������� ��� 
		octa |= bit_value << (2 - shft);	//�������� ��� � ������ ������ ������������� ����� (0-�, 1-� ��� 2-�)
		shft = (++bit - offset) % 3;		//����������� ������� ����� ������� ������������� ����� (>3 - ����� �����)
		if (shft)							//���� shft != 0, ����� ������������ ����� ��� �� ��������
			continue;
		//shft ���������, � ������ �������� ����� ������������ �����
		std::cout << +octa; //������� ������ (octa); ���c��, ����� ������� ��� �����, � �� ��� �����
		octa = 0; //������� octa ��� "����������" ���������� �����
	}
	std::cout << "\n";
}

void print_binary(unsigned char * arr, size_t count)
{
	std::cout << "������� ����� � �������� �����:\n";
	//��� � � print_oct ��������� ��������� ����
	unsigned int bit = 0;
	while (!get_bit(arr[0], 7 - bit) && bit < 8)
		bit++;
	while (((count << 3) - bit) % 3)
		bit--;

	for (; bit < count * 8; bit++)
		std::cout << get_bit(arr[bit >> 3], 7 - bit & 0b111);
	std::cout << "\n";
}