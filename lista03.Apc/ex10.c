#include <stdio.h>
int main()
{
	double s = 1, sn = 0, t = 0, d = 0;
	while ( s >= 0 ){
		scanf("%lf", &s);
		if ( s < 0){
			break;
		} else if ( s < 500 && s >= 0) {
			sn = (s*15)/100;			
		} else if ( s >= 500 && s <= 1000 ){
			sn = (s*10)/100;
		} else {
				sn = (s*5)/100;
		}
			d = sn + s;
			t += sn;
		printf("%.2lf ", d);
	}
	printf ("\n%.2lf\n", t);
return 0;
	}