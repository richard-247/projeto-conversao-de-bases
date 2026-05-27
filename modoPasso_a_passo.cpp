// modoPassoAPasso.cpp

#include <iostream>
#include <cmath>
#include <string>
#include "modoPasso_a_passo.h"
#include "conversor.h"

using namespace std;

// ======================================================
// DECIMAL -> BINARIO
// ======================================================

void traceDecimalCompletoParaBinario(double decimal){

    cout << "\n========== DECIMAL -> BINARIO ==========\n";

    long int parteInteira = (long int)decimal;
    double parteFracionaria = decimal - parteInteira;

    cout << "\nPARTE INTEIRA:\n\n";

    if(parteInteira == 0){
        cout << "0 em binario = 0\n";
    }

    long int numero = parteInteira;

    while(numero > 0){

        cout << numero
             << " / 2 = "
             << numero / 2
             << " | resto = "
             << numero % 2
             << endl;

        numero /= 2;
    }

    cout << "\nResultado da parte inteira: "
         << decimalParaBinario(parteInteira)
         << endl;

    if(parteFracionaria > 0){

        cout << "\nPARTE FRACIONARIA:\n\n";

        double fracao = parteFracionaria;

        int precisao = 16;

        while(fracao > 0 && precisao > 0){

            double resultado = fracao * 2;

            int bit = (int)resultado;

            cout << fracao
                 << " x 2 = "
                 << resultado
                 << " -> bit = "
                 << bit
                 << endl;

            fracao = resultado - bit;

            precisao--;
        }

        cout << "\nResultado da parte fracionaria: "
             << fracDecimalParaBinario(parteFracionaria)
             << endl;
    }

    cout << "\nRESULTADO FINAL: "
         << decimalCompletoParaBinario(decimal)
         << endl;
}

// ======================================================
// DECIMAL -> OCTAL
// ======================================================

void traceDecimalCompletoParaOctal(double decimal){

    cout << "\n========== DECIMAL -> OCTAL ==========\n";

    long int parteInteira = (long int)decimal;
    double parteFracionaria = decimal - parteInteira;

    cout << "\nPARTE INTEIRA:\n\n";

    if(parteInteira == 0){
        cout << "0 em octal = 0\n";
    }

    long int numero = parteInteira;

    while(numero > 0){

        cout << numero
             << " / 8 = "
             << numero / 8
             << " | resto = "
             << numero % 8
             << endl;

        numero /= 8;
    }

    cout << "\nResultado da parte inteira: "
         << decimalParaOctal(parteInteira)
         << endl;

    if(parteFracionaria > 0){

        cout << "\nPARTE FRACIONARIA:\n\n";

        double fracao = parteFracionaria;

        int precisao = 16;

        while(fracao > 0 && precisao > 0){

            double resultado = fracao * 8;

            int digito = (int)resultado;

            cout << fracao
                 << " x 8 = "
                 << resultado
                 << " -> digito = "
                 << digito
                 << endl;

            fracao = resultado - digito;

            precisao--;
        }

        cout << "\nResultado da parte fracionaria: "
             << fracDecimalParaOctal(parteFracionaria)
             << endl;
    }

    cout << "\nRESULTADO FINAL: "
         << decimalCompletoParaOctal(decimal)
         << endl;
}

// ======================================================
// DECIMAL -> HEXADECIMAL
// ======================================================

