#include <stdio.h>
#include <string.h> // Para strcmp

int main() {
    char palavra1[20] = "banana";
    char palavra2[20] = "laranja";
    char palavra3[20] = "banana";
    int resultado; // Para guardar o retorno de strcmp

    resultado = strcmp(palavra1, palavra2); // Compara "banana" e "laranja"
    if (resultado == 0) { printf("Iguais\n"); } // [cite: 77, 79]
    else if (resultado < 0) { printf("'%s' antes de '%s'\n", palavra1, palavra2); } 
    else { printf("'%s' depois de '%s'\n", palavra1, palavra2); }

    resultado = strcmp(palavra1, palavra3); // Compara "banana" e "banana"
    if (resultado == 0) { printf("'%s' e '%s' sao iguais.\n", palavra1, palavra3); }
    return 0;
}


