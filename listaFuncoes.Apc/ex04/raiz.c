#include <stdio.h>
#include <math.h>

float raiz (float a, float b, float c, float *p, float *r)
{
    float delta = ((b*b) - (4*a*c));
     *p = ((-b+(sqrt(delta)))/(2*a));
     *r = ((-b-(sqrt(delta)))/(2*a));

   if (delta > 0) {
        return 2;
   }
    else 
        if (delta == 0) {
        return 1;
        }
    else {
        return 0;
    }
}
