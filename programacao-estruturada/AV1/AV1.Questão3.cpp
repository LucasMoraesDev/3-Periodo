#include<locale.h>
#include<stdlib.h>
#include<iostream>
#include <stdio.h> 

using namespace std;

const int K = 12; // constante para as 12 posições
int CNPJ_VETOR[K]; // Vetor com os digitos informados do CNPJ
int DIGITO_1_PESO[K] = {5,4,3,2,9,8,7,6,5,4,3,2}; // pesos para digito verificador 1
int DIGITO_2_PESO[K] = {6,5,4,3,2,9,8,7,6,5,4,3}; // pesos para digito verificador 2
int auxiliar_d1[K]; // Vetor que armazena a multiplicação da posição de CNPJ_VETOR com o peso respectivo de DIGITO_1_PESO
int auxiliar_d2[K+1]; // Vetor que armazena a multiplicação da posição de CNPJ_VETOR com o peso respectivo de DIGITO_21_PESO
int D1; // Digito Verificador 1
int D2;// Digito Verificador 2
int somaD1;// para armazenar a soma do vetor auxiliar_d1
int somaD2;// para armazenar a soma do vetor auxiliar_d2
int CNPJ_COMPLETO[K+2];// Vetor para armazenar o CNPJ fornecido juntamente com os digitos verificadores
int quociente = 0; // Variavél para armazenar o quociente da divisão
int resto = 0; // Variavél para armazenar o resto da divisão


void entrada(){ // Função para receber a entrada dos números iniciais do CNPJ
	
	for (int i = 0; i < K ; i++){
		cout << endl << "  Informe dígito a dígito os 12 primeiros números do CNPJ"
			 << endl << "  > " << i + 1 << "° ";
		cin >> CNPJ_VETOR[i];
		system("clear || cls");	
	}
	
}

int calculoD1(){ // Função para calcular o digito verificador 1
	for (int i = 0; i < K; i++){
		auxiliar_d1[i] = CNPJ_VETOR[i] * DIGITO_1_PESO[i];
	}
	for (int i = 0; i < K; i++){
		somaD1 += auxiliar_d1[i]; 
	}
	quociente = somaD1 / 11;
	resto = somaD1 % 11;
	
	if (resto < 2) {
		D1 = 0;
	}else{
		D1 = 11 - resto;
	}
	return D1;
}

int calculoD2(){ // Função para calcular o digito verificador 2
	for (int i = 0; i < K; i++){
		auxiliar_d2[i] = CNPJ_VETOR[i] * DIGITO_2_PESO[i];
	}
		auxiliar_d2[12] = D1 * 2;
	for (int i = 0; i < K + 1; i++){
		somaD2 += auxiliar_d2[i]; 
	}
	quociente = somaD2 / 11;
	resto = somaD2 % 11;
	
	if (resto < 2) {
		D2 = 0;
	}else{
		D2 = 11 - resto;
	}
	return D2;
}

void imprime_CNPJ(){ // Função para imprimir o CNPJ juntamente com os digitos verificadores
	int i = 0;
	for (int i = 0; i < K; i++) {
		CNPJ_COMPLETO[i] = CNPJ_VETOR[i];
	}
	CNPJ_COMPLETO[12] = D1;
	CNPJ_COMPLETO[13] = D2;
	printf("O primeiro dígito verificador para este CNPJ é %d \n", D1);
	printf("O segundo dígito verificador para este CNPJ é %d\n", D2);
	printf("Logo o CNPJ completo é : ");
	for(i = 0; i< K +2;i++){
		switch(i){
			case 2:
			case 5:
				cout << ".";
				break;
			
			case 8:
				cout << "/";
				break;
				
			case 12:
				cout << "-";
				break;
		}
		cout << CNPJ_COMPLETO[i];
	}

}

int main(){
	setlocale(LC_ALL,"");
	entrada();
	calculoD1();
	calculoD2();
	imprime_CNPJ();
	
	return 0;
}
