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

int const MAXN = 1000 + 7;
int const LOGN = 10;

vector<int> g[MAXN];

int prof[MAXN];
int papa[MAXN][LOGN];

void dfs(int u, int p) {
    papa[u][0] = p;
    prof[u] = prof[p] + 1;

    for (const auto &var : g[u])
        if (var != p)
            dfs(var, u);
}

void build(int n) {
    dfs(0, 0);

    for (int salto = 1; salto < LOGN; ++salto)
        for (int u = 0; u < n; ++u) {
            int sube = papa[u][salto - 1];
            papa[u][salto] = papa[ sube ][salto - 1];
        }
}

int lca(int u, int v) {
    if (prof[u] < prof[v]) swap(u, v);

    for (int salto = LOGN - 1; salto >= 0; --salto)
        if (prof[ papa[u][salto] ] >= prof[v])
            u = papa[u][salto];

    if (u == v) return v;

    for (int salto = LOGN - 1; salto >= 0; --salto)
        if (papa[u][salto] != papa[v][salto]) {
            u = papa[u][salto];
            v = papa[v][salto];
        }

    return papa[v][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int casos;
    cin >> casos;

    forn(CC, casos) {
        int n;
        cin >> n;
        
        forn(i, n) g[i].clear();

        forn(i, n) {
            int len;
            cin >> len;

            forn(kk, len) {
                int u;
                cin >> u;
                --u;

                g[i].pb(u);
                g[u].pb(i);
            }
        }

        build(n);

        int q;
        cin >> q;

        cout << "Case " << CC + 1 << ":" << endl;

        forn(meh, q) {
            int u, v;
            cin >> u >> v;
            --u, --v;

            cout << 1 + lca(u, v) << endl;
        }
    }

    return 0;
}

