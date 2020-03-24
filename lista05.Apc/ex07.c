#include <stdio.h>

int conferir_contagem(int *my_hand){
    int contador = 0, i;
    for (i = 1; i < 5; i++){
        if (my_hand[i-1] < my_hand[i])
            contador++;
    }
    return contador;
}

void corrigir_contagem(int *my_hand){
	int contador, i, aux;
    while (contador){
        contador = 0;
        for (i = 1; i < 5; i++){
            if (my_hand[i] < my_hand[i-1]){
                aux = my_hand[i];
                my_hand[i] = my_hand[i-1];
                my_hand[i-1] = aux;
                contador = 1;
            }
        }
    }
}
	
int main(){
	int i, mao[5];
	for(i=0; i<5; ++i)
		scanf("%d", &mao[i]);

	if(conferir_contagem(mao) == 4)printf("Contagem Correta\n");
	else{
		printf("Contagem Incorreta\n");
		printf("Sequencia certa: ");
		corrigir_contagem(mao);
		for(i=0; i<5; ++i)
			printf("%d%c", mao[i], ((i==4)? '\n' : ' '));
	}

 return 0;
}
