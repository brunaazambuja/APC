#include <stdio.h>
int main()
{
    int n, i, pA, pB, anos;
    float ga, gb;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d %f %f", &pA, &pB, &ga, &gb);
        for (anos = 0; pA < pB; anos++){
            pA += pA*ga/100;
            pB += pB*gb/100;
        }
        if (anos <= 100){
            printf("%d anos.\n", anos);
        }
            else{
                printf("Mais de 1 seculo.\n");
            }
    }

return 0;
}