#include <stdio.h>
int main()
{
    float id = 0, op = 0, otimo = 0, bom = 0, soma = 0;
    float regular = 0, ruim = 0, pessimo = 0;
    float media = 0, n = 0;

    do {
        scanf("%f", &id);
        if (id >= 0){
            soma += id;
            n++;
            do {
                scanf("%f", &op);
            } while (op < 1 || op > 5);
            if (op == 1)
               otimo += 1;
            else if (op == 2)
                bom += 1;
            else if (op == 3)
                regular += 1;
            else if (op == 4)
                ruim += 1;
            else if (op == 5)
                pessimo += 1;
        }
    } while (id >= 0);
    media = soma/n;
    

    printf ("qtde de participantes: %.0f\n", n);
    printf ("idade media dos participantes: %.1f\n", media);
    printf ("Otimo: %.1f%%\n", (otimo*100)/n);
    printf ("Bom: %.1f%%\n", (bom*100)/n);
    printf ("Regular: %.1f%%\n", (regular*100)/n);
    printf ("Ruim: %.1f%%\n", (ruim*100)/n);
    printf ("Pessimo: %.1f%%\n", (pessimo*100)/n);

return 0;
}