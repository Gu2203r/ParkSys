#include <stdio.h>
#include <stdlib.h>

float lerValidarNota (int alunoNum, float notaNum){ // função que lê o número do aluno e a nota e verifica se é valida

    float nota;

    do{

        scanf("%f", &nota);
        

        if(nota < 0 || nota > 10){

           printf(" A nota %f do aluno %d está incorreta! Tente novamente (de 0 ate 10) :\n", notaNum, alunoNum);
    } 


    }while(nota < 0 || nota > 10);

    return nota;

}


float calcularMedia (float n1, float n2, float n3){ // função que calcula a média do aluno

      return (n1 + n2 + n3) /3;


}


void exibirCondicaoAluno (float media){ // função que exibe a situação do aluno de acordo com a média obtida

    if(media >= 7){
        printf("Parabéns! Você foi aprovado com media de %.2f\n", media);
     }else if( media >= 4){
        printf("Você ficou de recuperação com média igual a %.2f\n", media);
     }else if(media < 4){
        printf("Você foi reprovado com media igual a %.2f\n", media);
     }
}




int main(){


        float n1, n2, n3, media; // váriaveis
        int qnt_alunos ;

        system ("cls"); // limpa a tela do sistema



        printf("Digite a quantidade de alunos :\n");
        scanf("%d", &qnt_alunos); // lê a quantidade de alunos

        for(int i = 0; i < qnt_alunos; i++){ // faz o loop de acordo com a quantidade de alunos inserida

            printf("Digite a primeira nota:\n");
            n1 = lerValidarNota(i, n1);
            printf("Digite a segunda nota:\n");
            n2 = lerValidarNota(i, n2);
            printf("Digite a terceira nota:\n");
            n3 = lerValidarNota(i, n3);

            media = calcularMedia(n1,n2,n3); // chama a função para calcular a média dentro do main
    
            printf("Sua media foi de %.2f", media);

            exibirCondicaoAluno(media); // chama a função para mostrar a situação de cada aluno
            
        }

}