#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<Long, Long>
#define fi first
#define se second
#define pb push_back
using namespace std;

const int MAXN = 50007;
const int LOGN = 17;

vector<pii> g[MAXN];

int prof[MAXN];
Long pesos[MAXN];
int parent[MAXN][LOGN];

void dfs(int u, int p, int w) {
    parent[u][0] = p;
    prof[u]  = prof[p] + 1;
    pesos[u] = pesos[p] + w;
        
    for (const auto &var : g[u])
        if (var.fi != p) 
            dfs(var.fi, u, var.se);
}

void build(int n) {
    dfs(0, 0, 0);

    for (int salto = 1; salto < LOGN; ++salto)
        for (int u = 0; u < n; ++u) {
            int sube = parent[u][salto - 1];
            parent[u][salto] = parent[ sube ][salto - 1];
        }
}

int LCA(int u, int v) {
    if (prof[u] < prof[v]) swap(u, v);
    
    for (int salto = LOGN - 1; salto >= 0; --salto)
        if (prof[ parent[u][salto] ] >= prof[v])
            u = parent[u][salto];

    if (u == v) return v;

    for (int salto = LOGN - 1; salto >= 0; --salto)
        if (parent[u][salto] != parent[v][salto]) {
            u = parent[u][salto];
            v = parent[v][salto];
        }

    return parent[u][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    forn(i, n - 1) {
        Long u, v, w;
        cin >> u >> v >> w;

        g[u].pb(pii(v, w));
        g[v].pb(pii(u, w));
    }

    build(n);

    int m;
    cin >> m;

    forn(i, m) {
        int u, v;
        cin >> u >> v;
        
        cout << pesos[u] + pesos[v] - 2 * pesos[LCA(u, v)] << endl;
    }
    
    return 0;
}

