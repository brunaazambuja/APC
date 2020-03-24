#include <stdio.h>
int main()
{
    // linha com maior soma
    int a[10][5], i, j, maior = 0, soma = 0, k = 0;
    for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 10; i++){
        for (j = 0; j < 5; j++){
            soma += a[i][j];
        }
        if (i == 0)
            maior = soma;
            else if (soma > maior){
                maior = soma;
                k = i;
            }
        soma = 0;
    }
    printf("%d\n", k);


return 0;
}