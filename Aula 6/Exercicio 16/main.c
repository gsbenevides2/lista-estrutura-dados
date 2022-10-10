#include <stdio.h>

int hanoi(int n, char origem, char auxiliar, char destino)
{
	int m = 1;
	if (n == 1)
	{
		printf("mover 1 disco de %c para %c\n", origem, destino);
		return m;
	}
	m += hanoi(n - 1, origem, destino, auxiliar);

	printf("mover %d disco de %c para %c\n", n, origem, destino);

	m += hanoi(n - 1, auxiliar, origem, destino);
	return m;
}

int main(void)
{
	int m = hanoi(3, 'A', 'B', 'C');
	printf("Total de movimentos: %d\n", m);
	return 0;
}
