#include <stdlib.h>
#include <iostream>
#include <locale.h>
using namespace std;

int a,b,d;
double c;

int F(int N){ // Forma recursiva da função F
	if (N == 1){
		return 2;
	}
	else if(N > 1){
		return 3*(N - 1) + F(N - 1);
	}
}

int G(int N){ // Forma recursiva da função G
	if (N == 1 or N == 2){
		return 1;
	}
	else if(N > 2){
		return 4*G(N - 1) + 3*G(N - 2);
	}
}

int H(int N){ // Forma não recursiva da função H
	int prod = 1;
	while (N > 0){
		prod *= 7;
		N--;
	}
}

double I(double N){ // Sequência de Fibonacci não recursivo
	
	double a=0,b=1;
    while(--N){
    b = b + a;
    a = b - a;	
	}
    
    return b;
}

void entrada(){ // Onde o usuário digita os dados
	
	cout << endl << " Digite 4 números inteiros positivos" << endl;
	cout << endl << "   a = ";
	cin >> a;
	cout << endl << "   b = ";
	cin >> b;
	cout << endl << "   c = ";
	cin >> c;
	cout << endl << "   d = ";
	cin >> d;
	if (a<=0 or b <= 0 or c <= 0 or d <= 0){
		system( "cls || clear" );
		entrada();
	}
	
}

int processamento(){  // Processamento de dados
	int resultado = 2*F(b) + 5*G(a) - 3*H(d) + 7*I(c);
	return resultado;
}

void saida(){  //Saída do processamento
	cout << endl <<
	" Utilizando os valores de a = " << a
						<< " , b = " << b
						<< " , c = " << c
						<< " , d = " << d
						<< " , temos o resultado = " << processamento()
						<< endl;
	
}

int main(){  // Principal
	setlocale(LC_ALL,"");
	entrada();
	saida();
	
    return 0;
    
}

