#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char p1 ;
char p2 ;
char p3 ;
char p4 ;
char p5 ;
char p6 ;
char p7 ;
char p8 ;
char p9 ;



void exibirJogo(){
          
    printf("\n %c | %c | %c\n", p1, p2, p3);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", p4, p5, p6);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n\n", p7, p8, p9);

}

void jogar(char jogador, int posicao) {
    switch(posicao) {
        case 1: if(p1 == ' ') p1 = jogador; break;
        case 2: if(p2 == ' ') p2 = jogador; break;
        case 3: if(p3 == ' ') p3 = jogador; break;
        case 4: if(p4 == ' ') p4 = jogador; break;
        case 5: if(p5 == ' ') p5 = jogador; break;
        case 6: if(p6 == ' ') p6 = jogador; break;
        case 7: if(p7 == ' ') p7 = jogador; break;
        case 8: if(p8 == ' ') p8 = jogador; break;
        case 9: if(p9 == ' ') p9 = jogador; break;
        default: printf("Posição inválida!\n"); break;
    }
}



int verificarVitoria() {
    // Verifica as linhas
    if ((p1 == p2 && p2 == p3 && p1 != ' ') || 
        (p4 == p5 && p5 == p6 && p4 != ' ') || 
        (p7 == p8 && p8 == p9 && p7 != ' ')) {
        return 1;
    }
    
    // Verifica as colunas
    if ((p1 == p4 && p4 == p7 && p1 != ' ') || 
        (p2 == p5 && p5 == p8 && p2 != ' ') || 
        (p3 == p6 && p6 == p9 && p3 != ' ')) {
        return 1;
    }
    
    // Verifica as diagonais
    if ((p1 == p5 && p5 == p9 && p1 != ' ') || 
        (p3 == p5 && p5 == p7 && p3 != ' ')) {
        return 1;
    }
    
    // Não houve vencedor
    return 0;
}



int verificarEmpate() {
    // Verifica se todas as posições estão ocupadas
    if (p1 != ' ' && p2 != ' ' && p3 != ' ' &&
        p4 != ' ' && p5 != ' ' && p6 != ' ' &&
        p7 != ' ' && p8 != ' ' && p9 != ' ') {
        return 1; // Empate (todas as casas estão ocupadas)
    }
    return 0; // Ainda existem casas vazias
}


int main(){


    int opcao = 1;
    int escolha;
    int j = 2;
    char jogador; 

    char posicao[3];

    p1 = ' ';
    p2 = ' ';
    p3 = ' ';
    p4 = ' ';
    p5 = ' ';
    p6 = ' ';
    p7 = ' ';
    p8 = ' ';
    p9 = ' ';

    
    system ("cls");

    do{
        
        printf("Bem-vindo ao jogo da velha!\n");
        printf("Selecione qual jogador você sera: jogador1, jogador2");
        scanf("%d", &escolha); // le a escolha do jogador
        while(getchar() != '\n');

        

         if(escolha == 1){
            printf("x\n");
         }
        else{
             printf("o\n");
        }
         
        
        
        identificarPosicao(jogador, posicao);

        exibirJogo(); // chama a função para exibir a jogada


        if(j % 2 == 0){
            jogador = 'x';
    
        }else{
            jogador = 'o';
        }
        

        j++;



        
        




        scanf("%2s", posicao);
        scanf("%c", &posicao);
        while(getchar() != '\n');

        


        
    




        printf("Se deseja continuar aperte 3, senão aperte 4\n");
        scanf("%d", &opcao);

        if(opcao == 4){
            printf("Saindo do jogo...\n");
        }else{
            printf("Recomeçando o jogo\n");
        }



        
            









    }while(opcao != 4 );

    return 0;
}