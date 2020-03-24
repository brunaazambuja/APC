#include <stdio.h>
#include <string.h>
int main()
{
    char a[100], b[100];
    int i;
    gets(a);
    gets(b);
    if(strlen(a) == strlen(b)){
        for (i = 0; i < strlen(a); i++){
            printf("%c", a[i]);
            printf("%c", b[i]);
        }
    }
    if(strlen(a) > strlen(b)){
        for (i = 0; i < strlen(b); i++){
            printf("%c", a[i]);
            printf("%c", b[i]);
        }
        for (; i < strlen(a); i++){
            printf("%c", a[i]);
        }
    }
    if(strlen(a) < strlen(b)){
        for (i = 0; i < strlen(a); i++){
            printf("%c", a[i]);
            printf("%c", b[i]);
        }
        for (; i < strlen(b); i++){
            printf("%c", b[i]);
        }
    }
    printf("\n");
return 0;
}