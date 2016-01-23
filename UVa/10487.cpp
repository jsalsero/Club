#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, num, M, caso = 1;
	int index, aux, tam, dist;
	vector<int> V, res;

	while(cin >> N && N != 0) {		
		V.clear();
		res.clear();

		for (int i = 0; i < N; ++i) {
			cin >> num;
			V.push_back(num);
		}

		for (int i = 0; i < N; ++i)
			for (int j = i + 1; j < N; j++)
				if(V[i] != V[j])
					res.push_back(V[i] + V[j]);

		sort(res.begin(), res.end());
		tam = res.size();

		cout << "Case " << caso++ << ":\n";
		cin >> M;
		while (M--) {
			cin >> num;
			index = lower_bound(res.begin(), res.end(), num) - res.begin();
			aux = index;
			dist = abs(num - res[index]);
			if ( index + 1 < tam && abs(num - res[index + 1]) < dist ) {				
				aux = index + 1;
				dist = abs(num - res[index + 1]);
			}

			if ( index - 1 >= 0 && abs(num - res[index - 1]) < dist ) {				
				aux = index - 1;
				dist = abs(num - res[index - 1]);
			}

			cout << "Closest sum to " << num << " is " << res[aux] << ".\n";
		}
	}
	return 0;
}
