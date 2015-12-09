/*
ID: wizard.1
LANG: C++11
TASK: lamps
*/
#include <bits/stdc++.h>
using namespace std;

int N,C;
vector<int> on, off;

vector<int> boton(int j, vector<int> A) {
	int tam = A.size();
	if (j == 0) {
		for (int i = 0; i < tam; ++i)
			A[i] = 1 - A[i];

	} else if (j == 1) {
		for (int i = 0; i < tam; i += 2)
			A[i] = 1 - A[i];

	} else if (j == 2) {
		for (int i = 1; i < tam; i += 2)
			A[i] = 1 - A[i];

	} else if (j == 3) {
		for (int i = 0; i < tam; i += 3)
			A[i] = 1 - A[i];
	}
	return A;
}

bool checar(vector<int> A) {
	int tam = on.size();
	for (int i = 0; i < tam; i++) {
		if ( A[ on[i] - 1 ] == 0 )
			return false;
	}
	tam = off.size();
	for (int i = 0; i < tam; i++) {
		if ( A[ off[i] - 1 ] == 1 )
			return false;
	}
	return true;
}

int main() {	
	int num, len;
	vector<int> A, aux;
	set< vector<int> > R;
	
	ifstream fin("lamps.in");
	ofstream fout("lamps.out");

	fin >> N >> C;

	while (fin >> num && num != -1)
		on.push_back(num);
	while (fin >> num && num != -1)
		off.push_back(num);

	for (int i = 0; i < N; ++i)
		A.push_back(1);
	
	for (int i = 0; i < 16; i++) {
		if ( C < __builtin_popcount(i) || ( (C - __builtin_popcount(i)) % 2 == 1 ))
			continue;		
		
		aux = A;
		for (int j = 0; j < 4; ++j) {			
			if ( i & (1<<j) ) {
				aux = boton(j, aux);
			}
		}

		if ( checar(aux) )
			R.insert(aux);
	}

	int tam = R.size();
	if (tam == 0) {
		fout << "IMPOSSIBLE\n";
		return 0;
	}

	for (auto i : R) {
		len = i.size();
		for (int j = 0; j < len; j++)
			fout << i[j];
		fout << "\n";
	}


	return 0;
}
/*
100 
8394 
1 7 13 19 25 31 37 43 49 55 -1 
64 -1

*/ 
