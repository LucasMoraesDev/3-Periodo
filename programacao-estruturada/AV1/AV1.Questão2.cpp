#include <stdlib.h>
#include <iostream>
#include <locale.h>
using namespace std;

int a,b,c,d;

int F(int N){
	if (N == 1){
		return 2;
	}
	else if(N > 1){
		return 3*(N - 1) + F(N - 1);
	}
}

int G(int N){
	if (N == 1 or N == 2){
		return 1;
	}
	else if(N > 2){
		return 4*G(N - 1) + 3*G(N - 2);
	}
}
/*
int HR(int N){ // Forma recursiva da função H
	if (N == 0){
		return 1;
	}
	else if(N > 0){
		return 7*HR(N - 1);
	}
}
*/
int H(int N){ // Forma não recursiva da função H
	int prod = 1;
	while (N > 0){
		prod *= 7;
		N--;
	}
}

int I(int N){
	/*int n1 = 0, n2 = 1 , n3 = 0;
	while (N > 1){
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		N--;
	}
	
	return n2;*/
	int a=1,b=1;
    while(--N){
    b = b + a;
    a = b - a;	
	}
    
    return b;
}

/*
 F(N)= 2 quando N=1
 3*(N-1) + F(N-1) quando N>1
 
 G(N) = 1 quando N=1 ou N=2
 4*G(N-1)+3*G(N-2) quando N>2
 
 H(N) =1 quando N=0
 7*H(N-1) quando N>0
 
 I(N) = n-ésimo termo da sequência de Fibonacci 
*/

void entrada(){
	
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

int processamento(){
	int resultado = 2*F(b) + 5*G(a) - 3*H(d) + 7*I(c);
	return resultado;
}

void saida(){
	cout << endl <<
	" Utilizando os valores de a = " << a
						<< " , b = " << b
						<< " , c = " << c
						<< " , d = " << d
						<< " , temos o resultado = " << processamento()
						<< endl;
	
}

int main(){
	setlocale(LC_ALL,"");
	//entrada();
	//saida();
	
//Código usado para testes
int n;
cout << endl << " Digite um número: ";
cin >> n;
int a = n + 10;
 for(; n < a;n++){

 cout//<< endl << " F  " << "(" << n << ") = " << F(n)
 	 //<< endl << " G  " << "(" << n << ") = " << G(n)
	 //<< endl << " HR " << "(" << n << ") = " << HR(n)
	 //<< endl << " H  " << "(" << n << ") = " << H(n)
	 << endl << " I  " << "(" << n << ") = " << I(n)
	 << endl ;
}
    return 0;
    
}

