#include <bits/stdc++.h>
using namespace std;

int main(){
	int a[4], t, cont=1;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &a[0], &a[1], &a[2]);
		sort(a, a+3);
		printf("Case %d: %d\n", cont++,a[1]);
	}
	return 0;
}
