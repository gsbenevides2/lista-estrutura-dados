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

int len(Lista L){
	if(L == NULL) return 0;
	else return 1 + len(L->prox);
}

int main(void) {
	Lista A = no(1,no(2,no(3,no(4,NULL))));
	printf("A = "); exibe(A);
	printf("Tamanho de A: %d\n", len(A));
	return 0;
}
