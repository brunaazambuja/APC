#include <stdio.h>
int main()
{
    int t, i, da, db, x, anos, j = 0;
    float psa, psb, d, maior = 0;
    scanf("%d", &t);
    for(i = 1; i <= t; i++){
        scanf("%d %d %f %f %f", &da, &db, &psa, &psb, &d);
        for (anos = 0; da < db; anos++){
            da += da*psa/100;
            db += db*psb/100;
        }
        if (anos <= 100){
            printf("%d anos.\n", anos);
        }
            else{
                printf("Mais de 1 seculo.\n");
            }
        if (d > maior){
            maior = d;
            x = i;
        }
    }
    printf("Maior distancia: %.1f, par %d.\n", maior, x);


return 0;
}
