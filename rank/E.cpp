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

int const MAXN = 1e5 + 7;
const int LOGN = 18;

vector<int> g[MAXN];

int papa[MAXN][LOGN];
int prof[MAXN];
int  tam[MAXN];

void dfs(int u, int p) {
    papa[u][0] = p;
    prof[u] = prof[p] + 1;

    for (const auto &var : g[u]) if (var != p) {
        dfs(var, u);
        tam[u] += tam[var];
    }

    tam[u]++;
}

void build(int n) {
    dfs(0, 0);

    for (int salto = 1; salto < LOGN; ++salto)
        for (int u = 0; u < n; ++u) {
            int brinca = papa[u][salto - 1];
            papa[u][salto] = papa[ brinca ][salto - 1];
        }
}

int sube(int u, int salto) {
    for (int i = 0; i < LOGN; ++i)
        if (salto & (1<<i))
            u = papa[u][i];

    return u;
}

int low(int u, int w) {
    if (prof[u] < prof[w]) swap(u, w);

    u = sube(u, prof[u] - prof[w]);

    if (u == w) return w;

    for (int salto = LOGN - 1; salto >= 0; --salto)
        if (papa[u][salto] != papa[w][salto]) {
            u = papa[u][salto];
            w = papa[w][salto];
        }
    
    return papa[u][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;

        g[u].pb(v);
        g[v].pb(u);
    }

    build(n);

    int m;
    cin >> m;

    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --v, --u;

        if (u == v) {
            cout << n << endl;
            continue;
        }

        int lca = low(u, v);
        int dist = prof[u] + prof[v] - 2 * prof[lca];

        if (dist & 1) {
            cout << 0 << endl;
            continue;
        }

        if (prof[u] < prof[v]) swap(u, v);

        int len = dist/2;
        int x = sube(u, len);
        
        if (x == lca)
            cout << n - tam[ sube(u, len - 1) ] - tam[ sube(v, len - 1) ] << endl;
        else
            cout << tam[x] - tam[ sube(u, len - 1) ] << endl;
    }

    return 0;
}

