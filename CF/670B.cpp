#include <bits/stdc++.h>
using namespace std;

#define GAUSS ((x*(x + 1))/2)
typedef long long Long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Long n, k;

	cin >> n >> k;
	vector<Long> data(n);
	for (Long i = 0; i < n; ++i)
		cin >> data[i];

	Long x = -1 + sqrt(1 + 8*k);
	x /= 2;

	if (GAUSS == k)
		x--;
	cout << data[k - GAUSS - 1];
	
	return 0;
}
