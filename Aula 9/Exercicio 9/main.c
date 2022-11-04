#include <stdio.h>
#include <stdlib.h>

typedef int Item;
typedef struct no {
	Item item;
	struct no *prox;
} *Lista;

Lista no(Item x, Lista p){
	Lista n = malloc(sizeof(struct no));
	n->item = x;
	n->prox = p;
	return n;
}

void ins(Item x, Lista *L){
	while( *L != NULL && (*L)->item < x)
		L = &(*L)->prox;
	*L = no(x, *L);
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

int pert(Item x, Lista L){
	while(L!=NULL && L->item < x )
		L = L->prox;
	return (L != NULL && L->item == x);
}

int main (void){
	Lista I = NULL;
	ins(4, &I);
	ins(1, &I);
	ins(3, &I);
	ins(5, &I);
	ins(2, &I);
	printf("Lista I: ");
	exibe(I);
	printf("O item 6 pertence a lista I (1-SIM 0-NAO) %d\n",pert(6,I));
	printf("O item 3 pertence a lista I (1-SIM 0-NAO) %d\n",pert(3,I));
	return 0;
} 
