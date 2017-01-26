#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	cin >> n;
	vector<int> data(n + 7);
	for (int i = 1; i <= n; ++i) {
		cin >> data[i];
		data[i] += data[i - 1];
	}

	if (data[n] != 0) {
		cout << "YES\n";
		cout << "1\n1 " << n << "\n";
		return 0;
	}

	int ans = -1;
	for (int i = 1; i <= n && ans == -1; ++i) {
		if (data[i] - data[i - 1] != 0 &&
			data[n] - data[i] != 0)
			ans = i;
	}

	if (ans == -1)
		cout << "NO\n";
	else {
		cout << "YES\n";
		cout << 2 << "\n";
		cout << 1 << ' ' << ans << "\n";
		cout << ans + 1 << ' ' << n << "\n";
	}
	return 0;
}
