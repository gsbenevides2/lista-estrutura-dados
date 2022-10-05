#include <stdio.h>
#include <conio.h>
#include "pilha.h"

int main(void){
  	char e;
	int balanceado = 1;
	Pilha Expressao = pilha(sizeof(char)*255);
	Pilha ExpressaoTeste = pilha(sizeof(char)*255);

	printf("Entre com uma espressao: ");

	do{
		e = _getch();
		empilha(e,Expressao);
		if(vaziap(ExpressaoTeste)== 0){
			if(e == 125 && topo(ExpressaoTeste) != 123) balanceado = 0;
			else if(e == 93 && topo(ExpressaoTeste) != 91)balanceado = 0;
			else if(e == 41 && topo(ExpressaoTeste) != 40)balanceado = 0;
			else if(e == 125 || e == 93 || e == 41)desempilha(ExpressaoTeste);
			else empilha(e,ExpressaoTeste);
		}else empilha(e,ExpressaoTeste);

		
		
		printf("%c", e);

	}while(e != 13);

	printf("\n");
	if(balanceado) printf("A expressao esta balanceada.\n");
	else printf("A expressao nao esta balanceada.\n");
    return 0;
}
