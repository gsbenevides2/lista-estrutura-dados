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

int count(int x, Lista L){
	int e;
	if(L->item == x) e = 1;
	else e = 0;

	if(L->prox) return e + count(x,L->prox);
	else return e;
}

int main(void) {
	Lista A = no(1,no(2,no(3,no(4,no(1,no(8,no(1,no(3,no(2,no(1,NULL))))))))));
	
	printf("Lista A: "); exibe(A);
	printf("Quantidade de vezes que 1 aparece em A: %d\n", count(1,A));
	printf("Quantidade de vezes que 20 aparece em A: %d\n", count(20,A));
	return 0;
}
