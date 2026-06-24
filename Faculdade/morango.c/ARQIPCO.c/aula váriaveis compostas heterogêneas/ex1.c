#include <stdio.h>

//

typedef struct {

    int dia;
    int mes;
    int ano;
    
}Data;

int verificarData(Data x);



int main(){

     Data data;

     printf("Insira o dia:\n");
     scanf("%d", &data.dia);
     printf("Insira o mes:\n");
     scanf("%d", &data.mes);
     printf("Insira o ano:");
     scanf("%d", &data.ano);

     if(verificarData(data)){
        printf("Data com com mes valido\n");
     }else{
        printf("Data com mes inválido!\n");
     }
    
    


    return 0;
}

int verificarData(Data x){

    int valido = 1;

    if((x.mes < 1)||(x.mes > 12)) valido = 0;

    return(valido);

}