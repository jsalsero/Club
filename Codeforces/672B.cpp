#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	int n;
	string cad;

	cin >> n >> cad;

	if (cad.size() > 26) {
		cout << -1 << endl;
		return 0;
	}

	map<char, int> M;
	for (const auto &var : cad)
		M[var]++;

	int ans = 0;
	for (const auto& var : M)
		ans += var.second - 1;

	cout << ans << endl;

	return 0;
}
