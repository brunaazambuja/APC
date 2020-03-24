#include <stdio.h>
int main()
{
    int a[106], l, i, j, soma = 0;
    for (i = 0; i < 106;){
        scanf("%d", &a[i]);
        if (a[i] == 0)
            break;
            else
                i++;
    }
    scanf("%d", &l);
    for (j = 0; j < i; j++){
        if (a[j] <= l)
            soma += a[j];
    }
    printf("%d\n", soma);


return 0;
}