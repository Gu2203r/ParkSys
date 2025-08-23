#include <stdio.h>
#include <stdlib.h>


int ehBissexto(int anobissexto){

    if((anobissexto % 4) == 0){
        
        if ((anobissexto % 100) == 0)
        {
            if ((anobissexto % 400) == 0)
            {
                return 1;
            }else{
                return 0;
            }
            
        } else{
            return 1;
        }
        
    }else{
     
     return 0;
    }    
     

}

int main(){
    int anobissexto;
    int opcao;

    system("cls");

    do{
    

    printf("Bem-vindo ao identificador de ano bissexto!\n");
    printf("Digite um ano para verificar se e bissexto:\n");
    scanf("%d", &anobissexto);

    if(ehBissexto(anobissexto) == 1){
        printf("e um ano bissexto\n");

    } else if(ehBissexto(anobissexto) == 0){
        printf("nao e bissexto\n");
    }

    printf("Digite 1 para continuar e 0 para sair\n");
    scanf("%d", &opcao);

    if(opcao == 0){
        printf("Saindo do programa...Ate a proxima!\n");
    }

    }while(opcao != 0);

    return 0;
}