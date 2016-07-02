#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

int main() {
	Long t, c, num;
	vector<Long> V;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> c;
		V.clear();
		Long maxi = -1;
		for (Long i = 0; i < c; ++i) {
			Long cont = 9;
			Long sum = 0;
			while (cont--) {
				cin >> num;
				sum += num;
			}
			cin >> num;
			maxi = max(maxi, num);
			sum -= num;
			V.push_back(sum);
		}
		Long res = V[0];
		for (Long i = 1; i < V.size(); ++i)
			res = __gcd(res, V[i]);
		if (res > 1 && maxi < res)
			cout << res << "\n";
		else
			cout << "impossible\n";
	}
	return 0;
}
/*
4
2
1 1 1 1 1 1 1 1 1 9
2 4 6 8 10 12 14 16 18 90
3
1 1 1 1 1 1 1 1 1 1
5 4 7 2 6 4 2 1 3 2
1 2 3 4 5 6 7 8 9 5
2
1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 0
2
2 2 2 2 2 2 2 2 2 0
1 1 1 1 1 1 1 1 1 1


*/
