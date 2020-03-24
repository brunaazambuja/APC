#include <stdio.h>
int main()
{
    long int a;
    scanf("%ld", &a);
    if (a == 0 || a == 1 || a == 2 || a == 3 || a == 5 || a ==  13 || a == 89 || a == 233){
            printf("SIM\n");
    }
        else{
            printf("NAO\n");
        }

return 0;
}