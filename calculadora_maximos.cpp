#include <iostream>
#include <cmath>
#include "calculadora_maximos.h"
#include "conversor.h"

using namespace std;

void calculadora_maximos() {

    int k;

    cout << "Digite o numero de bits: ";
    cin >> k;

    long int maximo = pow(2, k) - 1;

    cout << "\n=====================================\n";
    cout << "MAXIMO REPRESENTAVEL COM "
         << k << " BITS\n";
    cout << "=====================================\n";

    cout << "\nDecimal: "
         << maximo << endl;

    cout << "Binario: "
         << decimalParaBinario(maximo) << endl;

    cout << "Octal: "
         << decimalParaOctal(maximo) << endl;

    cout << "Hexadecimal: "
         << decimalParaHexadecimal(maximo) << endl;
}