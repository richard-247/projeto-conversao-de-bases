#include <iostream>

#include "conversor.h"
#include "modoPasso_a_passo.h"
#include "quiz.h"
#include "modoBatch.h"
#include "calculadora_maximos.h"

using namespace std;

// ======================================================
// MENU DE CONVERSAO
// ======================================================

void menuConversoes(){

    int opcao;

    do{

        cout << "\n========================================";
        cout << "\n        MENU DE CONVERSOES";
        cout << "\n========================================";

        cout << "\n\n1  - Decimal -> Binario";
        cout << "\n2  - Decimal -> Octal";
        cout << "\n3  - Decimal -> Hexadecimal";

        cout << "\n4  - Binario -> Decimal";
        cout << "\n5  - Binario -> Octal";
        cout << "\n6  - Binario -> Hexadecimal";

        cout << "\n7  - Octal -> Decimal";
        cout << "\n8  - Octal -> Binario";
        cout << "\n9  - Octal -> Hexadecimal";

        cout << "\n10 - Hexadecimal -> Decimal";
        cout << "\n11 - Hexadecimal -> Binario";
        cout << "\n12 - Hexadecimal -> Octal";

        cout << "\n0  - Voltar";

        cout << "\n\nEscolha uma opcao: ";
        cin >> opcao;

        cout << endl;

        // ======================================================
        // DECIMAL
        // ======================================================

        if(opcao == 1){

            double valor;

            cout << "Digite um numero decimal: ";
            cin >> valor;

            cout << "Resultado: "
                 << decimalCompletoParaBinario(valor)
                 << endl;
        }

        else if(opcao == 2){

            double valor;

            cout << "Digite um numero decimal: ";
            cin >> valor;

            cout << "Resultado: "
                 << decimalCompletoParaOctal(valor)
                 << endl;
        }

        else if(opcao == 3){

            double valor;

            cout << "Digite um numero decimal: ";
            cin >> valor;

            cout << "Resultado: "
                 << decimalCompletoParaHexadecimal(valor)
                 << endl;
        }

        // ======================================================
        // BINARIO
        // ======================================================

        else if(opcao == 4){

            string valor;

            cout << "Digite um numero binario: ";
            cin >> valor;

            if(!validarEntrada(valor, 2)){

                cout << "Entrada invalida para base binaria!\n";
            }

            else{

                cout << "Resultado: "
                     << binarioCompletoParaDecimal(valor)
                     << endl;
            }
        }

        else if(opcao == 5){

            string valor;

            cout << "Digite um numero binario: ";
            cin >> valor;

            if(!validarEntrada(valor, 2)){

                cout << "Entrada invalida para base binaria!\n";
            }

            else{

                cout << "Resultado: "
                     << binarioCompletoParaOctal(valor)
                     << endl;
            }
        }

        else if(opcao == 6){

            string valor;

            cout << "Digite um numero binario: ";
            cin >> valor;

            if(!validarEntrada(valor, 2)){

                cout << "Entrada invalida para base binaria!\n";
            }

            else{

                cout << "Resultado: "
                     << binarioCompletoParaHexadecimal(valor)
                     << endl;
            }
        }

        // ======================================================
        // OCTAL
        // ======================================================

        else if(opcao == 7){

            string valor;

            cout << "Digite um numero octal: ";
            cin >> valor;

            if(!validarEntrada(valor, 8)){

                cout << "Entrada invalida para base octal!\n";
            }

            else{

                cout << "Resultado: "
                     << octalCompletoParaDecimal(valor)
                     << endl;
            }
        }

        else if(opcao == 8){

            string valor;

            cout << "Digite um numero octal: ";
            cin >> valor;

            if(!validarEntrada(valor, 8)){

                cout << "Entrada invalida para base octal!\n";
            }

            else{

                cout << "Resultado: "
                     << octalCompletoParaBinario(valor)
                     << endl;
            }
        }

        else if(opcao == 9){

            string valor;

            cout << "Digite um numero octal: ";
            cin >> valor;

            if(!validarEntrada(valor, 8)){

                cout << "Entrada invalida para base octal!\n";
            }

            else{

                cout << "Resultado: "
                     << octalCompletoParaHexadecimal(valor)
                     << endl;
            }
        }

        // ======================================================
        // HEXADECIMAL
        // ======================================================

        else if(opcao == 10){

            string valor;

            cout << "Digite um numero hexadecimal: ";
            cin >> valor;

            if(!validarEntrada(valor, 16)){

                cout << "Entrada invalida para base hexadecimal!\n";
            }

            else{

                cout << "Resultado: "
                     << hexadecimalCompletoParaDecimal(valor)
                     << endl;
            }
        }

        else if(opcao == 11){

            string valor;

            cout << "Digite um numero hexadecimal: ";
            cin >> valor;

            if(!validarEntrada(valor, 16)){

                cout << "Entrada invalida para base hexadecimal!\n";
            }

            else{

                cout << "Resultado: "
                     << hexadecimalCompletoParaBinario(valor)
                     << endl;
            }
        }

        else if(opcao == 12){

            string valor;

            cout << "Digite um numero hexadecimal: ";
            cin >> valor;

            if(!validarEntrada(valor, 16)){

                cout << "Entrada invalida para base hexadecimal!\n";
            }

            else{

                cout << "Resultado: "
                     << hexadecimalCompletoParaOctal(valor)
                     << endl;
            }
        }

    }while(opcao != 0);
}

// ======================================================
// MENU PASSO A PASSO
// ======================================================

