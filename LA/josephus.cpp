#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,d,res;
	while(true){
		cin >> n >> d;
		if(n == 0 && d == 0)
			return 0;
		res = 0;
		for (int i=1; i<=n; i++)
			res = (res+d) % i;
		cout << n << " " << d << " "<< res + 1 << "\n";
	}
	return 0;
}