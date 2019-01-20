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

int const MAXN = 17;

int n, m;
int data[MAXN][MAXN];
int uno[MAXN][MAXN];
int dos[MAXN][MAXN];

int memo[MAXN][1<<MAXN][MAXN];

int dp(int ini, int mask, int last) {
    int &t = memo[ini][mask][last];

    if (t != -1)
        return t;

    if (!mask)
        return t = dos[ini][last];

    forn(u, n) if (u != last && (mask & (1<<u)))
        t = max(t, min(uno[last][u], dp(ini, mask ^ (1<<last), u)));

    return t;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    forn(i, n) forn(j, m)
        cin >> data[i][j];
    
    forn(i, n) forn(j, n) {
        dos[i][j] = uno[i][j] = 1e9 + 7;

        forn(k, m) {
            uno[i][j] = min(uno[i][j], abs(data[i][k] - data[j][k]));
            
            if (k + 1 < m)
                dos[i][j] = min(dos[i][j], abs(data[i][k] - data[j][k + 1]));
        }
    }

    forn(i, MAXN)
        forn(j, (1<<MAXN))  
            fill(memo[i][j], memo[i][j] + MAXN, -1);

    int ans = 0;
    forn(u, n)
        ans = max(ans, dp(u, (1<<n) - 1, u));

    cout << ans << endl;
    return 0;
}

