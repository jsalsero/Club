#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

string solve(int n) {
	int a = 1 << 30, b = -1;
	for (int i = 0; n >= 7*i; ++i) {
		int aux = (n - 7*i)/4;
		if (4*aux + 7*i == n && i + aux < a + b)
			b = i, a = aux;
	}

	if (b == -1)
		return "-1";

	string ans = "";
	while (a-- > 0)
		ans += "4";
	while (b-- > 0)
		ans += "7";

	return ans;
}

int main() {
	int n;
	cin >> n;

	int resi = n % 4 + n % 7;

	if (n == 4 || n == 7)
		cout << n;
	else
		cout << solve(n) << endl;
	return 0;
}