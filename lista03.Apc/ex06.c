#include <stdio.h>

int main()
{
    int a, i;
    float s = 0;
    scanf("%d", &a);
    for(i=1; a>= 0; i++){
      s += a;
      scanf("%d", &a);
    }
    if(s == 0) {
      printf("0\n");
    }
    else {
    printf("%.0f\n", s);
    printf("%.1f\n", (s/(i-1)));
    }

return 0;
}
