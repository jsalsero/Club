#include <bits/stdc++.h>
using namespace std;

int main() {
	int caso;
	string cad, aux;
	

	cin >> caso;
	getline(cin, cad);
	cin.ignore();

	for (int i = 0; i < caso; ++i) {
		map<string, string> M;
		vector< string > V;

		while(getline(cin, cad)) {
			if(cad.empty())
				break;
			aux = cad;
			sort(aux.begin(), aux.end());

			string::iterator end_pos = remove(aux.begin(), aux.end(), ' ');
			aux.erase(end_pos, aux.end());

			V.push_back(cad);
			M[cad] = aux;
		}
		sort(V.begin(), V.end());

		int tam = V.size();
		for (int j = 0; j < tam; ++j) {
			for (int h = j + 1; h < tam; ++h) {
				if(M[V[j]] == M[V[h]])
					cout << V[j] << " = " << V[h] << "\n";
			}
		}

		if(i != caso - 1)
			cout << endl;
	}
	return 0;
}
