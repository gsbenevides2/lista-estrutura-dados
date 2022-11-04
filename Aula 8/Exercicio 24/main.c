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

void replace(int x, int y, Lista L){
	if(L->item == x) L->item = y;
	if(L->prox) replace(x,y,L->prox);
}

int main(void) {
	Lista A = no(1,no(2,no(3,no(4,no(1,no(8,no(1,no(3,no(2,no(1,NULL))))))))));
	
	printf("Lista A: "); exibe(A);
	replace(1,70,A);
	printf("Todos os numeros 1 em A foram substituidos por 70.\n");
	printf("Lista A: "); exibe(A);
	return 0;
}
