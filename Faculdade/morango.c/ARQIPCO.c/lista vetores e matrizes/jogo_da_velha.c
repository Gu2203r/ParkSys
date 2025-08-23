#include <stdio.h>  
#include <stdlib.h> 


#define LINHAS 3
#define COLUNAS 3

//Funções

void inicializarTabuleiro(char tabuleiro[LINHAS][COLUNAS]);
void exibirTabuleiro(char tabuleiro[LINHAS][COLUNAS]);
int validarJogada(char tabuleiro[LINHAS][COLUNAS], int linha, int coluna);
int tabuleiroCheio(char tabuleiro[LINHAS][COLUNAS]);
char verificarVencedor(char tabuleiro[LINHAS][COLUNAS]);


int main() {
    char tabuleiro[LINHAS][COLUNAS]; 
    int jogadorAtual = 1;             
    char simboloAtual;                
    int linha, coluna;                
    char vencedor = ' ';             
    int jogadas = 0;             

    inicializarTabuleiro(tabuleiro); // Inicia o tabuleiro vazio

    
    while (vencedor == ' ' && jogadas < (LINHAS * COLUNAS)) {
        exibirTabuleiro(tabuleiro); // Mostra o tabuleiro atual

        // Define o símbolo do jogador atual
        if (jogadorAtual == 1) {
            simboloAtual = 'X';
            printf("Jogador X, e sua vez.\n");
        } else {
            simboloAtual = 'O';
            printf("Jogador O, e sua vez.\n");
        }

        
        do {
            printf("Digite a linha (0-2) e coluna (0-2) separadas por espaco: ");
            scanf("%d %d", &linha, &coluna);
        } while (!validarJogada(tabuleiro, linha, coluna)); 

        // Aplica a jogada válida no tabuleiro
        tabuleiro[linha][coluna] = simboloAtual;
        jogadas++; 

        // Verifica se há um vencedor após a jogada
        vencedor = verificarVencedor(tabuleiro);

        
        if (vencedor == ' ') { 
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1; 
        }
    }

    exibirTabuleiro(tabuleiro); // Exibe o tabuleiro final

    
    if (vencedor != ' ') {
        printf("FIM DE JOGO! O Jogador %c venceu!\n", vencedor);
    } else {
        printf("FIM DE JOGO! Empate!\n");
    }

    return 0; 


}

// Função para inicializar o tabuleiro com espaços vazios
void inicializarTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            tabuleiro[i][j] = ' '; // Preenche cada célula com um espaço em branco
        }
    }
}

// Função para exibir o tabuleiro na tela
void exibirTabuleiro(char tabuleiro[LINHAS][COLUNAS]) {
    // Limpa a tela do console (opcional, para uma visualização mais limpa)
    // system("cls"); // Para Windows
    // system("clear"); // Para Linux/macOS
    printf("\n--- JOGO DA VELHA ---\n\n");
    printf("     0   1   2\n"); // Índices das colunas
    printf("   +---+---+---+\n");
    for (int i = 0; i < LINHAS; i++) {
        printf(" %d |", i); // Índices das linhas
        for (int j = 0; j < COLUNAS; j++) {
            printf(" %c |", tabuleiro[i][j]); // Exibe o conteúdo da célula
        }
        printf("\n   +---+---+---+\n");
    }
    printf("\n");
}

// Função para validar a jogada do jogador
// Retorna 1 se a jogada for válida, 0 caso contrário
int validarJogada(char tabuleiro[LINHAS][COLUNAS], int linha, int coluna) {
    // Verifica se a linha e a coluna estão dentro dos limites do tabuleiro
    if (linha < 0 || linha >= LINHAS || coluna < 0 || coluna >= COLUNAS) {
        printf("Posicao invalida! Linha e/ou coluna fora dos limites (0-2).\n");
        return 0; // Jogada inválida
    }
    // Verifica se a posição escolhida já está ocupada
    if (tabuleiro[linha][coluna] != ' ') {
        printf("Posicao ja ocupada! Escolha outra.\n");
        return 0; // Jogada inválida
    }
    return 1; // Jogada válida
}

// Função para verificar se há um vencedor
// Retorna o caractere do vencedor ('X' ou 'O'), ou ' ' se não houver
char verificarVencedor(char tabuleiro[LINHAS][COLUNAS]) {
    // Verificar linhas
    for (int i = 0; i < LINHAS; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return tabuleiro[i][0];
        }
    }

    // Verificar colunas
    for (int j = 0; j < COLUNAS; j++) {
        if (tabuleiro[0][j] != ' ' && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]) {
            return tabuleiro[0][j];
        }
    }

    // Verificar diagonais
    // Diagonal principal
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }
    // Diagonal secundária
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    return ' '; // Ninguém venceu ainda
}

// Função para verificar se o tabuleiro está cheio (empate)
// Retorna 1 se estiver cheio, 0 caso contrário
int tabuleiroCheio(char tabuleiro[LINHAS][COLUNAS]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0; 
            }
        }
    }
    return 1; 
}








