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
    

printf("Dê o valor da primeira string \n");
scanf("%s", x);
printf("Dê o valor da segunda string \n");
scanf("%s",y);

 
//Comparando as duas variáveis 
retorno1 = strcmp(x,y);
if (retorno1==0) 
printf ("As palavras são iguais\n");
else
printf ("As palavras são diferentes\n");

//Comparando os 3 primeiro caracteres duas variáveis
retorno2 = strncmp(x,y,3);
if (retorno2 == 0) 
printf ("Os 3 primeiros caracteres destas palavras são iguais entre si\n");
else
printf ("Pelo menos um dos 3 primeiros caracteres é diferente entre estas strings\n");

//Concatenando as duas variáveis
printf ("Concatenando fica %s",strcat(x,y));

}
