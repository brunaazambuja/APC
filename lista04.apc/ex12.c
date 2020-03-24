#include <stdio.h>
int main()
{
    // na diferença de x e y, imprime os numeros com repetiçao
    int n[20], i, contador = 0, j, n_[20], y[10], c = 0;
    //scanear
    for (i = 0; i < 20; i++){
        scanf("%d", &n[i]);
        n_[i] = n[i];
        if (i > 9){
            y[i - 10] = n[i];
        }
    }
    //imprimir todos juntos sem rep
    for (i = 0; i < 20; i++){
        for (j = 0; j <= i; j++){
            if (n[i] == n[j]){
                contador++;
            }
        }
        if (contador == 1){
            printf("%d ", n[i]);
        }
        contador = 0;
    }
    printf("\n");
    //imprimir os de x que nao tem em y
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if (n[i] == y[j]){
                contador++;
            }
        }
        for (j = 0; j <= i; j++){
            if (n[i] == n_[j]){
                c++;
            }
        }
        if (contador == 0 && c == 1){
            printf("%d ", n[i]);
        }
        contador = 0;
        c = 0;
    }
    printf("\n");
    //imprimir os em comum ((aqui no ex1 nao imprime o -9, o 1o))
    for (i = 0; i < 10; i++){
        for (j = 0; j < 10; j++){
            if (n[i] == y[j]){
                contador++;
                if (contador == 1)
                    printf("%d ", n[i]);
            }
        }
        contador = 0;
    }
    printf("\n");


return 0;
}