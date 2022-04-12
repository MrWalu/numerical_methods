#include <iomanip>
#include <cmath>
#include <iostream>

double func1(double x) { 
	return sin(x); 
}

double func2(double x) { 
	return (x * x) + (2 * x) + 5; 
}

double func3(double x) {
	return exp(x);
}

double trapezy(double (*func)(double), float a, float b, int n) {
	double h = (b - a) / (double)n;
	double suma= 0.0;
	double podstawa_a = func(a), podstawa_b;

	for (int i = 1; i <= n; ++i) {
		podstawa_b = func(a + h * i);
		suma += (podstawa_a + podstawa_b);
		podstawa_a = podstawa_b;
	}
	return suma * 0.5 * h;
}

double simpson(double (*func)(double), float a, float b, int n) {
	double suma = 0, st = 0, x;
	double dx = (b - a) / n;
	for (int i = 1; i <= n; ++i) {
		x = a + i * dx;
		st += func(x - dx / 2);
		if (i < n)
			suma += func(x);
	}
	return suma = dx / 6 * (func(a) + func(b) + 2 * suma + 4 * st);
}

double prostokaty(double (*func)(double), float a, float b, int n) {
	double suma = 0;
	double dx = (b - a) / n;
	for (int i = 1; i <= n; i++)
		suma += func(a + i * dx);
	return suma *= dx;
}

int main(){
	float a1 = 0.5, b1 = 2.5;
	float a2 = 0.5, b2 = 5.0;
	int n;
	std::cout << "Szukamy wynikow dla exp(x) w przedziale iteracji od 1 do 10:" << std::endl;
	std::cout << "Przedzial calkowania [" << a2 <<",  "<< b2<<"]" << std::endl;
	std::cout << "Metoda Simpsona" << std::endl;
	for (int n = 1; n <= 10; ++n) {
		if (!(a2 < b2))
			std::cout << "Bledny przedzial!\n";
		else
			std::cout << "Pole dla "<<n<< " iteracji wynosi: " << std::fixed << simpson(func3, a2, b2, n) << std::endl;
	}
	
	std::cout << "Metoda prostokatow" << std::endl;
	for (int n = 1; n <= 10; ++n) {
		if (!(a2 < b2))
			std::cout << "Bledny przedzial!\n";
		else
			std::cout << "Pole dla " << n << " iteracji wynosi: " << std::fixed << prostokaty(func3, a2, b2, n) << std::endl;
	}

	std::cout << "Metoda trapezow" << std::endl;
	for (int n = 1; n <= 10; ++n) {
		if (!(a2 < b2))
			std::cout << "Bledny przedzial!\n";
		else
			std::cout << "Pole dla " << n << " iteracji wynosi: " << std::fixed << trapezy(func3, a2, b2, n) << std::endl;
	}
	n = 4;
	std::cout << std::endl;
	std::cout << "Obliczamy wartosci calek dla pozostalych funkcji dla "<<n<<" iteracji" << std::endl;
	std::cout << "Przedzial calkowania [" << a1 << ",  " << b1 << "]" << std::endl;
	std::cout << "Pole wg metody prost. dla sin(x): " << std::fixed << prostokaty(func1, a1, b1, n) << std::endl;
	std::cout << "Pole wg metody prost. dla paraboli: " << std::fixed << prostokaty(func2, a1, b1, n) << std::endl;
	std::cout << "Pole wg metody trapezow dla sin(x): " << std::fixed << trapezy(func1, a1, b1, n) << std::endl;
	std::cout << "Pole wg metody trapezow dla paraboli: " << std::fixed << trapezy(func2, a1, b1, n) << std::endl;
	std::cout << "Pole wg metody Simpsona dla sin(x): " << std::fixed << simpson(func1, a1, b1, n) << std::endl;
	std::cout << "Pole wg metody Simpsona dla paraboli: " << std::fixed << simpson(func2, a1, b1, n) << std::endl;

	return 0;
}