#include <stdio.h>

int main() {
    double i = 0, a = 0, peso = 0;
    for (i = 0; i < 25; i++) {
        scanf("%lf", &a);
        peso += a;
    }
    printf("%.1lf\n", peso);
    
return 0;
}
