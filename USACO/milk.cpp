/*
ID: wizard.1
PROG: milk
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int leche, farmers, a,b, costo;
vector< pair<int,int> > info;

int main(){	
	ifstream fin ("milk.in");
	ofstream fout("milk.out");

	fin >> leche >> farmers;
	for(int i = 0; i < farmers; i++){
		fin >> a >> b;
		info.push_back( make_pair(a,b) );
	}
	sort( info.begin(), info.end());

	for(int i = 0; i < farmers && leche > 0; i++){
		if ( leche - info[i].second >= 0 ) {
			leche -= info[i].second;
			costo += info[i].first * info[i].second;
		} else {
			costo += info[i].first * (leche);
			leche -= info[i].second;
		}
	}
	fout << costo << endl;
	return 0;
}
/*
100 5
5 20
9 40
3 10
8 80
6 30

*/