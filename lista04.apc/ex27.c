#include <stdio.h>
int main()
{
    //matriz com elementos subtraidos pelo menor da linha
    int a[15][5], i, j, menor = 0, b[15][5];
    //para scanear
    for (i = 0; i < 15; i++){
        for (j = 0; j < 5; j++){
            scanf("%d", &a[i][j]);
        }
    }
    //para subtrair
    for (i = 0; i < 15; i++){
        for (j = 0; j < 5; j++){
            if (j == 0)
                menor = a[i][j];
                else if (a[i][j] < menor)
                    menor = a[i][j];
        }
        for (j = 0; j < 5; j++){
            b[i][j] = a[i][j] - menor;
        }
    }
    //para imprimir
    for (i = 0; i < 15; i++){
        for (j = 0; j < 5; j++){
            printf("%02d ", b[i][j]);
        }
        printf("\n");
    }


return 0;
}