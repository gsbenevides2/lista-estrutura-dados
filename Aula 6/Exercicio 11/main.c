#include <stdio.h>
#include <stdlib.h>

int quoc(int m, int n){
	if(n == 0){
		printf("Impossivel dividir por zero!!!");
		abort();
	}
	else if(m == n) return 1;
	else if (m < n) return 0;

	return 1 +  quoc(m - n, n);
}

int main(void){
	int m,n, resultado;

	printf("Entre com o primeiro operador:");
	scanf("%d", &m);

	printf("Entre com o segundo operador:");
	scanf("%d", &n);

	resultado = quoc(m,n);
	
	printf("%d / %d = %d.\n", m,n,resultado);
	
	return 0;
}
