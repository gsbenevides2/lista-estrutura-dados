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

int pert_rec(Item x, Lista L){
	if(L!=NULL && L->item < x )
		return pert_rec(x,L->prox);
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
	printf("O item 7 pertence (recursivo) a lista I (1-SIM 0-NAO) %d\n",pert_rec(7,I));
	printf("O item 2 pertence (recursivo) a lista I (1-SIM 0-NAO) %d\n",pert_rec(2,I));
	return 0;
} 
