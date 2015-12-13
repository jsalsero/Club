/*
ID: wizard.1
LANG: C++11
PROG: zerosum
*/
#include <bits/stdc++.h>
using namespace std;

string op[] = {"+", "-", " "};
set<string> S;

int N;

void genera(string cad, int pos) {
	if (pos == N)
		S.insert(cad + to_string(pos));
	else {
		for (int i = 0; i < 3; i++) {
			genera(cad + to_string(pos) + op[i], pos + 1);
		}
	}
}

int main() {

  ifstream fin ("zerosum.in");
  ofstream fout ("zerosum.out");

	fin >> N;
	genera("", 1);

	string aux, c_aux;
	int tam, suma;
	bool mas;

	for (auto cad : S) {
		aux = cad;
		tam = aux.length();
		mas = true;
		c_aux = "";
    	suma = 0;
    
		for (int i = 0; i < tam; i++) {
			if (cad[i] == '+' || cad[i] == '-') {
				(mas) ?	suma += stoi(c_aux) : suma -= stoi(c_aux);
				c_aux = "";
				(cad[i] == '+') ? mas = true : mas = false;				
			} else {
				if (cad[i] == ' ')
					i++;
        		c_aux += cad[i];
			}
		}
    	(mas) ?	suma += stoi(c_aux) : suma -= stoi(c_aux);
		if (suma == 0)
			fout << cad << "\n";
	}
	return 0;
}
