#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int const MAXN = 1e5 + 7;
    
int n;
string cad;

bool go(int k) {
    forn(i, k) {
        if (cad[i] == 'P') continue;
        
        bool valid = true;
        forn(itera, n/k)
            valid &= (cad[(i + itera*k) % n] == 'R');

        if (valid) return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> cad) {
        n = cad.size();

        vector<int> gcd(n + 8);
        rep(i, 2, n)
            gcd[__gcd(i, n)]++;

        bool all = true;
        forn(i, n) all &= (cad[i] == 'R');

        if (all) {
            cout << n - 1 << endl;
            continue;
        }
        
        int ans = 0;
        for (int div = 2; div*div <= n; ++div) {
            if (n % div == 0) {
                if (go(div))
                    ans += gcd[div];

                if (div != n/div && go(n/div))
                    ans += gcd[n/div];
            }
        }

        cout << ans << endl;
    }

    return 0;
}

