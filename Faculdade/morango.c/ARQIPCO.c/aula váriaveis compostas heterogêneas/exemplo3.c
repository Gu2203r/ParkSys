#include <stdio.h>

//

typedef struct {

    int dia;
    int mes;
    int ano;
    
}Data;

int main(){

     Data x, y; //
    

    x.dia = 17;
    x.mes = 6;
    x.ano = 2025;

    printf("Hoje: %d/%d/%d\n", x.dia, x.mes, x.ano);

    y = x;

    printf("Amanha: %d/%d/%d", y.dia+1, y.mes, y.ano);
    


    return 0;
}