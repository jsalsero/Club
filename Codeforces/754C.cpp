#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;

	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		set<string> names;
		for (int i = 0; i < n; ++i) {
			string cad;
			cin >> cad;
			names.insert(cad);
		}

		int m;
		cin >> m;
		vector<string> messa;
		vector< pair<string, set<string> > > data;
		
		for (int i = 0; i < m; ++i) {
			string cad;
			getline(cin, cad);

			int h = 0;
			while (cad[h] != ':')
				++h;
			string name = cad.substr(0, h + 1);
			string msj  = cad.substr(h);

			stringstream ss(msj);
			set<string> match;
			while (ss >> cad)
				if (names.find(cad) != names.end())
					match.insert(cad);
			
			data.push_back(make_pair(name, match));
		}
		
	}
	

	return 0;
}