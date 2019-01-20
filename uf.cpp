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

struct uf {
    vector<int> data;

    uf(int n) : data(n, -1){}

    int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

    bool unir(int x, int y) {
        int xp = find(x), yp = find(y);
        if (xp == yp) return false;
        if (p[xp] > p[yp]) swap(xp, yp);
        p[xp] += p[yp], p[yp] = xp;
        return true;
    }

    int size(int x) { return -p[find(x)]; }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}

