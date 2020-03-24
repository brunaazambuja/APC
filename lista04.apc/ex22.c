#include <stdio.h>
int main()
{
    int a[7][7], i, j, diagonal = 0;
    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            if (j == i){
                diagonal += a[i][j];
            }
        }
    }
    printf("%d\n", diagonal);

    
return 0;
}