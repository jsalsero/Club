#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long long long
#define fi first
#define se second
using namespace std;

const int MAXN = 1000 + 7;

int n;
Long data[MAXN];

bool valid(int len) {
    vector<Long> x(len);

    x[0] = data[1];
    rep(i, 1, len)
        x[i] = data[i + 1] - data[i];

    rep(i, 1, n + 1)
        if (data[i] != x[(i - 1 + len) % len] + data[i - 1])
            return false;

    return true;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    forn(i, n) cin >> data[i + 1];
    
    vector<int> ans;
    rep(len, 1, n + 1)
        if (valid(len)) ans.pb(len);

    cout << ans.size() << endl;
    for (const auto &var : ans)
        cout << var << ' ';
    cout << endl;
   
    return 0;
}

