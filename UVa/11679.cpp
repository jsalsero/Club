#include <bits/stdc++.h>
using namespace std;

int main(){
	int B, N, d,c,v, flag;
	while(scanf("%d %d", &B, &N)){
		if(B==0 && N==0)   break;
		int bancos[B+7];
		for(int i=0; i<B; i++)
			scanf("%d", &bancos[i]);
		for(int i=0; i<N; i++){
			scanf("%d %d %d", &d, &c, &v);
			bancos[d-1] -= v;
			bancos[c-1] += v;
		}
		flag = 0;
		for(int i=0; i<B; i++){
			if(bancos[i]<0)
				flag = 1;
		}
		(flag) ? printf("N\n") : printf("S\n");
	}
	return 0;
}
/*
3  3
1  1  1
1  2  1
2  3  2
3  1  3
3  3
1  1  1
1  2  1
2  3  2
3  1  4
3  3
1  1  1
1  2  2
2  3  2
3  1  2
0  0

*/
