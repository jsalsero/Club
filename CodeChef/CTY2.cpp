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

int const MAXN = 5005;

int n, m;
vector<int> data;

int memo[300][55];

int dp(int n, int idx) {
    int &t = memo[n][idx];

    if (t)      return t;
    if (n == 0) return 1;
    
    int ans = 0;
    for (int sig = idx; sig < m; ++sig)
        if (n - data[sig] >= 0)
            ans += dp(n - data[sig], sig);

    return t = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    data = vector<int>(m);
    forn(i, m) cin >> data[i];

    cout << dp(n, 0) << endl;

    return 0;
}

