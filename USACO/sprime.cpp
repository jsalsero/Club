#include <bits/stdc++.h>
using namespace std;

int exp(int base, int e) {
	int res = 1, p = a;
	for(; e; e >>= 1) {
		if (e & 1)
			res = res * p;
		p = p * p;
	}
	return res;
}

void criba(int tope) {
	
}

int main() {
	int N;

	criba();

	cin >> N;

	int tam = exp(10, N);
	for(int i = exp(10,N - 1); i < tam; ++i) {
		aux = i;
		while(aux != 0) {
			if(criba[aux])
				aux /= 10;
			else
				break;
		}
		if(aux == 0)
			cout << i << "\n";
	}


	return 0;
}