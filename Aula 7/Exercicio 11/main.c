#include <stdio.h>

int rlsearch(int x, int v[],  int u){
	if(x == v[p]) return 1;
	if(u == 0) return 0;
	return rlsearch(x,v,u-1);

}

int main(void){
	int v[8] = {19,27,31,48,52,66,75,80};
	printf("27: %d\n", rlsearch(27,v,0,8));
	printf("51: %d\n", rlsearch(51,v,0,8));
	return 0;
}