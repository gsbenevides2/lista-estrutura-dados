#include <stdio.h>

int q(int n){
	if(n == 0) return 0;
	else return q(n-1) + 2 * n - 1;
}

int main(void){
	int n;
	printf("Entre com um numero natural: ");
	scanf("%d",&n);
	printf("%d\n", q(n));
	return 0;
}