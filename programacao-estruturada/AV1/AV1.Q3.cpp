#include<locale.h>
#include<stdlib.h>
#include<iostream>
#include <stdio.h> 

using namespace std;

const int K = 12;
int CNPJ_VETOR[K]; // Vetor com os digitos informados do CNPJ

int DIGITO_1_PESO[K] = {5,4,3,2,9,8,7,6,5,4,3,2};
int DIGITO_2_PESO[K] = {6,5,4,3,2,9,8,7,6,5,4,3,};
int D1;
int D2;
int auxiliar_d1[K];
int auxiliar_d2[K+1];
int CNPJ_COMPLETO[K+2];
int quociente = 0;
int resto = 0;


void entrada(){
	
	for (int i = 0; i < K ; i++){
		cout << endl << "  Informe dígito a dígito os 12 primeiros números do CNPJ"
			 << endl << "  > " << i + 1 << "° ";
		cin >> CNPJ_VETOR[i];
		system("clear || cls");	
	}
	
}

int calculoD1(){
	for (int i = 0; i < K; i++){
		auxiliar_d1[i] = CNPJ_VETOR[i] * DIGITO_1_PESO[i];
	}
	for (int i = 0; i < K; i++){
		D1 += auxiliar_d1[i]; 
	}
	quociente = D1 / 11;
	resto = D1 % 11;
	
	if (resto < 2) {
		D1 = 0;
	}else{
		D1 = 11 - resto;
	}
	return D1;
}

int calculoD2(){
	for (int i = 0; i < K; i++){
		auxiliar_d2[i] = CNPJ_VETOR[i] * DIGITO_2_PESO[i];
	}
		auxiliar_d2[13] = DIGITO_2_PESO[13] * 2;
	for (int i = 0; i < K + 1; i++){
		D2 += auxiliar_d2[i]; 
	}
	quociente = D2 / 11;
	resto = D2 % 11;
	
	if (resto < 2) {
		D2 = 0;
	}else{
		D2 = 11 - resto;
	}
	return D2;
}

void imprime_CNPJ(){
	int i = 0;
	for (int i = 0; i < K; i++) {
		CNPJ_COMPLETO[i] = CNPJ_VETOR[i];
	}
	CNPJ_COMPLETO[13] = D1;
	CNPJ_COMPLETO[14] = D2;
	printf("O CNPJ completo é : %d",CNPJ_COMPLETO[i]);
}

/*int processamento(){ //D1
	
	int pesos[K] = {5, 4, 3, 2, 9, 8, 7, 6, 5, 4, 3, 2};
	int produto[K] , soma = 0;
	
	for (int i = 0; i < K; i++){
		produto[i] = CNPJ_VETOR[i] * pesos[i];
		soma += produto[i];
	}
	if (soma % 11 < 2){
		return 0;
	}
		else{
			return 11 - (soma % 11);
		}
	return 0;
}*/

int main(){
	setlocale(LC_ALL,"");
	entrada();
	calculoD1();
	calculoD2();
	imprime_CNPJ();
	
//	cout << D1;
	
	return 0;
}
