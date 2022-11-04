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

int pertence(int x, Lista L){
	if(L == NULL){
		printf("Erro Fatal: Lista Vazia!!!!\n");
		abort();
	}
	int p = 0;
	while(L != NULL){
		if(L->item == x){
			p = 1;
			break;
		}
		L = L->prox;
	}
}

int main(void) {
	Lista I = no(3,no(1,no(15,no(5,NULL))));
	Lista A = NULL;
	printf("I = "); exibe(I);
	printf("3 pertence a I? %c\n", pertence(3,I) ? 'S' : 'N');
	printf("70 pertence a I? %c\n", pertence(70,I) ? 'S' : 'N');
	printf("A = "); exibe(A);
	printf("70 pertence a A? %c\n", pertence(70,A) ? 'S' : 'N');
	return 0;
}
