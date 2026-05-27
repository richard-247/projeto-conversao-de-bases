#ifndef QUIZ_H
#define QUIZ_H

#include <string>

using namespace std;

struct Pergunta{

    string pergunta;
    string resposta;
};

Pergunta gerarPergunta(int nivel);

void iniciarQuiz();

string removerZerosEsquerda(string valor);

#endif