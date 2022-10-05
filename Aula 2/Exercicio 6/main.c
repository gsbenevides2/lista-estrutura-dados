#include <stdio.h>
#include "pilha.h"
#include <string.h>

int main(void){
	Pilha P = pilha(5);
	char s[11];
	
	for(int i=1; i<=3; i++){
		printf("? ");
		gets(s);
		char *e = _strdup(s);
		empilha(e,P);
	}
	while( !vaziap(P) ) puts(desempilha(P));
	return 0;
}
