#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	map<int, vector< pair<int, string> > > M;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string name;
		int region, score;

		cin >> name >> region >> score;
		M[region].push_back(make_pair(-score, name));
	}

	for (const auto& region : M) {
		if (region.second.size() == 2)
			cout << region.second[0].second << ' ' << region.second[1].second << endl;
		else {
			map<int, int> score;
			for (const auto& var : region.second)
				score[var.first]++;

			int prim = -1, segu = -1;
			for (const auto& var : score)
				if (prim == -1)
					prim = var.first;
				else if (segu == -1)
					segu = var.first;

			if (segu == -1)
				cout << '?' << endl;
			else {
				auto data = region.second;
				sort(data.begin(), data.end());
				for (const auto& var : data) {
					if (prim == var.first)
						cout << var.second << ' ';
					else if (segu == var.first) {
						cout << var.second;
						break;
					}
				}
				cout << endl;	
			}
		}
	}
	return 0;
}