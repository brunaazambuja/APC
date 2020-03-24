#include <stdio.h>

int main() 
{
    int i = 0, n = 0, g = 0;
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        g += i;
    }
    printf("%d\n", g);
return 0;
}
