#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	while( scanf("%d %d", &a, &b) ){
		if(a==-1 && b==-1)
			return 0;
		printf("%d\n", min( abs(a - b), min( abs(100 - a + b), abs(100 - b + a)) ) );
	}
	return 0;
}
