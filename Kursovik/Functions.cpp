#define _CRT_SECURE_NO_WARNINGS
#include <cstring>	// для функции memset
#include <iostream>
#include <cctype>   // для функции isdigit

extern unsigned char * p;
extern size_t string_lenght;

int input(char * mass)
{
	bool tag;
	do
	{
		tag = false;
		printf("Введите восьмеричное число:\n");
		scanf("%s", mass);
		fflush(stdin);
		for (int i = 0; i < strlen(mass); i++)
		{
			if ((mass[i]>='0') && (mass[i]<='7'))	//здесь используются коды симолов для чисел
			{
				tag = true;
			}
			else
			{
				printf("Введнное число не число или оно не восьмеричное!\n");
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
	string_lenght = (number_of_octal_digits * 3 + 7) / 8;	// длина строки
	p = new unsigned char[string_lenght];	// результирующий массив
	int i = 0;						// номер в строке
	int j = 0;						// номер текущего байта
	int bit = 8 - (string_lenght * 8 - number_of_octal_digits * 3);	// так как число значащих битов в результате может быть не кратно восьми,
															// считаем число не значащих битов для "отступа" слева
	memset(p, 0, string_lenght);		// заполняем память указанным значением (нулями). Так как массив динамический нужно вначале его занулить.

	while (i < number_of_octal_digits)
	{
		if (bit >= 3)
		{// если ещё осталось место в текущем байте, добавляем три бита (восьмеричное число) в соответствующий разряд
			bit -= 3;	// уменьшаем счётчик битов на 3
			p[j] = p[j] | ((mass[i] - '0') << bit);
		}
		else
		{
			// так как байт не кратен трём, когда осталось меньше трёх бит старшие запишем в текущий байт, а оставшиеся в новый байт
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
	std::cout << "Выведем число в восьмеричной форме:\n";
	if (!count)
		return;

	unsigned int bit = 0;

/*
	уставновим bit так, чтобы пропустить незначащие нули в первом байте (чаре) массива
	такое может легко случится, поскольку суммарное число бит в массиве может быть не кратно 3
	например, для хранения восьмеричного числа 3 понадобится 1 байт (чар)
	само число займёт лишь 3 бита в байте (чаре):  00000[011], а старшие 5 бит ни к чему не относятся.
	это издержки того, что байт - минимальная адрессуемая единица.
*/
	//пропускаем все нули
	while (!get_bit(arr[0], 7 - bit) && bit < 8)
		bit++;
	//уменьшаем индекс, пока число оставшися битов не станет  кратным 3 (признак восьмеричного числа)
	while (((count << 3) - bit) % 3)
		bit--;
	//запомним индекс бита, с которого реально начинается наше число
	const int offset = bit;
/*
	последовательно перебираем все биты в массиве
	каждые 3 бита пишем в соответствующий разряд числа octa, выводим octa, обнуляем и повторяем
*/
	while (bit != (count << 3))
	{
		static unsigned char octa;
		static int shft;

		bool bit_value = get_bit(arr[bit >> 3], 7 - bit & 0b111);	//извлекаем текущий бит 
		octa |= bit_value << (2 - shft);	//помещаем бит в нужный разряд восьмеричного числа (0-й, 1-й или 2-й)
		shft = (++bit - offset) % 3;		//увеличиваем текущий номер разряда восьмеричного числа (>3 - новое число)
		if (shft)							//если shft != 0, новое восьмеричное число еще не началось
			continue;
		//shft обнулился, а значит началось новое восьмеричное число
		std::cout << +octa; //выведем старое (octa); плюcик, чтобы вывести как число, а не как букву
		octa = 0; //обнулим octa для "накопления" следующего числа
	}
	std::cout << "\n";
}

void print_binary(unsigned char * arr, size_t count)
{
	std::cout << "Выведем число в двоичной форме:\n";
	//как и в print_oct пропустим фиктивные биты
	unsigned int bit = 0;
	while (!get_bit(arr[0], 7 - bit) && bit < 8)
		bit++;
	while (((count << 3) - bit) % 3)
		bit--;

	for (; bit < count * 8; bit++)
		std::cout << get_bit(arr[bit >> 3], 7 - bit & 0b111);
	std::cout << "\n";
}