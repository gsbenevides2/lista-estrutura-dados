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

int minimum(Lista L){
	int min = L->item;
	int other;
	if(L->prox != NULL) other = minimum(L->prox);
	else return min;
	
	if(min < other) return min;
	return other;
}

int main(void) {
	Lista A = no(7,no(2,no(1,no(5,NULL))));
	printf("Lista A = "); exibe(A);
	printf("O menor valor de A: %d\n", minimum(A));
	return 0;
}
