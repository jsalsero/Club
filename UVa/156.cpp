#include <bits/stdc++.h>
using namespace std;

int main() {
	istringstream iss;
	string s, cad, aux;
	int tam;
	map<string, int> M;
	map<string, vector<string> > dic;

	while (getline(cin, s)) {
		if (s[0] == '#')
			break;

		istringstream tmp(s);
		
		while (tmp >> cad) {
			tam = cad.size();
			aux = cad.substr(0,-1);
			for (int i = 0; i < tam; ++i) {
				aux[i] = tolower(aux[i]);
			}

			sort(aux.begin(), aux.end());
			M[aux]++;

			vector<string> V = dic[aux];
			V.push_back(cad);
			dic[aux] = V;
			//cout << "---" << cad << "   " << aux << endl;
		}
	}
	vector<string> res;

	for ( auto var : M) {
		if (var.second == 1) {
			vector<string> V = dic[var.first];
			sort(V.begin(), V.end());
			for (auto item : V) {
				res.push_back(item);
			}
		}				
	}
	sort(res.begin(), res.end());
	for (auto var : res) {
		cout << var << "\n";
	}
	return 0;
}
