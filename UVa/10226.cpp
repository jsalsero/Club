#include <bits/stdc++.h>
using namespace std;

int main() {
	int casos, total;
	string cad;	

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cout << fixed;
	cout << setprecision(4);

	cin >> casos;
	getline(cin, cad);
	getline(cin, cad);
	for (int i = 0; i < casos; i++) {
		map<string, int> M;
		total = 0;

		while( getline(cin, cad) ) {
			if (cad == "")
				break;
			M[cad]++;
			total++;
		}

		for (auto var : M) {
			cout << var.first << ' ' << (var.second*100.0)/(total + 0.0) << "\n";			
			
		}
		if (i != casos -1)
			cout << "\n";
	}
}
