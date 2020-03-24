#include <stdio.h>
int main()
{
    long int n, soma = 0, i, a = 2, b = 7, c = 3;
    scanf("%ld", &n);
    if(n%3 == 0){
        for (i = 0; i < n; i++){
            if (i%3 == 0 || i == 0){
                soma += a;
                a = a*2;
            }
                else if (i%3 == 1){
                    soma += b;
                    b = b*3;
                }
                    else if (i%3 == 2){
                        soma += c;
                        c = c*4;
                    }
        }
    printf("%ld\n", soma);
    }
        else {
            printf("SEM SOMA\n");
        }

return 0;
}