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

int const MAXN = 7500;

vector<int> coin;
Long memo[MAXN][MAXN];

Long dp(int n, int ini) {
    Long &t = memo[n][ini];
    
    if (!n)      return t = 1;
    if (t != -1) return t;

    t = 0;

    rep(i, ini, coin.size())
        if (n - coin[i] >= 0)
            t += dp(n - coin[i], i);

    return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    coin = {1, 5, 10, 25, 50};

    forn(i, MAXN)
        forn(j, MAXN)
            memo[i][j] = -1;

    int n;
    while (cin >> n)
        cout << dp(n, 0) << endl;

    return 0;
}

