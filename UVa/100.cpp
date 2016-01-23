#include <bits/stdc++.h>
using namespace std;

int main() {
	string cad, aux;

	cin.tie(0);
	ios::sync_with_stdio( true );

	while (cin >> cad && cad[0] != '#') {
		aux = cad;
		next_permutation(cad.begin(), cad.end());
		if(aux < cad)
			cout << cad << "\n";
		else
			cout << "No Successor\n";
	}
	return 0;
}
