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

void meh(vector<int> &data) {
    set<int> chafa;

    chafa = set<int>(data.begin(), data.end());

    for (const auto &var : chafa) cout << var << ' '; cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<int> data(200, 10);
    meh(data);

    if (data.size() > 10) data.resize(10);

    for (auto var : data) cout << var << ' '; cout << endl;

    return 0;
}

