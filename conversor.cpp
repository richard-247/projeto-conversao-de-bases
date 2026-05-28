#include <iostream>
#include <cmath>
#include <string>
#include "conversor.h"

using namespace std;

// ======================================================
// DECIMAL -> BINÁRIO/OCTAL/HEXADECIMAL (PARTE INTEIRA)
// ======================================================
// 110001 = 100011
string decimalParaBinario(long int numero){

    if(numero == 0){
        return "";
    }

    return decimalParaBinario(numero / 2) + char((numero % 2) + '0');
}

string decimalParaOctal(long int numero){

    if(numero == 0){
        return "";
    }

    return decimalParaOctal(numero / 8) + char((numero % 8) + '0');
}

string decimalParaHexadecimal(long int numero){

    if(numero == 0){
        return "";
    }

    int resto = numero % 16;

    char digito;

    if(resto < 10){
        (digito = resto + '0');
    }
    else{
        digito = 'A' + (resto - 10);
    }

    return decimalParaHexadecimal(numero / 16) + digito;
}

// ======================================================
// BINÁRIO/OCTAL/HEXADECIMAL -> DECIMAL (PARTE INTEIRA)
// ======================================================

string binarioParaDecimal(string binario){

    int decimal = 0;
    int posicao = 0;

    for(int i = binario.size() - 1; i >= 0; i--){

        decimal += (binario[i] - '0') * pow(2, posicao);

        posicao++;
    }

    return to_string(decimal);
}

string octalParaDecimal(string octal){

    int decimal = 0;
    int posicao = 0;

    for(int i = octal.size() - 1; i >= 0; i--){

        decimal += (octal[i] - '0') * pow(8, posicao);

        posicao++;
    }

    return to_string(decimal);
}

string hexadecimalParaDecimal(string hexadecimal){

    int decimal = 0;
    int base = 1;

    for(int i = hexadecimal.size() - 1; i >= 0; i--){

        char digito = hexadecimal[i];

        int valor = 0;

        if(digito >= '0' && digito <= '9'){
            valor = digito - '0';
        }
        else if(digito >= 'A' && digito <= 'F'){
            valor = digito - 'A' + 10;
        }
        else if(digito >= 'a' && digito <= 'f'){
            valor = digito - 'a' + 10;
        }

        decimal += valor * base;

        base *= 16;
    }

    return to_string(decimal);
}

// ======================================================
// BINÁRIO <-> OCTAL / HEXADECIMAL
// ======================================================

string binarioParaOctal(string binario){

    while(binario.size() % 3 != 0){
        binario = "0" + binario;
    }

    string octal = "";

    for(int i = 0; i < binario.size(); i += 3){

        int valor =
        (binario[i] - '0') * 4 +
        (binario[i + 1] - '0') * 2 +
        (binario[i + 2] - '0');

        octal += char(valor + '0');
    }

    return octal;
}

string octalParaBinario(string octal){

    string binario = "";

    for(int i = 0; i < octal.size(); i++){

        int digito = octal[i] - '0';

        if(digito == 0) binario += "000";
        if(digito == 1) binario += "001";
        if(digito == 2) binario += "010";
        if(digito == 3) binario += "011";
        if(digito == 4) binario += "100";
        if(digito == 5) binario += "101";
        if(digito == 6) binario += "110";
        if(digito == 7) binario += "111";
    }

    return binario;
}

string binarioParaHexadecimal(string binario){

    while(binario.size() % 4 != 0){
        binario = "0" + binario;
    }

    string hexadecimal = "";

    for(int i = 0; i < binario.size(); i += 4){

        int valor =
        (binario[i] - '0') * 8 +
        (binario[i + 1] - '0') * 4 +
        (binario[i + 2] - '0') * 2 +
        (binario[i + 3] - '0');

        if(valor < 10){
            hexadecimal += char(valor + '0');
        }
        else{
            hexadecimal += char('A' + (valor - 10));
        }
    }

    return hexadecimal;
}

string hexadecimalParaBinario(string hexadecimal){

    string binario = "";

    for(int i = 0; i < hexadecimal.size(); i++){

        char c = hexadecimal[i];

        if(c == '0') binario += "0000";
        if(c == '1') binario += "0001";
        if(c == '2') binario += "0010";
        if(c == '3') binario += "0011";
        if(c == '4') binario += "0100";
        if(c == '5') binario += "0101";
        if(c == '6') binario += "0110";
        if(c == '7') binario += "0111";
        if(c == '8') binario += "1000";
        if(c == '9') binario += "1001";

        if(c == 'A' || c == 'a') binario += "1010";
        if(c == 'B' || c == 'b') binario += "1011";
        if(c == 'C' || c == 'c') binario += "1100";
        if(c == 'D' || c == 'd') binario += "1101";
        if(c == 'E' || c == 'e') binario += "1110";
        if(c == 'F' || c == 'f') binario += "1111";
    }

    return binario;
}

