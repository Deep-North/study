// StaticLib_VC.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "StaticLib_VC.h"

double sl_VC_fPlus(double a, double b) {
	return a + b;
}

double sl_VC_fMult(double a, double b) {
	return a * b;
}

double sl_VC_fDiv(double a, double b) {
	return a / b;
}

double sl_VC_fMinus(double a, double b) {
	return a - b;
}
