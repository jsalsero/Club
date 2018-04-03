#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	int n;

	cin >> n;
	cout << 2*(n/7) + (n % 7 == 6) 
		 << ' ' 
		 << min(2, n) + 2*((n - 2)/7) + ((n - 2) % 7 == 6) 
		 << endl;
	
	return 0;
}
