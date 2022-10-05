#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *posfixa(char *e) {
	static char s[256];
	int j = 0;
	Pilha P1 = pilha(256);
	Pilha P2 = pilha(256);

	for(int i=0; e[i]; i++)
		if(strchr("!&|",e[i])) empilha(e[i],P2);
		else if(strchr("FV",e[i])) empilha(e[i],P1);
		else if(e[i] == ')') empilha(desempilha(P2),P1);

	while(!vaziap(P1))
		empilha(desempilha(P1),P2);

	while(!vaziap(P2))
		s[j++] = desempilha(P2);
		
	s[j] = '\0';
	destroip(&P1);
	destroip(&P2);
	return s;
}

int valor(char *e){
	Pilha P = pilha(256);
	for(int i=0; e[i]; i++)
		if(strchr("FV", e[i])) empilha(e[i],P);
		else if(e[i] == '!') {
			char op = desempilha(P);
			if(op == 'F') empilha('V', P);
			else empilha('F',P);
		} else if(e[i] == '&'){
			char op1 = desempilha(P);
			char op2 = desempilha(P);
			if(op1 == 'V' && op2 == 'V') empilha('V',P);
			else empilha('F',P);
		} else{
			char op1 = desempilha(P);
			char op2 = desempilha(P);
			if(op1 == 'V' || op2 == 'V') empilha('V',P);
			else empilha('F',P);
		}

	char r = desempilha(P);
	destroip(&P);
	return r == 'V';
}

int main(void){
	char e[513];
	printf("Infixa? ");
	gets(e);
	printf("Posfixa: %s\n", posfixa(e));
	printf("Valor: %d\n", valor(posfixa(e)));
	return 0;
}
