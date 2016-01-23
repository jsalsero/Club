#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, actual, num, top, low, c=1;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		scanf("%d", &actual);		
		top = 0;
		low = 0;
		for(int i=1; i<N; i++){
			scanf("%d", &num);
			if(num>actual)
				top++;
			else if(num<actual)
				low++;
			actual = num;
		}
		printf("Case %d: %d %d\n", c++, top, low);
	}
	return 0;
}
