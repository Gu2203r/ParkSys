#include <stdio.h>
#include <math.h>
int main(){

    int somaserie = 0;
    int i = 0;
    int n = 0;


    do{
        printf("Digite o valor de n: ");
    scanf("%d", &n);
    printf("\n");
    printf("Soma da série: \n");
    for(i = 1; i <= n; i++){
        somaserie += pow(i, 2) + pow(i, 3);
        printf("%d ", somaserie);
    }
    printf("Soma total: %d\n", somaserie);

    }while (n != 0);

}




