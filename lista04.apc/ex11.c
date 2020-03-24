#include <stdio.h>
int main()
{
    int i, j, a[500], b[500], contador = 0, n;
    for (i = 0; i < 500; i++){
        scanf("%d", &n);
        a[i] = n;
        b[i] = n;
    }
    for (i = 0; i < 500; i++){
        for (j = 0; j <= i; j++){
            if (a[i] == b[j]){
                contador++;
            }
        }
        if (contador == 1){
            printf("%d ", a[i]);
        }
        contador = 0;
    }
            
    
return 0;
}