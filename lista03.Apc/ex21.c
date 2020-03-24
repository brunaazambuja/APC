#include <stdio.h>
int main()
{    
int nv = 0, total = 0, melhor = 1821986291, pior, t = 0;
int i = 1, tempo2, x = 0, p = 0;
    scanf ("%d", &nv);
    pior = t;
    for (i = 1; i <= nv; i++){
        scanf("%d", &t);
            if (t == -1){
                scanf("%d", &tempo2);
                while (tempo2 < 0){
                    scanf("%d", &tempo2);
                }
                t = tempo2 + 10;
            }
            if (t == -2){
                scanf("%d", &tempo2);
                while (tempo2 < 0){
                    scanf("%d", &tempo2);
                }
                t = tempo2 + 25;
            }
            if (t == -3){
                scanf("%d", &tempo2);
                while (tempo2 < 0){
                    scanf("%d", &tempo2);
                }
                t = tempo2 + 40;
            }
            total += t;
            if (t < melhor){
                melhor = t;
                p = i;
            }
            if (t > pior){
                pior = t;
                x = i;
            }
        }
    printf ("Melhor volta: %d - %d seg\n", p, melhor);
    printf ("Pior volta: %d - %d seg\n", x, pior);
    printf ("Tempo total: %d seg\n", total);
    
return 0;
}