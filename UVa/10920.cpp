#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio( true );
	cin.tie( 0 );
	int N, P;

	while( cin >> N >> P && N != 0 && P != 0 ){
		int aux = (int)sqrt( P );
		int x = 0, y = 0;
		if( aux % 2 == 0 )
			aux--;
		x = ( aux + N )/2;
		y = ( aux + N )/2;
		int cont = 0;
		for( int k = 0; k < P - aux*aux; k++ ){
			if( k == 0 ){
				y++;
				cont++;
				continue;
			}
			switch( cont/(aux+1) ){
				case 0:
					x--;
					break;
				case 1:
					y--;
					break;
				case 2:
					x++;
					break;
				default:
					y++;
					break;
			}
			cont++;
		}
		cout << "Line = " << y << ", column = " << x << "." << "\n";
	}
	return 0;
}
/*
3  1
3  3
3  9
5  9
5  10
0  0
*/
