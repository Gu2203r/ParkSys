/*Crie um programa que simule um caixa eletrônico. O programa deve permitir
ao usuário realizar operações como consultar saldo, realizar saques,
depósitos e transferências.*/


#include <stdio.h>
#include <stdlib.h>



float consultarSaldo(float saldo) {
    return saldo; // Retorna o saldo atual
}

float realizarSaque(float saldo, float valorSaque) {
    if (valorSaque > saldo) {
        printf("Saldo insuficiente para saque.\n");
        return saldo; // Retorna o saldo sem alterações
    } else {
        saldo -= valorSaque; // Deduz o valor do saque do saldo
        printf("Saque de R$%.2f realizado com sucesso.\n", valorSaque);
        return saldo; // Retorna o novo saldo
    }
}

float realizarDeposito(float saldo, float valorDeposito) {
    saldo += valorDeposito; // Adiciona o valor do depósito ao saldo
    printf("Deposito de R$%.2f realizado com sucesso.\n", valorDeposito);
    return saldo; // Retorna o novo saldo

}
float realizarTransferencia(float saldo, float valor, int contaDestino) {
    if (valor > saldo) {
        printf("Saldo insuficiente para transferencia.\n");
        return saldo; // Retorna o saldo sem alterações
    } else {
        saldo -= valor; // Deduz o valor da transferência do saldo
        printf("Transferencia de R$%.2f realizada com sucesso para a conta %d.\n", valor, contaDestino);
        return saldo; // Retorna o novo saldo
    }
}

int main(){
    float saldo = 500.0; // Saldo inicial
    float valor;
    int opcao, contaDestino;


    system("cls"); // Limpa a tela do console (Windows)

    printf("Bem-vindo ao Caixa Eletronico\n");
    printf("Digite 1 para consultar saldo\n");
    printf("Digite 2 para realizar saque\n");
    printf("Digite 3 para realizar deposito\n");
    printf("Digite 4 para realizar transferencia\n");
    printf("Digite 5 para sair\n");
    scanf("%d", &opcao); // Lê a opção do usuário


    do{
        switch (opcao) {
            case 1:
                printf("Seu saldo atual e: R$%.2f\n", consultarSaldo(saldo)); // Consulta o saldo
                break;
            case 2:
                printf("Digite o valor do saque: ");
                scanf("%f", &valor); // Lê o valor do saque
                saldo = realizarSaque(saldo, valor); // Chama a função para realizar o saque
                break;
            case 3:
                printf("Digite o valor do deposito: ");
                scanf("%f", &valor); // Lê o valor do depósito
                saldo = realizarDeposito(saldo, valor); // Chama a função para realizar o depósito
                break;
            case 4:
                printf("Digite o valor da transferencia: ");
                scanf("%f", &valor); // Lê o valor da transferência
                printf("Digite a conta de destino: ");
                scanf("%d", &contaDestino); // Lê a conta de destino
                saldo = realizarTransferencia(saldo, valor, contaDestino); // Chama a função para realizar a transferência
                break;

            case 5:
                printf("Saindo do programa...\n"); // Sai do programa
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n"); // Opção inválida
        }
    }while(opcao != 5); // Repete até o usuário digitar 5
     
    return 0;
       
    }

