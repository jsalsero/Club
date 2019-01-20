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

void go(int n) {
    map<int, int> M;

    rep(i, 2, n)
        M[__gcd(i, n)]++;
    
    cout << n << endl;
    for (const auto &var : M)
        if (var.fi > 1 && var.se > 1)
            cout << "   " << var.fi << ' ' << var.se << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    rep(i, 2, 80)
        go(i);

    return 0;
}

