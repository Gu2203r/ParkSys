#include <stdio.h>

int maiorMultiplo(int inteiro, int maior){
    if(maior % inteiro == 0) return maior;
    else return maiorMultiplo(inteiro, maior - 1);
}
    

int main(){
    int inteiro, maior;

    system("cls");
    
    printf("Digite um numero inteiro: ");
    scanf("%d", &inteiro);
    printf("Digite o maior numero: ");
    scanf("%d", &maior);
    printf("O maior multiplo de %d menor que %d e: %d\n", inteiro, maior, maiorMultiplo(inteiro, maior));


    return 0;
}
    