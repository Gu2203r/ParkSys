#include <stdio.h>
#include "geometria.c"


int main(){

    int opcao;
    float raio, altura, base, lado1, lado2, lado3;


    do
    {
        printf("---Calculador de Areas e perimetros---\n");
        printf("1.Calcular area do circulo\n");
        printf("2.Calcular area do triangulo\n");
        printf("3.Calcular area do retangulo\n");
        printf("4.Calcular perimetro do circulo\n");
        printf("5.Calcular perimetro do triangulo\n");
        printf("6.Calcular perimetro do retangulo\n");
        printf("7.Sair\n");
        printf("Escolha uma opcao:\n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:

            calcularAreaCirculo(raio);

            printf("Area do circulo: %.2f\n", calcularAreaCirculo);

            break;
        case 2:
             calcularAreaTriangulo(base, altura);

             printf("Area do triangulo: %.2f\n", calcularAreaTriangulo);
           
            break;
        case 3:
        
             calcularAreaRetangulo(base,altura);

             printf("Area do retangulo: %.2f\n", calcularAreaRetangulo);

            break;
        case 4:
        
            calcularPerimetroCirculo(raio);

            printf("O perimetro do circulo: %.2f\n", calcularPerimetroCirculo);

            break;
        case 5:
        
            calcularPerimetroTriangulo(lado1, lado2, lado3);

            printf("O perimetro do triangulo: %.2f\n");

            break;
        case 6:
           
            calcularPerimetroRetangulo(base, altura);

            printf("O perimetro do retangulo: %.2f\n");

            break;


        default:

            printf("Opcao inexistente! Tente novamente\n");

            break;
        }

        if(opcao == 7){
            printf("Saindo do programa. Ate a proxima!\n");
        }

    } while (opcao != 7);
    

   
return 0;

}

