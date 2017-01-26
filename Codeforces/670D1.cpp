#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MID ((left + right)/2)
typedef long long Long;

bool valid(Long k, Long g, const vector<Long> &need, const vector<Long> &apo) {
	for (Long i = 0; i < need.size() && k >= 0; ++i)
		k -= max(g*need[i] - apo[i], 0LL);
	return k >= 0;
}

Long binary(Long k, const vector<Long> &need, const vector<Long> &apo) {
	Long  left = 0, ans = 0, right = 2000000000;
	while (left <= right) {
		if (valid(k, MID, need, apo))
			ans = MID, left = MID + 1;
		else
			right = MID - 1;
	}
	return ans;
}

int main() {
	Long n, k;

	cin >> n >> k;
	vector<Long> need(n), apo(n);
	for (Long i = 0; i < n; ++i)	cin >> need[i];
	for (Long i = 0; i < n; ++i)	cin >> apo[i];

	cout << binary(k, need, apo) << endl;

	return 0;
}
