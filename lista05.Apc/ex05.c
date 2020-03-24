#include <stdio.h>
#include <string.h>
typedef struct brinq {
    char brinquedo[50];
} brinq;
int main(){
    int n, i, t, j, l;
    brinq aux;
    strcpy(aux.brinquedo, " ");
    scanf("%d", &n);
    brinq vetor[n];
    for (i = 0; i < n; i++){
        scanf("%s", vetor[i].brinquedo);
    }
    scanf("%d", &t);
    for (j = 0; j < t; j++){
        scanf("%d %d", &i, &l);
        strcpy(aux.brinquedo,vetor[i].brinquedo);
        strcpy(vetor[i].brinquedo, vetor[l].brinquedo);
        strcpy(vetor[l].brinquedo, aux.brinquedo);
    }
    for (i = 0; i < n; i++){
        printf("%s \n", vetor[i].brinquedo);
    }
    
    return 0;
}