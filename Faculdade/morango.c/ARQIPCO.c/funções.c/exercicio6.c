

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ePrimo(int numero){
    if (numero <= 1) return 0;
    for (int i = 2; i <= sqrt(numero); i++){
        if (numero % i == 0) return 0; 
    }
    return 1; 
}

int main(){
    int numero;
    
    system("cls");
    
    printf("Digite um numero: ");
    scanf("%d", &numero);
    
    if (ePrimo(numero)){
        printf("%d e um numero primo.\n", numero);
    } else {
        printf("%d nao e um numero primo.\n", numero);
    }
    
    return 0;
}