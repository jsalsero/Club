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

int const MAXN = 2005;

int n;
int data[MAXN];
int memo[MAXN][5];

int dp(int idx, int state) {
    int &t = memo[idx][state];

    if (t != -1) return t;

    if (idx == n || state == 4)
        return t = 0;
    
    bool jump;
    if (data[idx] == 1)
        jump = (state != 0 && state != 2);
    else
        jump = (state != 1 && state != 3);

    int ans = 0;
    
    if (state != 3 || (state == 3 && data[idx] == 2))
        ans = max(ans, dp(idx + 1, state + jump) + 1);

    ans = max(ans, dp(idx + 1, state));

    return t = ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    forn(i, MAXN)
        forn(j, 5)
            memo[i][j] = -1;

    cin >> n;
    forn(i, n) cin >> data[i];

    cout << dp(0, 0) << endl;
    return 0;
}

