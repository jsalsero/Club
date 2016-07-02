#include <bits/stdc++.h>
using namespace std;
#define escoge ((track)?b:a)
const int MOD = 1000000007;

int n, a, b;
int memo[50007][3];
int dp(int pos, bool track) {
	int &res = memo[pos][track];
	if (res != -1) 	return res;
	if (pos >= n) 	return res = 1;
	
	int c = 0;
	int tope = min(n - pos, escoge);
	for (int i = 1; i <= tope; i++)
		c = (c + dp(pos + i, !track)) % MOD;
	return res = c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> a >> b;
	for (int i = 0; i <= n; ++i)
	for (int j = 0; j <= 2; ++j)
		memo[i][j] = -1;

	cout << (dp(0, false) % MOD + dp(0, true) % MOD) % MOD<< "\n";
	return 0;
}
