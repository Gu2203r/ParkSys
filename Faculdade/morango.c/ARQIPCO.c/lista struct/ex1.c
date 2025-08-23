#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_ALUNO 50


struct Aluno
{
    char nome;
    int idade;
    float nota_final;
};


struct Aluno turma[MAX_ALUNO];
int num_alunos = 0;


void cadastrarAluno();
float calcularMediaTurma();
void exibirMenu();



int main(){

    float media;
    int opcao;


        do
        {
            exibirMenu();
            printf("Digite sua opcao: ");
            scanf("%d", &opcao);
            while (getchar()!= '\n');

            if (opcao == 1) {
                cadastrarAluno();
            } else if (opcao == 2) {
                media = calcularMediaTurma();
                printf("A media da turma e: %.2f\n", media);
            } else if (opcao != 3) {
                printf("Opcao invalida! Tente novamente.\n");
            }else if(opcao == 3){
                printf("Saindo do programa...\n");
            }

        } while (opcao != 3);
        
       
   

    }


void cadastrarAluno(){

    if(num_alunos < MAX_ALUNO){
        printf("Nome do aluno:\n");
        scanf("%s",&turma[num_alunos].nome);
        printf("Idade:\n");
        scanf("%d",&turma[num_alunos].idade);
        printf("Nota final:\n");
        scanf("%f", &turma[num_alunos].nota_final);

        num_alunos = num_alunos + 1;

        printf("Aluno cadastrado com sucesso!\n");
    }else{
        printf("Turma cheia!\n");
    }
}

float calcularMediaTurma(){
    float soma_notas = 0.0;
    float media = 0.0;

    if(num_alunos > 0){

        for(int i = 0; i < num_alunos; i++){
            soma_notas = soma_notas + turma[i].nota_final;
        }

        media = soma_notas/num_alunos;

        return (media);
    }else{
        return (0.0);
    }

}

void exibirMenu(){

    printf("Escolha uma das opcoes:\n");
    printf("\n");
    printf("1. Cadastrar novo aluno\n");
    printf("2. mostrar media da turma\n");
    printf("3. Sair\n");

    
}
