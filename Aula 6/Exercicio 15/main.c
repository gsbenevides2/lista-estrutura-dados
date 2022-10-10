#include <stdio.h>

int qd(int n){
	if(n < 2) return + 1; 
	return 1 + qd(n / 2);
}

int main(void){
	int m;

	printf("Entre com um numero inteiro: ");
	scanf("%d", &m);
	
	printf("A soma dos digitos de %d em binario e: %d.\n", m,qd(m));
	
	return 0;
}
