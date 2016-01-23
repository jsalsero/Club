#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos, N, num, res;
	vector<int> V;

	cin >> casos;
	while (casos--) {
		V.clear();
		res = 0;

		cin >> N;
		for (int i = 0; i < N; ++i) {
			cin >> num;
			V.push_back(num);			
			for (int j = 0; j <= i; j++) {
				if(j == i)
					continue;
				if(V[j] <= num)
					res++;
			}
		}
		cout << res << "\n";
	}
	return 0;
}
