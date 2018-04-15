#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	int S,P, line, col, esquina;
	vector<lli> V;

	V.push_back(0);
	for(lli i = 1; i <= 100000; i+=2)
		V.push_back(i*i);
	//sort(V.begin(), V.end());

	for( auto var : V)
		cout << var << endl;

	while (cin >> S >> P && S != 0 && P != 0) {
		col = line = 0;
		int pos = (upper_bound(V.begin(), V.end(), P) - V.begin());

		cout << pos << endl;
		//esquina = V[pos - V.begin()];
		//cout << "esquina  " << esquina << endl;
	}
}