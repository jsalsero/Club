#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

struct hasher {
	int b = 10, m; vector<int> h, p;
	hasher(string s, int _m) : m(_m), h(s.size() + 7), p(s.size() + 7) {
		p[0] = 1, h[0] = 0;
		for (int i = 0; i < s.size(); ++i)	p[i + 1] = (Long)p[i] * b % m;
		for (int i = 0; i < s.size(); ++i)	h[i + 1] = ((Long)h[i] * b + (s[i] - '0')) % m;
	}

	int hash(int l, int r) {
		return (h[r + 1] + m - (Long)h[l] * p[r - l + 1] % m) % m;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string cad;
	int a, b;

	cin >> cad >> a >> b;
	hasher suffix(cad, a), prefix(cad, b);

	int ans = -1;
	for (int i = 0; i < cad.size() - 1 && ans == -1; ++i) {
		if (cad[i + 1] == '0')
			continue;
		if (suffix.hash(0, i) == 0 && prefix.hash(i + 1, cad.size() - 1) == 0)
			ans = i;
	}

	if (ans < 0)
		cout << "NO";
	else
		cout << "YES\n" << cad.substr(0, ans + 1) << endl << cad.substr(ans + 1);

	return 0;
}
/*
116401024
97 1024

*/

