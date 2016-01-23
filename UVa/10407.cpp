#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>

bitset<100000010> bs;
vi primos;

void criba(int n) {
	bs.set();
	bs[0] = bs[1] = 0;
	n++;
	for(ll i = 2; i <= n; ++i)
		if (bs[i]) {
			for(ll j = i*i; j <= n; j +=i)
				bs[j] = 0;
			primos.push_back((int)i);
		}		
}

vi primerFactor(ll N) {
	vi factors;
	ll PF_idx = 0, PF = primos[PF_idx];
	while (PF * PF <= N) {
		while(N % PF == 0) { N/= PF; factors.push_back(PF); }
		PF = primos[++PF_idx];
	}
	if (N != 1) factors.push_back(N);
	return factors;
}

int main() {
	int n, n2, aux;

	criba(100000);

	while(1) {
		cin >> n;
		if(n == 0)
			break;
		vi V;
		V.push_back(n);		
		while(cin >> n && n != 0)
			V.push_back(n);
		
		sort(V.begin(), V.end());

		aux = V[V.size() - 1] - V[0];
		vi facts = primerFactor(aux);

		cout << facts[facts.size() - 1] << "\n";

	}
	return 0;
}
/*
701 1059 1417 2312 0
14 23 17 32 122 0
14 -22 17 -31 -124 0
0

*/
