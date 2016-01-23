#include <bits/stdc++.h>
using namespace std;

int main() {
	double h,u,d,f, recorrido, anterior, menos;
	int dia;
	bool flag;

	ios::sync_with_stdio( true );
	cin.tie( 0 );

	while(cin >> h >> u >> d >> f && h != 0) {
		recorrido = 0.0;		
		anterior = 0.0;
		menos = u*(f/100);
		flag = false;
		dia = 0;
		while(1) {
			dia++;	
			recorrido += u;

			if(recorrido > h)
				break;

			recorrido -= d;
			if(recorrido < 0.0)
				break;

			u -= menos;
			(u < 0) ? u = 0 : u = u;
		}
		if(recorrido > h)
			cout << "success on day " << dia << "\n";
		else
			cout << "failure on day " << dia << "\n";
	}
	return 0;
}
/*
6 3 1 10
10 2 1 50
50 5 3 14
50 6 4 1
50 6 3 1
1 1 1 1
0 0 0 0

*/
