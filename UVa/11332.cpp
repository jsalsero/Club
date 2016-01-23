#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int suma(lli num){	
	if(num>9)
		return suma(suma(num/10) + num%10);
	return num;
}

int main(){
	lli n;
	while(1){
		scanf("%lli", &n);
		if(!n)
			return 0;
		printf("%d\n", suma(n));
	}
	return 0;
}
