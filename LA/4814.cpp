#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c,d,e, i, aux;
	int princess, prince;

	while( cin >> a >> b >> c >> d >> e && a != 0 && b != 0 && c != 0 && d != 0 && e != 0 ) {
		vector<int> A;
		vector<int> B;
		bool arre[60];
		fill(arre, arre + 55, false);
		princess = 0;
		prince = 0;

		arre[a] = true;
		arre[b] = true;
		arre[c] = true;
		arre[d] = true;
		arre[e] = true;

		A.push_back(a);
		A.push_back(b);
		A.push_back(c);
		sort(A.begin(), A.end());
		
		B.push_back(d);
		B.push_back(e);
		sort(B.begin(), B.end());
		//reverse(B.begin(), B.end());
		
		for (i = 0; i < 3; i++) {
			if(A[i] > B[0])
				break;
		}
		if(i == 3) {
			prince++;
			A.erase(A.begin());			
		} else {
			princess++;
			A.erase(A.begin() + i);			
		}
		B.erase(B.begin());

		for (i = 0; i < 2; i++) {
			if(A[i] > B[0]) 
				break;
		}
		if (i == 2) {
			prince++;
			A.erase(A.begin());
		} else {
			princess++;
			A.erase(A.begin() + i);
		}

		if (princess == 2)
			cout << "-1\n";
		else if (prince == 2) {

			int i = 1;
			while(arre[i] && i < 53)
				i++;
			if(i == 53)
				cout << "-1\n";
			else
				cout << i << "\n";

		} else if ((A[0] + 1) < 53){
			int i = 1;
			while(arre[ A[0] + i ] && (A[0] + i) < 53 )
				i++;
			if( (A[0] + i) == 53)
				cout << "-1\n";
			else
				cout << A[0] + i << "\n";
		} else 
			cout << "-1\n";
	}
	return 0;
}
/*
28 51 29 50 52
50 26 19 10 27
10 20 30 24 26
46 48 49 47 50
0 0 0 0 0


*/