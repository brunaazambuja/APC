#include <stdio.h>
#include <string.h>

typedef struct {
    int ind;
    char title[100];
    double orc;
    int id;
    int gen;
    int ano;
    int dur;
} film;

int main(){
    int i, n = 1, j, l;
    char title[100];
    double orc;
    int id;
    int gen;
    int ano;
    int dur;
    film filme[500];
    FILE *fp;
    fp = fopen("locadora.dat", "r");
    if (fp == NULL){
        fp = fopen("locadora.dat", "r");
    }
    while (fscanf(fp, "%d%s%lf%d%d%d%d", &filme[i].ind, filme[i].title, &filme[i].orc, &filme[i].id, &filme[i].gen, &filme[i].ano, &filme[i].dur) != EOF){
        i++;
    }
    for (j = 0; j < i; j++){
        printf("%d %s %.0lf %d %d %d %d\n", filme[j].ind, filme[j].title, filme[j].orc, filme[j].id, filme[j].gen, filme[j].ano, filme[j].dur);
    }
    while(n >= 1){
        scanf("%d", &n);
        if (n < 1)
            break;

        if (n > 0 && n <= i){
            scanf("%s%lf%d%d%d%d", title, &orc, &id, &gen, &ano, &dur);
            strcpy(filme[n-1].title, title);
            filme[n-1].orc = orc;
            filme[n-1].id = id;
            filme[n-1].gen = gen;
            filme[n-1].ano = ano;
            filme[n-1].dur = dur;
            for (j = 0; j < i; j++){
                printf("%d %s %.0lf %d %d %d %d\n", filme[j].ind, filme[j].title, filme[j].orc, filme[j].id, filme[j].gen, filme[j].ano, filme[j].dur);
            }
        }
    }

return 0;
}