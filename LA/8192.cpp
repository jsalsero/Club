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

int const MAXN = 1005;
const int INF  = 2000;

string cad;
int n;

int memo[MAXN][MAXN];
 
int dp(int idx, int mod) {
    int &t = memo[idx][mod];

    if (idx == cad.size())
        return t = (mod == 0);

    if (t != -1)
        return t;

    if (isdigit(cad[idx]))
        return t = dp(idx + 1, (10*mod + (cad[idx] - '0')) % n);

    bool ans = false;
    forn(dig, 10) {
        if (!idx && !dig) continue;

        ans |= dp(idx + 1, (10*mod + dig) % n);
    }

    return t = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> cad >> n) {
        forn(i, MAXN)
            forn(j, MAXN)
                memo[i][j] = -1;

        if (!dp(0, 0)) {
            cout << '*' << endl;
            continue;
        }

        int mod = 0;

        forn(i, cad.size()) {
            if (isdigit(cad[i])) {
                cout << cad[i];
                mod = (10*mod + (cad[i] - '0')) % n;
                continue;
            }

            forn(dig, 10) {
                if (!i && !dig) continue;

                int prueba = (10*mod + dig) % n;
                if (memo[i + 1][prueba] == 1) {
                    cout << dig;
                    mod = prueba;
                    break;
                }
            }
        }

        cout << endl;
    }

    return 0;
}

