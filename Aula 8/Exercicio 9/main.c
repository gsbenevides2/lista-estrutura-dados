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

int maximo(Lista L){
	if(L == NULL){
		printf("Erro Fatal: Lista Vazia!!!!\n");
		abort();
	}
	int max = L->item;
	L = L->prox;
	while(L != NULL){
		if(max < L->item) max = L->item;
		L = L->prox;
	}
	return max;
}

int main(void) {
	Lista I = no(3,no(1,no(15,no(5,NULL))));
	Lista A = NULL;
	printf("I = "); exibe(I);
	printf("Item Maximo = %d\n", maximo(I));
	printf("A = "); exibe(A);
	printf("Item Maximo = %d\n", maximo(A));
	return 0;
}
