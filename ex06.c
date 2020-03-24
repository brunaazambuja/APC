#include <stdio.h>
#include <math.h>
#define m1 (ponto[j].Y-ponto[i].Y)/(ponto[j].X-ponto[i].X)
typedef struct {
	int X,Y;
	int indice;
}ponto;
int main (){
	ponto ponto[100];
	int i = 1, j = 1, c = 1;
	int aux;
	int IND;
	double resp=0;
	FILE *fp;
	fp = fopen ("pontos.dat","r");
	while (1){
		fscanf (fp,"%d %d %d",&ponto[i].indice,&ponto[i].X,&ponto[i].Y);
		if (ponto[i].indice == NULL)
			break;
		//printf ("%d %d %d",ponto[i].indice,ponto[i].X,ponto[i].Y);
		i++;

	}
	double menor[i];
	fclose (fp);
	aux = i;
	for (i = -1, j = -1; i > aux || j > aux || i < 0 || j < 0;){
	scanf ("%d %d", &i, &j);
	}
	for (c=1;c<aux;c++){
		if (c!= j && c!= i){
			menor[c] = m1*ponto[c].X -ponto[c].Y + (ponto[i].Y - m1*ponto[i].X);
			if (menor[c]<0)menor[c]*=-1;
				menor[c] = (menor[c]/hypot(m1,-1));
			//printf("%d %lf\n",c,menor[c]);
		}
	}
	resp = menor[1];
	for (c = 1; c < aux; c++){
		if (menor[c] < 0)
			menor[c] *= -1;
		if (resp > menor[c] && c != i && c != j){
			resp = menor[c];
			IND = c;
		}
	}
	printf ("%d\n",IND);
return 0;	
}