#include <stdio.h>
int main()
{
    double rs = 0, rp = 0, ri, srp = 0, media = 0, maior;
    int i = 0;
    for (i = 0; i < 6; i++){
        scanf("%lf", &ri);
        if (i == 0){
            maior = ri;
        }
        rs += ri;
        srp += ri;
        if (ri > maior)
            maior = ri;
    }
    rp = 1/srp;
    media = rs/6;
    printf("%.4lf %.4lf %.4lf\n", rs, rp, (maior - media));

return 0;
}