// ======================================================
// OCTAL <-> HEXADECIMAL
// ======================================================

string octalParaHexadecimal(string octal){

    string binario = octalParaBinario(octal);

    return binarioParaHexadecimal(binario);
}

string hexadecimalParaOctal(string hexadecimal){

    string binario = hexadecimalParaBinario(hexadecimal);

    return binarioParaOctal(binario);
}

// ======================================================
// VALIDAÇÃO
// ======================================================

bool validarEntrada(string entrada, int base){

    int pontos = 0;

    for(int i = 0; i < entrada.size(); i++){

        char c = entrada[i];

        if(base == 2){
            if(c != '0' && c != '1' && c != '.'){
                return false;
            }
            else if(c == '.'){
                pontos++;
                if(pontos > 1){
                    return false;
                }
            }
        }

        else if(base == 8){

            if((c < '0' || c > '7') && c != '.'){
                return false;
            }
            else if(c == '.'){
                pontos++;
                if(pontos > 1){
                    return false;
                }
            }
        }

        else if(base == 16){

            if(!((c >= '0' && c <= '9') ||
                 (c >= 'A' && c <= 'F') ||
                 (c >= 'a' && c <= 'f') || c == '.')){
                return false;
            }
            else if(c == '.'){
                pontos++;
                if(pontos > 1){
                    return false;
                }
            }
        }
    }

    return true;
}

// ======================================================
// FRAÇÕES DECIMAIS -> OUTRAS BASES
// ======================================================

string fracDecimalParaBinario(long double fracao){

    string resultado = "";

    int precisao = 16;

    while(fracao > 0 && precisao > 0){

        fracao *= 2;

        int bit = (int)fracao;

        resultado += char(bit + '0');

        fracao -= bit;

        precisao--;
    }

    return resultado;
}

string fracDecimalParaOctal(long double fracao){

    string resultado = "";

    int precisao = 16;

    while(fracao > 0 && precisao > 0){

        fracao *= 8;

        int digito = (int)fracao;

        resultado += char(digito + '0');

        fracao -= digito;

        precisao--;
    }

    return resultado;
}

string fracDecimalParaHexadecimal(long double fracao){

    string resultado = "";

    int precisao = 16;

    while(fracao > 0 && precisao > 0){

        fracao *= 16;

        int valor = (int)fracao;

        if(valor < 10){
            resultado += char(valor + '0');
        }
        else{
            resultado += char('A' + (valor - 10));
        }

        fracao -= valor;

        precisao--;
    }

    return resultado;
}

// ======================================================
// FRAÇÕES OUTRAS BASES -> DECIMAL
// ======================================================

double fracBinarioParaDecimal(string fracao){

    double decimal = 0;

    for(int i = 0; i < fracao.size(); i++){

        int bit = fracao[i] - '0';

        decimal += bit * pow(2, -(i + 1));
    }

    return decimal;
}

double fracOctalParaDecimal(string fracao){

    double decimal = 0;

    for(int i = 0; i < fracao.size(); i++){

        int digito = fracao[i] - '0';

        decimal += digito * pow(8, -(i + 1));
    }

    return decimal;
}

double fracHexadecimalParaDecimal(string fracao){

    double decimal = 0;

    for(int i = 0; i < fracao.size(); i++){

        char digito = fracao[i];

        int valor;

        if(digito >= '0' && digito <= '9'){
            valor = digito - '0';
        }
        else if(digito >= 'A' && digito <= 'F'){
            valor = digito - 'A' + 10;
        }
        else{
            valor = digito - 'a' + 10;
        }

        decimal += valor * pow(16, -(i + 1));
    }

    return decimal;
}

// ======================================================
// BINARIO -> OCTAL/HEXADECIMAL (FRAÇÃO)
// ======================================================

string fracBinarioParaOctal(string binario){


    while(binario.size() % 3 != 0){
        binario += "0";
    }

    return binarioParaOctal(binario);
}


string fracBinarioParaHexadecimal(string binario){

    while(binario.size() % 4 != 0){
        binario += "0";
    }

    return binarioParaHexadecimal(binario);
}

