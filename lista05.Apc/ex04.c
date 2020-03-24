#include <stdio.h>
#include <string.h>

typedef struct pessoa {
	int idade;
	char nome[50];
} Depessoas;

void ordena(Depessoas vetor[], int n){
	int i, ordenado = 0;
	Depessoas aux;

	aux.idade = 0;
	strcpy(aux.nome, "");

	while (ordenado == 0){
		ordenado = 1;
		for (i = 0; i < n-1; i++){
			if (vetor[i].idade < vetor[i + 1].idade){
				ordenado = 0;

				aux.idade = vetor[i].idade;
				strcpy(aux.nome, vetor[i].nome);

				vetor[i].idade = vetor[i + 1].idade;
				strcpy(vetor[i].nome, vetor[i + 1].nome);

				vetor[i + 1].idade = aux.idade;
				strcpy(vetor[i + 1].nome, aux.nome);
			}
		}
	}
}

int main(){
	int n, i;
	scanf("%d", &n);
	if (n < 1)
		return 0;
	Depessoas vetor[n];
	for (i = 0; i < n; i++){
		scanf("%s", vetor[i].nome);
		scanf("%d", &vetor[i].idade);
	}
	ordena(vetor, n);
	for (i = 0; i < n; i++)
		printf("%s\n", vetor[i].nome);
	return 0;
}
