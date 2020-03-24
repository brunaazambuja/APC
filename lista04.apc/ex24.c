#include <stdio.h>
int main()
{
    int a[7][9], i, j;
    for (i = 0; i < 7; i++){
        for (j = 0; j < 9; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 9; i++){
        for (j = 0; j < 7; j++){
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }


return 0;
}