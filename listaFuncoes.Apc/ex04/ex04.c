#include <stdio.h>
#include <math.h>
#include "raiz.h"

int main()
{
    float a, b, c, x1, x2;
    printf("insira os tres coeficientes de uma equacao do segundo grau\n");
    scanf("%f %f %f", &a, &b, &c);
    int d = raiz(a, b, c, &x1, &x2);
    
    if (d == 0) {
        printf("a equacao nao possui raizes reais\n");
    }
    else 
        if (d == 1) {
            printf("a equacao tem 1 raiz: %f\n", x1);
        }
    else
        if (d == 2) {
            printf("a equacao tem 2 raizes: %f e %f\n", x1, x2);
        }
        

return 0;
}
