#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main(){
	int t;
	lli a,b;
	scanf("%d", &t);
	while(t--){
		scanf("%lli%lli", &a, &b);
		if(a<b)
			printf("<\n");
		else if(a>b)
			printf(">\n");
		else
			printf("=\n");
	}
	return 0;
}
