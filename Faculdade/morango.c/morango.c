#include <stdio.h>

int main(){

int opcao;

do{

    printf("------------------------------\n");
    printf("BEM-VINDO AO JOGO DE ESCOLHA\n");
    printf("------------------------------\n");
    printf("1. Se seu animal favorito for gatinhos\n");
    printf("2. Se seu animal favorito for cachorrinhos\n");
    printf("3. Se seu animal favorito for coelhinhos\n");
    printf("4. Se seu animal favorito for lontrinhas\n");
    printf("5. Se não gostar de animais\n");
    printf("Escolha uma opcao:\n");
    scanf("%d", &opcao); 

    switch (opcao){

        case 1:
        
            printf("Você escolheu gatinhos!\n");
            printf("Você é uma pessoa carinhosa e sensível.\n");
            break; 
        
        
       case 2:

           printf("Você escolheu cachorrinhos!\n");
           printf("Você é uma pessoa leal.");
           break;
       
           
    
       case 3:
       
        printf("Você escolheu coelhinhos!\n");
        printf("Você é uma pessoa fofa e meiga.");
        break;
    
       
            
    
       case 4:
       
        printf("Você escolheu lontrinhas!\n");
        printf("Você é uma pessoa energica e feliz.");
        break;
       
           
    
       case 5:
       
        printf("Você não gosta de animais? Você deve ser uma pessoa fria e calculista...\n");
            break;
       
            
    
       default:
       printf("Opcão inválida! Tente novamente.");
    
    
    }
    
    

}while(opcao != 5);

return 0;

}
