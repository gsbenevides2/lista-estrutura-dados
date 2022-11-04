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
	while( *L != NULL && (*L)->item > x)
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

int osd(Lista L){
	if(L!=NULL && L->prox && L->item >= L->prox->item )
		return osd(L->prox);
	else if(L!=NULL && L->prox) return 0;
	else return 1;
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
	printf("A lista I esta ordenada simplesmente decrescente(1-SIM 0-NAO) %d\n",osd(I));
	printf("Incluindo um no 5 de forma forcada\n");
	I = no(5,I);
	printf("Lista I: ");
	exibe(I);
	printf("A lista I esta ordenada simplesmente decrescente(1-SIM 0-NAO) %d\n",osd(I));
	printf("Incluindo um no 1 de forma forcada\n");
	I = no(1,I);
	printf("Lista I: ");
	exibe(I);
	printf("A lista I esta ordenada simplesmente decrescente(1-SIM 0-NAO) %d\n",osd(I));
	return 0;
} 
