#include <iostream>
#include <cstdlib>
#include <ctime>

#include "quiz.h"
#include "conversor.h"

using namespace std;

// ======================================================
// REMOVE ZEROS À ESQUERDA
// ======================================================

string removerZerosEsquerda(string valor){

    while(valor.size() > 1 &&
          valor[0] == '0' &&
          valor[1] != '.'){

        valor.erase(0, 1);
    }

    return valor;
}

// ======================================================
// GERA PERGUNTA
// ======================================================

Pergunta gerarPergunta(int nivel){

    Pergunta p;

    int tipo;

    // ==================================================
    // NÍVEL 1
    // decimal <-> binario
    // números pequenos
    // ==================================================

    if(nivel == 1){

        tipo = rand() % 2;

        int numero = rand() % 16 + 1;

        if(tipo == 0){

            p.pergunta =
            "Converta " +
            to_string(numero) +
            " decimal para binario: ";

            p.resposta =
            decimalCompletoParaBinario(numero);
        }

        else{

            string binario =
            decimalCompletoParaBinario(numero);

            p.pergunta =
            "Converta " +
            binario +
            " binario para decimal: ";

            p.resposta =
            to_string(numero);
        }
    }

    // ==================================================
    // NÍVEL 2
    // adiciona octal
    // ==================================================

    else if(nivel == 2){

        tipo = rand() % 4;

        int numero = rand() % 128 + 1;

        if(tipo == 0){

            p.pergunta =
            "Converta " +
            to_string(numero) +
            " decimal para octal: ";

            p.resposta =
            decimalCompletoParaOctal(numero);
        }

        else if(tipo == 1){

            string octal =
            decimalCompletoParaOctal(numero);

            p.pergunta =
            "Converta " +
            octal +
            " octal para decimal: ";

            p.resposta =
            to_string(numero);
        }

        else if(tipo == 2){

            string binario =
            decimalCompletoParaBinario(numero);

            p.pergunta =
            "Converta " +
            binario +
            " binario para octal: ";

            p.resposta =
            binarioCompletoParaOctal(binario);
        }

        else{

            string octal =
            decimalCompletoParaOctal(numero);

            p.pergunta =
            "Converta " +
            octal +
            " octal para binario: ";

            p.resposta =
            octalCompletoParaBinario(octal);
        }
    }

    // ==================================================
    // NÍVEL 3
    // adiciona hexadecimal
    // ==================================================

    else if(nivel == 3){

        tipo = rand() % 4;

        int numero = rand() % 1024 + 1;

        if(tipo == 0){

            p.pergunta =
            "Converta " +
            to_string(numero) +
            " decimal para hexadecimal: ";

            p.resposta =
            decimalCompletoParaHexadecimal(numero);
        }

        else if(tipo == 1){

            string hexadecimal =
            decimalCompletoParaHexadecimal(numero);

            p.pergunta =
            "Converta " +
            hexadecimal +
            " hexadecimal para decimal: ";

            p.resposta =
            to_string(numero);
        }

        else if(tipo == 2){

            string binario =
            decimalCompletoParaBinario(numero);

            p.pergunta =
            "Converta " +
            binario +
            " binario para hexadecimal: ";

            p.resposta =
            binarioCompletoParaHexadecimal(binario);
        }

        else{

            string hexadecimal =
            decimalCompletoParaHexadecimal(numero);

            p.pergunta =
            "Converta " +
            hexadecimal +
            " hexadecimal para binario: ";

            p.resposta =
            hexadecimalCompletoParaBinario(hexadecimal);
        }
    }

    // ==================================================
    // NÍVEL 4
    // números fracionários
    // ==================================================

    else if(nivel == 4){

        tipo = rand() % 3;

        double numero =
        (rand() % 50) +
        ((rand() % 8) / 8.0);

        if(tipo == 0){

            p.pergunta =
            "Converta " +
            to_string(numero) +
            " decimal para binario: ";

            p.resposta =
            decimalCompletoParaBinario(numero);
        }

        else if(tipo == 1){

            string binario =
            decimalCompletoParaBinario(numero);

            p.pergunta =
            "Converta " +
            binario +
            " binario para decimal: ";

            p.resposta =
            to_string(
            binarioCompletoParaDecimal(binario));
        }

        else{

            string hexadecimal =
            decimalCompletoParaHexadecimal(numero);

            p.pergunta =
            "Converta " +
            hexadecimal +
            " hexadecimal para decimal: ";

            p.resposta =
            to_string(
            hexadecimalCompletoParaDecimal(hexadecimal));
        }
    }

    // ==================================================
    // NÍVEL 5
    // qualquer conversão
    // ==================================================

    else{

        tipo = rand() % 6;

        double numero =
        (rand() % 500) +
        ((rand() % 16) / 16.0);

        string binario =
        decimalCompletoParaBinario(numero);

        string octal =
        decimalCompletoParaOctal(numero);

        string hexadecimal =
        decimalCompletoParaHexadecimal(numero);

        if(tipo == 0){

            p.pergunta =
            "Converta " +
            octal +
            " octal para hexadecimal: ";

            p.resposta =
            octalCompletoParaHexadecimal(octal);
        }

        else if(tipo == 1){

            p.pergunta =
            "Converta " +
            hexadecimal +
            " hexadecimal para octal: ";

            p.resposta =
            hexadecimalCompletoParaOctal(hexadecimal);
        }

        else if(tipo == 2){

            p.pergunta =
            "Converta " +
            binario +
            " binario para octal: ";

            p.resposta =
            binarioCompletoParaOctal(binario);
        }

        else if(tipo == 3){

            p.pergunta =
            "Converta " +
            octal +
            " octal para binario: ";

            p.resposta =
            octalCompletoParaBinario(octal);
        }

        else if(tipo == 4){

            p.pergunta =
            "Converta " +
            hexadecimal +
            " hexadecimal para binario: ";

            p.resposta =
            hexadecimalCompletoParaBinario(hexadecimal);
        }

        else{

            p.pergunta =
            "Converta " +
            binario +
            " binario para hexadecimal: ";

            p.resposta =
            binarioCompletoParaHexadecimal(binario);
        }
    }

    return p;
}

// ======================================================
// INICIAR QUIZ
// ======================================================

void iniciarQuiz(){

    srand(time(0));

    int nivel;
    int quantidade;
    int pontos = 0;

    cout << "\n=====================================\n";
    cout << "MODO QUIZ\n";
    cout << "=====================================\n";

    cout << "\nEscolha o nivel (1-5): ";
    cin >> nivel;

    cout << "Quantidade de perguntas: ";
    cin >> quantidade;

    for(int i = 1; i <= quantidade; i++){

        Pergunta p = gerarPergunta(nivel);

        string respostaUsuario;

        cout << "\n-------------------------------------\n";
        cout << "Pergunta " << i << endl;
        cout << "-------------------------------------\n";

        cout << p.pergunta;

        cin >> respostaUsuario;

        string correta =
        removerZerosEsquerda(p.resposta);

        string usuario =
        removerZerosEsquerda(respostaUsuario);

        if(usuario == correta){

            cout << "\nResposta correta!\n";

            pontos += nivel * 10;
        }

        else{

            cout << "\nResposta errada!\n";

            cout << "Resposta correta: "
                 << p.resposta << endl;
        }
    }

    cout << "\n=====================================\n";
    cout << "QUIZ FINALIZADO\n";
    cout << "=====================================\n";

    cout << "\nPontuacao final: "
         << pontos << endl;
}