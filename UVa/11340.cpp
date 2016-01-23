#include <bits/stdc++.h>
using namespace std;

int main() {
	int T,K, M, num, tam;
	double res;
	map<char,double> letras;
	char carac;
	string cad;

	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cout << std::fixed;
	cout << setprecision(2);

	cin >> T;
	for(int i = 0; i < T; ++i) {
		cin >> K;
		for(int j = 0; j < K; ++j) {
			cin >> carac >> num;
			letras[carac] = num/100.0;
		}
		cin >> M;
		res = 0.0;
		cin.ignore();
		for(int j = 0; j < M; ++j) {
			cad = "";
			getline(cin, cad);
			tam = cad.size();
			for(int h = 0; h < tam; ++h) {
				if(letras.count(cad[h]) != 0)
					res += letras[cad[h]];
			}
		}
		cout << res << "$\n";
		letras.clear();
	}
	return 0;
}
