/*Crie um programa que gere senhas aleatórias com base em critérios
definidos pelo usuário, como comprimento da senha, inclusão de letras
maiúsculas, minúsculas, números e símbolos.*/

#include <stdio.h>
#include <stdlib.h>

char* gerarSenha(int comprimento, int incluirMaiusculas, int incluirMinusculas, int incluirNumeros, int incluirSimbolos){
    char* senha = (char*)malloc((comprimento + 1) * sizeof(char)); // Aloca memória para a senha
    const char* maiusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // Letras maiúsculas
    const char* minusculas = "abcdefghijklmnopqrstuvwxyz"; // Letras minúsculas
    const char* numeros = "0123456789"; // Números
    const char* simbolos = "!@#$%^&*()_+-=[]{}|;:,.<>?"; // Símbolos
    int i, j, k = 0;
    
    for (i = 0; i < comprimento; i++) {
        int tipo = rand() % 4; // Gera um número aleatório entre 0 e 3
        
        if (tipo == 0 && incluirMaiusculas) {
            senha[i] = maiusculas[rand() % 26]; // Adiciona uma letra maiúscula
        } else if (tipo == 1 && incluirMinusculas) {
            senha[i] = minusculas[rand() % 26]; // Adiciona uma letra minúscula
        } else if (tipo == 2 && incluirNumeros) {
            senha[i] = numeros[rand() % 10]; // Adiciona um número
        } else if (tipo == 3 && incluirSimbolos) {
            senha[i] = simbolos[rand() % 30]; // Adiciona um símbolo
        } else {
            i--; // Se não for possível adicionar, repete a iteração
        }
    }
    
    senha[comprimento] = '\0'; // Adiciona o caractere nulo ao final da string
    
    return senha; // Retorna a senha gerada
}
    int main(){

        int comprimento, incluirMaiusculas, incluirMinusculas, incluirNumeros, incluirSimbolos;
        char* senha;
        
        system("cls"); // Limpa a tela do console (Windows)

        do{
            printf("Digite o comprimento da senha: ");
        scanf("%d", &comprimento); // Lê o comprimento da senha
        
        printf("Incluir letras maiusculas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &incluirMaiusculas); // Lê se deve incluir letras maiúsculas
        
        printf("Incluir letras minusculas? (1 - Sim, 0 - Nao): ");
        scanf("%d", &incluirMinusculas); // Lê se deve incluir letras minúsculas
        
        printf("Incluir numeros? (1 - Sim, 0 - Nao): ");
        scanf("%d", &incluirNumeros); // Lê se deve incluir números
        
        printf("Incluir simbolos? (1 - Sim, 0 - Nao): ");
        scanf("%d", &incluirSimbolos); // Lê se deve incluir símbolos
        
        senha = gerarSenha(comprimento, incluirMaiusculas, incluirMinusculas, incluirNumeros, incluirSimbolos); // Chama a função para gerar a senha
        
        printf("Senha gerada: %s\n", senha); // Exibe a senha gerada
        
        free(senha); // Libera a memória alocada para a senha
        
        }while(1); // Repete o loop indefinidamente
        
        return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
    }
    
    