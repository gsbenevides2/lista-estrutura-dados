#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef int Item;
typedef struct no {
	Item item;
	struct no *prox;
} *Lista;

Lista no (Item x, Lista p) {
	Lista n = malloc(sizeof(struct no));
	n->item = x;
	n->prox = p;
	return n;
}

void exibe(Lista L) {
	printf("[");
	while( L != NULL ){
		printf("%d", L->item);
		L = L->prox;
		if( L != NULL ) printf(","); 
	}
	printf("]\n");
}

int tamanho(Lista L){
	int t = 0;
	while(L){
		t++;
		L=L->prox;
	}
	return t;
}

Lista intervalo(int p, int u){
	int a = u;
	Lista L = NULL;
	while(a >= p){
		L = no(a,L);
		a--;
	}
	return L;
}


int main(void) {
	Lista A = intervalo(-2,3);
	//printf("I = "); exibe(I);
	printf("A = "); exibe(A);
	return 0;
}
