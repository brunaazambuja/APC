#include <stdio.h>
int main()
{
    int a[8][8], i, j, diagonal = 0, soma = 0;
    int maior = 0, c = 0;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if (j == i){
                diagonal += a[i][j];
            }
        }
    }
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            soma += a[i][j];
        }
        for (j = 0; j < 8; j++){
            if (i == 0 && j == 0){
                    maior = soma%diagonal;
                    c = 0;
                }
                    else if (soma%diagonal > maior){
                        maior = soma%diagonal;
                        c = i;
                    }
        }
        soma = 0;
    }
    printf("%d\n", c);

    
return 0;
}