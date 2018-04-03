#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
typedef pair<int, int> pii;

void bug(vector< pair<char, int> > &rep) {
	for (const auto& var : rep)
		cout << var.first << "  " << var.second << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string cad;
	cin >> cad;

	vector< pair<char, int> > rep;
	for (int i = 0; i < cad.size(); ) {
		int last = i + 1;
		while (last < cad.size() && cad[last] == cad[i])
			last++;
		rep.push_back(pii(cad[i], min(2, last - i)));
		i = last;
	}

	//bug(rep);

	for (int i = 0; i < rep.size() - 1; ++i)
		if (rep[i].second == 2 && rep[i + 1].second == 2)
			--rep[i + 1].second;

	for (const auto& var : rep)
		for (int i = 0; i < var.second; ++i)
			cout << var.first;

	return 0;
}