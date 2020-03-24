#include <stdio.h>
#include "SinalNumero.h"

int main()
{
	int n, m;
	scanf("%d",&n);
	sinal(n);
	m = sinal(n);
	if (m==1)
		printf("Numero Positivo\n");
	if (m==-1)
		printf("Numero Negativo\n");
	if (m==0)
		printf("Zero\n");
return 0;
}