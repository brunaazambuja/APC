#include <stdio.h>
#include <math.h>
int main()
{
    int i;
    double x, y, sx = 0, sy = 0, p = 0, s2x = 0, s2y = 0, sxy = 0;
    for (i = 0; i < 10; i++){
        scanf("%lf %lf", &x, &y);
        sx += x;
        sy += y;
        s2x += pow(x, 2);
        s2y += pow(y,2);
        sxy += x*y;
    }
    p = ((10*sxy) - (sx*sy))/ (sqrt(10*s2x - (pow(sx, 2)))*sqrt(10*s2y - (pow(sy,2))));
    printf("%.2lf\n", p);


return 0;
}