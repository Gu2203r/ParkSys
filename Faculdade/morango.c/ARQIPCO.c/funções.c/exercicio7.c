

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ePerfeito(int numero){
    int soma = 0;
    for (int i = 1; i < numero; i++){
        if (numero % i == 0){
            soma += i;
        }
    }
    return soma == numero;
}
int main(){
    int contador = 0;
    int numero = 1;
    
    system("cls");
    
    printf("Os 4 primeiros numeros perfeitos sao:\n");
    
    while (contador < 4){
        if (ePerfeito(numero)){
            printf("%d\n", numero);
            contador++;
        }
        numero++;
    }
    
    return 0;
}