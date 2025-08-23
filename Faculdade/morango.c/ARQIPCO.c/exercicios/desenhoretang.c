#include <stdio.h>
#include <math.h>

int main (){
    int larguraL = 0;
    int alturaH = 0;
    int i = 0;

    printf("Digite a largura do retangulo: ");
    scanf("%d", &larguraL);
    printf("Digite a altura do retangulo: ");
    scanf("%d", &alturaH);
    printf("\n\nDesenhando o retangulo:\n\n");

    for(i = 0; i < alturaH; i++){
        int j = 0;
        for(j = 0; j < larguraL; j++){
            if(j == 0 || j == larguraL - 1 || i == alturaH - 1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
return 0;

}