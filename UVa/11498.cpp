#include <bits/stdc++.h>
using namespace std;

int main(){
	int K, n,m,x,y;
	while(1){
		scanf("%d",&K);
		if(!K) return 0;
		scanf("%d%d", &n, &m);
		while(K--){
			scanf("%d%d", &x, &y);
			if(x==n || y==m)
				printf("divisa\n");
			else{
				if(x>n && y>m) printf("NE\n");
				else if(x>n && y<m) printf("SE\n");
				else if(x<n && y>m) printf("NO\n");
				else printf("SO\n");
			}
		}
	}
	return 0;
}
/*
3
2 1
10 10
-10 1
0 33
4
-1000 -1000
-1000 -1000
0 0
-2000 -10000
-999 -1001
0

*/
