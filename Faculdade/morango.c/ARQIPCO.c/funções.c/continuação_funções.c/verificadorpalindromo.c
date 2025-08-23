/*Crie um programa que determine se uma string é um palíndromo (ou seja, a
string é a mesma lida da esquerda para a direita ou da direita para a
esquerda). O programa deve solicitar ao usuário uma string e exibir se ela é
ou não um palíndromo.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ePalindromo(char str[]) {
    int i, j;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // Não é um palíndromo
        }
    }
    return 1; // É um palíndromo
}

 int main(){
    char str[100];
    int resultado;
    int opcao;

    system("cls"); // Limpa a tela do console (Windows)

    printf("Verificador de Palindromo\n");
    printf("Para sair digite 1.\n");

    do{
        printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin); // Lê a string do usuário
    str[strcspn(str, "\n")] = 0; // Remove o caractere de nova linha

    resultado = ePalindromo(str);

    if (resultado) {
        printf("A string '%s' eh um palindromo.\n", str);
    } else {
        printf("A string '%s' nao eh um palindromo.\n", str);
    }

    if(opcao == 1){
        printf("Saindo do programa...\n");
        break; // Sai do loop se o usuário digitar 1
    }
    }while(opcao != 1); // Repete até o usuário digitar 1

    

    return 0;
}