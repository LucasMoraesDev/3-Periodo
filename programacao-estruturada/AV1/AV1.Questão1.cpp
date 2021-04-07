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


int H(int N){
	if (N == 0){
		return 1;
	}
	else if(N > 0){
		return 7*H(N - 1);
	}
}


int main(){
	setlocale(LC_ALL,"");
	
int n;
cout << endl << " Digite um número: ";
cin >> n;
 
 cout<< endl << " F  " << "(" << n << ") = " << F(n)
 	 << endl << " G  " << "(" << n << ") = " << G(n)
	 << endl << " H  " << "(" << n << ") = " << H(n)
	 << endl ;
    return 0;
}
