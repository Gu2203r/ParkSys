#include <stdio.h>
#include <string.h>

int main(){

    char senha1[30];
    char senha2[30];
    
    int resultado;



    do{
    
        printf("Digite a primeira senha\n");
        scanf("%s", senha1);

        printf("Digite a segunda senha\n");
        scanf("%s", senha2);

        resultado = strcmp (senha1, senha2);

        if(resultado == 0){
             printf("Senhas iguais! Acesso permitido.\n");
         }else{
             printf("Tente novamente.\n");
          }

    }while( resultado != 0);


    return 0;


}