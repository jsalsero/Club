#include <bits/stdc++.h>
using namespace std;

int main(){
	int res, N, num, caso=1;
	while(scanf("%d", &N)){
		if(!N) return 0;
		res = 0;
		while(N--){
			scanf("%d", &num);			
			if(!num)
				res--;
			else
				res++;
		}
		printf("Case %d: %d\n", caso++, res);
	}
	return 0;
}
