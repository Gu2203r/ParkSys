#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUNOS 30
#define TAM_MAX_NOME 100
#define MAX_DISCIPLINAS 4

char nomes_alunos[MAX_ALUNOS][TAM_MAX_NOME];
float notas[MAX_ALUNOS][MAX_DISCIPLINAS];

int indice_aluno_atual = 0;


void exebirMenuNotas();
void cadastrarNovoAluno();
void  lancarNotas();
void listarAlunosNotas();
void calcularMediaAluno();
void calcularMediaDisciplina();
void relatorioDesempenho();
void limparBufferEntrada();
void aguardar_tecla();


int main(){

    int opcao = 0;

    do
    {


        exebirMenuNotas();

        printf("Digite sua opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:

            cadastrarNovoAluno();

            break;
        case 2:

            lancarNotas();
        
            break;

        case 3:    

            listarAlunosNotas();

            break;

        case 4:

            calcularMediaAluno();                

            break;

        case 5:
            
            calcularMediaDisciplina();

            break;

        case 6:

            relatorioDesempenho();
        
            break;

        case 7:

            printf("Encerrando o sistema...Ate a proxima!\n");
        
            break;
        
        
        default:

            printf("Opcao invalida! Tente novamente.\n");
            
            break;
        }

        printf("Pressione Enter para continuar\n");
        aguardar_tecla(); // Pausa para o usuário poder ler a saída antes de mostrar o menu novamente

    
    } while (opcao != 7);
    

return 0;


}

void exebirMenuNotas(){

    system("cls");

    printf("SISTEMA DE GERENCIAMENTO DE NOTAS\n");
    printf("\n");
    printf("Escolha uma das opcoes:\n");
    printf("1. Cadastrar novo aluno\n");
    printf("2. Lancar/atualizar notas\n");
    printf("3. Listar todos os alunos e suas notas\n");
    printf("4. Calcular a media do aluno\n");
    printf("5. Calcular a media da disciplina\n");
    printf("6. Relatorio de desempenho (aprovados/reprovados)\n");
    printf("7. Sair\n");



}

void cadastrarNovoAluno(){

    if(indice_aluno_atual < MAX_ALUNOS){

        printf("Cadastro de novo aluno\n");
        printf("\n");
        printf("Digite o nome do aluno\n");
        scanf("%s", nomes_alunos[indice_aluno_atual]);
        limparBufferEntrada();

        for(int j = 0; j < MAX_DISCIPLINAS; j++){

            notas[indice_aluno_atual][j] = 0.0;
            
        }

        printf("Aluno %s cadastrado com sucesso!\n", nomes_alunos[indice_aluno_atual]);

        indice_aluno_atual = indice_aluno_atual + 1;

    }else{

        printf("Erro: Capacidade maxima de alunos atingida!\n");
    }

}

void  lancarNotas(){

    int id_aluno, id_disciplina;
    

    printf("Lancar/Atualizar notas\n");
    printf("\n");
    printf("Digite o ID do aluno:\n");
    scanf("%d", &id_aluno);
    limparBufferEntrada();

    if(id_aluno >= 0 && id_aluno < indice_aluno_atual){

        printf("Aluno selecionado: %s\n", nomes_alunos[id_aluno]);
        printf("Disciplinas: 0-Matematica, 1-Portugues, 2-Ciencias, 3-Historia\n");
        printf("Digite o indice da disciplina:\n");
        scanf("%d", &id_disciplina);
        limparBufferEntrada();

        if(id_disciplina >= 0 && id_disciplina < MAX_DISCIPLINAS){

            printf("Nota atual: %f\n", notas[id_aluno][id_disciplina]);
            printf("Digite a nova nota:\n");
            scanf("%f", &notas[id_aluno][id_disciplina]);
            limparBufferEntrada();
    
            if(notas[id_aluno][id_disciplina] >= 0.0 && notas[id_aluno][id_disciplina] <= 10.0){
        
                printf("Nota atualizada com sucesso!\n");
        
            }else{
        
                printf("Erro: Nota invalida! A nota deve ser entre 0 e 10.\n");
            }
    



        }else{

            printf("Erro: Ìndice de disciplina invalido.\n");

        }

    }else{

        printf("Erro: ID de aluno nao encontrado ou invalido\n");
    }
}

