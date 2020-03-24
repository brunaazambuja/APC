#include <stdio.h>

int main()
{
  float c, f1, f2;
  scanf("%f %f", &f1, &f2);
  for(f1 = f1; f1 <= f2; f1++){
    c = (f1 - 32)*5/9;
    printf("%.0f F : %.1f C\n", f1, c);
  }

return 0;
}
