#include <bits/stdc++.h>
using namespace std;

bool primero(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first < b.first;
}

int main() {
	int n;
	vector<int> data(10);

	cin >> n;
	int mini = 1 << 30;
	for (int i = 0; i < 9; ++i)
		cin >> data[i], mini = min(mini, data[i]);

	int len = n/mini;
	if (!len)
		cout << -1;

	while (len) {
		for (int i = 8; i >= 0; --i)
			if (data[i] <= n && (n - data[i])/mini == len - 1) {
				cout << i + 1;
				n -= data[i];
				--len;
				break;
			}
	}

	return 0;
}
