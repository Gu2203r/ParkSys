#include <stdio.h>
#include <math.h>

int main(){


    int multiplicacao = 0;
    int n = 0;
    int i = 0;
    int resultado = 0;

    
    do {    
        printf("Digite um número inteiro positivo: ");
        scanf("%d", &n);
        if (n < 0) {
            printf("Número inválido. Por favor, insira um número inteiro positivo.\n");
            return 1;
        }
        printf("A tabuada do número %d é:\n", n);
        for (i = 0; i <= 10; i++) {
            resultado = n * i;
            printf("%d x %d = %d\n", n, i, resultado);
        }
    } while (multiplicacao == 0);
    

}