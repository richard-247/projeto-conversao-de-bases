// modoPassoAPasso.h

#ifndef MODOPASSOAPASSO_H
#define MODOPASSOAPASSO_H

#include <string>

using namespace std;

// ======================================================
// DECIMAL -> OUTRAS BASES
// ======================================================

void traceDecimalCompletoParaBinario(double decimal);

void traceDecimalCompletoParaOctal(double decimal);

void traceDecimalCompletoParaHexadecimal(double decimal);

// ======================================================
// OUTRAS BASES -> DECIMAL
// ======================================================

void traceBinarioCompletoParaDecimal(string binario);

void traceOctalCompletoParaDecimal(string octal);

void traceHexadecimalCompletoParaDecimal(string hexadecimal);

// ======================================================
// BINARIO <-> OCTAL / HEXADECIMAL
// ======================================================

void traceBinarioCompletoParaOctal(string binario);

void traceBinarioCompletoParaHexadecimal(string binario);

void traceOctalCompletoParaBinario(string octal);

void traceHexadecimalCompletoParaBinario(string hexadecimal);

// ======================================================
// OCTAL <-> HEXADECIMAL
// ======================================================

void traceOctalCompletoParaHexadecimal(string octal);

void traceHexadecimalCompletoParaOctal(string hexadecimal);

#endif