#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, flag;
	string cad;
	cin >> T;
	while(T--){
		cin >> cad;
		char aux = cad[0];
		flag = 1;
		for (int i=1; i<cad.length(); i++){
			if(aux!=cad[i]){
				flag = 2;
				break;
			}
		}
		cout << flag << "\n";
	}
	return 0;
}