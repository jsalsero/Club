/*
ID: wizard.1
PROG: dualpal
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

bool es_palin(string cad){
	int tam = cad.length();
	for(int i = 0; i < tam/2; i++){
		if( cad[i] != cad[tam - i - 1] )
			return false;
	}
	return true;
}

int main(){
	char alfb[] = {'0','1','2','3','4','5','6','7','8','9'};
	int n, s, aux, flag;
	string cad;

	ifstream fin ("dualpal.in");
	ofstream fout("dualpal.out");

	fin >> n >> s;
	for(int num = s + 1; num < INT_MAX && n; num++){
		flag = 0;
		for(int base = 2; base < 11 && n; base++){
			aux = num;
			cad = "";
			while(aux){
				cad = alfb[aux%base] + cad;
				aux /= base;
			}
			if( es_palin(cad) ){
				flag++;
				if(flag == 2)
					break;
			}
		}
		if(flag == 2){
			fout << num << "\n";
			n--;
		}
	}
	return 0;
}