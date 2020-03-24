#include <stdio.h>
#include <math.h>
int main()
{
    int a[121], i;
    float soma = 0, media;
    for (i = 0; i < 121; i++){
        scanf("%d", &a[i]);
        soma += a[i];
    }
    media = soma/121;
    for (i = 0; i < 121; i++){
        printf("%.1f ", pow((media - a[i]), 2));
    }

return 0;
}


    float a[500], b[500] = {0.5};
    int i, j = 0;
    for (i = 0; i < 500; i++){
        scanf("%f", &a[i]);
    }
    b[0] = a[0];
    for (i = 1; i < 500; i++){
        for (j = 1; j < 500; j++){
            if (a[i] != b[j]){
                b[j] = a[i];
                break;
            }
        }
    }
    for (j = 0; j < 500; j++){
        if (b[j] == 0.5)
            break;
        printf("%.0f ", b[j]);
    }
    