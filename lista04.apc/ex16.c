#include <stdio.h>
#include <string.h>
int main()
{
    char a[109];
    int i;
    gets(a);
    for (i = 0; i < strlen(a); i++){
        if (a[i] == 'a'|| a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            printf("a");
        }
        else 
            printf("%c", a[i]);
    }
    printf("\n");
    for (i = 0; i < strlen(a); i++){
        if (a[i] == 'a'|| a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            printf("e");
        }
        else 
            printf("%c", a[i]);
    }
    printf("\n");
    for (i = 0; i < strlen(a); i++){
        if (a[i] == 'a'|| a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            printf("i");
        }
        else 
            printf("%c", a[i]);
    }
    printf("\n");
    for (i = 0; i < strlen(a); i++){
        if (a[i] == 'a'|| a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            printf("o");
        }
        else 
            printf("%c", a[i]);
    }
    printf("\n");
    for (i = 0; i < strlen(a); i++){
        if (a[i] == 'a'|| a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            printf("u");
        }
        else 
            printf("%c", a[i]);
    }
    printf("\n");

return 0;
}