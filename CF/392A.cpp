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

    Long n;
    cin >> n;

    if (!n) {
        cout << 1 << endl;
        return 0;
    }
    
    Long ans = 0;
    for (Long y = n, x = 0; y >= 0; --y) {
        Long prev = x;
        while (y * y + x * x <= n * n) ++x;
        --x;

        if (prev < x) ans += x - prev;
        else ans++;
    }

    cout << (ans - 1) * 4 << endl;
    return 0;
}

