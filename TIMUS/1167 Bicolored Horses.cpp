#include <bits/stdc++.h>
using namespace std;

#define SAD(ini, fin) (white[fin]-white[ini])*(black[fin]-black[ini])
const int INF = 1<<30;
vector<int> data, white, black;
int n, k;

vector<vector<int>> memo(507, vector<int>(507, -1));
int dp(int idx, int remain) {
	int &table = memo[idx][remain];
	if (table != -1)	return table;
	if (!remain)		return table = (idx != n)? INF: 0;

	int ans = INF;
	for (int fin = idx; fin < n; ++fin)
		ans = min(ans, SAD(idx, fin + 1) + dp(fin + 1, remain - 1));
	return table = ans;
}

int main() {
	cin >> n >> k;
	data  = vector<int>(n);
	white = vector<int>(n + 5);
	black = vector<int>(n + 5);

	for (int i = 0; i < n; ++i) {
		cin >> data[i];
		data[i]? black[i + 1]++: white[i + 1]++;
		black[i + 1] += black[i];
		white[i + 1] += white[i];
	}

	cout << dp(0, k);
	return 0;
}