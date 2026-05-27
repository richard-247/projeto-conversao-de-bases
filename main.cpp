#include <iostream>
#include "conversor.h"
#include "modoPasso_a_passo.h"
#include "quiz.h"
#include "modoBatch.h"
#include "calculadora_maximos.h"
using namespace std;

// ======================================================
// MAIN
// ======================================================

int main(){


    cout << decimalCompletoParaBinario(12.625) << endl;
    cout << decimalCompletoParaOctal(12.625) << endl;
    cout << decimalCompletoParaHexadecimal(12.625) << endl;

    cout << octalCompletoParaDecimal("17.52") << endl;
    cout << hexadecimalCompletoParaDecimal("1A.A") << endl;

    cout << binarioCompletoParaHexadecimal("1101.101") << endl;
    cout << hexadecimalCompletoParaBinario("1A") << endl;

    cout << octalCompletoParaHexadecimal("17.52") << endl;
    cout << hexadecimalCompletoParaOctal("F.2A") << endl;

	cout << binarioCompletoParaOctal("1101.101") << endl;

    if(validarEntrada("1101.1A", 16)){
        cout << "Entrada hexadecimal válida!" << endl;
    }
    else cout << "Entrada hexadecimal inválida!" << endl;

// ======================================================
// MODO PASSO A PASSO
// ======================================================

// DECIMAL -> OUTRAS BASES
traceDecimalCompletoParaBinario(12.625);
traceDecimalCompletoParaOctal(12.625);
traceDecimalCompletoParaHexadecimal(12.625);

// BINARIO -> OUTRAS BASES
traceBinarioCompletoParaDecimal("1101.101");
traceBinarioCompletoParaHexadecimal("1101.101");
traceBinarioCompletoParaOctal("1101.101");

// OCTAL -> OUTRAS BASES
traceOctalCompletoParaDecimal("17.52");
traceOctalCompletoParaBinario("17.52");
traceOctalCompletoParaHexadecimal("17.52");

// HEXADECIMAL -> OUTRAS BASES
traceHexadecimalCompletoParaDecimal("1A.A");
traceHexadecimalCompletoParaBinario("1A.A");
traceHexadecimalCompletoParaOctal("F.2A");

// ======================================================
// MODO QUIZ
// ======================================================

iniciarQuiz();

// ======================================================
// MODO BATCH
// ======================================================

cout << "\n\n\n\n\n ---------------------------------------------\n\n\n\n\n";

executarModoBatch("entrada.csv", "saida.csv");

// ======================================================
// CALCULADORA MAXIMOS
// ======================================================

calculadora_maximos();

    return 0;
}