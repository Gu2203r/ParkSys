#include <stdio.h>
#include <math.h>

int main (){
    int n = 0;
    int i = 0;
    int fib1 = 0;
    int fib2 = 1; 
    int resultado = 0;

    do{
        printf("Digite o valor de n: ");
        scanf("%d", &n);
        printf("\n");
        printf("Sequência de Fibonacci: \n");
        for(i = 0; i < n; i++){
            printf("%d ", fib1);
            resultado = fib1 + fib2;
            fib1 = fib2;
            fib2 = resultado;
        }
        printf("\n\nResultado: %d\n", resultado);
        
    }while (n != 0);

    return 0;
}