void traceDecimalCompletoParaHexadecimal(double decimal){

    cout << "\n========== DECIMAL -> HEXADECIMAL ==========\n";

    long int parteInteira = (long int)decimal;
    double parteFracionaria = decimal - parteInteira;

    cout << "\nPARTE INTEIRA:\n\n";

    if(parteInteira == 0){
        cout << "0 em hexadecimal = 0\n";
    }

    long int numero = parteInteira;

    while(numero > 0){

        int resto = numero % 16;

        cout << numero
             << " / 16 = "
             << numero / 16
             << " | resto = ";

        if(resto < 10){
            cout << resto;
        }
        else{
            cout << char('A' + (resto - 10));
        }

        cout << endl;

        numero /= 16;
    }

    cout << "\nResultado da parte inteira: "
         << decimalParaHexadecimal(parteInteira)
         << endl;

    if(parteFracionaria > 0){

        cout << "\nPARTE FRACIONARIA:\n\n";

        double fracao = parteFracionaria;

        int precisao = 16;

        while(fracao > 0 && precisao > 0){

            double resultado = fracao * 16;

            int valor = (int)resultado;

            cout << fracao
                 << " x 16 = "
                 << resultado
                 << " -> digito = ";

            if(valor < 10){
                cout << valor;
            }
            else{
                cout << char('A' + (valor - 10));
            }

            cout << endl;

            fracao = resultado - valor;

            precisao--;
        }

        cout << "\nResultado da parte fracionaria: "
             << fracDecimalParaHexadecimal(parteFracionaria)
             << endl;
    }

    cout << "\nRESULTADO FINAL: "
         << decimalCompletoParaHexadecimal(decimal)
         << endl;
}

// ======================================================
// BINARIO -> DECIMAL
// ======================================================

void traceBinarioCompletoParaDecimal(string binario){

    cout << "\n========== BINARIO -> DECIMAL ==========\n";

    string parteInteira = "";
    string parteFracionaria = "";

    bool encontrouPonto = false;

    for(int i = 0; i < binario.size(); i++){

        if(binario[i] == '.'){
            encontrouPonto = true;
        }
        else if(!encontrouPonto){
            parteInteira += binario[i];
        }
        else{
            parteFracionaria += binario[i];
        }
    }

    cout << "\nPARTE INTEIRA:\n\n";

    int posicao = 0;
    int soma = 0;

    for(int i = parteInteira.size() - 1; i >= 0; i--){

        int bit = parteInteira[i] - '0';

        int valor = bit * pow(2, posicao);

        cout << bit
             << " x 2^"
             << posicao
             << " = "
             << valor
             << endl;

        soma += valor;

        posicao++;
    }

    cout << "\nSoma da parte inteira = "
         << soma
         << endl;

    if(parteFracionaria != ""){

        cout << "\nPARTE FRACIONARIA:\n\n";

        double somaFracao = 0;

        for(int i = 0; i < parteFracionaria.size(); i++){

            int bit = parteFracionaria[i] - '0';

            double valor = bit * pow(2, -(i + 1));

            cout << bit
                 << " x 2^-"
                 << (i + 1)
                 << " = "
                 << valor
                 << endl;

            somaFracao += valor;
        }

        cout << "\nSoma da parte fracionaria = "
             << somaFracao
             << endl;
    }

    cout << "\nRESULTADO FINAL: "
         << binarioCompletoParaDecimal(binario)
         << endl;
}

// ======================================================
// BINARIO -> OCTAL
// ======================================================

void traceBinarioCompletoParaOctal(string binario){

    cout << "\n========== BINARIO -> OCTAL ==========\n";

    string parteInteira = "";
    string parteFracionaria = "";

    bool encontrouPonto = false;

    for(int i = 0; i < binario.size(); i++){

        if(binario[i] == '.'){
            encontrouPonto = true;
        }
        else if(!encontrouPonto){
            parteInteira += binario[i];
        }
        else{
            parteFracionaria += binario[i];
        }
    }

    while(parteInteira.size() % 3 != 0){
        parteInteira = "0" + parteInteira;
    }

    cout << "\nAGRUPAMENTO DA PARTE INTEIRA:\n\n";

    for(int i = 0; i < parteInteira.size(); i += 3){

        cout << parteInteira[i]
             << parteInteira[i + 1]
             << parteInteira[i + 2]
             << endl;
    }

    if(parteFracionaria != ""){

        while(parteFracionaria.size() % 3 != 0){
            parteFracionaria += "0";
        }

        cout << "\nAGRUPAMENTO DA PARTE FRACIONARIA:\n\n";

        for(int i = 0; i < parteFracionaria.size(); i += 3){

            cout << parteFracionaria[i]
                 << parteFracionaria[i + 1]
                 << parteFracionaria[i + 2]
                 << endl;
        }
    }

    cout << "\nRESULTADO FINAL: "
         << binarioCompletoParaOctal(binario)
         << endl;
}

