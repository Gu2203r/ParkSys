#include <stdio.h>

int main(){

    //Estrutura de dados com o nome dma(dia,mes,ano)

    struct dma{

        int dia;
        int mes;
        int ano;
    };
    struct dma x, y; //x e y são as váriaveis de dma

    x.dia = 17;
    x.mes = 6;
    x.ano = 2025;

    printf("Hoje: %d/%d/%d\n", x.dia, x.mes, x.ano);

    y = x;

    printf("Amanha: %d/%d/%d", y.dia+1, y.mes, y.ano); 
    


    return 0;
}