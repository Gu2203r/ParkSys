


#include <stdio.h>
#include <math.h>

float PesToPolegadas(float pes){
    return pes * 12;
}
float JardaToPes(float jarda){
    return jarda * 3;
}

int main(){
    float pes, polegadas, jarda, milha, metros;
    
    system("cls");
    
    printf("Digite a medida em pes: ");
    scanf("%f", &pes);
    
    polegadas = PesToPolegadas(pes);
    jarda = JardaToPes(pes);
    milha = jarda / 1760;
    metros = milha * 16093;
    
    printf("A medida em polegadas e: %.2f\n", polegadas);
    printf("A medida em jardas e: %.2f\n", jarda);
    printf("A medida em milhas e: %.2f\n", milha);
    printf("A medida em metros e: %.2f\n", metros);
    
    return 0;
}

