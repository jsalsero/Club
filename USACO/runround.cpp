/*
ID: wizard.1
LANG: C++
TASK: runround
*/
#include <bits/stdc++.h>
using namespace std;

string to_string(long M) {
	stringstream ss;
	ss << M;
	return ss.str();
}

bool unico(string M) {
	bool cubeta[10];
	fill(cubeta, cubeta + 10, false);
	int tam = M.length();

	for (int i = 0; i < tam; ++i) {
		if (M[i] == '0')
			return false;
		if (cubeta[ M[i] - '0' ])
			return false;
		cubeta[ M[i] - '0' ] = true;
	}
	return true;
}

bool checar(long M) {
	string cad = to_string(M);
	int tam = cad.length();
	if (!unico(cad)) return false;

	bool visitados[tam];
	fill(visitados, visitados + tam, false);

	int actual = 0;
	int index = 0;
	for (int i = 0; i < tam; i++) {		
		if (visitados[index])
			return false;
		visitados[index] = true;
		actual = cad[index] - '0';		
		index = (index + actual) % tam;
	}
	return index == 0;
}

int main() {	
	long M;

	ifstream fin("runround.in");
	ofstream fout("runround.out");

	fin >> M;
	M++;
	while (!checar(M)) M++;
	fout << M << "\n";
	return 0;
}