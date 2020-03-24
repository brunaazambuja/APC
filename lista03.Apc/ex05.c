#include <stdio.h>

int main ()
{
    double b, D, TJ;
    int T, a;
    scanf("%lf %lf %d", &D, &TJ, &T);
    for(a = 0; a < T; a++) {
        b = (D*TJ)/100;
        D = (b + D);
        printf("Rendimento no mes %d: %.2lf\n", a, b);
    }
    while(a == T) {
    printf("Saldo final do investimento: %.2lf\n", D);
    a++;
    }

return 0;
}
