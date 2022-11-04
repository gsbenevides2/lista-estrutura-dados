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

int last(Lista L){
	if(L->prox == NULL) return L->item;
	else last(L->prox);
}

int main(void) {
	Lista A = no(7,no(2,no(5,no(1,NULL))));
	printf("Lista A = "); exibe(A);
	printf("Ultimo elemento de A: %d\n", last(A));
	return 0;
}
