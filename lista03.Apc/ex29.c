#include <stdio.h>
int main()
{
    long int n, f = 1, k;
    int i = 0, primo = 0;
    scanf("%ld", &n);
    while (n < 0){
        scanf("%ld", &n);
    }
    if (n < 3)
        printf("NENHUM PRIMO\n");
    for (i = n; i > 0; i--){
        f *= i;
    }
    for (i = 2; i <= f; i++){
        primo = 0;
        for (k = 2; k < i; k++){
            if (i%k == 0)
                primo++;
        }
        if (primo == 0){
            printf("%d ", i);
        }
    }
    printf("\n");

return 0;
}