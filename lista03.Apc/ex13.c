#include <stdio.h>
int main()
{
    int n, i = 1;
    scanf("%d", &n);
    for (i = 1; i <= 10; i++){
        printf("%dx%d=%d\n", n, i, i*n);
    }
return 0;
}