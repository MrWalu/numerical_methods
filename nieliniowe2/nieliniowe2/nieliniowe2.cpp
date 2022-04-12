#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

double fun1(double x){
    return cos(x * x * x - 2 * x);
}

double fun2(double x) {
    return (x * x * x) + (x * x) - 3 * x - 3;
}

double fun3(double x) {
    return -(x * x * x) - 2 * x * x - 7 * x + 3;
}

void bisekcja(double (*func)(double), double a, double b, double x0) {
    double epsilon = 0.01;
    int counter = 1;
    double fa = func(a);
    double fb = func(b);
    cout << "\t\ta \t\tb \t\tf(a) \t\tf(b)  \t\tx0 \t\tf(x0) \t\tf(a)*f(x0)" << endl;
    if (fa * fb > 0)
        cout << "Funkcja nie spelnia zalozen" << endl;
    else {
        while (fabs(a - b) > epsilon) {
            double x0 = (a + b) / 2; 
            double f0 = func(x0);
            cout << counter << "\t\t" << a << "\t\t" << b << "\t\t" << func(a) << "\t\t" << func(b) << "\t\t" << x0 << "\t\t" << func(x0) << "\t\t" << func(a) * func(x0) << endl;
            if (fabs(f0) < epsilon)
                break;
            if (fa * f0 < 0)
                b = x0;
            else {
                a = x0;
                fa = f0;
            }
            counter++;
        }
    }
}

void falsi(double (*func)(double), double a, double b, double x0) {
    double epsilon = 0.01;
    int counter = 1;
    cout << "\t\ta \t\tb \t\tf(a) \t\tf(b)  \t\tx0 \t\tf(x0) \t\tf(a)*f(x0)" << endl;
    while (fabs(func(x0)) >= epsilon) {
        cout << counter << "\t\t" << a << "\t\t" << b << "\t\t" << func(a) << "\t\t" << func(b) << "\t\t" << x0 << "\t\t" << func(x0) << "\t\t" << func(a) * func(x0) << endl;

        if (func(a) * func(x0) < 0)
            b = x0;
        else
            a = x0;

        x0 = (a + b) / 2;
        counter++;
    }
}

int main() {
    double a = 0, b = 2;
    double x0 = (a + b) / 2;

    cout << "Dla funkcji cos(x^3 - 2x)" << endl;
    cout << "Metoda bisekcji" << endl;
    bisekcja(fun1, a, b, x0);
    cout << endl;
    cout << "Metoda Falsi" << endl;
    falsi(fun1, a, b, x0);
    cout << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    cout << "Dla funkcji x^3 + x^2 - 3x - 3" << endl;
    cout << "Metoda bisekcji" << endl;
    bisekcja(fun2, a, b, x0);
    cout << endl;
    cout << "Metoda Falsi" << endl;
    falsi(fun2, a, b, x0);
    cout << endl;
    cout<<"----------------------------------------------------------------------------" << endl;

    cout << "Dla funkcji -x^3 - 2x^2 - 7x + 3" << endl;
    cout << "Metoda bisekcji" << endl;
    bisekcja(fun3, a, b, x0);
    cout << endl;
    cout << "Metoda Falsi" << endl;
    falsi(fun3, a, b, x0);
    cout << endl << endl;

    return 0;
}