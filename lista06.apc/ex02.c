#include <stdio.h>
typedef struct {
    char title[100];
    double orc;
    int id;
    int gen;
    int ano;
    int dur;
} film;

int main(){
    int cont = 0, j, i, anoaux;
    double orc;
    int mo;
    int id;
    int mi;
    int ano;
    int ma;
    int dur;
    int md;
    film filme[500];
    FILE *fp;
    fp = fopen("locadora.dat", "r");
    if (fp == NULL){
        fp = fopen("locadora.dat", "r");
    }
    while (fscanf(fp, "%d%s%lf%d%d%d%d", &i, filme[i].title, &filme[i].orc, &filme[i].id, &filme[i].gen, &filme[i].ano, &filme[i].dur) != EOF){
    }
    while (1){
        anoaux = ano;
        scanf("%d", &ano);
        if (ano < 0){
            ano = anoaux;
            break;
        }
        scanf("%d%d%d%lf%d%d%d", &ma, &id, &mi, &orc, &mo, &dur, &md);
    }
    for (j = 0; j < i; j++){
        cont = 0;
        switch(ma){
            case 1:{
                if (filme[j].ano >= ano) cont++;
                break;
            }
            case 2:{
                if (filme[j].ano <= ano) cont++;
                break;
            }
            case 3:{
                if (filme[j].ano != ano) cont++;
                break;
            }
            case 4:{
                if (filme[j].ano == ano) cont++;
                break;
            }
        }
        switch(mi){
            case 1:{
                if (filme[j].id >= id) cont++;
                break;
            }
            case 2:{
                if (filme[j].id <= id) cont++;
                break;
            }
            case 3:{
                if (filme[j].id != id) cont++;
                break;
            }
            case 4:{
                if (filme[j].id == id) cont++;
                break;
            }
        }
        switch(mo){
            case 1:{
                if (filme[j].orc >= orc) cont++;
                break;
            }
            case 2:{
                if (filme[j].orc <= orc) cont++;
                break;
            }
            case 3:{
                if (filme[j].orc != orc) cont++;
                break;
            }
            case 4:{
                if (filme[j].orc == orc) cont++;
                break;
            }
        }
        switch(md){
            case 1:{
                if (filme[j].dur >= dur) cont++;
                break;
            }
            case 2:{
                if (filme[j].dur <= dur) cont++;
                break;
            }
            case 3:{
                if (filme[j].dur != dur) cont++;
                break;
            }
            case 4:{
                if (filme[j].dur == dur) cont++;
                break;
            }
        }
        if (cont == 0){
            printf("%s\n", filme[j].title);
        }
    }

return 0;
}