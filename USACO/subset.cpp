/*
ID: wizard.1
LANG: C++
TASK: subset
*/
#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int N;
lli memo[41][820];

lli dp(int pos, int acumulado) {
	if (pos == N)
		if (acumulado == 0)
			return 1;
		else 
			return 0;
	if (memo[pos][acumulado] != -1)
		return memo[pos][acumulado];

	return memo[pos][acumulado] = dp(pos + 1, acumulado + (pos + 1)) + dp(pos + 1, acumulado - (pos + 1));
}

int main() {
	ifstream fin("subset.in");
	ofstream fout("subset.out");

	fin >> N;
	memset(memo,-1 , sizeof(memo));
	
	lli res = dp(0,0);
	if (res == 0)
		fout << "0\n";
	else
		fout << res/2 << "\n";

	return 0;
}