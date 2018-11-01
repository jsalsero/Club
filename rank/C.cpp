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

string cad;
bitset<MAXN> mark;

vector<pii> bloque;

void go(int fin) {
    int idx  = 0;
    while (idx < fin) {
        while (idx < fin && cad[idx] == 'b') idx++;

        int len = 0;
        while (idx < fin && 'a' == cad[idx]) {
            len++;
            idx++;
        }

        bloque.pb({len, idx - len});
    }
}

solve(int fin) {
    mayor =;

    if (mayor >= bloque[0].fi) {
        swapeas
        solve(
    } else {
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> cad;

    mark.reset();

    go(cad.size());

    solve(bloque.size());

    forn(i, cad.size())
        cout << mark[i] << ' ';
    cout << endl;

    return 0;
}

