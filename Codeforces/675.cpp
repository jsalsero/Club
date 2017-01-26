#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

int main() {
	Long a, b, c;
	cin >> a >> b >> c;

	if ((b < a && c > 0) || (a < b && c < 0))
		cout << "NO" << endl;
	else if (c == 0)
		cout << (a == b? "YES": "NO") << endl;
	else {
		Long x = (b - a)/c;
		cout << (a + x*c == b? "YES": "NO") << endl;
	}
	return 0;
}

// a + xc = b
// x = b - a  /  c