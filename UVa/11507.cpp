#include <bits/stdc++.h>
using namespace std;

bool signos(char cur, char c1, char c2){
    if(cur == 'x' && c1 == '-') return true;
    if(cur == 'y' && c2 == 'y' && c1 == '+') return true;
    if(cur == 'z' && c2 == 'z' && c1 == '+') return true;
    return false;
}

int main() {
	int n, signo;
	string cad;
	char actual;

	while(cin >> n && n != 0) {
		n--;
		actual = 'x';
		signo = 1;

		for(int i = 0; i < n; i++) {
			cin >> cad;

			if(cad[0] == 'N')
				continue;

			if(signos(actual, cad[0], cad[1]))
				signo = -signo;

			if(actual == 'x')
				actual = cad[1];
			else if(actual == 'y' && cad[1] == 'y') actual = 'x';
			else if(actual == 'z' && cad[1] == 'z') actual = 'x';			
		}
		if(signo == 1)
			cout << "+";
		else 
			cout << "-";
		cout << actual << "\n";
	}
	return 0;
}
