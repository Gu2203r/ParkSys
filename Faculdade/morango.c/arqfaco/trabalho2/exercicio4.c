#include <stdio.h>

int main() {
    int x[7] = {0, 1, 3, 4, 6, 9, 11};
    int y[7] = {1, 3, 6, 9, 11, 13, 15};
    int soma_x = 0, soma_y = 0;

    for (int i = 0; i < 7; i++) {
        soma_x += x[i];
        soma_y += y[i];
    }

    printf("Soma dos elementos de x: %d\n", soma_x);
    printf("Soma dos elementos de y: %d\n", soma_y);

    return 0;
}
