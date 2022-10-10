#include <stdio.h>

int prod(int m, int n){
	if(n == 0) return 0;
	else return m + prod(m, n-1);
}

int main(void){
	int m,n, resultado;

	printf("Entre com o primeiro operador:");
	scanf("%d", &m);

	printf("Entre com o segundo operador:");
	scanf("%d", &n);

	resultado = prod(m,n);
	
	printf("%d X %d = %d.\n", m,n,resultado);
	
	return 0;
}