void listarAlunosNotas(){

    printf("Lista de alunos e Notas\n");

    if(indice_aluno_atual == 0){

        printf("Nenhum aluno cadastrado ainda.\n");
        
    }else{

        printf("ID | Nome | Matematica | Portugues | Ciencias | Historia\n");
        printf("\n");

        for(int i = 0; i < indice_aluno_atual; i++){

            printf("| %s |", nomes_alunos[i]);

            for( int j = 0; j < indice_aluno_atual; j++){

                printf("%f", notas[i][j]);

            }

            printf("\n");
        }
    }
    getchar();
}

void calcularMediaAluno(){

    int id_aluno;
    float soma_notas_aluno = 0.0;
    float media_aluno;

    printf("Calcular a media do aluno\n");
    printf("Digite o ID do aluno:\n");
    scanf("%d", &id_aluno);
    limparBufferEntrada();

    if(id_aluno >= 0 && id_aluno < indice_aluno_atual){

        for(int j = 0; j < MAX_DISCIPLINAS; j++){

            soma_notas_aluno = soma_notas_aluno + notas[id_aluno][j];
        }

        media_aluno = soma_notas_aluno / MAX_DISCIPLINAS;

        printf("A media do aluno %s e: %f\n", nomes_alunos[id_aluno], media_aluno);
    }
}

void calcularMediaDisciplina(){

    int id_disciplina;
    float soma_notas_disciplina = 0.0;
    float media_disciplina;

    printf("Calcular Media da disciplina\n");
    printf("Disciplinas: 0-Matematica, 1-Portugues, 2-Ciencias, 3-Historia\n");
    printf("Digite o indice da disciplina:\n");
    scanf("%d", &id_disciplina);
    limparBufferEntrada();

    if(id_disciplina >= 0 && id_disciplina < MAX_DISCIPLINAS){

        for(int i = 0; i < indice_aluno_atual; i++){

            soma_notas_disciplina = soma_notas_disciplina + notas[i][id_disciplina];
        }


        if(indice_aluno_atual > 0 ){

            media_disciplina = soma_notas_disciplina / indice_aluno_atual;

            printf("A media da disciplina %d e: %f\n", id_disciplina, media_disciplina);

        }else{

            printf("Nenhum aluno cadastrado para calcular a media da disciplina\n");
        }


    }else{

        printf("Erro: Ìndice de disciplina invalido\n");
    }


}

void relatorioDesempenho(){

    float soma_notas_aluno = 0.0, media_aluno = 0.0;

    printf("Relatorio de Desempenho\n");

    if(indice_aluno_atual == 0){

        printf("Nenhum aluno cadastrado ainda.\n");

    }else{

        printf("ID | Nome | Media | Status\n");
        printf("\n");

        for(int i = 0; i < MAX_DISCIPLINAS; i++){

            soma_notas_aluno = 0.0;

            for(int j = 0; j < MAX_DISCIPLINAS; i++){

                soma_notas_aluno = soma_notas_aluno + notas[i][j];
            }

            soma_notas_aluno = soma_notas_aluno / MAX_DISCIPLINAS;

            printf("| %s  %f|", nomes_alunos[i], media_aluno);

            if(media_aluno >= 7.0){

                printf("Aluno aprovado!\n");
            }else{

                printf("Aluno reprovado!\n");
            }

            printf("\n");
        }
    }
}

void limparBufferEntrada(){

    while ((getchar()) != '\n'); 

}

void aguardar_tecla(){


    getchar();

}






