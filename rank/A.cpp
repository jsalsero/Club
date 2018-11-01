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

const int MAXN = 100 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

<<<<<<< HEAD
    int n;
    cin >> n;
    
    int acc = 0;
    int ini = 1;
    forn(i, n) {
        int val;
        cin >> val;
        ini = max(ini, val);

        acc += val;
    }
    
    rep(ans, ini, 10000) {
        int yo = ans*n - acc;
        if (yo > acc) {
            cout << ans << endl;
            return 0;
        }
    }

=======
    int n, L, a;
    cin >> n >> L >> a;

    if (!n) {
        cout << L/a << endl;
        return 0;
    }
    
    vector<pii> data(n);
    forn(i, n) cin >> data[i].fi >> data[i].se, data[i].se += data[i].fi;

    Long ans = 0;
    ans += data[0].fi/a;

    forn(i, n - 1) ans += (data[i + 1].fi - data[i].se)/a;

    ans += (L - data.back().se)/a;

    cout << ans << endl;
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
    return 0;
}

