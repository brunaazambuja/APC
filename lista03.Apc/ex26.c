#include <stdio.h>
int main()
{
    int i;
    double a, t = 0, l, tf = 0;
    for (i = 0; i < 12; i++){
        scanf("%lf", &a);
        t += a;
        tf += a;
        if (t >= 10000)
            t = (t*1.0225);
            else 
                t = (t*1.0175);
    }
    l = t - tf;
    printf("%.2lf\n", l);

return 0;
}