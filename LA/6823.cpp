#include <bits/stdc++.h>
using namespace std;

int main() {
	string cad, aux;
	int num, tam, res, izq, cads;
	vector<string> V;

	while (getline(cin, cad)) {
		/*
		V.clear();
		tam = cad.length();
		izq = 0;

		for (int i = 0; i < tam; ++i) {
			if ( isalpha(cad[i]) ) {
				aux = cad.substr(izq, i - izq);
				if ( cad.length() != 0)
					V.push_back( aux );
				while ( isalpha(cad[i]) && i < tam )
					i++;
				izq = i;
			}
		}
		V.push_back( cad.substr(izq, -1) );

		res = 0;
		cads = V.size();
		for (int h = 0; h < cads; ++h) {
			tam = V[h].length();
			for (int i = 0; i < tam; ++i) {
				for (int j = i + 1; j <= tam; ++j) {
					if ( atoi ( V[h].substr(i, j - i).c_str() ) % 3 == 0 ) 
						res++;
				}
			}
		}
		*/
		tam = cad.length();
		res = 0;
		for (int i = 0; i < tam; ++i) {
			if ( isalpha(cad[i]) )
				continue;
			num = 0;
			for (int j = i; j < tam; ++j) {
				if ( isalpha(cad[j]) )
					break;
				else {
					num += cad[j] - '0';
					if ( num % 3 == 0 ) 
						res++;
				}
			}
		}
		cout << res << "\n";
	}
	return 0;
}