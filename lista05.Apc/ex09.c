#include <stdio.h>
#include <math.h>

//suas structs
typedef struct ponto {
    int x, y;
} ponto;
//cálculo da distância (pode ser modificado para suas structs)
double distance(struct ponto a,struct ponto b){
    //printf("%lf\n", hypot(a.x-b.x,a.y-b.y));
	return hypot(a.x-b.x,a.y-b.y);
}

int main(){
    double raioA, raioB, raioC, k, l, j;
    ponto c, torreA, torreB, torreC; 
    scanf("%d %d", &c.x, &c.y);
    scanf("%lf %d %d", &raioA, &torreA.x, &torreA.y);
    scanf("%lf %d %d", &raioB, &torreB.x, &torreB.y);
    scanf("%lf %d %d", &raioC, &torreC.x, &torreC.y);
    k = distance(torreA, c);
    l = distance(torreB, c);
    j = distance(torreC, c); 
    if (k <= raioA && l <= raioB && j <= raioC)
        printf("Celular encontrado\n");
        else
            printf("Nao foi possivel encontrar\n");

 return 0;
}
