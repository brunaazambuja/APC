#include <stdio.h>
int main()
{
  int a, num1;
  scanf("%d", &a);
  if (a >= 0){
    while (1){
      num1 = a%10;
      a = a/10;
      printf("%d", num1);
      if(a <= 0)
        break;
      }
      printf("\n");
    }
    if (a < 0){
      a = -a;
      printf("-");
        while (1){
          num1 = a%10;
          a = a/10;
          printf("%d", num1);
          if (a <= 0)
            break;
        }
        printf("\n");
      }
return 0;
}
