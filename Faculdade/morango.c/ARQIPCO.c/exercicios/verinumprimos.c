#include <stdio.h>
#include <math.h>
int main(){
    int n = 0;
    int primo = 0;
    int i = 2;

    do {
        printf("Digite um valor para n:");
        scanf("%d", &n);    

        if(n < 2){
            printf("O número deve ser maior ou igual a 2.\n");
        }
        else {
            printf("%d é primo? ", n);
            for (i = 2; i <= sqrt(n); i++){
                if(n % i == 0){
                    primo = 1;
                    break;
                }
            }
            if(primo == 0){
                printf("Sim\n");
            } else {
                printf("Não\n");
            }
        }
        }while(n != 0);

        return 0;
    }
