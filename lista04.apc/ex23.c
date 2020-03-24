#include <stdio.h>
int main()
{
    int a[4][5], b[4][5], i, j, c[4][5] = {0};
    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            scanf("%d", &b[i][j]);
        }
    }
    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
return 0;
}