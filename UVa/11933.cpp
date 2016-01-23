#include <bits/stdc++.h>
using namespace std;

int main() {
	int N,A,B, tam;
	bool par;
	while (cin >> N && N != 0) {
		vector<int> a,b;
		par = true;

		for (int i = 0; i < 31; ++i) {
			if (N & (1<<i)) {
				if(par)
					a.push_back(i);
				else
					b.push_back(i);
				par = !par;				
			}
		}
		tam = a.size();
		A = 0;
		for (int i = 0; i < tam; ++i) {
			A |= (1<<a[i]);
		}

		tam = b.size();
		B = 0;
		for (int i = 0; i < tam; ++i) {
			B |= (1<<b[i]);
		}

		cout << A << ' ' << B << "\n";
	}
}
