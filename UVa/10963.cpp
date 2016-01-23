#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, W, y1, y2, flag, dist, c=1;
	scanf("%d", &T);
	while(T--){
		if(c > 1)
			printf("\n");
		scanf("%d", &W);
		scanf("%d%d", &y1, &y2);
		dist = y1-y2;
		flag = 0;
		W--;
		while(W--){
			scanf("%d%d", &y1, &y2);
			if(dist != (y1-y2))
				flag = 1;
		}
		(flag==0) ? printf("yes\n") : printf("no\n");
		c++;
	}
	return 0;
}
/*
2

5
2 1
0 -1
1 0
1 0
2 1

5
2 1
0 -1
1 0
1 0
2 1

*/
