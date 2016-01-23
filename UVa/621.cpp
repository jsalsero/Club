#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, tam;
	string cad;

	cin >> n;
	while(n--){
		cin >> cad;
		tam = cad.length();
		if(tam == 1 || cad.compare("78") == 0)
			cout << "+\n";
		else if(cad[tam-2] == '3' && cad[tam-1] == '5')
			cout << "-\n";
		else if(cad[0] == '9' && cad[tam-1] == '4')
			cout << "*\n";
		else if(cad[0] == '1' && cad[1] == '9' && cad[2] == '0')
			cout << "?\n";
	}
	return 0;
}
