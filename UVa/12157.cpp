#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, N, num, mile, juice, c=1;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		mile = 0;
		juice = 0;
		for(int i=0; i<N; i++){
			scanf("%d", &num);
			mile += (1 + (num/30) ) * 10;
			juice+= (1 + (num/60) ) * 15;
		}
		if(mile<juice)
			printf("Case %d: Mile %d\n", c++, mile);
		else if(mile>juice)
			printf("Case %d: Juice %d\n", c++, juice);
		else
			printf("Case %d: Mile Juice %d\n", c++, juice);
	}
	return 0;
}
