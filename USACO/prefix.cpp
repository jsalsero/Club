/*
ID: wizard.1
PROG: prefix
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

struct Trie{
	bool es_palabra;
	map<int, Trie*> sig;

	Trie() : es_palabra(false) {}

	void Agregar(const string& str) {
		Trie* cabeza = this;
		for (int i = 0; i < str.size(); ++i) {
			if (cabeza->sig.find(str[i] - 'A') == cabeza->sig.end())
				cabeza->sig[str[i] - 'A'] = new Trie();
			cabeza = cabeza->sig[str[i] - 'A'];
		}
		cabeza->es_palabra = true;
	}
};

set<int> idxs;
string S;
int res, tam;

void busca(Trie* t, int index) {		
	if (t->es_palabra) {
		idxs.insert(index);
		res = max(res, index);		
	}
	if (index != tam) {
		for (int i = 0; i < 26; ++i) {
			if (t->sig.find(i) != t->sig.end()) {
				if ((char)(i + 'A') == S[index]) {		
					//cout << (char)(i + 'A') << "   " << index << endl;
					busca(t->sig[i], index + 1);			
				}
			}
		}
	}
}

int main() {
	ifstream fin("prefix.in");
	ofstream fout("prefix.out");

	Trie* dic = new Trie();
	string cad;

	while (fin >> cad && cad != ".")
		dic->Agregar(cad);
		
	while (fin >> cad)
		S += cad;

	tam = S.size();
	int index;
	res = 0;

	idxs.insert(0);
	while (idxs.size() != 0) {
		index = *idxs.begin();
		idxs.erase(idxs.begin());
		if (index == tam)
			break;
		busca(dic, index);
	}
	fout << res << "\n";
	return 0;
}
