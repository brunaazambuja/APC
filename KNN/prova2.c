#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define verbose 0
#define cols 4

int main(){
    int K, Ntrain, Nteste, i, j;
    scanf("%d", &K);
    scanf("%d", &Ntrain);
    scanf("%d", &Nteste);
    double train[Ntrain][cols], teste[Nteste][cols], indicestrain[Ntrain];
    int* sestosa = (int*)calloc(400, sizeof(int));
    int* versicolor = (int*)calloc(400, sizeof(int));
    int* virginia = (int*)calloc(400, sizeof(int));
    int* CS0 = (int*)calloc(Ntrain*10, sizeof(int));
    int* LS0 = (int*)calloc(Ntrain*10, sizeof(int));
    int* CP0 = (int*)calloc(Ntrain*10, sizeof(int));
    int* LP0 = (int*)calloc(Ntrain*10, sizeof(int));
    int* CS1 = (int*)calloc(Ntrain*10, sizeof(int));
    int* LS1 = (int*)calloc(Ntrain*10, sizeof(int));
    int* CP1 = (int*)calloc(Ntrain*10, sizeof(int));
    int* LP1 = (int*)calloc(Ntrain*10, sizeof(int));
    int* CS2 = (int*)calloc(Ntrain*10, sizeof(int));
    int* LS2 = (int*)calloc(Ntrain*10, sizeof(int));
    int* CP2 = (int*)calloc(Ntrain*10, sizeof(int));
    int* LP2 = (int*)calloc(Ntrain*10, sizeof(int));
    
    for (i = 0; i < Ntrain; i++){
        scanf("%lf %lf %lf %lf", &train[i][0], &train[i][1], &train[i][2], &train[i][3]);
    }
    // ==================================
    if (verbose){
        printf("matriz train\n");
        for (i = 0; i < Ntrain; i++){
            for (j = 0; j < cols; j++){
                printf("%.0lf ", train[i][j]);
            }
            printf("\n");
        }
    }
    // ==================================
    for (i = 0; i < Ntrain; i++){
        scanf("%lf", &indicestrain[i]);
    }
    // ===================================
    if (verbose){
        printf("vetor indices\n");
        for (i = 0; i < Ntrain; i++){
            printf("%.0lf ", indicestrain[i]);
        }
        printf("\n");
    }
    // ===================================
    for (i = 0; i < Ntrain; i++){
        scanf("%lf %lf %lf %lf", &teste[i][0], &teste[i][1], &teste[i][2], &teste[i][3]);
    }
    // ====================================
    if (verbose){
        printf("matriz teste\n");
        for (i = 0; i < Nteste; i++){
            for (j = 0; j < cols; j++){
                printf("%.0lf ", teste[i][j]);
            }
            printf("\n");
        }
    }
    // ===================================
    for (i = 0; i < Ntrain; i++){
        if (indicestrain[i] == 0){
            j = train[i][0]*10;
            CS0[j]++;
        }
            else if (indicestrain[i] == 1){
                j = train[i][0]*10;
                CS1[j]++;
            }
                else if (indicestrain[i] == 2){
                    j = train[i][0]*10;
                    CS2[j]++;
                }
    }
    for (i = 0; i < Ntrain; i++){
        if (indicestrain[i] == 0){
            j = train[i][1]*10;
            LS0[j]++;
        }
            else if (indicestrain[i] == 1){
                j = train[i][1]*10;
                LS1[j]++;
            }
                else if (indicestrain[i] == 2){
                    j = train[i][1]*10;
                    LS2[j]++;
                }
    }
    for (i = 0; i < Ntrain; i++){
        if (indicestrain[i] == 0){
            j = train[i][2]*10;
            CP0[j]++;
        }
            else if (indicestrain[i] == 1){
                j = train[i][2]*10;
                CP1[j]++;
            }
                else if (indicestrain[i] == 2){
                    j = train[i][2]*10;
                    CP2[j]++;
                }
    }
    for (i = 0; i < Ntrain; i++){
        if (indicestrain[i] == 0){
            j = train[i][3]*10;
            LP0[j]++;
        }
            else if (indicestrain[i] == 1){
                j = train[i][3]*10;
                LP1[j]++;
            }
                else if (indicestrain[i] == 2){
                    j = train[i][3]*10;
                    LP2[j]++;
                }
    }
    // ==================================
    for (i = 0; i < 400; i++){
            if (i < 100)
                sestosa[i] = CS0[i];
                else if (i >= 100 && i < 200)
                    sestosa[i] = LS0[i-100];
                    else if (i >= 200 && i < 300)
                        sestosa[i] = CP0[i-200];
                        else if (i >= 300 && i < 400)
                            sestosa[i] = LP0[i-300];
                if (i < 100)
                    versicolor[i] = CS1[i];
                    else if (i >= 100 && i < 200)
                        versicolor[i] = LS1[i-100];
                        else if (i >= 200 && i < 300)
                            versicolor[i] = CP1[i-200];
                            else if (i >= 300 && i < 400)
                                versicolor[i] = LP1[i-300];
                    if (i < 100)
                        virginia[i] = CS2[i];
                        else if (i >= 100 && i < 200)
                            virginia[i] = LS2[i-100];
                            else if (i >= 200 && i < 300)
                                virginia[i] = CP2[i-200];
                                else if (i >= 300 && i < 400)
                                    virginia[i] = LP2[i-300];
    }
    for (i = 0; i < 400; i++){
        printf("%d ", sestosa[i]);
    }
    printf("\n");
    for (i = 0; i < 400; i++){
        printf("%d ", versicolor[i]);
    }
    printf("\n");
    for (i = 0; i < 400; i++){
        printf("%d ", virginia[i]);
    }
    free(sestosa);
    free(versicolor);
    free(virginia);
    free(CS0);
    free(LS0);
    free(CP0);
    free(LP0);
    free(CS1);
    free(LS1);
    free(CP1);
    free(LP1);
    free(CS2);
    free(LS2);
    free(CP2);
    free(LP2);

return 0;
}