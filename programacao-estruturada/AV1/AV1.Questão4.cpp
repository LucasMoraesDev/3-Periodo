#include <stdio.h>
#include <locale.h>
#include <string.h>
int main()
{
	char x[100];
	char y[100];
	
	int retorno1;
	int retorno2;
	/* Set the locale to the environment default */
    setlocale (LC_ALL, "");
    

printf("D� o valor da primeira string \n");
scanf("%s", x);
printf("D� o valor da segunda string \n");
scanf("%s",y);

 
//Comparando as duas vari�veis 
retorno1 = strcmp(x,y);
if (retorno1==0) 
printf ("As palavras s�o iguais\n");
else
printf ("As palavras s�o diferentes\n");

//Comparando os 3 primeiro caracteres duas vari�veis
retorno2 = strncmp(x,y,3);
if (retorno2 == 0) 
printf ("Os 3 primeiros caracteres destas palavras s�o iguais entre si\n");
else
printf ("Pelo menos um dos 3 primeiros caracteres � diferente entre estas strings\n");

//Concatenando as duas vari�veis
printf ("Concatenando fica %s",strcat(x,y));

}
