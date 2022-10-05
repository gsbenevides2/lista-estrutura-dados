#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "pilha.h"

char *prefixa(char *e){
	static char s[256];
	int j = 0;
	char a;

	Pilha P1 = pilha(256);
	Pilha P2 = pilha(256);
	
	for (int i=strlen(e); i >= 0; i--){
		a = e[i];
		if(isdigit(a)) empilha(a,P1);
		else if(strchr("+-*/",a)) empilha(a,P2);
		else if(a == '(')empilha(desempilha(P2),P1);
	}
	while( !vaziap(P1) )
		s[j++] = desempilha(P1);
	s[j]= '\0';
	destroip(&P1);
	destroip(&P2);
	return s;
}

int valpre(char *e){
	int qtdNumeros = 0;
	Pilha P = pilha(255);
	char * inver = _strrev(e);
	for(int i = 0; inver[i]; i++){
		if (strchr("+-*/",inver[i])){
			int x = desempilha(P) - '0';
			int y = desempilha(P) - '0';
			int r;
			switch(inver[i]){
				case '+': r = x+y; break;
				case '-': r = x-y; break;
				case '*': r = x*y; break;
				case '/': r = x/y; break;
			}
			empilha(r + '0',P);
		}else empilha(inver[i],P);
	}
	int a = desempilha(P) - '0';
	destroip(&P);
	return a;

}

int main(void){
	char e[513];
	printf("Infixa? ");
	gets(e);
	printf("Prefixa: %s\n", prefixa(e));
	printf("Valor: %d\n",valpre(prefixa(e)));
	return 0;
}
