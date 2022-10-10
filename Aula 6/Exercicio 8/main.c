#include <stdio.h>

void hanoi(int n, char origem, char auxiliar, char destino){
	if (n == 1) {
		printf("mover 1 disco de %c para %c\n", origem, destino);
		return;
	}
	hanoi(n-1, origem, destino, auxiliar);

	printf("mover %d disco de %c para %c\n", n, origem, destino);

	hanoi(n-1, auxiliar, origem, destino);
}

int main(void){
	hanoi(3, 'A', 'B' , 'C');
	return 0;
}
