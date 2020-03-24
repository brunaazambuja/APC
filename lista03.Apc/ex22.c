#include <stdio.h>
int main ()
{
   int t, i, kma, kme = 1;
   double d = 0, fa = 0, fe = 9999999, th;
   for(i = 0; i < 10; i++){
        scanf("%d %lf", &t, &d);
        if (d <= 5000)
            th = 0.015;
        if (d > 5000 && d < 15000)
            th = 0.035;
        if (d >= 15000)
            th = 0.047;
        d = d*th;
        if (d > fa){
            fa = d;
            kma = t;
        }
        if (d < fe){
            fe = d;
            kme = t;
        }
   }
        printf("%d %.2lf %d %.2lf\n", kma, fa, kme, fe);
return 0;
}