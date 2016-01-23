#include <bits/stdc++.h>
using namespace std;

int main(){
	int inicio, n1,n2,n3, res;
	while(1){
		scanf("%d %d %d %d", &inicio, &n1, &n2, &n3);
		if(inicio==0 && n1==0 && n2==0 && n3==0)
			return 0;
		res = 1080;

		if(n1>inicio)
			res += (40 + inicio - n1)*9;
		else
			res += (inicio - n1)*9;

		if(n2<n1)
			res += (40 - n1 + n2)*9;
		else
			res += (n2 - n1)*9;

		if(n3>n2)
			res += (40 + n2 - n3)*9;
		else
			res += (n2 - n3)*9;

		printf("%d\n", res);
	}
	return 0;
}
