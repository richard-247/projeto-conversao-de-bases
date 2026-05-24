#include <iostream>
using namespace std;

// CONVERTER DECIMAL --> BINÁRIO/OCTAL/HEXADECIAL

	void decimalParaBinario(long int numero){
		if(numero != 0){
			decimalParaBinario(numero/2);
			cout << numero % 2;		}
	}

	void decimalParaOctal(long int numero){
		if(numero != 0 ){
			decimalParaOctal(numero/8);
			cout << numero % 8;
		}
	}

	void decimalParaHexadecimal(long int numero){
		
		if(numero != 0){
			decimalParaHexadecimal(numero/16);
		
			int resto = numero % 16;

			if(resto < 10){
				cout << resto;
			}
			else{
				char letra = 'A' + (resto - 10);
				cout << letra;
			}
		}
	}

// CONVERTER BINÁRIO/OCTAL/HEXADECIAL --> DECIMAL

void binarioParaDecimal(int binario){
	if(binario == 0){
		cout << 0;
		
	}else{

	int decimal = 0;
	int base = 1;

	while(binario > 0){
		int digito = binario % 10;
		decimal += digito * base;
		base *= 2;
		binario /= 10;
	}

	cout << decimal;
	}
}

void octalParaDecimal(int octal){
	if(octal == 0){
		cout << 0;
		
	}else{

	int decimal = 0;
	int base = 1;

	while(octal > 0){
		int digito = octal % 10;
		decimal += digito * base;
		base *= 8;
		octal /= 10;
	}

	cout << decimal;
	}
}

void hexadecimalParaDecimal(string hexadecimal){
	if(hexadecimal == "0"){
		cout << 0;
		
	}
	else{
	int decimal = 0;
	int base = 1;

	for(int i = hexadecimal.size() - 1; i >= 0; --i){
		char digito = hexadecimal[i];
		int valor = 0;

		if(digito >= '0' && digito <= '9') {
			valor = digito - '0';
		}
		else if(digito >= 'A' && digito <= 'F'){
			valor = digito - 'A' + 10;
		}
		else if(digito >= 'a' && digito <= 'f') {
			valor = digito - 'a' + 10;
		}
		decimal += valor * base;
		base *= 16;
	}
	cout << decimal;
	}
}


// CONVERTER BINÁRIO <--> OCTAL E BINÁRIO <--> HEXADECIMAL



// COVERTER OCTAL <--> DECIMAL



// VALIDAR A ENTRADA DE ACORDO COM A BASE DE ORIGEM



//SUPORTAR NÚMEROS FRACIONÁRIOS



// IMPRIMIR P TRACE DO ALGORITMO



//MODO BATCH



// MODO QUIZ



// CALCULADORA DE MÁXIMOS


int main(){

	//cout << "Olá, mundo";

	decimalParaBinario(35);
	cout << endl;
	decimalParaOctal(35);
	cout << endl;
	decimalParaHexadecimal(35);
	cout << endl;
	binarioParaDecimal(100011);
	cout << endl;
	octalParaDecimal(43);
	cout << endl;
	hexadecimalParaDecimal("2AB");

	return 0;
}
