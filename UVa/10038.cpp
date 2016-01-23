#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, aux, num;
	bool flag; 

	while(cin >> n) {
		map<int, int> M;
		flag = false;
		cin >> aux;
		for(int i = 1; i < n; i++) {
			cin >> num;
			if( abs(aux - num) >= n )
				flag = true;
			else
				M[ abs(aux - num) ]++;
			aux = num;
		}	
		if(!flag && M.size() == n - 1)
			cout << "Jolly\n";
		else
			cout << "Not jolly\n";
	}
	return 0;
}
/*
4 1 4 2 3
5 1 4 2 -1 6


*/
