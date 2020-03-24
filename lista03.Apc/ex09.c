#include <stdio.h>

int main()
{
    int q = 1;
    double pr, t = 0;
    while (q > 0){
        scanf("%d %lf", &q, &pr);
        if (q > 0){
            while (pr < 0) {
                scanf("%lf", &pr);
            }
        t += (pr*q);
        }
    }
    printf("%.2f\n", t);
return 0;
}
