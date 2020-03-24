#include <stdio.h>
int main()
{
    int i = 0, l = 0, p = 0;
    float compra, venda, c = 0, v = 0;
    for (i = 0; i < 6; i++){
        scanf("%f %f", &compra, &venda);
        if (compra >= venda){
            p++;
        }
            else if (compra < venda){
                l++;
            }
        c += compra;
        v += venda;
    }
    printf("%.2f", ((v-c)/50000)*100);
    printf(" %d %d\n", l, p);
return 0;
}