#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos, n, num, caso = 1;

	cin >> casos;
	while(casos--) {
		cin >> n;

		for(int i=0; i<n; i++) {
			cin>> num;
			if(i == (n/2) + 1)
				cout << "Case " << caso++ << ": " num << "\n";
		}
	}
	return 0;
}