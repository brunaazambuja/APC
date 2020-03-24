#include <stdio.h>
int main()
{
    int a[9][9], i, j, aux = 0;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            scanf("%d", &a[i][j]);
        }
    }   
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            if (i == j){
                aux = a[i][j];
                a[i][j] = a[8 - j][j];
                a[8 - j][j] = aux;
            }
        }
    }
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

return 0;
}