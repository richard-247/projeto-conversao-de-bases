// conversor.h
#ifndef CONVERSOR_H
#define CONVERSOR_H

#include <string>
using namespace std;

// Declarações (Protótipos das funções)
string decimalParaBinario(long int numero);
string decimalParaOctal(long int numero);
string decimalParaHexadecimal(long int numero);

string binarioParaDecimal(string binario);
string octalParaDecimal(string octal);
string hexadecimalParaDecimal(string hexadecimal);

string binarioParaOctal(string binario);
string octalParaBinario(string octal);
string binarioParaHexadecimal(string binario);
string hexadecimalParaBinario(string hexadecimal);

string octalParaHexadecimal(string octal);
string hexadecimalParaOctal(string hexadecimal);

bool validarEntrada(string entrada, int base);

string fracDecimalParaBinario(long double fracao);
string fracDecimalParaOctal(long double fracao);
string fracDecimalParaHexadecimal(long double fracao);

double fracBinarioParaDecimal(string fracao);
double fracOctalParaDecimal(string fracao);
double fracHexadecimalParaDecimal(string fracao);

string fracBinarioParaOctal(string binario);
string fracBinarioParaHexadecimal(string binario);

string decimalCompletoParaBinario(double decimal);
string decimalCompletoParaOctal(double decimal);
string decimalCompletoParaHexadecimal(double decimal);

double binarioCompletoParaDecimal(string binario);
double octalCompletoParaDecimal(string octal);
double hexadecimalCompletoParaDecimal(string hexadecimal);

string binarioCompletoParaOctal(string binario);
string octalCompletoParaBinario(string octal);
string binarioCompletoParaHexadecimal(string binario);
string hexadecimalCompletoParaBinario(string hexadecimal);

string octalCompletoParaHexadecimal(string octal);
string hexadecimalCompletoParaOctal(string hexadecimal);

#endif