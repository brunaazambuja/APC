#include <stdio.h>
int main()
{
    int t = 1, i = 0, total = 0, penalidade = 0;
    int menor = 0, maior = 0, x = 0, p = 0;
    do {
        scanf("%d", &t);
        if (t == 0)
            break;
        else if(t < 0){
            penalidade = t;
        }
        else{
            t -= penalidade;
            penalidade = 0;
            if (i == 0){
                maior = t;
                menor = maior;
                }
            if (t > maior){
                i++;
                total += t;
                maior = t;
                x = i;
            }
            else if (t < menor){
                i++;
                total += t;
                menor = t;
                p = i;
            }
            else {
                i++;
                total += t;
            }
        }
    }while (t != 0);
    printf("Melhor volta: %d - %d seg\n", p, menor);
    printf("Pior volta: %d - %d seg\n", x, maior);
    printf("Tempo total: %d seg\n", total);

return 0;
}