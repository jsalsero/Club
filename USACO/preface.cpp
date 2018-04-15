/*
ID: wizard.1
LANG: C++
TASK: preface
*/
#include <bits/stdc++.h>
using namespace std;

string M[4000];

map<char, int> res;
int tam;

void cuenta (int N) {
	if(N != 0) {
		for (int i = 1; i <= N; ++i) {
			if ( M[i] != "" ) {
				tam = M[i].size();
				for(int j = 0; j < tam; j++)
					res[ M[i][j] ]++;				
			} else {		
				M[i] = M[ i%10000 - i%1000 ] + M[ (i%1000) - i%100 ] + M[ (i%100) - i%10 ] + M[i%10];
				tam = M[i].size();
				for(int j = 0; j < tam; j++)
					res[ M[i][j] ]++;
			}
		}
	}
}

int main() {
	int N;

	ifstream fin ("preface.in");
	ofstream fout("preface.out");

	fin >> N;
	fill(M, M + 3600, "");
	M[0]    = "";
	M[1]    = "I";
	M[5]    = "V";
	M[10]   = "X";
	M[50]   = "L";
	M[100]  = "C";
	M[500]  = "D";
	M[1000] = "M";

	M[2]    = "II";
	M[3]    = "III";
	M[4]    = "IV";
	M[6]    = "VI";
	M[7]    = "VII";
	M[8]    = "VIII";
	M[9]    = "IX";

	M[20]   = "XX";
	M[30]   = "XXX";
	M[40]   = "XL";
	M[60]   = "LX";
	M[70]   = "LXX";
	M[80]   = "LXXX";
	M[90]   = "XC";

	M[200]   = "CC";
	M[300]   = "CCC";
	M[400]   = "CD";
	M[600]   = "DC";
	M[700]   = "DCC";
	M[800]   = "DCCC";
	M[900]   = "CM";

	M[2000]   = "MM";
	M[3000]   = "MMM";
	cuenta(N);

	//for(int i = 1; i <= N; i++ )
		//fout << M[i] << endl;

	if(res.count('I') != 0) fout << "I " << res['I'] << "\n";
	if(res.count('V') != 0) fout << "V " << res['V'] << "\n";
	if(res.count('X') != 0) fout << "X " << res['X'] << "\n";
	if(res.count('L') != 0) fout << "L " << res['L'] << "\n";
	if(res.count('C') != 0) fout << "C " << res['C'] << "\n";
	if(res.count('D') != 0) fout << "D " << res['D'] << "\n";
	if(res.count('M') != 0) fout << "M " << res['M'] << "\n";

	return 0;
}