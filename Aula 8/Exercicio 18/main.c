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

int in(int x, Lista L){
	if(L->prox == NULL) return 0;
	else if(L->item == x) return 1;
	else in(x,L->prox);
}

int main(void) {
	Lista A = no(7,no(2,no(5,no(1,NULL))));
	printf("Lista A = "); exibe(A);
	printf("O item 5 pertence a lista(1-sim 0-nao): %d\n", in(5,A));
	printf("O item 6 pertence a lista(1-sim 0-nao): %d\n", in(6,A));
	return 0;
}
