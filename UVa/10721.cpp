#include <bits/stdc++.h>
using namespace std;
typedef long long Long;

int n, k, m;
Long memo[53][53][53];
Long barras(int pos, int acc, int shift) {
	Long &pointer = memo[pos][acc][shift];
	if (pointer != -1) 	return pointer;
	if (pos == n) 		return pointer = (shift == k);

	Long res = 0;
	if (shift + 1 <= k)		res += barras(pos + 1, 1, shift + 1);
	if (acc + 1 <= m)		res += barras(pos + 1, acc + 1, shift);
	return pointer = res;
}

void init() {
	for (int i = 0; i < 51; ++i)
	for (int j = 0; j < 51; ++j)
	for (int k = 0; k < 51; ++k)
		memo[i][j][k] = -1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> n >> k >> m) {
		init();
		cout << barras(1, 1, 1) << "\n";
	}
	return 0;
}
