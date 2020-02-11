extern "C" {
	__declspec(dllexport) double dle_Plus(double a, double b) {
		return a + b;
	}

	__declspec(dllexport) double dle_Mult(double a, double b) {
		return a * b;
	}

	__declspec(dllexport) double dle_Div(double a, double b) {
		return a / b;
	}

	__declspec(dllexport) double dle_Minus(double a, double b) {
		return a - b;
	}
}