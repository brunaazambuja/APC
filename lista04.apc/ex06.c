#include <stdio.h>
int main()
{
    int a[53], l, i, j, n = 0;
    float soma = 0;
    for (i = 0; i < 53; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &l);
    for (j = 0; j < i; j++){
        if (a[j] <= l){
            soma += a[j];
            n++;
        }
    }
    printf("%.1f\n", soma/n);


return 0;
}