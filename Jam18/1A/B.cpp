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

int const MAXN = 10;
Long const INF = (1LL<<40);

Long maxi[MAXN];
Long scan[MAXN];
Long lag[MAXN];

Long r, b, c;

Long act = -INF;
Long ans =  INF;

void dp(int idx, int bits, int mask) {
    if (idx == r)
        if (bits) return;

    if (!bits) {
        ans = min(ans, act);
        return;
    }
    
    forn(cashier, c) {
        if (mask & (1<<cashier)) continue;

        Long tope = min(maxi[cashier], (Long)bits);
        for (int i = 0; i <= tope; ++i) {
            Long prev = act;

            act = max(act, scan[cashier] * i + (i != 0)*lag[cashier]);
            dp(idx + 1, bits - i, mask | (1<<cashier));

            act = prev;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    forn(caso, t) {
        if (caso) cout << endl;
        cout << "Case #" << caso + 1 << ": ";
        
        cin >> r >> b >> c;
        forn(i, c) cin >> maxi[i] >> scan[i] >> lag[i];
        
        dp(0, b, 0);
        cout << ans;
    }    

    return 0;
}

