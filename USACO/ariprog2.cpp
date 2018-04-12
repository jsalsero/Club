/*
ID: wizard.1
PROG: ariprog
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	map<int,int> MP;
	bool flag = false;
	int N,M, aux, ini, res, num, actual, anterior;

	ifstream fin ("ariprog.in");
	ofstream fout("ariprog.out");

	fin >> N >> M;
	for(int i = 0; i <= M; i++)
		for(int j = 0; j <= M; j++)
			MP[i*i + j*j]++;

	for(int incre = 1; incre <= M*N; incre++) {
		aux = N - 2;
		auto it = MP.begin();
		ini = it->first;
		anterior = ini;
		it++;
		actual = it->first;

		while( it != MP.end() ) { 
			if( actual - anterior != incre )
				break;
			if( !aux ){
				cout << ini << ' ' << incre << "\n";
				while( it != MP.end() ) {
					ini = it->first;	
					anterior = actual;
					it++;
					actual = it->first;
					if( actual - anterior == incre )
						break;
					it++;
				}				
				aux = N - 2;
			}
			anterior = actual;
			it++;
			actual = it->first;			
			aux--;
		}
	}

	if(!flag)
		fout << "NONE\n";
	
}
/*
21
200

*/