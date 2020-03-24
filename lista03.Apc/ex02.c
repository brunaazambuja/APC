#include <stdio.h>

int main()
{
    int i = 0, h = 0, nh = 0;
    for (i = 0; i < 30; i++) {
        scanf("%d", &h);
        nh += h;
    }
    printf("%d\n", nh);
return 0;
}
        
