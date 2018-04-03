#include <bits/stdc++.h>
using namespace std;

bool is_lucky(int n) {
	bool lucky = true;
	while (n > 0 && lucky) {
		lucky = (n % 10 == 4 || n % 10 == 7);
		n /= 10;
	}
	return lucky;
}



int main() {
	int n;
	cin >> n;
	
	bool ans = is_lucky(n);
	for (int i = 4; i <= n && !ans; ++i) 
		if (is_lucky(i) && n % i == 0)
			ans = true;
	
	cout << (ans? "YES": "NO");
	return 0;
}

