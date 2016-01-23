#include <bits/stdc++.h>
using namespace std;

int T, N;

int main(){
	cin >> T;
	while(T--){
		string cad[107];
		int res=0;
		cin >> N;
		getchar();
		for(int i=0; i<N; i++){
			getline(cin, cad[i]);			
			if(cad[i][0] == 'L')
				res--;
			else if(cad[i][0] == 'R')
				res++;
			else{
				int tam = cad[i].length();
				int aux;
				aux = cad[i][tam - 1] - '0';
				//cout << aux << endl;
				cad[i] = cad[ aux - 1 ];
				(cad[i][0] == 'L') ? res-- : res++;
			}
		}
		cout << res << "\n";
	}
	return 0;
}