// ======================================================
// BINARIO -> HEXADECIMAL
// ======================================================

void traceBinarioCompletoParaHexadecimal(string binario){

    cout << "\n========== BINARIO -> HEXADECIMAL ==========\n";

    string parteInteira = "";
    string parteFracionaria = "";

    bool encontrouPonto = false;

    for(int i = 0; i < binario.size(); i++){

        if(binario[i] == '.'){
            encontrouPonto = true;
        }
        else if(!encontrouPonto){
            parteInteira += binario[i];
        }
        else{
            parteFracionaria += binario[i];
        }
    }

    while(parteInteira.size() % 4 != 0){
        parteInteira = "0" + parteInteira;
    }

    cout << "\nAGRUPAMENTO DA PARTE INTEIRA:\n\n";

    for(int i = 0; i < parteInteira.size(); i += 4){

        cout << parteInteira[i]
             << parteInteira[i + 1]
             << parteInteira[i + 2]
             << parteInteira[i + 3]
             << endl;
    }

    if(parteFracionaria != ""){

        while(parteFracionaria.size() % 4 != 0){
            parteFracionaria += "0";
        }

        cout << "\nAGRUPAMENTO DA PARTE FRACIONARIA:\n\n";

        for(int i = 0; i < parteFracionaria.size(); i += 4){

            cout << parteFracionaria[i]
                 << parteFracionaria[i + 1]
                 << parteFracionaria[i + 2]
                 << parteFracionaria[i + 3]
                 << endl;
        }
    }

    cout << "\nRESULTADO FINAL: "
         << binarioCompletoParaHexadecimal(binario)
         << endl;
}

// ======================================================
// OCTAL -> DECIMAL
// ======================================================

void traceOctalCompletoParaDecimal(string octal){

    cout << "\n========== OCTAL -> DECIMAL ==========\n";

    string parteInteira = "";
    string parteFracionaria = "";

    bool encontrouPonto = false;

    for(int i = 0; i < octal.size(); i++){

        if(octal[i] == '.'){
            encontrouPonto = true;
        }
        else if(!encontrouPonto){
            parteInteira += octal[i];
        }
        else{
            parteFracionaria += octal[i];
        }
    }

    cout << "\nPARTE INTEIRA:\n\n";

    int soma = 0;
    int posicao = 0;

    for(int i = parteInteira.size() - 1; i >= 0; i--){

        int digito = parteInteira[i] - '0';

        int valor = digito * pow(8, posicao);

        cout << digito
             << " x 8^"
             << posicao
             << " = "
             << valor
             << endl;

        soma += valor;

        posicao++;
    }

    cout << "\nSoma da parte inteira = "
         << soma
         << endl;

    if(parteFracionaria != ""){

        cout << "\nPARTE FRACIONARIA:\n\n";

        double somaFracao = 0;

        for(int i = 0; i < parteFracionaria.size(); i++){

            int digito = parteFracionaria[i] - '0';

            double valor = digito * pow(8, -(i + 1));

            cout << digito
                 << " x 8^-"
                 << (i + 1)
                 << " = "
                 << valor
                 << endl;

            somaFracao += valor;
        }

        cout << "\nSoma da parte fracionaria = "
             << somaFracao
             << endl;
    }

    cout << "\nRESULTADO FINAL: "
         << octalCompletoParaDecimal(octal)
         << endl;
}

// ======================================================
// OCTAL -> BINARIO
// ======================================================

void traceOctalCompletoParaBinario(string octal){

    cout << "\n========== OCTAL -> BINARIO ==========\n";

    cout << "\nCada digito octal equivale a 3 bits:\n\n";

    for(int i = 0; i < octal.size(); i++){

        if(octal[i] != '.'){

            cout << octal[i]
                 << " -> "
                 << octalParaBinario(string(1, octal[i]))
                 << endl;
        }
    }

    cout << "\nRESULTADO FINAL: "
         << octalCompletoParaBinario(octal)
         << endl;
}

// ======================================================
// OCTAL -> HEXADECIMAL
// ======================================================

