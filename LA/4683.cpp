#include <bits/stdc++.h>
using namespace std;
#define MAX 2000

int T, n, k, num, arre[MAX];

void criba(int inicio){
	for (int i=inicio; i*i<=MAX; i++){
		if(arre[i]==0){
			for( int j=1; j*i<=MAX; j++){
				arre[i*j]++;
			}
		}
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d", &k, &n);
		fill(arre, arre+MAX, 0);
		for (int i=0; i<k; i++){
			scanf("%d", &num);
			criba(num);
		}
		for (int i=2; i<MAX; i++){
			if(arre[i]==1)
				n--;
			if(n==0){
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;	
}