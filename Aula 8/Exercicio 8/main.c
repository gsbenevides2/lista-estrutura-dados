#include <stdio.h>
#include <stdlib.h>

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

int ultimo(Lista L){
	if(L == NULL){
		printf("Erro Fatal: Lista Vazia!!!!\n");
		abort();
	}
	int lastDance = 0;
	while(L != NULL){
		lastDance = L->item;
		L = L->prox;
	}
	return lastDance;
}

int main(void) {
	Lista I = no(3,no(1,no(5,NULL)));
	Lista A = NULL;
	printf("I = "); exibe(I);
	printf("Ultimo Item = %d\n", ultimo(I));
	printf("A = "); exibe(A);
	printf("Ultimo Item = %d\n", ultimo(A));
	return 0;
}
