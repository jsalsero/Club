#include <bits/stdc++.h>
using namespace std;

int main() {
	int i,r,n, caso = 1;
	bool flag;

	while(1) {
		cin >> r >> n;
		if(n == 0 && r == 0)
			break;	
		flag = false;
		
		for(int i = 1; i <=27; i++) {
			if( n*i >= r) {
				cout << "Case " << caso++ << ": " << i - 1 << "\n";
				flag = true;
				break;
			}
		}

		if(!flag)
			cout << "Case " << caso++ << ": impossible\n";
	}
	return 0;
}
