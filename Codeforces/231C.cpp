#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	Long n, k;
	cin >> n >> k;
	vector<int> v(n, 0);
	for (int i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());

	Long sum = 0LL;
	int L = 0;
	pair<int,int> res(0, 0);

	for (int i = 0; i < n; ++i) {
		sum += (Long)v[i];
		while (sum + (Long)k < (Long)v[i] * (i - L + 1LL)) {
			sum -= (Long)v[L];
			L++;
		}
		if (res.first < i - L + 1) {
			res.first = i - L + 1;
			res.second = v[i];
		}
	}
	cout << res.first << " " << res.second << "\n";
	return 0;
}
