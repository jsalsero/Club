#include <bits/stdc++.h>
using namespace std;

int main(){
	int meses, deprec, index;
	double pago, coche, deuda, anterior, tasa, down_payment;
	double tasas[107];

	while(1){
		fill(tasas, tasas+101, -1.0);
		scanf("%d %lf %lf %d", &meses, &down_payment, &coche, &deprec);		
		if(meses<0)
			return 0;
		for(int i=0; i<deprec; i++){
			scanf("%d %lf", &index, &tasa);
			tasas[index] = tasa;
		}
		pago = coche/meses;
		deuda = coche;		
		coche = coche + down_payment;

		anterior = 1.0 - tasas[0];
		coche = coche*anterior;

		if(coche>deuda){
			printf("0 months\n");
		} else{
			for(int i=1; i<=meses; i++){
				if(tasas[i] != -1.0)
					anterior = 1.0 - tasas[i];
				if(coche>deuda){
					if(i>2)
						printf("%d months\n", i-1);
					else
						printf("1 month\n");				
					deuda = -1;
					break;
				}
				coche = coche*anterior;
				deuda -= pago;
			}
			if(deuda != -1)
				printf("%d months\n", meses);
		}
	}
	return 0;
}
/*
30 500.0 15000.0 3
0 .10
1 .03
3 .002
12 500.0 9999.99 2
0 .05
2 .1
60 2400.0 30000.0 3
0 .2
1 .05
12 .025
-99 0 17000 1

*/
