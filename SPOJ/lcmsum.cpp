#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define ll long long

ll criba[MAX + 7], res[MAX + 7];

void cribaPhi(ll upper) {
	for (int i = 0; i < upper + 1; i++)
		criba[i] = i;

	//for (int i = 0 ; i < 30; i++)
		//cout << i << ' ' << criba[i] << endl;
	//cout << endl << endl;

	for (int i = 2; i < upper + 1; ++i) {
		if (i == criba[i]) {
			for (int j = 1; j*i < upper + 1; ++j) {			
				criba[i*j] /= i;
				criba[i*j] *= (i - 1);
			}
		}
	}

	for (int i = 1; i < upper + 1; ++i) {
		for (int j = i; j < upper + 1; j += i)
			res[j] += criba[i]*i;
	}
}

int main() {
	ll T, N, actual;	

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cribaPhi(MAX);

	//for (int i = 0 ; i < 30; i++)
		//cout << i << ' ' << criba[i] << endl;

	cin >> T;
	for (int i = 0; i < T; ++i) {
		cin >> N;
		cout << (res[N] + 1)*N/2 << "\n";
	}
	return 0;
}