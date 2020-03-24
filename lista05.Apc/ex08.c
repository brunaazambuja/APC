#include <stdio.h>
#include <math.h>
typedef struct xy {
    int x, y;
} xy;
typedef struct Triangle {
    xy a, b, c;
} t;

/*int verificar(struct Triangle t){
    double d;
    d = (t.a.x*t.b.y + t.a.y*t.c.x + t.b.x*t.c.y) - (t.c.x*t.b.y + t.a.x*t.c.y + t.a.y*t.b.x);
    printf("%d\n", d);
    if (d != 0)
        return 1;
        else 
            return 0;
}*/

//Nao altere essa função
double area(struct Triangle t){
	return 0.5*fabs(t.a.x*(t.b.y-t.c.y) + t.b.x*(t.c.y-t.a.y) + t.c.x*(t.a.y-t.b.y));
}
int main(){
	/*inicio da area editavel */

    t my_tri;

    scanf("%d %d", &my_tri.a.x, &my_tri.a.y);
    scanf("%d %d", &my_tri.b.x, &my_tri.b.y);
    scanf("%d %d", &my_tri.c.x, &my_tri.c.y);

	/*fim da area editavel */
	double resp  = area(my_tri);
	if(!resp)printf("Nao e um triangulo\n");
	else printf("A area do triangulo e %.2lf\n", resp);
 return 0;
}
