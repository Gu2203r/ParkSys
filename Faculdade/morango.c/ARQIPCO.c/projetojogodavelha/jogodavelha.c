#include <stdio.h>
#include <stdlib.h>

// Variáveis do tabuleiro
char p1 = ' ';
char p2 = ' ';
char p3 = ' ';
char p4 = ' ';
char p5 = ' ';
char p6 = ' ';
char p7 = ' ';
char p8 = ' ';
char p9 = ' ';

void exibirJogo() {
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

int main() {
    int opcao = 1;
    int jogada;
    int turno = 1;
    char jogador;



    system("cls");

        do{

             p1 = ' ';
             p2 = ' ';
             p3 = ' ';
             p4 = ' ';
             p5 = ' ';
             p6 = ' ';
             p7 = ' ';
             p8 = ' ';
             p9 = ' ';


         while(opcao != 4){
    
        printf("Bem-vindo ao Jogo da Velha!\n");

        exibirJogo();

        jogador = (turno % 2 == 1) ? 'X' : 'O';
        printf("Vez do jogador %c. Escolha uma posição (1-9): ", jogador);
        scanf("%d", &jogada);

        jogar(jogador, jogada);

        if (verificarVitoria()) {
            exibirJogo();
            printf("Jogador %c venceu!\n", jogador);
            break;
        }

        if (verificarEmpate()) {
            exibirJogo();
            printf("O jogo terminou em empate!\n");
            break;
        }

        turno++;

        printf("Deseja continuar? 3.sim, 4.nao: ");
        scanf("%d", &opcao);
    }

    if(opcao == 4) {
        printf("Obrigado por jogar!\n");
    }

    printf("Deseja jogar novamente? 1.para jogar, 2.Para sair\n");
    scanf("%d", &opcao);

    if(opcao == 2){
        printf("saindo do programa...\n");
    }

}while(opcao != 2 );

    return 0;
}