#include <stdio.h>
int main()
{
    // soma da cruz e quadrantes
    int a[7][7], i, j, cruz = 0, soma = 0;
    int q1 = 0, q2 = 0, q3 = 0, q4 = 0;
    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 7; i++){
        cruz += a[i][3];
        cruz += a[3][i];
    }
    cruz -= a[3][3];
    for (i = 0; i < 7; i++){
        for (j = 0; j < 7; j++){
            if (i > 3 && j > 3)
                q1 += a[i][j];
                else if (i > 3 && j < 3)
                    q2 += a[i][j];
                    else if (i < 3 && j > 3)
                        q3 += a[i][j];
                        else if (i < 3 && j < 3)
                            q4 += a[i][j];
        }
    }
    if (q1 > cruz)
        soma += q1;
    if (q2 > cruz)
        soma += q2;
    if (q3 > cruz)
        soma += q3;
    if (q4 > cruz)
        soma += q4;
    printf("%d\n", soma);


return 0;
}