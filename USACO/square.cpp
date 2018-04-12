#include <bits/stdc++.h>
using namespace std;

int main(){
	int n = 100000001;

	int temp = sqrt(n);
	if( temp*temp == n )
		printf("yes\n");
	else
		printf("%d\n", temp);
	return 0;
}