void traceOctalCompletoParaHexadecimal(string octal){

    cout << "\n========== OCTAL -> HEXADECIMAL ==========\n";

    cout << "\n1° PASSO: OCTAL -> BINARIO\n";

    string binario = octalCompletoParaBinario(octal);

    cout << "Resultado em binario: "
         << binario
         << endl;

    cout << "\n2° PASSO: BINARIO -> HEXADECIMAL\n";

    cout << "Resultado final: "
         << octalCompletoParaHexadecimal(octal)
         << endl;
}

// ======================================================
// HEXADECIMAL -> DECIMAL
// ======================================================

void traceHexadecimalCompletoParaDecimal(string hexadecimal){

    cout << "\n========== HEXADECIMAL -> DECIMAL ==========\n";

    string parteInteira = "";
    string parteFracionaria = "";

    bool encontrouPonto = false;

    for(int i = 0; i < hexadecimal.size(); i++){

        if(hexadecimal[i] == '.'){
            encontrouPonto = true;
        }
        else if(!encontrouPonto){
            parteInteira += hexadecimal[i];
        }
        else{
            parteFracionaria += hexadecimal[i];
        }
    }

    cout << "\nPARTE INTEIRA:\n\n";

    int soma = 0;
    int posicao = 0;

    for(int i = parteInteira.size() - 1; i >= 0; i--){

        char digito = parteInteira[i];

        int valorDigito;

        if(digito >= '0' && digito <= '9'){
            valorDigito = digito - '0';
        }
        else{
            valorDigito = digito - 'A' + 10;
        }

        int valor = valorDigito * pow(16, posicao);

        cout << digito
             << " x 16^"
             << posicao
             << " = "
             << valor
             << endl;

        soma += valor;

        posicao++;
    }

    cout << "\nSoma da parte inteira = "
         << soma
         << endl;

    if(parteFracionaria != ""){

        cout << "\nPARTE FRACIONARIA:\n\n";

        double somaFracao = 0;

        for(int i = 0; i < parteFracionaria.size(); i++){

            char digito = parteFracionaria[i];

            int valorDigito;

            if(digito >= '0' && digito <= '9'){
                valorDigito = digito - '0';
            }
            else{
                valorDigito = digito - 'A' + 10;
            }

            double valor = valorDigito * pow(16, -(i + 1));

            cout << digito
                 << " x 16^-"
                 << (i + 1)
                 << " = "
                 << valor
                 << endl;

            somaFracao += valor;
        }

        cout << "\nSoma da parte fracionaria = "
             << somaFracao
             << endl;
    }

    cout << "\nRESULTADO FINAL: "
         << hexadecimalCompletoParaDecimal(hexadecimal)
         << endl;
}

// ======================================================
// HEXADECIMAL -> BINARIO
// ======================================================

void traceHexadecimalCompletoParaBinario(string hexadecimal){

    cout << "\n========== HEXADECIMAL -> BINARIO ==========\n";

    cout << "\nCada digito hexadecimal equivale a 4 bits:\n\n";

    for(int i = 0; i < hexadecimal.size(); i++){

        if(hexadecimal[i] != '.'){

            cout << hexadecimal[i]
                 << " -> "
                 << hexadecimalParaBinario(string(1, hexadecimal[i]))
                 << endl;
        }
    }

    cout << "\nRESULTADO FINAL: "
         << hexadecimalCompletoParaBinario(hexadecimal)
         << endl;
}

// ======================================================
// HEXADECIMAL -> OCTAL
// ======================================================

void traceHexadecimalCompletoParaOctal(string hexadecimal){

    cout << "\n========== HEXADECIMAL -> OCTAL ==========\n";

    cout << "\n1° PASSO: HEXADECIMAL -> BINARIO\n";

    string binario = hexadecimalCompletoParaBinario(hexadecimal);

    cout << "Resultado em binario: "
         << binario
         << endl;

    cout << "\n2° PASSO: BINARIO -> OCTAL\n";

    cout << "Resultado final: "
         << hexadecimalCompletoParaOctal(hexadecimal)
         << endl;
}