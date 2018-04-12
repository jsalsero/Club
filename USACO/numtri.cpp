/*
ID: wizard.1
PROG: numtri
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int R;
int T[1007][1007];
int memo[1007][1007];

int dp(int fila, int col) {
	if(fila < 0 || col < 0 || fila >=R || col > fila)
		return 0;
	if(memo[fila][col] == -1)
		return memo[fila][col] = max(T[fila][col] + dp(fila + 1, col), T[fila][col] + dp(fila + 1, col + 1));
	return memo[fila][col];
}

int main() {

	ifstream fin ("numtri.in");
	ofstream fout ("numtri.out");

	fin >> R;
	for(int i = 1; i <= R; ++i) {
		for(int j = 0; j < i; ++j) {
			fin >> T[i - 1][j];
		}
	}
	memset(memo, -1, sizeof memo);
	fout << dp(0,0) << "\n";
}