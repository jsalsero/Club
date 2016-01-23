#include <bits/stdc++.h>
using namespace std;

int main() {
	string cad, aux;

	while(getline(cin, cad)) {
		if(cad == "DONE")
			return 0;
		cad.erase( remove_if(cad.begin(), cad.end(), [](char c) { return !isalpha(c); } ), cad.end() );
		transform(cad.begin(), cad.end(), cad.begin(), ::tolower);
		aux = cad;
		reverse(aux.begin(), aux.end());
		(aux == cad) ? cout << "You won't be eaten!\n" : cout << "Uh oh..\n";
	}
	return 0;
}
