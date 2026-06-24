#include <stdio.h>
#include <math.h>

int main (){
    int n = 0;
    int fatorial = 1;
    int i = 0;
    int resultado = 0;

    do{

        printf("Digite o valor de n: ");
        scanf("%d", &n);
        printf("\n");
        printf("Fatorial: \n");
        for(i = 1; i <= n; i++){
            fatorial *= i;
            printf("%d ", fatorial);
        }
        printf("\n\nFatorial total: %d\n", fatorial);
        printf("Resultado: %d\n", fatorial);
        resultado = fatorial;
        fatorial = 1; // Reset fatorial for next iteration
        printf("Resultado: %d\n", resultado);
        


    }while (n != 0);

    return 0;
}


