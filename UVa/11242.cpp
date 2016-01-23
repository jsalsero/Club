#include <bits/stdc++.h>
using namespace std;

int main() {
	int f, r, num;
	cout << fixed;
	cout << setprecision(2);
	while (cin >> f >> r && f != 0) {
		vector<int> front, atras;
		vector<double> res;

		for (int i = 0; i < f; ++i) {
			cin >> num;
			front.push_back(num);
		}

		for (int i = 0; i < r; ++i) {
			cin >> num;
			atras.push_back(num);
		}

		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < f; ++j) {
				res.push_back(atras[i]/(front[j] + 0.0));
			}
		}
		sort(res.begin(), res.end());

		int tam = (f*r) - 1;
		double dist = 0.0;

		for (int i = 0; i < tam; ++i)
			if ( dist < (res[i + 1]/res[i]) )
				dist = res[i + 1]/res[i];
		
		cout << dist << "\n";
	}
	return 0;
}
