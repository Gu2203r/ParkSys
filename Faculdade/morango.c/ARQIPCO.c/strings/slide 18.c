#include <stdio.h>
#include <string.h> // Para strncpy

int main() {
    char palavraFonte[50] = "Instituto Federal";
    char palavraAlvo[10]; // Caixinha pequena!

    strncpy(palavraAlvo, palavraFonte, 9); // Copia no máx. 9 chars 
    palavraAlvo[9] = '\0'; // CRUCIAL para garantir o terminador!
    printf("Alvo: %s\n", palavraAlvo); // Mostra "Instituto"

    char fonteLimite[20] = "NoveLetra"; // 9 letras 
    char alvoExato[10];
    strncpy(alvoExato, fonteLimite, 9); // Copia "NoveLetra"
    alvoExato[9] = '\0'; // ESSENCIAL AQUI! strncpy NÃO pôs \0 
    printf("Alvo exato: %s\n", alvoExato); 
    return 0;
}



// REGRA DE OURO com strncpy: Sempre defina o \0 manualmente no final do buffer de destino se você não tiver 100% de certeza (ex: destino[tamanho_buffer - 1] = '\0'; ou destino[n_copiados] = '\0'; se houver espaço).
