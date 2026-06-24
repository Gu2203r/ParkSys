#include <stdio.h>
#include <stdlib.h>

int main(){

    system ("cls");

    int numeros[10];
    

    
    for(int i = 0; i < 10; i++){

        printf("Digite os numeros inteiros %d:\n ", i + 1);
        scanf("%d", &numeros[i]);

    }

    if(numeros >= 50){

        printf("A quantidade de numeros maior que 50 e: %d\n" );

    }else if(numeros <= 10){

        printf("A quantidade de numeros menor que 10 e: %d\n" );
    }

return 0;

}