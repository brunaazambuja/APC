#include <stdio.h>
int main()
{
    // simetrica
    int a[9][9], i, j, c = 0;
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            if (a[i][j] == a[j][i]){
                c++;
            }
        }
    }
    if (c == 81)
        printf("S\n");
        else
            printf("N\n");

return 0;
}