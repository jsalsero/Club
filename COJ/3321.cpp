#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const Long MOD = 10000000000L;

bitset<10000010> bs; // 10^7 should be enough for most
vector<int> primes;

void criba(Long tam) {
	bs.set();
	bs[0] = bs[1];
	for (Long i = 2; i <= tam; ++i) if (bs[i]) {
		for (Long j = i * i; j <= tam; j += i)
			bs[j] = 0;
		primes.push_back((int)i);
	}
}

Long Multiplicar(Long a, Long b, Long m) {
    Long res = 0, p = a;
    for (; b; b >>= 1) {
        if (b & 1) res =
            (res + p) % m;
        p = (p + p) % m;
    }
    return res;
}

//Long memo[10000010];
vector<Long> memo(10000010, 0);
void pre() {
	Long actual = 1;
	//memo[2] = 2;
	for (int i = 0; i < primes.size() - 1 && primes[i] <= MOD; ++i) {
		//actual = (actual % MOD * primes[i] % MOD) % MOD;
		actual = Multiplicar(actual, primes[i], MOD);
		for (int j = primes[i]; j < primes[i + 1]; ++j)
			memo[j] = actual;
	}

}

int main() {
	criba(1005000);
	pre();
	int t;
	int n;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		if (n <= 28) {
			cout << memo[n] << "\n";
			continue;
		}
		string cad = to_string(memo[n]);
		int tam = cad.size();
		for (int i = 0; i < 10 - tam; i++)
			cad = "0" + cad;
		cout << cad << "\n";
	}
	return 0;
}
