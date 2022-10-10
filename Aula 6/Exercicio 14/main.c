#include <stdio.h>
#include <stdlib.h>

int sd(int m){
	if(m < 10) return m;
	int lastDigit = m % 10;
	return lastDigit + sd(m/10);
}

int main(void){
	int m;

	printf("Entre com um numero inteiro:");
	scanf("%d", &m);
	
	printf("A soma dos digitos de %d e %d.\n", m,sd(m));
	
	return 0;
}
