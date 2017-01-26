#include <bits/stdc++.h>
using namespace std;

#define UP(i)		data[i % n].second < data[(i + 1) % n].second
#define LEFT(i)		data[i % n].first  > data[(i + 1) % n].first
#define RIGHT(i)	data[i % n].first  < data[(i + 1) % n].first
#define DOWN(i)		data[i % n].second > data[(i + 1) % n].second

int main() {
	int n;

	cin >> n;
	vector< pair<int, int> > data(n + 1);
	for (int i = 0; i < n + 1; ++i)
		cin >> data[i].first >> data[i].second;

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (RIGHT(i) && UP(i + 1))		ans++;
		if (UP(i) && LEFT(i + 1))		ans++;
		if (DOWN(i) && RIGHT(i + 1))	ans++;
		if (LEFT(i) && DOWN(i + 1))		ans++;
	}

	cout << ans;
	return 0;
}