#include <stdio.h>
int main(){
    
    int senhacorreta = 123456;
    
    printf("Digite a senha: ");
    scanf("%d", &senhacorreta);

    if (senhacorreta == 123456){
        printf("Senha correta!\n");
    } else {
        printf("Senha incorreta!\n");
    }   
    while( senhacorreta != 123456){
        printf("Digite a senha: ");
        scanf("%d", &senhacorreta);
        if (senhacorreta == 123456){
            printf("Senha correta!\n");
        } else {
            printf("Senha incorreta!\n");
        }
    }
    printf("Acesso permitido!\n");
    return 0;
}