#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(a, b, n) for (int i = a; i < b; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long long long
#define fi first
#define se secon
using namespace std;

const int MAXN = 100 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    forn(caso, t) {
        if (caso) cout << endl;

        Long d;
        string cad;

        cin >> d >> cad;
        
        int p = cad.size();
        int ans = 0;
        Long acc = 0;
        forn(it, 1000) {
            Long hit = 1;
            acc = 0;

            forn(i, p)
                if (cad[i] == 'S')
                    acc += hit;
                else
                    hit *= 2LL;

            if (acc <= d) break;

            ans++;

            for (int i = p - 2; i >= 0; --i) {
                if (cad[i] == 'C' && cad[i + 1] == 'S') {
                    swap(cad[i], cad[i + 1]);
                    break;
                }
            }
        }
        
        cout << "Case #" << caso + 1 << ": ";
        if (acc <= d)  
            cout << ans;
        else
            cout << "IMPOSSIBLE";
    }

    return 0;
}

