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

const int MAXN = 5000 + 7;
const int  MOD = 1e9 + 7;

int n; 
string data;

Long memo[MAXN][MAXN];

Long dp(int idx, int depth) {
    Long &t = memo[idx][depth];

    if (t != -1)  return t;
    if (idx == n - 1) return t = 1;

    if (data[idx] == 'f')
        t = dp(idx + 1, depth + 1);
    else
        t = (depth? dp(idx, depth - 1): 0) + dp(idx + 1, depth);

    t %= MOD;
    return t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    forn(i, MAXN)
        forn(j, MAXN)
            memo[i][j] = -1;

    cin >> n;

    data = string(n, ' ');
    forn(i, n) cin >> data[i];

    cout << dp(0, 0);
    return 0;
}

