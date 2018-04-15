/*
ID: wizard.1
PROG: holstein
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int V, G, tam;
	int vaca[27];
	int producs[17][27];
	bool flag;
	int suma, suma_id, id, tam_id;

	ifstream fin ("holstein.in");
	ofstream fout("holstein.out");

	fin >> V;
	for(int i = 0; i < V; ++i) {
		fin >> vaca[i];
	}

	fin >> G;
	for(int i = 0; i < G; i++) {
		for(int j = 0; j < V; j++) {
			fin >> producs[i][j];
		}
	}

	suma_id = 100000000;
	tam_id = 100000;

	// Checamos todas las opciones posibles
	for(int i = 0; i < (1<<G); ++i) {

		int aux[27];
		fill(aux, aux + 26, 0);
		tam = 0;

		for(int j = 0; j < G; ++j) {
			if(i&(1<<j)) { // está prendido
				tam++;
				for(int h = 0; h < V; h++)
					aux[h] += producs[j][h];
			}
		}

		flag = true;
		suma = 0;
		for(int h = 0; h < V && flag; h++) {
			suma += aux[h];
			if(aux[h] < vaca[h])
				flag = false;
		}

		if(flag) {
			if(tam_id > tam) {				
				id = i;
				tam_id = tam;
				suma_id = suma;				
			}
		}
	}

	fout << tam_id << ' ';
	int cont = 1;
	for(int j = 0; j < G; ++j) {
		if(id & (1<<j)) { // está prendido
			if(cont++ != tam_id)
				fout << j + 1 << ' ';
			else
				fout << j + 1;
		}
	}
	fout << "\n";

	return 0;
}