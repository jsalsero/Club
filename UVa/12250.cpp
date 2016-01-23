#include <bits/stdc++.h>
using namespace std;

int main(){
	string cad;
	int cont=1;
	map<string,string> M;
	M["HELLO"] = "ENGLISH";
	M["HOLA"] = "SPANISH";
	M["HALLO"] = "GERMAN";
	M["BONJOUR"] = "FRENCH";
	M["CIAO"] = "ITALIAN";
	M["ZDRAVSTVUJTE"] = "RUSSIAN";
	while(cin >> cad){
		if(cad[0]=='#')
			return 0;
		if(M.count(cad))
			cout << "Case " << cont++ << ": " <<  M[cad] << "\n";
		else
			cout << "Case " << cont++ << ": UNKNOWN" << "\n";
	}
	return 0;
}
