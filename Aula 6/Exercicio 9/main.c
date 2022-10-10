#include <stdio.h>

int par(int n){
	if(n >= 2) return par(n - 2);
	else if(n == 0) return 1;
	else return 0;
}

int main(void){
	int numero;
	int ePar;

	printf("Entre com um numero:");
	scanf("%d", &numero);

	ePar = par(numero);

	if(ePar)
		printf("%d e par.", numero);
	else
		printf("%d nao e par.", numero);

	return 0;
}
