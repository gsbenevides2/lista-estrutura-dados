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

void anexa(Lista *A, Lista B){
	if(!B)return;
	while(*A) A = &(*A)->prox;
	*A =B;
}

int main(void) {
	Lista H = no(4,no(2,NULL));
	Lista I = no(3,no(1,no(5,NULL)));
	printf("H = "); exibe(H);
	printf("I = "); exibe(I);
	printf("Pressione enter");
	getchar();
	anexa(&H, I);
	printf("H = "); exibe(H);
	printf("I = "); exibe(I);
	return 0;
}
