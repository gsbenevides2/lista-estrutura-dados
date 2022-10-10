#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibe(int v[], int n) {
	for(int i=0; i<n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

void intercala(int v[], int p, int m, int u) {
	int *w = malloc((u-p+1)*sizeof(int));
	int i=p, j=m+1, k=0;
	while( i<=m && j<=u )
		w[k++] = (v[i]<v[j]) ? v[i++] : v[j++];
	while( i<=m ) w[k++] = v[i++];
	while( j<=u ) w[k++] = v[j++];
	for(k=0; k<=u-p; k++) v[p+k] = w[k];
	free(w);
}

void ms(int v[], int p, int u) {
	if( p==u ) return;
	int m = (p+u)/2;
	ms(v,p,m);
	ms(v,m+1,u);
	intercala(v,p,m,u);
}

void msort(int v[], int n) {
	ms(v,0,n-1);
}

void preenche(int v[], int n, int s) {
	srand(s); // definida em stdlib.h
	for(int i=0; i<n; i++) v[i] = rand()%1000;
}

void troca(int v[], int a,int b) {
	int x = v[a];
	v[a] = v[b];
	v[b] = x;
}

void bsort(int arr[], int n){
    for (int i = 0; i < n; i++)
		for(int j=0; j<n-1; j++)
			if(arr[j] > arr[j+1]) troca(arr,j, j+1);
}

int main (void) {
	int *v = malloc(1e8*sizeof(int));
	puts("     n msort");
	for(int n=1e7; n<=1e8; n+=1e7) {
		preenche(v,n,1);
		double t = clock();
		msort(v,n);
		double m = (clock()-t)/CLOCKS_PER_SEC;
		printf("%9d %5.1f\n",n,m);
	}
	return 0;
}
