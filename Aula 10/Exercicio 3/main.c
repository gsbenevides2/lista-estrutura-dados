﻿#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Chave;
typedef char Valor[22];
typedef struct map {
	Chave chave;
	Valor valor;
	struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
	Map n = malloc(sizeof(struct map));
	n->chave = c;
	strcpy(n->valor,v);
	n->prox = p;
	return n;
}
void insmr(Chave c, Valor v, Map *M){
	if(*M && c>(*M)->chave )
		insmr(c,v,&(*M)->prox);
	else if( *M && c==(*M)->chave )
		strcpy((*M)->valor,v);
	else *M = no_map(c,v,*M);
}

void exibem(Map M){
	printf("[");
	while( M ){
		printf("(%d,%s)",M->chave,M->valor);
		if(M->prox)printf(",");
		M = M->prox;
	}
	printf("]\n");
}
void remm(Chave c, Map *M){
	while(*M && c > (*M)->chave )
		M = &(*M)->prox;
	if( *M==NULL || c!=(*M)->chave ) return;
	Map n = *M;
	*M = n->prox;
	free(n);
}

int main(void){
	Map I = NULL;
	insmr(36,"Leo",&I);
	insmr(15,"Ivo",&I);
	insmr(42,"Eva",&I);
	insmr(29,"Ana",&I);
	exibem(I);
	remm(29,&I);
	exibem(I);
	remm(42,&I);
	exibem(I);
	return 0;
}
