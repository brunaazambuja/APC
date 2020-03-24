#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define cols 6
#define verbose 0

// caso 2 (caso teste 1) - deu certo
// caso 8 (caso teste 7) - deu certo
// caso 14 (caso teste 13) - deu certo
// caso 20 (caso teste 19) - deu certo

int kvizinhos (int ntrain, int nteste, double Train[][cols], double indicesTrain[], double Teste[][cols], int K){
    FILE* fp;
    fp = fopen("teste", "w");
    double Wf[nteste][ntrain];
    int If[nteste][ntrain];
    double Aux = 0, Aux2 = 0;
    int Sobv = 0, Mortos = 0;
    int i, j, k;
    // inicializando a matriz de indices;
    for (i = 0; i < nteste; i++){
            for (j = 0; j < ntrain; j++){
                If[i][j] = j;
            }
        }
        if (verbose){
            printf("matriz indices nao organizada\n");
            for (i = 0; i < nteste; i++){
                for (j = 0; j < ntrain; j++){
                    printf("%d ", If[i][j]);
                }
                printf("\n");
            }
        }
        // inicializando a matriz W
        for (i = 0; i < nteste; i++){
            for (j = 0; j < ntrain; j++){
                Wf[i][j] = 0;
            }
        }
        if (verbose){
            printf("matriz W zerada\n");
            for (i = 0; i < nteste; i++){
                for (j = 0; j < ntrain; j++){
                    printf("%.0lf ", Wf[i][j]);
                }
                printf("\n");
            }
        }
        // calcular DEuclidiana e botar na matriz W
        for (i = 0; i < nteste; i++){
            for (j = 0; j < ntrain; j++){
                for (k = 0; k < cols; k++){
                    Wf[i][j] += (Teste[i][k] - Train[j][k])*(Teste[i][k] - Train[j][k]);
                }
                Wf[i][j] = sqrt(Wf[i][j]);
            }
        }
        if (verbose){
            printf("matriz W nao organizada\n");
	        for (i = 0; i < nteste; i++){
                for (k = 0; k < ntrain; k++){
                    printf("%.4lf ", Wf[i][k]);
                }
                printf("\n");
            }
        }
        // Insertion sort;
        for (k = 0; k < nteste; k++){
            for (i = 1; i < ntrain; i++){
                Aux = Wf[k][i];
                Aux2 = If[k][i];
                j = i -1;
                while ((j >= 0) && (Wf[k][j] > Aux)){
                    Wf[k][j+1] = Wf[k][j];
                    If[k][j+1] = If[k][j];
                    j--;
                }
                Wf[k][j+1] = Aux;
                If[k][j+1] = Aux2;
            }
        }
        if (verbose){
            printf("matriz W organizada\n");
            for (k = 0; k < nteste; k++){
                for (i = 0; i < ntrain; i++){
                    printf("%lf ", Wf[k][i]);
                }
                printf("\n");
            }
            printf("matriz I organizada\n");
            for (k = 0; k < nteste; k++){
                for (i = 0; i < ntrain; i++){
                    printf("%d ", If[k][i]);
                }
                printf("\n");
            }
        }
        for (i = 0; i < nteste; i++){
            Mortos = 0;
            Sobv = 0;
            for (j = 0; j < K; j++){
                if (indicesTrain[If[i][j]] == 0){
                    Mortos++;
                }
                    else
                        Sobv++;
            }
            if (Mortos < Sobv)
                fprintf(fp, "1\n");
                else
                    fprintf(fp, "0\n");
        }
        fclose(fp);
return 0;
}
int normalize_data(int ntrain, int nteste, double Train[][cols], double indicesTrain[], double Teste[][cols]){
    double soma[cols], media[cols], desvio[cols];
    double variancia = 0;
    int j, i;
    // para inicializar os vetores com zero;
    for (i = 0; i < cols; i++){
            media[i] = 0;
            soma[i] = 0;
            desvio[i] = 0;
        }
        if (verbose){
            printf("soma[i] zerado\n");
            for (i = 0; i < cols; i++){
                printf("%.1lf ", soma[i]);
            }
            printf("\n");
            printf("media[i] zerado\n");
            for (i = 0; i < cols; i++){
                printf("%.1lf ", media[i]);
            }
            printf("\n");
            printf("desvio[i] zerado\n");
            for (i = 0; i < cols; i++){
                printf("%.1lf ", desvio[i]);
            }
            printf("\n");
        }
        // calcular media;
        for (i = 0; i < cols; i++){
            for (j = 0; j < ntrain; j++){
                soma[i] += Train[j][i];
            }
            media[i] = soma[i]/ntrain;
        }
        if (verbose){
            printf("media[i]\n");
            for (i = 0; i < cols; i++){
                printf("%.2lf ", media[i]);
            }
            printf("\n");
        }
        for (i = 0; i < cols; i++){
            soma[i] = 0;
        }
        // calcular desvio padrao;
        for (i = 0; i < cols; i++){
            variancia = 0;
            for (j = 0; j < ntrain; j++){
                variancia += (Train[j][i] - media[i])*(Train[j][i] - media[i]);
            }
            variancia = variancia/ntrain;
            desvio[i] = sqrt(variancia);
        }
        if (verbose){
            printf("desvio[i]\n");
            for (i = 0; i < cols; i++){
                printf("%lf ", desvio[i]);
            }
            printf("\n");
        }
        // NORMALIZAR OS VALORES;
        for (i = 0; i < cols; i++){
            for (j = 0; j < ntrain; j++){
                Train[j][i] = (Train[j][i] - media[i])/desvio[i];
            }
        }
        for (i = 0; i < cols; i++){
            for (j = 0; j < nteste; j++){
                Teste[j][i] = (Teste[j][i] - media[i])/desvio[i];
            }
        }
        if (verbose){
            printf("matriz teste normalizada\n");
            for (i = 0; i < nteste; i++){
                for (j = 0; j < cols; j++){
                    printf("%lf ", Teste[i][j]);
                }
                printf("\n");
            }
        }
return 0;
}

