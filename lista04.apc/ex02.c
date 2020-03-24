#include <stdio.h>
int main()
{
    int a[300] = {0}, i;
    for (i = 0; i < 300;){
        scanf("%d", &a[i]);
        if (a[i] < 0)
            break;
            else 
                i++;
    }
    for (i = i - 1; i >= 0; i--){
        printf("%d ", a[i]);
    }
    printf("\n");

return 0;
}