#include <bits/stdc++.h>
using namespace std;

int const MOD = 1e9 + 7;
typedef long long Long;

int main() {
	int n, m;

	cin >> n >> m;
	vector< set<char> > ans(m);
	for (int i = 0; i < n; ++i) {
		string cad;
		cin >> cad;
		for (int i = 0; i < m; ++i)
			ans[i].insert(cad[i]);
	}

	Long acc = 1;
	for (const auto &var : ans)
		acc *= var.size(), acc %= MOD;
	cout << acc << endl;

	return 0;
}
