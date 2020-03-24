#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define cols 6
#define verbose 0

int main()
{
    // LER OS VALORES;
    int Ntrain, Nteste, i, j, k;
    scanf("%d", &Ntrain);
    scanf("%d", &Nteste);
    double train[Ntrain][cols], teste[Nteste][cols], indicestrain[Ntrain];
    double classe, idade, parceiros, filhos, sexoN, portoN;
    char sexo, porto;
    int classemortos[3] = {0}, classevivos[3] = {0};
    int sexovivos[2] = {0}, sexomortos[2] = {0}, idadevivos[100] = {0}, idademortos[100] = {0};
    int parceirosmortos[10] = {0}, parceirosvivos[10] = {0}, paismortos[10] = {0}, paisvivos[10] = {0};
    int portomortos[3] = {0}, portovivos[3] = {0}, vivos[128] = {0}, mortos[128] = {0};
    int hist[128] = {0};

    for (i = 0; i < Ntrain; i++){
        scanf("%lf %c %lf %lf %lf %c", &classe, &sexo, &idade, &parceiros, &filhos, &porto);
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
        train[i][0] = classe;
        train[i][1] = sexoN;
        train[i][2] = idade;
        train[i][3] = parceiros;
        train[i][4] = filhos;
        train[i][5] = portoN;
    }
    if (verbose){
        printf("matriz train\n");
        for (i = 0; i < Ntrain; i++){
            for (j = 0; j < cols; j++){
                printf("%.0lf ", train[i][j]);
            }
            printf("\n");
        }
    }
    for (i = 0; i < Ntrain; i++){
        scanf("%lf", &indicestrain[i]);
    }
    if (verbose){
        printf("vetor indices\n");
        for (i = 0; i < Ntrain; i++){
            printf("%.0lf ", indicestrain[i]);
        }
        printf("\n");
    }
    for (i = 0; i < Nteste; i++){
        scanf("%lf %c %lf %lf %lf %c", &classe, &sexo, &idade, &parceiros, &filhos, &porto);
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
        teste[i][0] = classe;
        teste[i][1] = sexoN;
        teste[i][2] = idade;
        teste[i][3] = parceiros;
        teste[i][4] = filhos;
        teste[i][5] = portoN;
    }
    if (verbose){
        printf("matriz teste\n");
        for (i = 0; i < Nteste; i++){
            for (j = 0; j < cols; j++){
                printf("%.0lf ", teste[i][j]);
            }
            printf("\n");
        }
    }
    for(i = 0; i < Ntrain; i++){
            if (indicestrain[i] == 1){
                j = train[i][0] - 1;
                classevivos[j]++;
            }
                else if (indicestrain[i] == 0){
                    j = train[i][0] - 1;
                    classemortos[j]++;
                }
    }
    for(i = 0; i < Ntrain; i++){
            if (indicestrain[i] == 1){
                j = train[i][1];
                sexovivos[j]++;
            }
                else if (indicestrain[i] == 0){
                    j = train[i][1];
                    sexomortos[j]++;
                }
    }
    for(i = 0; i < Ntrain; i++){
            if (indicestrain[i] == 1){
                j = train[i][2];
                idadevivos[j]++;
            }
                else if (indicestrain[i] == 0){
                    j = train[i][2];
                    idademortos[j]++;
                }
    }
    for(i = 0; i < Ntrain; i++){
            if (indicestrain[i] == 1){
                j = train[i][3];
                parceirosvivos[j]++;
            }
                else if (indicestrain[i] == 0){
                    j = train[i][3];
                    parceirosmortos[j]++;
                }
    }
    for(i = 0; i < Ntrain; i++){
            if (indicestrain[i] == 1){
                j = train[i][4];
                paisvivos[j]++;
            }
                else if (indicestrain[i] == 0){
                    j = train[i][4];
                    paismortos[j]++;
                }
    }

    for(i = 0; i < Ntrain; i++){
            if (indicestrain[i] == 1){
                j = train[i][5];
                portovivos[j]++;
            }
                else if (indicestrain[i] == 0){
                    j = train[i][5];
                    portomortos[j]++;
                }
    }
    for(i = 0; i < Ntrain; i++){
            if (indicestrain[i] == 1){
                for (j = 0; j < 128; j++){
                    if (j < 3) vivos[j] = classevivos[j];
                    if (j >= 3 && j < 5) vivos[j] = sexovivos[j-3];
                    if (j >= 5 && j < 105) vivos[j] = idadevivos[j-5];
                    if (j >= 105 && j < 115) vivos[j] = parceirosvivos[j - 105];
                    if (j >= 115 && j < 125) vivos[j] = paisvivos[j - 115];
                    if (j >= 125 && j < 128) vivos[j] = portovivos[j - 125];
                }
            }
                else if (indicestrain[i] == 0){
                    for (j = 0; j < 128; j++){
                        if (j < 3) mortos[j] = classemortos[j];
                        if (j >= 3 && j < 5) mortos[j] = sexomortos[j-3];
                        if (j >= 5 && j < 105) mortos[j] = idademortos[j-5];
                        if (j >= 105 && j < 115) mortos[j] = parceirosmortos[j - 105];
                        if (j >= 115 && j < 125) mortos[j] = paismortos[j - 115];
                        if (j >= 125 && j < 128) mortos[j] = portomortos[j - 125];
                    }
                }
        }
    // histograma mortos e vivos;
    for (i = 0; i < 128; i++){
        if (vivos[i] > mortos[i]){
            hist[i] = 1;
        }
            else if (mortos[i] > vivos[i]){
                hist[i] = -1;
            }
                else 
                hist[i] = 0;
    }
    if (verbose){
        for (i = 0; i < 128; i++){
            printf("%d ", hist[i]);
        }
        printf("\n");
    }
    int* a = calloc(Nteste, sizeof(int));
    // CALCULANDO O PRODUTO INTERNO ENTRE TESTE[][] E O HIST[];  
    if (verbose) {
        printf("matriz a zerada (produto interno de cada linha nteste)\n");
        for (i = 0; i < Nteste; i++){
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    int negativo = 0, positivo = 0;
    // ======================================== 
    /*for (i = 0; i < Nteste; i++){
        negativo = 0;
        positivo = 0;
        for (j = 0; j < cols; j++){
            for (l = 0; l < 128; l++){
                if (l < 3) k = teste[i][j];
                if (l >= 3 && l < 5) k = teste[i][j+3];
                if (l >= 5 && l < 105) k = teste[i][j+5];
                if (l >= 105 && l < 115) k = teste[i][j+105];
                if (l >= 115 && l < 125) k = teste[i][j+115];
                if (l >= 125 && l < 128) k = teste[i][j+125];
                if (teste[i][j]*hist[k] > 0)
                    positivo++;
                    else if (teste[i][j]*hist[k] < 0)
                        negativo++;
        }
        a[i] = positivo - negativo;
    }
    for (i = 0; i < Nteste; i++){
            else if (a[i] > 0)
                a[i] = 1;
                else
                    a[i] = 0;
    }

    for (i = 0; i < Nteste; i++){
        printf("%d ", a[i]);
    }*/
    // =======================================
    for (i = 0; i < Nteste; i++){
        for (j = 0; j < cols; j++){
            for (l = 0; l < 128; l++){
                if (l < 3) k = teste[i][j];
                if (l >= 3 && l < 5) k = teste[i][j+3];
                if (l >= 5 && l < 105) k = teste[i][j+5];
                if (l >= 105 && l < 115) k = teste[i][j+105];
                if (l >= 115 && l < 125) k = teste[i][j+115];
                if (l >= 125 && l < 128) k = teste[i][j+125];
                a[i] += teste[i][j]*hist[k];
            }
        }
    }
    for (i = 0; i < Nteste; i++){
            else if (a[i] > 0)
                a[i] = 1;
                else
                    a[i] = 0;
    }

    for (i = 0; i < Nteste; i++){
        printf("%d ", a[i]);
    }

return 0;
}