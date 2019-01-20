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

const int MAXN = 100 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<pii> s;
    s.insert({1, 4});
    s.insert({5, 10});

    auto it = s.upper_bound({3, 7});
    if (it != s.begin() && 3 < (*it).fi) it--;
    cout << (*it).fi << endl;

    return 0;
}

