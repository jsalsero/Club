#include <bits/stdc++.h>
using namespace std;

int cri[1000007];

void criba(int max){
	fill(cri , cri+max, 0);
    
    for(int i = 2; i*i <= max; ++i) {
        if(cri[i]==0) {
        	cri[i]++;
            for(int h = 2; i*h <= max; ++h){
                cri[i*h]++;
            }
        }
    }
}

int main(){
	criba(1000000);
	int n;
	while(1){
		scanf("%d", &n);
		if(!n)
			break;
		printf("%d : %d\n", n, cri[n]);
	}
	return 0;
}
/*
289384
930887
692778
636916
747794
238336
885387
760493
516650
641422
0

*/
