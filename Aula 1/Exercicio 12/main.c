#include <stdio.h>
void troca(int a, int b){
    int c = a;
    a = b;
    b = c;
}

int main(void){
    int x = 5;
    int y = 3;

    printf("x = %d , y = %d\n",x,y);
    troca(x,y);
    printf("x = %d , y = %d\n",x,y);
    return 0;
}
