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

int tamanho(Lista L){
	int t = 0;
	while(L){
		t++;
		L=L->prox;
	}
	return t;
}

// Falta terminar
Lista inversa(Lista L){
	Lista I = NULL;
	while(L){
		I = no(L->item, I);
		L = L->prox;
	}
	return I;
	
}

int main(void) {
	Lista I = no(3,no(1,no(15,no(5,NULL))));
	Lista A = inversa(I);
	printf("I = "); exibe(I);
	printf("A = "); exibe(A);
	return 0;
}
