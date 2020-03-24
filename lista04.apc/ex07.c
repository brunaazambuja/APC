#include <stdio.h>
int main()
{
    int a[135], li, ls, i;
    for (i = 0; i < 135; i++){
        scanf("%d", &a[i]);
    }
    do {
        scanf("%d %d", &li, &ls);
    } while (ls <= li);
    for (i = 0; i < 135; i++){
        if (a[i] < li || a[i] > ls){
            printf("%d ", a[i]);
        }
    }
    printf("\n");


return 0;
}