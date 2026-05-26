#include <iostream>
#include <cmath>
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


// CONVERTER BINÁRIO <--> OCTAL E BINÁRIO <--> HEXADECIMAL SEM PASSAR PELO DECIMAL

void binarioParaOctal(string binario){

    while(binario.size() % 3 != 0){
        binario = "0" + binario;
    }

    for(int i = 0; i < binario.size(); i += 3){

        int octal =
        (binario[i] - '0') * 4 +
        (binario[i+1] - '0') * 2 +
        (binario[i+2] - '0');

        cout << octal;
    }
}


string octalParaBinario(string octal) {

    string binario = "";

    if(octal != "") {

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
    }
    else{
        return "0";
    }

    return binario;
}

void binarioParaHexadecimal(string binario){

    while(binario.size() % 4 != 0){
        binario = "0" + binario;
    }

    for(int i = 0; i < binario.size(); i += 4){

        int hexadecimal =
        (binario[i] - '0') * 8 +
        (binario[i+1] - '0') * 4 +
        (binario[i+2] - '0') * 2 +
        (binario[i+3] - '0');

        if(hexadecimal >= 10 && hexadecimal <= 15){
            char letra=('A' + (hexadecimal - 10));
			cout << letra;
        }
        else{
            cout << hexadecimal;
        }
    }
}

void hexadecimalParaBinario(string hexadecimal){
	string binario = "";
	if(hexadecimal != ""){
    	for(int i = 0; i < hexadecimal.size(); i++){

        	if(hexadecimal[i] == '0') binario += "0000";
        	if(hexadecimal[i] == '1') binario += "0001";
        	if(hexadecimal[i] == '2') binario += "0010";
        	if(hexadecimal[i] == '3') binario += "0011";
        	if(hexadecimal[i] == '4') binario += "0100";
        	if(hexadecimal[i] == '5') binario += "0101";
        	if(hexadecimal[i] == '6') binario += "0110";
        	if(hexadecimal[i] == '7') binario += "0111";
        	if(hexadecimal[i] == '8') binario += "1000";
        	if(hexadecimal[i] == '9') binario += "1001";

        	if(hexadecimal[i] == 'A' || hexadecimal[i] == 'a') binario += "1010";
        	if(hexadecimal[i] == 'B' || hexadecimal[i] == 'b') binario += "1011";
        	if(hexadecimal[i] == 'C' || hexadecimal[i] == 'c') binario += "1100";
        	if(hexadecimal[i] == 'D' || hexadecimal[i] == 'd') binario += "1101";
        	if(hexadecimal[i] == 'E' || hexadecimal[i] == 'e') binario += "1110";
        	if(hexadecimal[i] == 'F' || hexadecimal[i] == 'f') binario += "1111";
    	}
	}
	else cout << 0;

    cout << binario;
}


// COVERTER OCTAL <--> HEXADECIMAL

void octalParaHexadecimal(string octal){
	
	string binario = octalParaBinario(octal);
	binarioParaHexadecimal(binario);
}

void decimalParaOctal(int decimal){

}


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
	 cout << endl;
	binarioParaOctal("110111");
	 cout << endl;
	binarioParaHexadecimal("11110001"); 
	 cout << endl;
	cout << octalParaBinario("11");
	 cout << endl;
	hexadecimalParaBinario("1AF");
	 cout << endl;
	octalParaHexadecimal("735");


	return 0;
}
