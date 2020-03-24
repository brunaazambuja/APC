#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int i = 0, n;
    
    FILE *fp;
    fp = fopen("pontos.dat", "w");
    if (fp == NULL){
        fp = fopen("pontos.dat", "w");
    }
    scanf("%d", &n);
    int x[n], y[n];
    for (i = 0; i < n; i++){
        scanf("%d%d", &x[i], &y[i]);
        fprintf(fp, "%d %d %d\n", i+1, x[i], y[i]);
    }
    fclose(fp);

return 0;
} 