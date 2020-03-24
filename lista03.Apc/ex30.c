#include <stdio.h>
#include <math.h>

int main()
{
    int b, a, c, d = 0, i;
    scanf("%d %d", &a, &b);
    for (i = 0; a > 0; i++){
        if (a%10 >= b)
            c = 1;
        d += pow(b,i)*(a%10);
        a = a/10;
    }
    if (c == 1)
        printf("ERROR\n");
        else 
            printf("%d\n", d);

return 0;
}