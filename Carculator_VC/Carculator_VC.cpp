// Carculator_VC.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "../../StaticLib_VC/StaticLib_VC/StaticLib_VC.h"
using namespace std;


int main()
{
	cout << "++ Calculator ++\n\n";


	while (true)
	{
		cout << "Insert first number> ";
		double a;
		cin >> a;

		cout << "Insert operation> ";
		char operation;
		cin >> operation;

		cout << "Insert second number> ";
		double b;
		cin >> b;

		double res;
		bool error = false;

		switch (operation)
		{
		case '+':
			res = sl_VC_fPlus(a, b);
			break;
		case '-':
			res = sl_VC_fMinus(a, b);
			break;
		case '*':
			res = sl_VC_fMult(a, b);
			break;
		case '/':
			res = sl_VC_fDiv(a, b);
			break;
		default:
			error = true;
			break;
		}
		if (error) { cout << "error"; }
		else { cout << "result = " << res; }
		cout << endl << endl;
	}
	system("pause");
}