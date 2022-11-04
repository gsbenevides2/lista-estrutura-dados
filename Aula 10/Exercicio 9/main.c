#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Chave;
typedef int Valor;
typedef struct map {
	Chave chave;
	Valor valor;
	struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
	Map n = malloc(sizeof(struct map));
	n->chave = c;
	n->valor = v;
	n->prox = p;
	return n;
}
void insmr(Chave c, Valor v, Map *M){
	if(*M && c>(*M)->chave )
		insmr(c,v,&(*M)->prox);
	else if( *M && c==(*M)->chave )
		(*M)->valor = v;
	else *M = no_map(c,v,*M);
}

void exibem(Map M){
	printf("[");
	while( M ){
		printf("(%d,%d)",M->chave,M->valor);
		if(M->prox)printf(",");
		M = M->prox;
	}
	printf("]\n");
}


int main(void){
	Map I = NULL;
	Valor w;
	insmr(36,50,&I);
	insmr(15,40,&I);
	insmr(42,12,&I);
	exibem(I);
	insmr(42,30,&I);
	exibem(I);
	return 0;
}
