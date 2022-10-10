#include <stdio.h>

void inv(char s[], int p, int u){
	if(p == u) return;
	char a = s[p];
	char b = s[u];
	s[p] = b;
	s[u] = a;
	if(p != u-1) inv(s, p+1, u-1);
}

int count(char s[]){
	int i;
	for(i = 0; s[i]; i++);
	return i;
}

void exibe(char s[], int lenght){
	for(int i =0; i<lenght; i++)
		printf("%c",s[i]);
	printf("\n");
}

int main(void){
	char entrada[256];
	printf("Entre com uma palavra para inverter: ");
	gets(&entrada);
	int qtdLetras = count(entrada);
	inv(entrada, 0, qtdLetras - 1);
	exibe(entrada, qtdLetras);
	return 0;
}
