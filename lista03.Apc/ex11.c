#include <stdio.h>
int main()
{
    int n = 0, a = 0, maior = 0, menor = 0, i = 1;
    scanf("%d", &n);
    scanf("%d", &a);
    maior = a;
    menor = maior;
    for (i = 1; i < n; i++){
        scanf("%d", &a);
        if (a  > maior){
            maior = a;
        }
        if (a < menor){
            menor = a;
        }
    }
    printf("Menor: %d\n", menor);
    printf("Maior: %d\n", maior);

return 0;
}