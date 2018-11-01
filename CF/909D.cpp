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

const int MAXN = 1000 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    string cad;
    cin >> cad;

    cad.pb(cad.back());

    int ans = 0;
    int tam = cad.size() - 1;
    while (true) {
        int idx = 0;
        rep(i, 1, tam) {
            if (cad[i - 1] == cad[i]) {
                cad[idx++] = cad[i - 1];

                if (cad[i] == cad[i + 1])
                    cad[idx++] = cad[i];

                ++i;
            }
        }

        if (idx == tam) break;
        tam = idx;
        ans++;

        cout << idx << ' ' <<  cad.substr(tam) << endl;
    }

    cout << ans << endl;
    return 0;
}

// aabb
