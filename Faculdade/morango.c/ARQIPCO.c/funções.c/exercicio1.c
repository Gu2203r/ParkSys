#include <stdio.h>

int menor(int num1, int num2, int num3){
    int menor = num1;
    if(num2 < menor) menor = num2;
    if(num3 < menor) menor = num3;
    return(menor);
}



int main(){

    int num1; int num2; int num3;

    printf("Digite o num1:\n");
    scanf("%d", &num1);
    printf("Digite o num2:\n");
    scanf("%d", &num2);
    printf("Digite o num3:\n");
    scanf("%d", &num3);

    printf("O menor valor = %d", menor (num1, num2, num3));
    return 0;

}
