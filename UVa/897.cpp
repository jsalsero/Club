// 15 29
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bitset<10000010> bs;
vector<int> primes;
void criba(ll tam) {
	bs.set();
	bs[0] = bs[1] = 0;
	for (ll i = 2; i <= tam; i++) if (bs[i]) {
		for (ll j = i*i; j <= tam; j += i)
			bs[j] = 0;
		primes.push_back((int)i);
	}
}

ll Expo(ll a, ll n) {
	ll res = 1, p = a;
	for (; n; n >>= 1) {
		if (n & 1) res = 
			(res * p);
		p *= p;
	}
	return res;
}

bool anam(int pr) {	
	int num;
	bool flag = true;
	string cad = to_string(pr);
	sort(cad.begin(), cad.end());

	do {
		stringstream ss(cad);
		ss >> num;
		if (!bs[num]) flag = false;
	} while (next_permutation(cad.begin(), cad.end()) && flag);
	return flag;
}

int main() {
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	criba(10000007);

	while (cin >> n && n != 0) {
		int idx = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
		int tope = log10(n) + 1;		
		int res = 0;
		//cout << " - - " << Expo(10, tope) << endl;
		while (idx < primes.size() && primes[idx] <= Expo(10, tope)) {
			if (anam(primes[idx])) {
				res = primes[idx];
				break;
			}
			idx++;
		}
		cout << res << "\n";
	}
	return 0;
}
