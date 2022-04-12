#include <iostream>
#include <fstream>
using namespace std;

bool gauss(int n, double** macierz, double* mnoz){
    int i, j, k;
    double m, s;

    for (i = 0; i < n-1; ++i){
        for (j = i+1; j < n; ++j){
            if (macierz[i][i] == 0)
                return false;
            else{
                m = -macierz[j][i] / macierz[i][i];
                for (k = 0; k <= n; ++k) {
                    macierz[j][k] += m * macierz[i][k];
                }
            }
        }
    }

    for (i = n - 1; i >= 0; --i) {
        s = macierz[i][n];
        for (j = n - 1; j >= i + 1; --j)
            s -= macierz[i][j] * mnoz[j];
        if ((macierz[i][i]) == 0)
            return false;
        mnoz[i] = s / macierz[i][i];
    }
    return true;
}

int main(){
    double liczba=0;
    fstream plik("RURL_dane1.txt");
    plik.open("RURL_dane1.txt");
    plik >> liczba;
    double** tab = new double* [liczba];
    for(int i=0; i<liczba; i++){
        tab[i]=new double[liczba+1];
        for(int j=0; j<(liczba+1); ++j){
            plik >> tab[i][j];
        }
    }
    plik.close();

    cout<<"Uklad rownan:"<<endl;
    for(int i=0; i<liczba; ++i){
        for(int j=0; j<(liczba+1); ++j){
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }

    double *mnozniki = new double[liczba];

    if (gauss(liczba, tab, mnozniki)) {
        for (int i = 0; i < liczba; i++)
            cout << "x" << i + 1 << " = " << mnozniki[i] << endl;
    }
    else
        cout << "Dzielnik wynosi zero"<<endl;

    cout << "Postepowanie proste:"<<endl;

    for (int i = 0; i < liczba; ++i) {
        for (int j = 0; j < (liczba+1); ++j) {
            cout << tab[i][j] << "      ";
        }
        cout << endl;
    }


    for (int i = 0; i < liczba; i++)
        delete[] tab[i];


    return 0;
}
