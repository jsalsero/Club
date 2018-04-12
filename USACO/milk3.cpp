/*
ID: wizard.1
PROG: milk3
LANG: C++11
*/

#include <bits/stdc++.h>
using namespace std;

int cA,cB,cC, aux;
int edos[27][27][27];
map<int,int> M;

void leche(int A, int B, int C) {
	if( edos[A][B][C] == -1 ) {
		edos[A][B][C] = 0;
		if( A == 0 ){
			M[C]++;
		} 

		if( A > 0 ) {
			aux = cB - B;
			leche(A - min(A, aux), B + min(A, aux), C);
			aux = cC - C;
			leche(A - min(A, aux), B, C + min(A, aux));
		}
		if( B > 0 ) {
			aux = cA - A;
			leche(A + min(B, aux), B - min(B, aux), C);
			aux = cC - C;
			leche(A, B - min(B, aux), C + min(B, aux));
		}
		if( C > 0 ) {
			aux = cA - A;
			leche(A + min(C, aux), B, C - min(C, aux));
			aux = cB - B;
			leche(A, B + min(C, aux), C - min(C, aux));
		}
	
	}
}


int main() {

	ifstream fin ("milk3.in");
	ofstream fout ("milk3.out");
	
	memset(edos, -1, sizeof edos);
	fin >> cA >> cB >> cC;
	leche(0,0, cC);

	bool flag = false;
	for (auto var : M) {
		if( flag )
			fout << ' ';
		flag = true;
		fout << var.first;
	}
	fout << "\n";

	return 0;
}