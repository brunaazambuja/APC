#include <stdio.h>
int main()
{
    int a[87], l, i, j;
    for (i = 0; i < 87;){
        scanf("%d", &a[i]);
        if (a[i] == 0)
            break;
            else
                i++;
    }
    scanf("%d", &l);
    for (j = 0; j < i; j++){
        if (a[j] > l)
            printf("%d ", a[j]);
    }


return 0;
}