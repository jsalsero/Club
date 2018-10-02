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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    int ans = 0;
    for (int i = 1; i <= 5 * 100000; ++i) {
        // tipo A
        if (i <= n && 2*i <= m) {
            int aux = min((n - i)/2, m - 2*i);
            ans = max(ans, i + aux);
        }

        // tipo B
        if (2*i <= n && i <= m) {
            int aux = min(n - 2*i, (m - i)/2);
            ans = max(ans, i + aux);
        }
    }
    
    cout << ans << endl;
    return 0;
}

