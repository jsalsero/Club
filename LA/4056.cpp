#include <bits/stdc++.h>
using namespace std;

int main(){
	int T, Q, tam, puntero, col, row;
	int r1,r2,c1,c2;
	string S;

	cin >> T;
	while(T--){
		cin >> S >> Q;
		tam = S.length();
		while(Q--){
			cin >> r1 >> c1 >> r2 >> c2;
			r1--;r2--;c1--;c2--;
			for (row=r1; row < tam-1-r2%tam; row++){

				col = c1;
				puntero = col;

				for ( ; col < tam-c1-c2; col++){
					cout << S[puntero];
					if(col<row)
						puntero++;
				}
cout << "****";
				for ( ; col < c2; col++){
					cout << S[puntero];
					if(tam - col%tam - 2 <= row)
						puntero--;
				}			
				cout << endl;
			}

			for ( ; row > c1; row--){

				col = c1;
				puntero = col;

				for ( ; col < tam; col++){
					cout << S[puntero];
					if(col<row)
						puntero++;
				}

				if(row==tam-1)
					puntero--;

				for ( ; col < c2; col++){				
					cout << S[puntero];
					if(tam - col%tam - 2 <= row)
						puntero--;
				}			
				cout << endl;
			}
		}
	}
	return 0;
}
/*
2
abca  2
3  2  5  7
3  2  3  2

Aacc32  1
1  1  8  2

*/