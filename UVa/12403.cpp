#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, num, res=0;
	char cad[10];
	
	scanf("%d", &T);
	while(T--){
		scanf("%s", &cad);
		if(cad[0] == 'd'){
			scanf("%d", &num);
			res += num;
		} else
			printf("%d\n", res);

	}
}