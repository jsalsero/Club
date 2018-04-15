#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;

	while (cin >> n) {
		vector<int> res;
		set<int> S;
		for (int i = n + 1; i <= n*2; ++i) {
			if( (i - n)/__gcd((i - n), (i*n)) == 1 ) {
				res.push_back( i );
				if (i != (i*n)/(i - n))
					res.push_back( (i*n)/(i - n) );	
			}
		}
		sort(res.begin(), res.end());

		int tam = res.size();
		cout << (tam/2) + 1 << "\n";
		for (int i = 0; i < tam; ++i) {
			if (S.count( res[i] ) == 0 && S.count((res[i]*n)/(res[i] - n)) == 0) {
				S.insert( res[i] );
				S.insert( (res[i]*n)/(res[i] - n) );
				cout << "1/" << n << " = " << "1/" << (res[i]*n)/(res[i] - n) << " + " << "1/" << res[i] << "\n";
			}
		}
	}
	return 0;
}