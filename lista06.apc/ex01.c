#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char title[100];
    double orc;
    int id;
    int gen;
    int ano;
    int dur;
    int i = 0;
    FILE *fp;
    fp = fopen("locadora.dat", "w");
    if (fp == NULL){
        fp = fopen("locadora.dat", "w");
    }
    while (1){
        i++;
        scanf("%s", title);
        if (strcmp(title, "FIM")==0)
            break;
            else {
                scanf("%lf%d%d%d%d", &orc, &id, &gen, &ano, &dur);
                fprintf(fp, "%d %s %.0lf %d %d %d %d\n", i, title, orc, id, gen, ano, dur);
                //printf("%d %s %.0lf %d %d %d %d", i, title, orc, id, gen, ano, dur);
            }
    }
    fclose(fp);

return 0;
} 