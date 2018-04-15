/*
ID: wizard.1
PROG: hamming
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int N,B,D, tam;
vector<int> V;

void f(int ini) {
	int aux;
	bool flag;

	for(int i = ini; i < (1<<B); i++) {				
		if(V.size() == N)
			break;

		tam = V.size();
		flag = true;
		for(int k = 0; k < tam; k++) { // checamos todos los num validos
			aux = V[k] xor i;

			if(__builtin_popcount(aux) < D)
				flag = false;
		}

		if(flag)
			V.push_back(i);
	}
}

int main() {
	ifstream fin("hamming.in");
	ofstream fout("hamming.out");

	fin >> N >> B >> D;

	for(int i = 0; i < 256; i++) {
		V.clear();
		f(i);
		if(V.size() == N)
			break;
	}

	tam = V.size();
	for(int i = 0; i < tam; i++) {
		fout << V[i];

		if((i + 1)%10 == 0)
			fout << "\n";
		else if(i != tam - 1)
			fout << ' ';
	}
	if(tam%10 != 0)
		fout << "\n";
	
	return 0;
}