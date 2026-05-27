// modoBatch.cpp

#include <iostream>
#include <fstream>
#include <string>

#include "conversor.h"
#include "modoBatch.h"

using namespace std;

void executarModoBatch(string arquivoEntradaNome,
                        string arquivoSaidaNome){

    ifstream arquivoEntrada(arquivoEntradaNome);

    if(!arquivoEntrada.is_open()){

        cout << "Erro ao abrir "
             << arquivoEntradaNome
             << endl;

        return;
    }

    ofstream arquivoSaida(arquivoSaidaNome);

    if(!arquivoSaida.is_open()){

        cout << "Erro ao criar "
             << arquivoSaidaNome
             << endl;

        return;
    }

    string linha;

    // Ignora cabeçalho
    getline(arquivoEntrada, linha);

    // Cabeçalho da saída
    arquivoSaida
    << "valor;base_origem;resultado;base_destino\n";

    while(getline(arquivoEntrada, linha)){

        if(linha == ""){
            continue;
        }

        string valor = "";
        string baseOrigemStr = "";
        string baseDestinoStr = "";

        int campo = 0;

        // ======================================================
        // SEPARAR CAMPOS MANUALMENTE
        // ======================================================

        for(int i = 0; i < linha.size(); i++){

            if(linha[i] == ';'){
                campo++;
            }

            else if(campo == 0){
                valor += linha[i];
            }

            else if(campo == 1){
                baseOrigemStr += linha[i];
            }

            else if(campo == 2){
                baseDestinoStr += linha[i];
            }
        }

        int baseOrigem = stoi(baseOrigemStr);

        int baseDestino = stoi(baseDestinoStr);

        string resultado = "";

        // ======================================================
        // BASE 10
        // ======================================================

        if(baseOrigem == 10){

            double decimal = stod(valor);

            if(baseDestino == 2){
                resultado =
                decimalCompletoParaBinario(decimal);
            }

            else if(baseDestino == 8){
                resultado =
                decimalCompletoParaOctal(decimal);
            }

            else if(baseDestino == 16){
                resultado =
                decimalCompletoParaHexadecimal(decimal);
            }

            else if(baseDestino == 10){
                resultado = valor;
            }
        }

        // ======================================================
        // BASE 2
        // ======================================================

        else if(baseOrigem == 2){

            if(baseDestino == 10){
                resultado =
                to_string(
                binarioCompletoParaDecimal(valor));
            }

            else if(baseDestino == 8){
                resultado =
                binarioCompletoParaOctal(valor);
            }

            else if(baseDestino == 16){
                resultado =
                binarioCompletoParaHexadecimal(valor);
            }

            else if(baseDestino == 2){
                resultado = valor;
            }
        }

        // ======================================================
        // BASE 8
        // ======================================================

        else if(baseOrigem == 8){

            if(baseDestino == 10){
                resultado =
                to_string(
                octalCompletoParaDecimal(valor));
            }

            else if(baseDestino == 2){
                resultado =
                octalCompletoParaBinario(valor);
            }

            else if(baseDestino == 16){
                resultado =
                octalCompletoParaHexadecimal(valor);
            }

            else if(baseDestino == 8){
                resultado = valor;
            }
        }

        // ======================================================
        // BASE 16
        // ======================================================

        else if(baseOrigem == 16){

            if(baseDestino == 10){
                resultado =
                to_string(
                hexadecimalCompletoParaDecimal(valor));
            }

            else if(baseDestino == 2){
                resultado =
                hexadecimalCompletoParaBinario(valor);
            }

            else if(baseDestino == 8){
                resultado =
                hexadecimalCompletoParaOctal(valor);
            }

            else if(baseDestino == 16){
                resultado = valor;
            }
        }

        // ======================================================
        // ESCREVER RESULTADO
        // ======================================================

        arquivoSaida
        << valor << ";"
        << baseOrigem << ";"
        << resultado << ";"
        << baseDestino
        << "\n";
    }

    arquivoEntrada.close();

    arquivoSaida.close();

    cout << "\nModo batch executado com sucesso."
         << endl;

    cout << "Arquivo "
         << arquivoSaidaNome
         << " gerado.\n"
         << endl;
}