// ======================================================
// FUNÇÕES COMPLETAS
// ======================================================

string decimalCompletoParaBinario(double decimal){

    long int parteInteira = (long int)decimal;

    double parteFracionaria = decimal - parteInteira;

    string resultado;

    if(parteInteira == 0){
        resultado = "0";
    }
    else{
        resultado = decimalParaBinario(parteInteira);
    }

    if(parteFracionaria > 0){

        resultado += ".";

        resultado += fracDecimalParaBinario(parteFracionaria);
    }

    return resultado;
}

string decimalCompletoParaOctal(double decimal){

    long int parteInteira = (long int)decimal;

    double parteFracionaria = decimal - parteInteira;

    string resultado;

    if(parteInteira == 0){
        resultado = "0";
    }
    else{
        resultado = decimalParaOctal(parteInteira);
    }

    if(parteFracionaria > 0){

        resultado += ".";

        resultado += fracDecimalParaOctal(parteFracionaria);
    }

    return resultado;
}

string decimalCompletoParaHexadecimal(double decimal){

    long int parteInteira = (long int)decimal;

    double parteFracionaria = decimal - parteInteira;

    string resultado;

    if(parteInteira == 0){
        resultado = "0";
    }
    else{
        resultado = decimalParaHexadecimal(parteInteira);
    }

    if(parteFracionaria > 0){

        resultado += ".";

        resultado += fracDecimalParaHexadecimal(parteFracionaria);
    }

    return resultado;
}

double binarioCompletoParaDecimal(string binario){

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

    // CORREÇÃO: Adicionado tratamento caso a parte inteira esteja vazia (ex: .101)
    if(parteInteira == "") parteInteira = "0";

    double inteira = stod(binarioParaDecimal(parteInteira)); // a função stod transforma o retorno string em uma variável do tipo double

    double fracao = fracBinarioParaDecimal(parteFracionaria);

    return inteira + fracao;
}

string binarioCompletoParaOctal(string binario){

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
    if(parteFracionaria == "") {
        return binarioParaOctal(parteInteira);
    }else return binarioParaOctal(parteInteira) + "." + fracBinarioParaOctal(parteFracionaria);
}

string binarioCompletoParaHexadecimal(string binario){

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

    if(parteFracionaria == "") {
        return binarioParaHexadecimal(parteInteira);
    }else return binarioParaHexadecimal(parteInteira) + "." + fracBinarioParaHexadecimal(parteFracionaria);
}

double octalCompletoParaDecimal(string octal){

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

    // CORREÇÃO: Adicionado tratamento caso a parte inteira esteja vazia
    if(parteInteira == "") parteInteira = "0";

    double inteira = stod(octalParaDecimal(parteInteira));

    double fracao = fracOctalParaDecimal(parteFracionaria);

    return inteira + fracao;
}

string octalCompletoParaHexadecimal(string octal){

    string binario = octalCompletoParaBinario(octal);

    // CORREÇÃO: Chamava 'binarioParaHexadecimal' (inteiro), alterado para chamar a versão 'Completo' (que aceita o ponto '.')
    string hexadecimal = binarioCompletoParaHexadecimal(binario); 

    return hexadecimal;

}

string octalCompletoParaBinario(string octal){

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

    if(parteFracionaria == "") {
        return octalParaBinario(parteInteira);
    }else return octalParaBinario(parteInteira) + "." + octalParaBinario(parteFracionaria);
}

double hexadecimalCompletoParaDecimal(string hexadecimal){

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

    // CORREÇÃO: Adicionado tratamento caso a parte inteira esteja vazia
    if(parteInteira == "") parteInteira = "0";

    double inteira = stod(hexadecimalParaDecimal(parteInteira));

    double fracao = fracHexadecimalParaDecimal(parteFracionaria);

    return inteira + fracao;
}

string hexadecimalCompletoParaBinario(string hexadecimal){

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


    if(parteFracionaria == "")
        return hexadecimalParaBinario(parteInteira);
    else return hexadecimalParaBinario(parteInteira) + "." + hexadecimalParaBinario(parteFracionaria);
}

string hexadecimalCompletoParaOctal(string hexadecimal){

    string binario = hexadecimalCompletoParaBinario(hexadecimal);

    // CORREÇÃO: Chamava 'binarioParaOctal' (inteiro), alterado para chamar a versão 'Completo' (que aceita o ponto '.')
    string octal = binarioCompletoParaOctal(binario);

    return octal;

}