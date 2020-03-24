#include <stdio.h>
int main()
{
    int a = 0, b = 0, i = 0;
    scanf("%d %d", &a, &b);
    for (i = 0; ; i++){
        a += 2;
        b += 3;
        if (a == b){
            printf("%d\n", i+1);
            break;
        }
    }

return 0;
}