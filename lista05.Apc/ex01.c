#include <stdio.h>
#include <string.h>
char* extraiSobrenome(char nome[30]){
    int i = 0;
    char *sobrenome;
    while (nome[i] != '_'){
        i++;
    }
    sobrenome = &nome[i+1];
    nome[i] = '\0'; 
    return sobrenome;
}

int main(){
    char nome[30];
    char *sobrenome;
    scanf("%s", nome);
    sobrenome = extraiSobrenome(nome);
    printf("Nome\n%s\nSobrenome\n%s\n",nome, sobrenome);
return 0;
}