#include <stdio.h>
int main()
{
    int n = 0, i = 0, v = 0, maior = 0;
    scanf("%d", &n);
    scanf("%d", &v);
    maior = v;
    for (i = 1; i < n; i++){
        scanf("%d", &v);
        if (v > maior)
            maior = v;
    }
    if (maior < 10){
        printf("1\n");
    }else if (maior >= 10 && maior < 20){
        printf("2\n");
    }else {
        printf("3\n");}

return 0;
}