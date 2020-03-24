#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	char title[100];
	double orc;
	int idx;
	int id;
	int gen,ano,dur;
}filme;
int main(){
	filme filme[100];
	int indice = 0, i = 1, aux, f;
	char title[100];
	double orc;
	int id,gen,ano,dur;
	FILE *fp;
	fp = fopen("locadora.dat","r");

	while (1){
		fscanf (fp,"%d %s %lf %d %d %d %d ",&filme[i].idx,filme[i].title,&filme[i].orc,&filme[i].id,&filme[i].gen,&filme[i].ano,&filme[i].dur);
		if (filme[i].idx == NULL)
            break;
		printf ("%d %s %lf %d %d %d %d\n",filme[i].idx,filme[i].title,filme[i].orc,filme[i].id,filme[i].gen,filme[i].ano,filme[i].dur);
		i++;
	}
	printf ("\n");
	while (1){
	    aux = 1;
	    fclose (fp);
	    fp = fopen ("locadora.dat","w");
	    while (indice > i || aux == 1){
	    	scanf("%d",&indice);
	    	aux = 0;
	    }
	    if (indice < 1)
            break;
	    while ((indice+1) <= i){
	    	filme[indice].idx = filme[indice+1].idx;
	    	strcpy(filme[indice].title, filme[indice+1].title);
	    	filme[indice].dur = filme[indice+1].dur;
	    	filme[indice].gen = filme[indice+1].gen;
	    	filme[indice].ano = filme[indice+1].ano;
	    	filme[indice].orc = filme[indice+1].orc;
	    	filme[indice].id = filme[indice+1].id;
	    	indice++;
	    }
	    fclose (fp);
	    fp =fopen ("locadora.dat","r");
	    i = 1;
	    while (1){
	    	fprintf (fp,"%d %s %lf %d %d %d %d ",filme[i].idx,filme[i].title,filme[i].orc,filme[i].id,filme[i].gen,filme[i].ano,filme[i].dur);
	    	if (filme[i].idx == NULL)
                break;
	    	printf ("%d %s %lf %d %d %d %d\n",filme[i].idx,filme[i].title,filme[i].orc,filme[i].id,filme[i].gen,filme[i].ano,filme[i].dur);
	    	i++;	
	    }
    }
    f = i;
    i = 1;
    while (1){
    	if (i == f)
            break;
    	fprintf (fp,"%d %s %lf %d %d %d %d\n",filme[i].idx,filme[i].title,filme[i].orc,filme[i].id,filme[i].gen,filme[i].ano,filme[i].dur);
    	printf ("%d %s %lf %d %d %d %d\n",filme[i].idx,filme[i].title,filme[i].orc,filme[i].id,filme[i].gen,filme[i].ano,filme[i].dur);
    	i++;
    }
	return 0;
}