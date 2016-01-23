#include <bits/stdc++.h>
using namespace std;

int main(){
	string cad;
	int abre = 0;
	while(getline(cin, cad)){
		while(cad.find("\"") != -1){
			if(abre%2 == 0)
				cad.replace(cad.find("\""),1, "``");
			else
				cad.replace(cad.find("\""),1, "''");
			abre = (abre+1)%2;
		}
		cout << cad << "\n";
	}
	return 0;
}
/*
"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"

*/
