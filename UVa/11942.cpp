#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, num[13], flag, asc, des, actual;
	scanf("%d", &T);
	printf("Lumberjacks:\n");
	while(T--){
		for(int i=0; i<10; i++)
			scanf("%d",&num[i]);

		asc = 0;
		des = 0;

		actual = num[0];
		for(int i=1; i<10; i++){
			if(actual>num[i]){
				asc = 1;
				break;
			}
			actual = num[i];
		}

		actual = num[0];
		for(int i=1; i<10; i++){
			if(actual<num[i]){
				des = 1;
				break;
			}
			actual = num[i];
		}

		(asc == des) ? printf("Unordered\n") : printf("Ordered\n");
	}
	return 0;
}
