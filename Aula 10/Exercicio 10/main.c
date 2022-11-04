#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Chave[22];
typedef char Valor[22];
typedef struct map {
	Chave chave;
	Valor valor;
	struct map *prox;
} *Map;

Map no_map(Chave c, Valor v, Map p) {
	Map n = malloc(sizeof(struct map));
	strcpy(n->chave,c);
	strcpy(n->valor,v);
	n->prox = p;
	return n;
}
void insmr(Chave c, Valor v, Map *M){
	if(*M &&  strcmp(c,(*M)->chave) == 1 )
		insmr(c,v,&(*M)->prox);
	else if( *M && strcmp(c,(*M)->chave) == 0 )
		strcpy((*M)->valor,v);
	else *M = no_map(c,v,*M);
}

void exibem(Map M){
	printf("[");
	while( M ){
		printf("(%s,%s)",M->chave,M->valor);
		if(M->prox)printf(",");
		M = M->prox;
	}
	printf("]\n");
}


int main(void){
	Map I = NULL;
	Valor w;
	insmr("A","Ana Julia",&I);
	insmr("C","Carolina",&I);
	insmr("B","Beatriz",&I);
	exibem(I);
	insmr("C","Carmem",&I);
	exibem(I);
	return 0;
}
