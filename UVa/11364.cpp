#include <bits/stdc++.h>
using namespace std;

int main(){
	int t, num, izq, der, N;
	scanf("%d", &t);
	while(t--){
		izq = 102;
		der = -1;
		scanf("%d", &N);
		while(N--){
			scanf("%d", &num);
			if(num>der)
				der = num;
			if(num<izq)
				izq = num;
		}
		printf("%d\n", 2*(der-izq));
	}
	return 0;
}
