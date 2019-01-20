#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(Long i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int const MAXN = 5005;
const Long INF = 3e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    Long d, m, d1, n, d2;
    cin >> d >> m >> d1 >> n >> d2;
    
    Long ans = INF;
    forn(grande, 64) {
        if (grande > m) break;

        if (d <= 0) {
            ans = min(ans, grande);
            break;
        }

        Long aux = d;
        forn(chico, 64) {
            if (chico > n) break;
            if (chico + grande > 63) break;
            
            if (aux <= 0) {
                ans = min(ans, grande + chico);
                break;
            }

            aux = 2LL*aux - d2;
        }

        d = 2LL*d - d1;
    }

    if (ans == INF) ans = -1;
    cout << ans << endl;

    return 0;
}

