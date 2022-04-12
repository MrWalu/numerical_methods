#include <iostream>
#include <cmath>

using namespace std;

double fun1(double x) {
    return -(x * x * x) + 10 * x + 5;
}

double fun1_prim(double x) {
    return (-3) * x * x + 10;
}

double fun2(double x) {
    return (x * x * x) + (x * x) - 3 * x - 3;
}

double fun2_prim(double x) {
    return 3 * x * x + 2 * x - 3;
}

double fun3(double x) {
    return -(x * x * x * x) + 3 * x * x + 4 * x - 5;
}

double fun3_prim(double x) {
    return -4 * x * x * x + 6 * x + 4;
}

void met_stycznych(double (*func)(double), double (*func_prim)(double), double* X, int n, double k) {
    X[0] = k - (func(k) / func_prim(k));
    for (int i = 0; i < n; i++) {
        X[i+1] = X[i] - (func(X[i]) / func_prim(X[i]));
    }
    for (int j = 0; j < n; j++) {
        cout << "x" << j + 1 << " = " << X[j] << endl;
    }
    cout << endl;

}

void met_siecznych(double (*func)(double), double x0, double n) {
    double x = x0;
    double xk = x0 - 0.1;
    double tmp = 0;

    for (int i = 0; i < n; i++) {
        tmp = x;
        x = x - func(x) * ((x - xk) / (func(x) - func(xk)));
        xk = tmp;
        cout << "x" << (i+1) << " = " << x << endl;
    }
}

int main(){
    int n1 = 5;
    double k = 6.0;
    double* X = new double[n1];

    cout << "Wyniki dla funkcji -x^3 + 10x +5:" << endl;
    cout << "Metoda stycznych" << endl;
    met_stycznych(fun1, fun1_prim, X, n1, k);
    cout << "Metoda siecznych" << endl;
    met_siecznych(fun1, k, n1);
    cout << endl;

    double k2 = 4;
    int n2 = 8;
    double* X2 = new double[n2];

    cout << "Wyniki dla funkcji x^3 + x^2 + 3x - 3:" << endl;
    cout << "Metoda stycznych" << endl;
    met_stycznych(fun2, fun2_prim, X2, n2, k2);
    cout << "Metoda siecznych" << endl;
    met_siecznych(fun2, k2, n2);
    cout << endl;

    double k3 = 8;
    int n3 = 10;
    double* X3 = new double[n3];

    cout << "Wyniki dla funkcji -x^4 + 3x^2 + 4x - 5:" << endl;
    cout << "Metoda stycznych" << endl;
    met_stycznych(fun3, fun3_prim, X3, n3, k3);
    cout << "Metoda siecznych" << endl;
    met_siecznych(fun3, k3, n3);
    
    delete[] X;
    delete[] X2;
    delete[] X3;

    return 0;
}


