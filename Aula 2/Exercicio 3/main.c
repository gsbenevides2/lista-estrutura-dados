#include <stdio.h>
#include "pilha.h"

void mostrarPilha(Pilha p){
	char t = desempilha(p);
	if(vaziap(p) == 0) mostrarPilha(p);
	printf("%c", t);
}

void jogarPalavraNaFrase(Pilha Palavra, Pilha Frase){
	while(vaziap(Palavra) == 0)
		empilha(desempilha(Palavra),Frase);
}

int main(void){
  	char e;
	Pilha Palavra = pilha(sizeof(char)*255);
	Pilha Frase = pilha(sizeof(char)*255);
	printf("Entre com uma frase: ");

	do{
		e = _getch();
		if(e == 32){
			jogarPalavraNaFrase(Palavra,Frase);
			empilha(e,Frase);
		}
		else if(e == 13){
			jogarPalavraNaFrase(Palavra,Frase);
		}
		else{
			empilha(e, Palavra);
		}
		printf("%c", e);


	}while(e != 13);

	printf("\n");

	mostrarPilha(Frase);

	printf("\n");
    return 0;
}
