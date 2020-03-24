#include <stdio.h>
#include "LePonto.h"
 int x;
 int y;
 
int main()
{
    LePonto();
    int x1 = x;
    int y1 = y;
    
    LePonto();
    
    if (x1 != x && y1 != y) {
        printf("o coeficiente angular da reta que passa pelos pontos e %d\n", ((y1 - y)/(x1 - x)));
    }
    else {
        printf("Erro, os pontos sao os mesmos. Tente novamente\n");
    }
return 0;
}
    
