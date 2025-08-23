/*Escreva um programa que valide se um CPF (Cadastro de Pessoa Física) é
válido. O programa deve solicitar ao usuário um CPF e vericar se ele segue a
formatação e os dígitos vericadores corretos.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validarCPF(char cpf[]){
    int i, soma = 0, digito1, digito2, peso = 10;
    
    // Verifica se o CPF tem 11 dígitos
    for (i = 0; i < 11; i++) {
        if (cpf[i] < '0' || cpf[i] > '9') {
            return 0; // CPF inválido
        }
    }
    
    // Calcula o primeiro dígito verificador
    for (i = 0; i < 9; i++) {
        soma += (cpf[i] - '0') * peso--;
    }
    digito1 = (soma * 10) % 11;
    if (digito1 == 10) {
        digito1 = 0;
    }
    
    // Verifica o primeiro dígito verificador
    if (cpf[9] - '0' != digito1) {
        return 0; // CPF inválido
    }
    
    // Reseta a soma e o peso para o segundo dígito verificador
    soma = 0;
    peso = 11;
    
    // Calcula o segundo dígito verificador
    for (i = 0; i < 10; i++) {
        soma += (cpf[i] - '0') * peso--;
    }
    digito2 = (soma * 10) % 11;
    if (digito2 == 10) {
        digito2 = 0;
    }
    
    // Verifica o segundo dígito verificador
    if (cpf[10] - '0' != digito2) {
        return 0; // CPF inválido
    }
    
    return 1; // CPF válido
}

int main(){
    char cpf[12]; // CPF com 11 dígitos + caractere nulo
    int valido;
    
    system("cls"); // Limpa a tela do console (Windows)
    
    do{
        printf("Digite o CPF (apenas numeros): ");
        scanf("%s", cpf); // Lê o CPF
        
        valido = validarCPF(cpf); // Chama a função para validar o CPF
        
        if (valido) {
            printf("CPF valido!\n"); // Exibe mensagem de CPF válido
        } else {
            printf("CPF invalido!\n"); // Exibe mensagem de CPF inválido
        }
        
    }while(valido == 0); // Repete o loop até que o CPF seja válido
    
    return 0; // Retorna 0 para indicar que o programa terminou com sucesso
}