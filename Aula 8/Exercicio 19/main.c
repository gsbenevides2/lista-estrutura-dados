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

int nth(int x, Lista L){
	if(L == NULL){
		printf("Posicao invalida!!!");
		abort();
	}
	else if(x-1 == 0) return L->item;
	else nth(x-1,L->prox);

}

int main(void) {
	Lista A = no(7,no(2,no(5,no(1,NULL))));
	printf("Lista A = "); exibe(A);
	printf("O item segunda posicao e: %d\n", nth(2,A));
	printf("O item quarta posicao e: %d\n", nth(4,A));
	printf("Tentando exibir o item inexistente da quinta posicao:\n");
	nth(5,A);
	return 0;
}
