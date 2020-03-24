#include <stdio.h>
int main()
{
    int i = 0, a = 0, menor = 0, maior = 0;
    scanf("%d", &a);
    maior = a;
    menor = maior;
    for (i = 1; i < 20; i++){
        scanf("%d", &a);
        if (a < menor)
            menor = a;
        else if (a > maior)
            maior = a;
    }
    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);

return 0;
}