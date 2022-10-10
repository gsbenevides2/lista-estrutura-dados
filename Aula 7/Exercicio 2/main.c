#include <stdio.h>

void exibe(int v[], int n) {
	for(int i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void troca(int v[], int a,int b) {
	int x = v[a];
	v[a] = v[b];
	v[b] = x;
}

int maximo(int v[], int p){
	if(p == 0) return 0;
	int m;
	int x = v[p];
	int y = v[p-1];
	if(x>y) m = p;
	int m2 = maximo(v,p-1);
	if(v[m] > v[m2]) return m;
	else return m2; 
}

void empurra(int v[], int u){
	int m = maximo(v,u);
	troca(v,m,u);
}

int main (void) {
	int v[] = {51,82,38,99,75,19,69,46,27};
	empurra(v,8);
	exibe(v,9);
	return 0;
}
