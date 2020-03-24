#include <stdio.h>
#include <stdlib.h>
#define MAX 9
int trocaDiagonal (int C[MAX][MAX]){
    int i, j, aux = 0;
    for (i = 0; i < MAX; i++){
        for (j = 0; j < MAX; j++){
            if (i == j){
                aux = C[i][j];
                C[i][j] = C[8 - j][j];
                C[8 - j][j] = aux;
            }
        }
    }
    return C[MAX][MAX];
}
int main()
{
  int M[MAX][MAX];
  int l, c;

  for(l=0;l<MAX;l++)
    for(c=0;c<MAX;c++)
       scanf("%d",&M[l][c]);

  trocaDiagonal(M);
  printf("\n");

  for(l=0;l<MAX;l++)
  {
    for(c=0;c<MAX;c++)
      printf("%d ",M[l][c]);
    printf("\n");
  }

  return 0;
}
