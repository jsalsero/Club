#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	while(N--){
		char cad[10];
		scanf("%s", &cad);
		if( strlen(cad) == 5)
			printf("3\n");
		else{
			int cont = 0;

			if( cad[0] == 'o') cont++;
			if( cad[1] == 'n') cont++;
			if( cad[2] == 'e') cont++;

			if(cont>=2) 
				printf("1\n");
			else
				printf("2\n");
		}

	}
	return 0;
}
