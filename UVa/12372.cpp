#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, l, w, h, caso=1;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &l, &w, &h);
		(l>20 || w>20 || h>20) ? printf("Case %d: bad\n", caso++) :	printf("Case %d: good\n", caso++);
	}
	return 0;	
}
