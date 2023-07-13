#include <iostream>
#include <cstdlib>
#include <ctime>



// P - состовл€юща€
int Power(int power, float err, float kp ) {
	float setpoint; float input; int kp1 = 20;
	std::cout << "¬ведите заданое значение, и вход -> " << "\n";
	std::cin >> setpoint >> input;
	err = setpoint - input;
	kp = 0.6 * kp1;
	power = err * kp;
	std::cout << "Power = " << power << "\n";
	return power;
}

//I - составл€юща€; где setpoint(установка заданного значени€), а input(вход значен€ с датчика)
int Current(int current, float err, float ki ,int t) {
	float setpoint; float input;
	std::cout << "¬ведите заданое значение, и вход -> " << "\n";
	std::cin >> setpoint >> input;
	std::cout << "¬ведите начальный ток -> " << "\n";
	std::cin >> current;
	err = setpoint - input;
  current = current + (setpoint - input) * t;
	std::cout << "Current = " << current << "\n";
	return current;
}

 //D - —остовл€юща€;  - где ошибка регулировани€
int Diff(int err,  int D, int t, int prevErr ) {
	float setpoint, input;
	std::cout << " ¬ведите врем€ -> " << "\n";
	std::cin >> t;
	float kd = 12 * 3 / 8 / t;
	std::cout << "¬ведите заданое значение, и вход -> " << "\n";
	std::cin >> setpoint >> input;
	err = setpoint - input;
	D = ((err - prevErr) / t)*kd;
	std::cout << "Diff = " << D << "\n";
	return D;
}
double f(double x) {
	return sin(x);
}


int main() {
	setlocale(LC_ALL, "Ru");

	// ¬ычисление »нтеграла по формуле трапеции 
	int t;
	std::cout << " ¬ведите врем€ интегрировани€ - > ";
	std::cin >> t;
	int i; double Integral;
	double a = 0.0, b = t;
	double h = 0.1;
	double n;
	n = (b - a) / h;
	Integral = h * (f(a) + f(b)) / 2.0;
	for (int i = 1; i <= n - 1; i++) {
		Integral = Integral + h * f(a + h * i);
	}
	std::cout << " I2 = " << Integral << '\n';




	return 0;
}




