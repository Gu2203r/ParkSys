#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

// Constantes para dimensionar as estruturas de dados

#define MAX_PRODUTOS 50
#define TAM_MAX_NOME 100


struct Produto
{
   char nome[TAM_MAX_NOME];
   int quantidade;
   float preco; 

};

struct Produto estoque[MAX_PRODUTOS];
int indice_atual = 0;


//Funções

void exibirMenu();
void cadastrarProduto();
void listrarProdutos();
void atualizarEstoque();
void buscarProduto();
void calcularValorTotal();
void relatorioEstoqueBaixo();
void limparBufferEntrada();
void aguardar_tecla();


int main(){

    int opcao = 0;

    do{


        exibirMenu();
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao)
        {
        case 1:

            cadastrarProduto();
            
            break;

        case 2:

            listrarProdutos();
        
            break;

        case 3:

            atualizarEstoque();
        
            break;

        case 4:

            buscarProduto();
        
            break;

        case 5:

            calcularValorTotal();
        
            break;

        case 6:

            relatorioEstoqueBaixo();
        
            break;

        case 7:

            printf("Encerrando o sistema...Ate a proxima!");
        
            break;
        
        default:

            printf("Opcao invalida! Tente novamente.\n");

            break;
        }

        printf("Pressione Enter para continuar\n");
        aguardar_tecla(); // Pausa para o usuário poder ler a saída antes de mostrar o menu novamente

    }while(opcao != 7);

    
return 0;


}

//Função para exibir o menu

void exibirMenu(){

    system ("cls");

    printf("Escolha uma das opcoes:\n");
    printf("\n");
    printf("1. Cadastrar novo produto\n");
    printf("2. Listar todos os produtos\n");
    printf("3. Atualizar Estoque de um Produto\n");
    printf("4. Buscar Produto por Nome/ID\n");
    printf("5. Calcular Valor Total do Estoque\n");
    printf("6. Relatorio de Produtos com Estoque Baixo\n");
    printf("7. Sair\n");

    
}

//Função para cadastrar produtos

void cadastrarProduto(){

    // Verifica se ainda há espaço para novos produtos

    if(indice_atual < MAX_PRODUTOS){
        printf("Cadastro de novo produto\n");
        printf("Digite o nome do produto\n");
        scanf("%99s",estoque[indice_atual].nome);
        limparBufferEntrada();
        printf("\n");

        printf("Digite a quantidade inicial\n");
        scanf("%d", &estoque[indice_atual].quantidade);
        limparBufferEntrada();
        printf("\n");

        printf("Digite o preco unitario(R$):\n");
        scanf("%f", &estoque[indice_atual].preco);
        limparBufferEntrada();
        printf("\n");

        printf("Produto %s Cadastrado com sucesso! ID:%d\n", estoque[indice_atual].nome, indice_atual);

        indice_atual = indice_atual + 1;
    }else{
        printf("Erro: Capacidade mamixa de produtos atingida!\n");
    }
}

//Função para listar todos os produtos

void listrarProdutos(){

    printf("Lista de produtos cadastrados\n");
    printf("\n");

    if(indice_atual == 0){
        printf("Nenhum produto cadastrado ainda\n");
    }else{

        // Percorre o vetor até o último produto cadastrado
        for(int i = 0; i < indice_atual; i++){
            printf("ID: %d | Nome: %s | Quantidade: %d | Preco: R$ %.2f\n", i, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
        }
    }
}

//Função para atualizar o estoque de um produto

void atualizarEstoque(){

    int id_produto;
    int qnt_movimento;

    printf("Atualizar estoque\n");
    printf("\n");
    printf("Digite o ID do produto que deseja atualizar:");
    scanf("%d", &id_produto);
    limparBufferEntrada();


    // Validação: verifica se o ID é válido (está dentro dos limites dos produtos cadastrados)
    if(id_produto >= 0 && id_produto < indice_atual ){
        printf("Produto selecionado: %s\n", estoque[id_produto].nome);
        printf("Estoque atual: %d\n", estoque[id_produto].quantidade);
        printf("Digite a quantidade a ser selecionada ou removida");
        scanf("%d", &qnt_movimento);
        limparBufferEntrada();
    }


    // Validação: impede que o estoque se torne negativo
    if((estoque[id_produto].quantidade + qnt_movimento) >= 0){
        estoque[id_produto].quantidade = estoque[id_produto].quantidade + qnt_movimento;
        printf("Estoque atualizado com sucesso! Novo estoque: %d\n", estoque[id_produto].quantidade);
    }else{
        printf("Erro:Operacao invalida! O estoque nao pode ficar negativo\n");
    }
}



//Função que busca o produto por nome/ID

void buscarProduto(){


     // Implementação simplificada da busca por nome (conter texto)
    char texto[TAM_MAX_NOME];
    int id_busca;
    char* encontrado = NULL;
    int verificar;

    

    printf("Buscar produto\n");
    printf("\n");
    printf("Digite o ID ou parte do nome do produto\n");
    scanf("%s", texto);
    limparBufferEntrada();

    verificar = sscanf(texto,"%d", &id_busca);


     // Tenta converter o termo para um número para checar se é um ID
    if(verificar == 1){

        printf("Produto encontrado por ID\n");
        printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %.2f", id_busca, estoque[id_busca].nome, estoque[id_busca].quantidade, estoque[id_busca].preco);

    }else{

        // Se não encontrou por ID, busca por nome
        for(int i = 0; i < indice_atual; i++){

            encontrado = strstr(estoque[i].nome, texto);

            
            if(encontrado){

                printf("ID: %d | Nome: %s | Quantidade: %d | Preco: %f", i, estoque[i].nome, estoque[i].quantidade, estoque[i].preco);
            }

        }

        
    }
    
    
}


//Função que calcula o valor total do estoque

void calcularValorTotal(){
    float valor_total_estoque = 0.0;
    float valor_produto_atual;

    for(int i = 0; i < indice_atual; i++){

        valor_produto_atual = estoque[i].quantidade * estoque[i].preco;
        valor_total_estoque = valor_total_estoque + valor_produto_atual;
    }

    printf("Valor total estoque:\n");
    printf("\n");
    printf("O valor total de todos os produtos em estoque é: R$ %.2f", valor_total_estoque);


}

//Função que faz o relatório de produtos com estoque baixo

void relatorioEstoqueBaixo(){

    int limite_estoque;
    bool encontrou_item_abaixo = false;

    printf("Relatorio de estoque baixo\n");
    printf("\n");
    printf("Digite a quantidade limite para considerar o estoque baixo (ex: 5)\n");
    scanf("%d", &limite_estoque);
    limparBufferEntrada();
    printf("\n");

    printf("Produtos com estoque igual ou inferior a %d:\n", limite_estoque);

    for(int i = 0; i < indice_atual; i++){
        if(estoque[i].quantidade <= limite_estoque){
            printf("ALERTA | ID: %d | Nome: %s | Estoque atual: %d\n", i, estoque[i].nome, estoque[i].quantidade);

            encontrou_item_abaixo = true;

        }
    }

    if(encontrou_item_abaixo == false){
        printf("Nenhum produto com estoque baixo encontrado.\n");
    }
}

//Função que limpa o caminho para a próxima leitura

void limparBufferEntrada(){

    while ((getchar()) != '\n'); 

}

//Função que espera alguma tecla ser apertada, permitindo que o usuário tenha tempo de ler o conteúdo

void aguardar_tecla(){


    getchar();

}












