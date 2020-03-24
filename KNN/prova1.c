#include <stdio.h>
#define cols 7
int main(){
    int t, n, i, j, k;
    float classe, idade, parceiros, filhos, sexoN = 0, portoN = 0, ind = 0;
    char sexo, porto;
    int classemortos[3] = {0}, classevivos[3] = {0};
    int sexovivos[2] = {0}, sexomortos[2] = {0}, idadevivos[100] = {0}, idademortos[100] = {0};
    int parceirosmortos[10] = {0}, parceirosvivos[10] = {0}, paismortos[10] = {0}, paisvivos[10] = {0};
    int portomortos[3] = {0}, portovivos[3] = {0}, vivos[128] = {0}, mortos[128] = {0}, resultado[128] = {0};
    int hist[128] = {0};

    scanf("%d", &t);
    scanf("%d", &n);
    float train[n][cols];
    for (i = 0; i < n; i++){
        scanf("%f %c %f %f %f %c %f\n", &classe, &sexo, &idade, &parceiros, &filhos, &porto, &ind);
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
        train[i][6] = ind;
    }

    for(i = 0; i < n; i++){
            if (train[i][6] == 1){
                j = train[i][0] - 1;
                classevivos[j]++;
            }
                else if (train[i][6] == 0){
                    j = train[i][0] - 1;
                    classemortos[j]++;
                }
    }
    for(i = 0; i < n; i++){
            if (train[i][6] == 1){
                j = train[i][1];
                sexovivos[j]++;
            }
                else if (train[i][6] == 0){
                    j = train[i][1];
                    sexomortos[j]++;
                }
    }
    for(i = 0; i < n; i++){
            if (train[i][6] == 1){
                j = train[i][2];
                idadevivos[j]++;
            }
                else if (train[i][6] == 0){
                    j = train[i][2];
                    idademortos[j]++;
                }
    }
    for(i = 0; i < n; i++){
            if (train[i][6] == 1){
                j = train[i][3];
                parceirosvivos[j]++;
            }
                else if (train[i][6] == 0){
                    j = train[i][3];
                    parceirosmortos[j]++;
                }
    }
    for(i = 0; i < n; i++){
            if (train[i][6] == 1){
                j = train[i][4];
                paisvivos[j]++;
            }
                else if (train[i][6] == 0){
                    j = train[i][4];
                    paismortos[j]++;
                }
    }

    for(i = 0; i < n; i++){
            if (train[i][6] == 1){
                j = train[i][5];
                portovivos[j]++;
            }
                else if (train[i][6] == 0){
                    j = train[i][5];
                    portomortos[j]++;
                }
    }
    for(i = 0; i < n; i++){
            if (train[i][6] == 1){
                for (j = 0; j < 128; j++){
                    if (j < 3) vivos[j] = classevivos[j];
                    if (j >= 3 && j < 5) vivos[j] = sexovivos[j-3];
                    if (j >= 5 && j < 105) vivos[j] = idadevivos[j-5];
                    if (j >= 105 && j < 115) vivos[j] = parceirosvivos[j - 105];
                    if (j >= 115 && j < 125) vivos[j] = paisvivos[j - 115];
                    if (j >= 125 && j < 128) vivos[j] = portovivos[j - 125];
                }
            }
                else if (train[i][6] == 0){
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

    if (t == 0){
        for (i = 0; i < 3; i++){
            printf("%d ", classemortos[i]);
        }
        printf("\n");
        for (i = 0; i < 3; i++){
            printf("%d ", classevivos[i]);
        }
    }
    if (t == 1){
        for (i = 0; i < 2; i++){
            printf("%d ", sexomortos[i]);
        }
        printf("\n");
        for (i = 0; i < 2; i++){
            printf("%d ", sexovivos[i]);
        }
    }
    if (t == 2){
        for (i = 0; i < 100; i++){
            printf("%d ", idademortos[i]);
        }
        printf("\n");
        for (i = 0; i < 100; i++){
            printf("%d ", idadevivos[i]);
        }
    }
    if (t == 3){
        for (i = 0; i < 10; i++){
            printf("%d ", parceirosmortos[i]);
        }
        printf("\n");
        for (i = 0; i < 10; i++){
            printf("%d ", parceirosvivos[i]);
        }
    }
    if (t == 4){
        for (i = 0; i < 10; i++){
            printf("%d ", paismortos[i]);
        }
        printf("\n");
        for (i = 0; i < 10; i++){
            printf("%d ", paisvivos[i]);
        }
    }
    if (t == 5){
        for (i = 0; i < 3; i++){
            printf("%d ", portomortos[i]);
        }
        printf("\n");
        for (i = 0; i < 3; i++){
            printf("%d ", portovivos[i]);
        }
    }
    if (t == 6){
        for (i = 0; i < 128; i++){
            printf("%d ", mortos[i]);
        }
        printf("\n");
        for (i = 0; i < 128; i++){
            printf("%d ", vivos[i]);
        }
    }
    if (t == 7){
        for (i = 0; i < 128; i++){
            printf("%d ", hist[i]);
        }
    }

return 0;
}