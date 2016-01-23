#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	int N, M, num, res;
	set<lli> S;

	while (cin >> N >> M && N != 0 && M != 0) {
		res = 0;
		S.clear();
		for (int i = 0; i < N; ++i) {
			cin >> num;
			S.insert(num);
		}
		for (int i = 0; i < M; ++i) {
			cin >> num;
			if(S.count(num) != 0)
				res++;
		}
		cout << res << "\n";
	}
	return 0;
}
