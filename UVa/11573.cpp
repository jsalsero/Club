#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {	
	int casos,N, res, aux;
	lli num;
	map<lli,int> M;
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> casos;
	for (int i = 0; i < casos; i++) {
		M.clear();
		res = -1;

		cin >> N;

		for (int j = 0; j < N; j++) {
			cin >> num;
			aux = M.size();
			M[num]++;
			if (aux == M.size()) {
				res = max(aux, res);
				M.clear();
				M[num]++;
			}
		}
		
		cout << res << "\n";
	}
	return 0;
}
