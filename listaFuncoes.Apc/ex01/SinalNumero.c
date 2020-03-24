#include <stdio.h>

int sinal(int n)
{
	int m;
	if (n > 0)
		m = 1;
	if (n < 0)
		m = -1;
	if (n == 0)
		m = 0;
	return m;
}