void menuPassoAPasso(){

    int opcao;

    do{

        cout << "\n========================================";
        cout << "\n        MENU PASSO A PASSO";
        cout << "\n========================================";

        cout << "\n\n1  - Decimal -> Binario";
        cout << "\n2  - Decimal -> Octal";
        cout << "\n3  - Decimal -> Hexadecimal";

        cout << "\n4  - Binario -> Decimal";
        cout << "\n5  - Binario -> Octal";
        cout << "\n6  - Binario -> Hexadecimal";

        cout << "\n7  - Octal -> Decimal";
        cout << "\n8  - Octal -> Binario";
        cout << "\n9  - Octal -> Hexadecimal";

        cout << "\n10 - Hexadecimal -> Decimal";
        cout << "\n11 - Hexadecimal -> Binario";
        cout << "\n12 - Hexadecimal -> Octal";

        cout << "\n0  - Voltar";

        cout << "\n\nEscolha uma opcao: ";
        cin >> opcao;

        cout << endl;

        // ======================================================
        // DECIMAL
        // ======================================================

        if(opcao == 1){

            double valor;

            cout << "Digite um numero decimal: ";
            cin >> valor;

            traceDecimalCompletoParaBinario(valor);
        }

        else if(opcao == 2){

            double valor;

            cout << "Digite um numero decimal: ";
            cin >> valor;

            traceDecimalCompletoParaOctal(valor);
        }

        else if(opcao == 3){

            double valor;

            cout << "Digite um numero decimal: ";
            cin >> valor;

            traceDecimalCompletoParaHexadecimal(valor);
        }

        // ======================================================
        // BINARIO
        // ======================================================

        else if(opcao == 4){

            string valor;

            cout << "Digite um numero binario: ";
            cin >> valor;

            if(!validarEntrada(valor, 2)){

                cout << "Entrada invalida para base binaria!\n";
            }

            else{

                traceBinarioCompletoParaDecimal(valor);
            }
        }

        else if(opcao == 5){

            string valor;

            cout << "Digite um numero binario: ";
            cin >> valor;

            if(!validarEntrada(valor, 2)){

                cout << "Entrada invalida para base binaria!\n";
            }

            else{

                traceBinarioCompletoParaOctal(valor);
            }
        }

        else if(opcao == 6){

            string valor;

            cout << "Digite um numero binario: ";
            cin >> valor;

            if(!validarEntrada(valor, 2)){

                cout << "Entrada invalida para base binaria!\n";
            }

            else{

                traceBinarioCompletoParaHexadecimal(valor);
            }
        }

        // ======================================================
        // OCTAL
        // ======================================================

        else if(opcao == 7){

            string valor;

            cout << "Digite um numero octal: ";
            cin >> valor;

            if(!validarEntrada(valor, 8)){

                cout << "Entrada invalida para base octal!\n";
            }

            else{

                traceOctalCompletoParaDecimal(valor);
            }
        }

        else if(opcao == 8){

            string valor;

            cout << "Digite um numero octal: ";
            cin >> valor;

            if(!validarEntrada(valor, 8)){

                cout << "Entrada invalida para base octal!\n";
            }

            else{

                traceOctalCompletoParaBinario(valor);
            }
        }

        else if(opcao == 9){

            string valor;

            cout << "Digite um numero octal: ";
            cin >> valor;

            if(!validarEntrada(valor, 8)){

                cout << "Entrada invalida para base octal!\n";
            }

            else{

                traceOctalCompletoParaHexadecimal(valor);
            }
        }

        // ======================================================
        // HEXADECIMAL
        // ======================================================

        else if(opcao == 10){

            string valor;

            cout << "Digite um numero hexadecimal: ";
            cin >> valor;

            if(!validarEntrada(valor, 16)){

                cout << "Entrada invalida para base hexadecimal!\n";
            }

            else{

                traceHexadecimalCompletoParaDecimal(valor);
            }
        }

        else if(opcao == 11){

            string valor;

            cout << "Digite um numero hexadecimal: ";
            cin >> valor;

            if(!validarEntrada(valor, 16)){

                cout << "Entrada invalida para base hexadecimal!\n";
            }

            else{

                traceHexadecimalCompletoParaBinario(valor);
            }
        }

        else if(opcao == 12){

            string valor;

            cout << "Digite um numero hexadecimal: ";
            cin >> valor;

            if(!validarEntrada(valor, 16)){

                cout << "Entrada invalida para base hexadecimal!\n";
            }

            else{

                traceHexadecimalCompletoParaOctal(valor);
            }
        }

    }while(opcao != 0);
}

// ======================================================
// MAIN
// ======================================================

int main(){

    int opcao;

    do{

        cout << "\n========================================";
        cout << "\n     CONVERSOR DE BASES NUMERICAS";
        cout << "\n========================================";

        cout << "\n\n1 - Conversoes";
        cout << "\n2 - Modo passo a passo";
        cout << "\n3 - Quiz";
        cout << "\n4 - Modo batch";
        cout << "\n5 - Calculadora de maximos";
        cout << "\n0 - Sair";

        cout << "\n\nEscolha uma opcao: ";
        cin >> opcao;

        cout << endl;

        if(opcao == 1){

            menuConversoes();
        }

        else if(opcao == 2){

            menuPassoAPasso();
        }

        else if(opcao == 3){

            iniciarQuiz();
        }

        else if(opcao == 4){

            executarModoBatch("entrada.csv",
                               "saida.csv");
        }

        else if(opcao == 5){

            calculadora_maximos();
        }

    }while(opcao != 0);

    cout << "\nPrograma encerrado.\n";

    return 0;
}