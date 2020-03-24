#include <stdio.h>
int main()
{
    int n = 0, l = 1, c = 1, i = 0, t = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d %d", &l, &c);
        t += l*c;
    }
    printf("%d\n", t);

return 0;
}