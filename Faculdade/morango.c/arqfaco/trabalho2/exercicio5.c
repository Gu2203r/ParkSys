#include <stdio.h>

int main() {
    int t;
    int max_pessoas = 0;
    int horario_pico = 0;

    printf("Pessoas no parque (das 8h as 18h):\n");

    for (t = 0; t <= 10; t++) {
        int pessoas = -2 * t * t + 8 * t + 10;
        int hora = 8 + t;

        printf("%d:00 - %d pessoas\n", hora, pessoas);

        // Verifica se é o maior número de pessoas
        if (pessoas > max_pessoas) {
            max_pessoas = pessoas;
            horario_pico = hora;
        }
    }

    printf("\nHorario com mais pessoas: %d:00\n", horario_pico);
    printf("Total de pessoas nesse horario: %d\n", max_pessoas);

    return 0;
}
