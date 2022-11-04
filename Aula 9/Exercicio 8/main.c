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

void rem_todo(Item x, Lista *L){
	if(*L != NULL && (*L)->item < x )
		rem_todo(x,&(*L)->prox);
	else if( *L == NULL || (*L)->item > x ) return;
	else {
		Lista n = *L;
		*L = n->prox;
		free(n);
	}
}

int main (void){
	Lista I = NULL;
	ins(4, &I);
	ins(1, &I);
	ins(3, &I);
	ins(5, &I);
	ins(2, &I);
	printf("Lista antes da remocao: ");
	exibe(I);
	rem_todo(4, &I);
	printf("Lista apos a remocao recursiva de 4: ");
	exibe(I);
	return 0;
} 
