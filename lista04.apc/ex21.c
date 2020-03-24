#include <stdio.h>
int main()
{
    int a[4][5], i, j, maior = 0, l, c;
    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            scanf("%d", &a[i][j]);
            maior = a[0][0];
        }
    }
    for (i = 0; i < 4; i++){
        for (j = 0; j < 5; j++){
            if (a[i][j] > maior){
                maior = a[i][j];
                l = i;
                c = j;
            }
        }
    }
    printf("%d %d %d\n", maior, l, c);

return 0;
}