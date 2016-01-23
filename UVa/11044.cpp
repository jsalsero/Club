#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n, m;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n", (1 + ((n - 1 - 2) / 3)) * (1 + ((m - 1 - 2) / 3)) );
	}
	return 0;
}
