/*
ID: wizard.1
LANG: C++11
TASK: crypt1
*/
#include <bits/stdc++.h>
using namespace std;

int N, num;
map<int, int> M;

bool checar(int valor){
	while(valor){
		if( M.count(valor%10) == 0 )
			return false;
		valor /= 10;
	}
	return true;
}

int main(){
	vector<int> numeros;
	vector<int> decenas;

	for (int i = 111; i < 1000; i++)
		numeros.push_back(i);

	for (int i = 11; i < 100; i++)
		decenas.push_back(i);

	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	fin >> N;
	for(int i = 0; i < N; i++){
		fin >> num;
		M[num]++;
	}
	fin.close();

	for (int i = 0; i < numeros.size(); i++){
		if( !checar(numeros[i]) ){
			numeros.erase(numeros.begin() + i);
			i--;
		}
	}

	for (int i = 0; i < decenas.size(); i++){
		if( !checar(decenas[i]) ){
			decenas.erase(decenas.begin() + i);
			i--;
		}
	}

	int multi, p1, p2;
	int total = 0;
	for (int i = 0; i < numeros.size(); i++){
		for (int j = 0; j < decenas.size(); j++){
			multi = numeros[i] * decenas[j];
			if( !checar( multi ) || multi >= 10000)
				continue;
			
			p1 = numeros[i] * (decenas[j]%10);
			p2 = numeros[i] * (decenas[j]/10);
			if( p1 >= 1000 || p2 >= 1000 )
				continue;

			if( checar( p1 ) && checar( p2 ) && (multi == (p1 + 10*p2)) )
				total++;				
		}
	}

	fout << total << "\n";

	return 0;
}