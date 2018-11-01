#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long long long
#define fi first
#define se second
using namespace std;

<<<<<<< HEAD
const int MAXN = 1000 + 7;
=======
int const MAXN = 1e6 + 7;

bitset<MAXN> bs;
vector<int> primes;
//int last[MAXN];

void criba() {
    bs.set();

    bs[0] = bs[1] = 0;
    for (Long i = 2; i < MAXN; ++i) if (bs[i]) {
        for (Long j = i*i; j < MAXN; j += i)
            bs[j] = 0;

        primes.pb((int)i);
        //last[i] = i;
    }
}
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0

string cad;
bitset<MAXN> mark;

<<<<<<< HEAD
vector<pii> bloque;

void go(int fin) {
    int idx  = 0;
    while (idx < fin) {
        while (idx < fin && cad[idx] == 'b') idx++;

        int len = 0;
        while (idx < fin && 'a' == cad[idx]) {
            len++;
            idx++;
        }

        bloque.pb({len, idx - len});
    }
}

solve(int fin) {
    mayor =;

    if (mayor >= bloque[0].fi) {
        swapeas
        solve(
    } else {
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> cad;

    mark.reset();

    go(cad.size());

    solve(bloque.size());

    forn(i, cad.size())
        cout << mark[i] << ' ';
    cout << endl;
=======
    criba();

    int n;
    while (cin >> n) {
    
    int unos = 1; // contamos el primer uno, porque no es primo
    
    int idx = upper_bound(primes.begin(), primes.end(), n) - primes.begin();
    unos += idx + 1;

    unos -= (idx < primes.size() && primes[idx] > n);

    if (n < 4) {
        forn(i, n - 1) cout << 1 << ' ';
        cout << n << endl;
        return 0;
    }

    forn(i, unos) cout << 1 << ' ';

    set<int> all;
    forn(i, n) if (i > 0 && !bs[i + 1])
        all.insert(i + 1); 
    
    int gcd, borra;
    while (all.size()) {
        gcd = *all.rbegin();
        borra = gcd;

        for (const auto &var : all) {
            int nuevo = __gcd(gcd, var);

            if (nuevo < gcd)
                borra = var;
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0

            gcd = nuevo;
        }

        cout << gcd << ' ' ;
        all.erase(all.find(borra));
    }

    cout << endl;
    }
    return 0;
}

