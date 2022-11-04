#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

Lista rnd(int n, int m){
	int numeroAleatorio = rand()%m;
	if(n == 1) return no(numeroAleatorio,NULL);
	return no(numeroAleatorio, rnd(n-1,m));
}

int main(void) {
	srand(time(NULL));
	Lista A = rnd(8,43);
	Lista B = rnd(5,8);
	printf("Lista A = "); exibe(A);
	printf("Lista B = "); exibe(B);
	return 0;
}
