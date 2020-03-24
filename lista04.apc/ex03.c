#include <stdio.h>
int main()
{
    int a[150], l, i;
    for (i = 0; i < 150; i++){
        scanf("%d", &a[i]);
    }
    scanf("%d", &l);
    for (i = 0; i < 150; i++){
        if (a[i] < l)
            printf("%d ", a[i]);
    }


return 0;
}