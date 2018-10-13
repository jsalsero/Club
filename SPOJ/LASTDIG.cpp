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

Long exp(Long a, Long n, Long MOD) {
    Long ans = 1;

    for (; n; n >>= 1LL) {
        if (n & 1)
            ans = (ans * a) % MOD;
        a = (a * a) % MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        Long a, b;
        cin >> a >> b;
        cout << exp(a, b, 10) << endl;
    }

    return 0;
}

