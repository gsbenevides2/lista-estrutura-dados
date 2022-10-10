#include <stdio.h>
#include <stdlib.h>

int resto(int m, int n){
	if(n == 0){
		printf("Impossivel dividir por zero!!!");
		abort();
	}
	else if(m < n) return m;

	return resto(m - n, n);
}

int main(void){
	int m,n, resultado;

	printf("Entre com o primeiro operador:");
	scanf("%d", &m);

	printf("Entre com o segundo operador:");
	scanf("%d", &n);

	resultado = resto(m,n);
	
	printf("%d %% %d = %d.\n", m,n,resultado);
	
	return 0;
}
