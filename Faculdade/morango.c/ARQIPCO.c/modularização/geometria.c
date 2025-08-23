#include "funcao.h"

float calcularAreaCirculo(float raio){

    float pi = 3.14;

    printf("Digite o raio do circulo:\n");
    scanf("%f",&raio);

    return pi * pow(raio,2);

}

float calcularPerimetroCirculo(float raio){

    float pi = 3.14;

    printf("Digite o raio do circulo:\n");
    scanf("%f",&raio);

    return 2 * pi * raio;



}

float calcularAreaTriangulo(float base, float altura){

    printf("Digite a area e a altura do triangulo:\n");
    scanf("%f",&base,&altura);

    return (base * altura) / 2;

}

float calcularPerimetroTriangulo(float lado1, float lado2, float lado3){

    printf("Digite os tres lados do triangulo:\n");
    scanf("%f",&lado1,&lado2,&lado3);

    return lado1 + lado2 + lado3;

}

float calcularAreaRetangulo(float base, float altura){

    printf("Digite a base e a altura do retangulo:\n");
    scanf("%f",&base,&altura);

    return base * altura;

}

float calcularPerimetroRetangulo(float base, float altura){

    printf("Digite a base e a altura do retangulo\n");
    scanf("%f",&base,&altura);


    return 2 * (base + altura);

}
 