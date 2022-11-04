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

int sorted(Lista L){
	if(L->prox == NULL) return 1;
	int next = L->prox->item;
	if(L->item < next) return sorted(L->prox);
	else return 0;
}

int main(void) {
	Lista A = no(1,no(2,no(3,no(4,NULL))));
	Lista B = no(2,no(1,no(6,no(3,NULL))));
	printf("Lista A = "); exibe(A);
	printf("A este ordenado(1-sim 0-nao): %d\n", sorted(A));
	printf("Lista B = "); exibe(B);
	printf("B este ordenado(1-sim 0-nao): %d\n", sorted(B));
	return 0;
}
