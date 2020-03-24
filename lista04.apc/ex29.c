#include <stdio.h>
int main()
{
    //soma dos lugares d * ((abaixo da diagonal principal))
    int a[10][10], i, j, soma = 0;
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            scanf("%d", &a[i][j]);
        }
    }   
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if (j <= i)
                soma += a[i][j];
        }
    }
    printf("%d\n", soma);


return 0;
}