int main(){
    int T, Ntrain, Nteste, i, j, k;

    scanf("%d", &T);    
    scanf("%d", &Ntrain);
    scanf("%d", &Nteste);

    double train[Ntrain][cols], teste[Nteste][cols], indicestrain[Ntrain];
    double classe, idade, parceiros, filhos, sexoN, portoN;
    char sexo, porto;
    int negativo = 0, positivo = 0;
    int* a = calloc(Nteste, sizeof(int));

    int classemortos[3] = {0}, classevivos[3] = {0};
    int sexovivos[2] = {0}, sexomortos[2] = {0}, idadevivos[100] = {0}, idademortos[100] = {0};
    int parceirosmortos[10] = {0}, parceirosvivos[10] = {0}, paismortos[10] = {0}, paisvivos[10] = {0};
    int portomortos[3] = {0}, portovivos[3] = {0}, vivosarray[128] = {0}, mortosarray[128] = {0};
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
    

    // histograma;
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
                    if (j < 3) vivosarray[j] = classevivos[j];
                    if (j >= 3 && j < 5) vivosarray[j] = sexovivos[j-3];
                    if (j >= 5 && j < 105) vivosarray[j] = idadevivos[j-5];
                    if (j >= 105 && j < 115) vivosarray[j] = parceirosvivos[j - 105];
                    if (j >= 115 && j < 125) vivosarray[j] = paisvivos[j - 115];
                    if (j >= 125 && j < 128) vivosarray[j] = portovivos[j - 125];
                }
            }
                else if (indicestrain[i] == 0){
                    for (j = 0; j < 128; j++){
                        if (j < 3) mortosarray[j] = classemortos[j];
                        if (j >= 3 && j < 5) mortosarray[j] = sexomortos[j-3];
                        if (j >= 5 && j < 105) mortosarray[j] = idademortos[j-5];
                        if (j >= 105 && j < 115) mortosarray[j] = parceirosmortos[j - 105];
                        if (j >= 115 && j < 125) mortosarray[j] = paismortos[j - 115];
                        if (j >= 125 && j < 128) mortosarray[j] = portomortos[j - 125];
                    }
                }
        }
    for (i = 0; i < 128; i++){
        if (vivosarray[i] > mortosarray[i]){
            hist[i] = 1;
        }
            else if (mortosarray[i] > vivosarray[i]){
                hist[i] = -1;
            }
                else 
                hist[i] = 0;
    }
    FILE* fp;
    fp = fopen("teste", "w");
    // deu certo
    // TAREFA 0 ---------------------------------------------------------------
    if (T == 0){
        for (i = 0; i < Nteste; i++){
            if ((teste[i][2] > 15 && teste[i][2] <= 45) || (teste[i][1] == 1 && teste[i][0] > 1))
                fprintf(fp, "0\n");
                else
                    fprintf(fp, "1\n");
        }
    }
    // deu certo
    // TAREFA 1 --------------------------------------------------------------
    if (T == 1){

        for (i = 0; i < Nteste; i++){
            negativo = 0;
            positivo = 0;
            for (j = 0; j < cols; j++){
                if (j == 0) k = teste[i][j] - 1;
                if (j == 1) k = teste[i][j] + 3;
                if (j == 2) k = teste[i][j] + 5;
                if (j == 3) k = teste[i][j] + 105;
                if (j == 4) k = teste[i][j] + 115;
                if (j == 5) k = teste[i][j] + 125;
                if (hist[k] > 0)
                    positivo++;
                    else if (hist[k] < 0)
                        negativo++;
            }
            a[i] = positivo - negativo;
        }
        for (i = 0; i < Nteste; i++){
                if (a[i] > 0)
                    a[i] = 1;
                    else
                        a[i] = 0;
        }

        for (i = 0; i < Nteste; i++){
            fprintf(fp, "%d\n", a[i]);

        }

    }
    // nao deu certo +-
    // TAREFA 2 ----------------------------------------------------------
    if (T == 2){
    // KVIZINHOS SEM NORMALIZAR K = 1;
        kvizinhos (Ntrain, Nteste, train, indicestrain, teste, 1);
    }
    // deu certo +-
    // TAREFA 3 ----------------------------------------------------------
    if (T == 3){
    // KVIZINHOS SEM NORMALIZAR K = 13;
        kvizinhos (Ntrain, Nteste, train, indicestrain, teste, 11);
    }
    // TAREFA 4 ----------------------------------------------------------
    if (T == 4){
    // KVIZINHOS NORMALIZADO K = 1;
        normalize_data(Ntrain, Nteste, train, indicestrain, teste);
        kvizinhos (Ntrain, Nteste, train, indicestrain, teste, 1);
    }
    // deu certo
    // TAREFA 5 ---------------------------------------------------
    if (T == 5){
    //KVIZINHOS NORMALIZADO K = 13;
        normalize_data(Ntrain, Nteste, train, indicestrain, teste);
        kvizinhos (Ntrain, Nteste, train, indicestrain, teste, 11);
    }
    fclose(fp);

return 0;
}
