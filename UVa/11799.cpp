#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, max, num, c=1;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		scanf("%d", &max);
		for(int i=1; i<N; i++){
			scanf("%d", &num);
			if(max<num)	
				max = num;
		}			
		printf("Case %d: %d\n", c++, max);
	}
	return 0;
}
