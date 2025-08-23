#include <stdio.h>
#include <string.h>
#include "data.c"
#include "utils.c"
#include "datatype.h"

int main(){

    int opcao;

    do
    {
        printf("---Menu Inicial---\n");
        printf("1.Adicionar novo contato\n");
        printf("2.Listar todos os contatos\n");
        printf("3.Encontrar contato\n");
        printf("4.Sair do programa\n");
        printf("---Escolha uma das opcoes---\n");
        scanf("%d", &opcao);
        
        if(opcao == 4){
            printf("Saindo do programa...");
            break;
        }
 

        ListaDeContatos agenda;
        int i;
        for(i = 0; i < TAM_AGENDA; i++){
            printf("\n Entre com o nome: ");
            // fgets(agenda.contato[i].nome, TAM_NOME, stdin); // Lê a linha inteira
            // Remove o '\n' que o fgets pode deixar no final
            // agenda.contato[i].nome[strcspn(agenda.contato[i].nome, "\n")] = '\0'; 
            // ou... use o gets
            gets(agenda.contato[i].nome);
            printf("\n Entre com a data de nascimento: ");
            agenda.contato[i].dataDeNascimento = lerData();
            }
            limparBufferEntrada();       
            printf("\n Entre com o email: ");
            gets(agenda.contato[i].email);
            printf("\n Entre com o telefone: ");
            gets(agenda.contato[i].telefone);
            printf("\n Entre com o endereco : ");
            gets(agenda.contato[i].endereco);
           //  limparBufferEntrada();
        
        
        // Exibe os elementos da agenda
        printf("\n\n Agenda");
        for(int i = 0;i<TAM_AGENDA;i++){
            printf("\n (%d) Nome: %s, ", i+1, agenda.contato[i].nome);
            printf("Data de nascimento: ");
            imprimirData(agenda.contato[i].dataDeNascimento);
            printf(" Email: %s ", agenda.contato[i].email);
            printf(" Telefone: %s\n", agenda.contato[i].telefone);
            printf(" Endereco : %s\n", agenda.contato[i].endereco);
            }
    
          
        }while(opcao == 4);
    

   
        return 0; // Add return statement to properly end main function
    }



