#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, farmers, tam, animals, parametro, res;
	scanf("%d", &T);
	while(T--){
		res = 0;
		scanf("%d", &farmers);
		while(farmers--){
			scanf("%d%d%d", &tam, &animals, &parametro);
			res += tam*parametro;
		}
		printf("%d\n", res);
	}
	return 0;
}
