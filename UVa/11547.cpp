#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, n;
	scanf("%d",&t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", abs(( ((n*63 + 7492)*5) - 498)/10)%10  );
	}
	return 0;
}
