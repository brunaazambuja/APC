#include <stdio.h>
#include <string.h>
int main()
{
    char a[100], b[100];
    int i, f = 0;
    gets(a);
    for(i = strlen(a) - 1; i >= 0; i--){
        b[f] = a[i];
        f++;
    }
    b[f] = '\0';
    puts(b);

return 0;
}