

#include <stdio.h>
#include <math.h>

float MediaPonderada(float nota1, float peso1, float nota2, float peso2){
    return (nota1 * peso1 + nota2 * peso2) / (peso1 + peso2);
}

int main(){
    float nota1, peso1, nota2, peso2, media;
    
    system("cls");
    
    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite o peso da primeira nota: ");
    scanf("%f", &peso1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite o peso da segunda nota: ");
    scanf("%f", &peso2);
    
    media = MediaPonderada(nota1, peso1, nota2, peso2);
    
    printf("A media ponderada e: %.2f\n", media);
    
    return 0;
}