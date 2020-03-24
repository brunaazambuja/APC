#include <stdio.h>
int main()
{
    int a[200], i;
    for (i = 1; i <= 200; i++){
        scanf("%d", &a[i]);
    }
    for (i = 200; i >= 1; i--){
        printf("%d ", a[i]);
    }
    printf("\n");
return 0;
}