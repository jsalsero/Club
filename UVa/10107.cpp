#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
	lli N;
	int tam;
	vector<int> V;
	bool par = false;

	while(cin >> N) {
		V.push_back(N);
		sort(V.begin(), V.end());		
		tam = V.size();
		if(par)
			cout << (V[ tam/2 ] + V[ (tam/2) - 1])/2 << "\n";
		else
			cout << V[ tam/2 ] << "\n";

		par = !par;
	}
	return 0;
}
