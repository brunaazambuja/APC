#include <stdio.h>
int main()
{
    int a;
    do {
        scanf("%d", &a);
        if (a < 0)
            break;
        if (a%2 == 0){
        printf("%d: par\n", a);
        }
        else {
            printf("%d: impar\n", a);
        }
    } while (a >= 0);
return 0;
}   