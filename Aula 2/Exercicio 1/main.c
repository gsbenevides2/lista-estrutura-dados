#include <stdio.h>
#include "pilha.h"

void mostrarPilha(Pilha p){
	while(vaziap(p) == 0)
		printf(" %d ", desempilha(p));
}

int main(void){
  	int qtdDeElementosNaPilha, t, entrada;

    printf("Qual o tamanho da pilha de numeros ordenados(maximo:indefinido e inteiros)? ");
    scanf("%d",&qtdDeElementosNaPilha);

    Pilha A = pilha(qtdDeElementosNaPilha*sizeof(int));
    Pilha B = pilha(qtdDeElementosNaPilha*sizeof(int));
    
    for(int i =1; i<=qtdDeElementosNaPilha; i++){
        printf("%do numero(inteiro)? ", i);
        scanf("%d", &entrada);
        empilha(entrada, B);
    }
   
    empilha(desempilha(B),A);
    for(int i = 1; i < (qtdDeElementosNaPilha * qtdDeElementosNaPilha); i++){
		if(vaziap(B)){
        	while(vaziap(A) == 0){
          		empilha(desempilha(A),B);
        	}
        	empilha(desempilha(B),A);
      	}
		else if(topo(B) < topo(A))
        	empilha(desempilha(B),A);
      	else{
        	t = desempilha(A);
        	empilha(desempilha(B),A);
        	empilha(t, A);
      	}
    }

    printf("Mostrando Pilha! \n");
    mostrarPilha(A);
    printf("\n");
  
    return 0;
}
