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

void ins_rsr(Item x, Lista *L){
	if( *L != NULL && (*L)->item < x) 
		ins_rsr(x, &(*L)->prox);
	else if(*L == NULL || (*L)->item != x) 
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

int main (void){
	Lista I = NULL;
	printf("Insercao recursiva e sem repeticao\n");
	ins_rsr(4, &I);
	ins_rsr(1, &I);
	ins_rsr(3, &I);
	ins_rsr(5, &I);
	ins_rsr(2, &I);
	ins_rsr(4, &I);
	exibe(I);
	return 0;
} 
