#include <bits/stdc++.h>
using namespace std;

int main() {
	int lines, tam, K, root;
	bool flag;
	string cad, aux;

	cin >> lines;
	cin.ignore();
	for(int i = 1; i <= lines; ++i) {

		getline(cin, cad);
		cad.erase( remove_if(cad.begin(), cad.end(), [](char c) { return !isalpha(c); } ), cad.end() );
		
		tam = cad.size();
		root = (int)sqrt(tam);

		flag = true;

		cout << "Case #" << i << ":\n";

		if(root*root != tam)
			cout << "No magic :(\n";
		else {
			K = root; 
			// down 
			for (int i = 0; i < tam && flag; ++i) {
				if(cad[i] != cad[ (i*K + i/K) % tam ] )
					flag = false;
			}

			// izq
			aux = cad;
			reverse(aux.begin(), aux.end());
			if(cad != aux)
				flag = false;

			// up
			for (int i = 0; i < tam && flag; ++i) {
				if(cad[i] != cad[ tam - 1 - ((i*K + i/K) % tam) ] )
					flag = false;
			}
			if (flag)
				cout << K << "\n";
			else
				cout << "No magic :(\n";
		}		
	}
	return 0;
}
/*
3
sator arepo tenet opera rotas
this sentence is, quite clearly, not a magic square palindrome! but then again, you never know...
muse sun, eve.s e(y)es even use sum.

*/
