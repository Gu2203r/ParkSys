#include <stdio.h>

int main(){

    int B[10];

    for(int i = 0 ; i < 10 ; i++){

        B[i] = 10 - i;

        printf("%d ", B[i]);

    }

    return 0;
}