#include <stdio.h> 
#include <stdlib.h>

#define NUMERO_DE_ALUNOS 5
#define TAMANHO_MAX_NOME 30

void LerDadosAlunos(char nomes[][TAMANHO_MAX_NOME], float notas[]);
float calcularMedia(float caderno_notas[]);
int contarMediaAcima(float caderno_notas[], float media_turma) ;
float encontrarMaiorNota(float caderno_notas[]);
float encontrarMenorNota(float caderno_notas[]);
int indiceMaiorNota(float caderno_notas[]);


int main() {

    system("cls");

    char caderno_nomes[NUMERO_DE_ALUNOS][TAMANHO_MAX_NOME];
    float caderno_notas[NUMERO_DE_ALUNOS];

    float media_final; // Variável para armazenar o resultado da média
    int qnt_acima_media; // Variável para armazenar a quantidade de alunos acima da média
    float maior_nota_turma; // Variável para armazenar a maior nota
    float menor_nota_turma; // Variável para armazenar a menor nota
    int indice_aluno_maior_nota; // Variável para armazenar o índice do aluno com maior nota

    // Chama a função para ler os dados dos alunos
    LerDadosAlunos(caderno_nomes, caderno_notas);

    // Calcula a média da turma
    media_final = calcularMedia(caderno_notas); // Passa apenas o array de notas

    // Conta quantos alunos ficaram acima da média
    qnt_acima_media = contarMediaAcima(caderno_notas, media_final); // Passa a média calculada

    // Encontra a maior nota
    maior_nota_turma = encontrarMaiorNota(caderno_notas);

    // Encontra a menor nota
    menor_nota_turma = encontrarMenorNota(caderno_notas);

    // Encontra o índice (posição) do aluno com a maior nota
    indice_aluno_maior_nota = indiceMaiorNota(caderno_notas);


    printf("\nResultados da Turma\n");
    printf("A média da turma foi: %.2f\n", media_final); 
    printf("Alunos que ficaram acima da media: %d\n", qnt_acima_media); 
    printf("A maior nota foi: %.2f\n", maior_nota_turma);
    printf("A menor nota foi: %.2f\n", menor_nota_turma);
    printf("O aluno com a maior nota foi: %s (Nota: %.2f)\n", 
           caderno_nomes[indice_aluno_maior_nota], caderno_notas[indice_aluno_maior_nota]); 

    return 0;
}

//Função para Ler Dados dos Alunos 
void LerDadosAlunos(char nomes[][TAMANHO_MAX_NOME], float notas[]) {
    int i;
    for (i = 0; i < NUMERO_DE_ALUNOS; i++) { 
        printf(" Aluno %d\n", i + 1); // Indica qual aluno está sendo lido
        printf("Informe o nome do aluno: ");
        scanf("%s", nomes[i]); 
        printf("Digite a nota do aluno: ");
        scanf("%f", &notas[i]); 
    }
}

//Função para Calcular Média da Turma
float calcularMedia(float caderno_notas[]) { 
    float soma_total = 0;
    int i;

    for (i = 0; i < NUMERO_DE_ALUNOS; i++) { // Loop 
        soma_total = soma_total + caderno_notas[i]; // Acumula a soma das notas
    }

    // Retorna a média
    return soma_total / NUMERO_DE_ALUNOS;
}

//Função para Contar Alunos Acima da Média
int contarMediaAcima(float caderno_notas[], float media_turma) {
    int contador_acima = 0;
    int i;

    for (i = 0; i < NUMERO_DE_ALUNOS; i++) { // Loop
        if (caderno_notas[i] > media_turma) { // Verifica se a nota atual é maior que a média da turma
            contador_acima = contador_acima + 1; // Incrementa o contador
        }
    }
    return contador_acima;
}

//Função para Encontrar a Maior Nota
float encontrarMaiorNota(float caderno_notas[]) {
    float maior_nota = caderno_notas[0]; // Inicializa maior_nota com a primeira nota para comparação
    int i;

    for (i = 1; i < NUMERO_DE_ALUNOS; i++) {
        if (caderno_notas[i] > maior_nota) {
            maior_nota = caderno_notas[i]; 
        }
    }
    return maior_nota;
}

//Função para Encontrar a Menor Nota
float encontrarMenorNota(float caderno_notas[]) {
    float menor_nota = caderno_notas[0]; // Inicializa menor_nota com a primeira nota
    int i;

    for (i = 1; i < NUMERO_DE_ALUNOS; i++) { 
        if (caderno_notas[i] < menor_nota) {
            menor_nota = caderno_notas[i];
        }
    }
    return menor_nota;
}

//Função para Encontrar o Índice (posição) da Maior Nota
int indiceMaiorNota(float caderno_notas[]) {
    int i;
    int indice_maior = 0;

    for (i = 1; i < NUMERO_DE_ALUNOS; i++) { 
        if (caderno_notas[i] > caderno_notas[indice_maior]) {
            indice_maior = i;
        }
    }
    return indice_maior; // Retorna a posição do aluno com a maior nota
}







