#include <stdio.h>

int pal(char s[], int p, int u){
	char a = s[p];
	char b = s[u];
	char space = ' ';
	if(a == space)a = s[++p];
	if(b == space)b = s[--u];
	if(a != b) return 0;
	else if( p == u || p == u -1) return 1;
	else return pal(s,++p,--u); 
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
	printf("Entre com uma palavra/frase para saber se e palindroma: ");
	gets(&entrada);
	int qtdLetras = count(entrada) -1;
	int ePalindroma = pal(entrada, 0, qtdLetras);
	if(ePalindroma)
		printf("E palindroma!!\n");
	else
		printf("Nao e palindroma!!\n");
	return 0;
}
