#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

bitset<10000010> bs;
vector<Long> primes;
void criba(int tam) {
	bs.set();
	bs[0] = bs[1] = 0;
	for (Long i = 2; i <= tam; ++i) if (bs[i]) {
		for (Long j = i * i; j <= tam; j += i) bs[j] = 0;
		primes.push_back((int)i);
	}
}

Long getPower(Long n, Long p) {
	Long res = 0;
	while (n > 0) {
		res += n/p;
		n /= p;
	}
	return res;
}

Long expo(Long a, Long n, Long m) {
	Long res = 1, p = a;
	for (; n; n >>= 1) {
		if (n & 1) res = (res * p) % m;
		p = (p * p) % m;
	}
	return res;
}

vector<Long> res;
void factoriza(Long n, Long signo) {
	for (Long i = 0; i < primes.size() && primes[i] <= n; ++i) {
		res[i] += signo * getPower(n, primes[i]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	criba(1000007);
	int t;
	string cad;
	vector<int> letras(30, 0);

	cin >> t;
	while (t--) {
		cin >> cad;
		res.assign(primes.size() + 3, 0);

		fill(letras.begin(), letras.end(), 0);
		for (int i = 0; i < cad.size(); ++i)
			letras[cad[i] - 'a']++;

		factoriza(cad.size(), 1);
		for (int i = 0; i < 30; ++i) {
			if (letras[i] <= 1) continue;
			factoriza(letras[i], -1);
		}
		
		int resta = min(res[0], res[2]);
		res[0] -= resta;
		res[2] -= resta;
		Long ans = 1;
		for (Long i = 0; i < res.size(); ++i)
			ans = (ans * expo(primes[i], res[i], 10)) % 10;

		cout << ans % 10 << "\n";
	}
	return 0;
}
/*
4  
aaba   
aaabababababa   
abbzazzazzalzalzzaaaaazlalzaazlalzla   
w

*/
