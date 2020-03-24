#include <stdio.h>

int main()
{
    int i = 0, n = 0, fatorial = 1;
    scanf("%d", &n); 
    if (n < 0) {
        printf("nao existe\n");
    }
    else if (n > 0){
        for (i = 1; i <= n; i++) {
            fatorial *= i;
        }
        printf("%d\n", fatorial);
    }
    else {
        printf("1\n");
    }

return 0;
}
