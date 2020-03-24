#include <stdio.h>
#include <string.h>
int main()
{  
    char a[80];
    gets(a);
    printf("%ld\n", strlen(a));

return 0;
}