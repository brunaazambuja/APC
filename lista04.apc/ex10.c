#include <stdio.h>
#include <math.h>
int main()
{
    int a[28], i;
    float media = 0, soma = 0, d = 0;
    for (i = 0; i < 28; i++){
        scanf("%d", &a[i]);
        d += a[i];
    }
    media = d/28;
    for (i = 0; i < 28; i++){
        soma += pow((a[i] - media),2);
    }
    printf("%.1f\n", soma/28);
    printf("%.1f\n", sqrt(soma/28));




return 0;
}