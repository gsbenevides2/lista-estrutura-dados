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

Lista clone(Lista L){
	if(L == NULL) return NULL;
	else return no(L->item, clone(L->prox));
}

int main(void) {
	Lista A = no(1,no(2,no(3,no(4,NULL))));
	Lista B = clone(A);
	printf("Lista A = "); exibe(A);
	printf("LIsta B que e clone de A = "); exibe(B);
	return 0;
}
