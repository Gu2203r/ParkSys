#include <stdio.h> // Para printf e scanf

int main() {
    char nome[30]; // "Caixinha" para guardar o nome

    printf("Digite seu primeiro nome: ");
    scanf("%s", nome); // Lê a string digitada

    printf("Ola, %s!\n", nome); // Mostra o nome lido

    return 0; // Indica que o programa terminou bem
}
/*Já usamos printf com %s para mostrar strings na tela.
Lendo com scanf (para uma palavra):
Pede uma palavra e guarda na "caixa" (vetor).
Código: scanf("%s", nomeDaVariavelString);
NÃO use & antes do nome do vetor de char com %s.
Atenção scanf!
Para de ler no primeiro ESPAÇO, Tab ou Enter.
Se o usuário digitar algo maior que a "caixa", pode estourar (buffer overflow)!
*/