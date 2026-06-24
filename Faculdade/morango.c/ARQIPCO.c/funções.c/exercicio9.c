

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calcularDosagemAdulto(float peso){
    if (peso >= 60){
        return 1000; // 1000 mg
    } else {
        return 875; // 875 mg
    }
}
float calcularDosagemCrianca(float peso){
    if (peso >= 5 && peso <= 9){
        return 125; // 125 mg
    } else if (peso > 9 && peso <= 16){
        return 250; // 250 mg
    } else if (peso > 16 && peso <= 24){
        return 375; // 375 mg
    } else if (peso > 24 && peso <= 30){
        return 500; // 500 mg
    } else {
        return 750; // acima de 30kg
    }
}

int main(){
    int idade;
    float peso, dosagem, gotasPorDose;
    
    system("cls");
    
    printf("Digite a idade do paciente: ");
    scanf("%d", &idade);
    printf("Digite o peso do paciente (em kg): ");
    scanf("%f", &peso);
    
    if (idade >= 12){
        dosagem = calcularDosagemAdulto(peso);
    } else {
        dosagem = calcularDosagemCrianca(peso);
    }
    
    gotasPorDose = (dosagem / 500) * 20; // 500 mg por ml e 20 gotas por ml
    
    printf("A dosagem do medicamento e: %.2f mg\n", dosagem);
    printf("O paciente deve tomar %.2f gotas por dose.\n", gotasPorDose);
    
    return 0;
}

