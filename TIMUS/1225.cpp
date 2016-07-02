#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
const int MAX = 50;

int N;
Long memo[MAX][4];
Long solve(int pos, int flag) {
	if (pos == N)			return !flag;
	if (memo[pos][flag] != -1) 	return memo[pos][flag];

	Long res = 0;
	res += solve(pos + 1, 0);
	if (!flag)	
		res += solve(pos + 1, 1);
	return memo[pos][flag] = res;
}

int main() {	
	cin >> N;
	for (int i = 0; i <= N; ++i) memo[i][0] = memo[i][1] = -1;
	cout << solve(1, 0) * 2 << "\n";
	return 0;
}
