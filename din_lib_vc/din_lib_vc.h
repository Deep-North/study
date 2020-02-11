#pragma once

extern "C" {
#ifdef MY_DLL
#define LINKDLL __declspec( dllexport)
#else
#define LINKDLL __declspec( dllimport)
#endif

	LINKDLL double dl_Plus(double a, double b);
	LINKDLL double dl_Mult(double a, double b);
	LINKDLL double dl_Div(double a, double b);
	LINKDLL double dl_Minus(double a, double b);
}