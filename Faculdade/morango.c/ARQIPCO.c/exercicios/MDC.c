#include <stdio.h>
int main(){

    int mdc = 0;
    int a = 0;
    int b = 0;
    int resto = 0;
   
    printf("Digite dois numeros inteiros positivos: ");
    scanf("%d %d", &a, &b);

    if (a <= 0 || b <= 0) {
        printf("Por favor, insira dois numeros inteiros positivos.\n");
    
    }else {
        while (b != 0) {
            resto = a % b; 
            a = b; 
            b = resto; 
        }
        mdc = a; 
        printf("O MDC e: %d\n", mdc);
    }
    
    printf("Fim do programa.\n");
    return 0;
}   