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

int equal(Lista A, Lista B){
	if(A->prox == NULL && B->prox == NULL) return 1;
	else if(A->prox == NULL || B->prox == NULL) return 0;
	else if(A->item != B->item) return 0;
	else equal(A->prox, B->prox);
}

int main(void) {
	Lista A = no(1,no(2,no(3,no(4,NULL))));
	Lista B = no(1,no(2,no(3,no(4,NULL))));
	Lista C = no(1,no(2,no(3,NULL)));
	Lista D = no(2,no(1,no(6,no(3,NULL))));
	printf("Lista A = "); exibe(A);
	printf("Lista B = "); exibe(B);
	printf("Lista C = "); exibe(C);
	printf("Lista D = "); exibe(D);
	
	printf("A lista A e igual a B(1-sim 0-nao): %d\n", equal(A,B));
	printf("A lista A e igual a C(1-sim 0-nao): %d\n", equal(A,C));
	printf("A lista A e igual a D(1-sim 0-nao): %d\n", equal(A,D));
	return 0;
}
