#include <stdio.h>
int main()
{
    int t, n, i = 0;
    float classe, idade, parceiros, filhos, sexoN = 0, portoN = 0;
    float classeS = 0, idadeS = 0, parceirosS = 0, filhosS = 0, sexoNS = 0, portoNS = 0;
    char sexo, porto;
    scanf("%d\n%d", &t, &n);
    for (i = 0; i < n; i++){
            scanf("%f %c %f %f %f %c\n", &classe, &sexo, &idade, &parceiros, &filhos, &porto);
            if (sexo == 'm'){
                sexoN = 0;
            }
                else if (sexo == 'f'){
                    sexoN = 1;
                }
            if (porto == 'S'){
                portoN = 0;
            }
                else if (porto == 'C'){
                    portoN = 1;
                }
                    else if (porto == 'Q'){
                        portoN = 2;
                    }
    if (t == 0){
        printf("%.1f %.1f %.1f %.1f %.1f %.1f\n", classe, sexoN, idade, parceiros, filhos, portoN);
        }
        else if (t == 1){
                if ((idade > 15 && idade <= 45) || (classe > 1 && sexoN == 1))
                    printf("Morreu\n");
                    else 
                        printf("Sobreviveu\n");
        }
            if (t == 2){
                    classeS += classe;
                    sexoNS += sexoN;
                    idadeS += idade;
                    parceirosS += parceiros;
                    filhosS += filhos;
                    portoNS += portoN;
            }
    }
    if (t == 2){
        printf("%.3f %.3f %.3f %.3f %.3f %.3f\n", (classeS/n), (sexoNS/n), (idadeS/n), (parceirosS/n), (filhosS/n), (portoNS/n));
    }
return 0;
}