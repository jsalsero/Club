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
const int LOGN = 18;

int n, r;

vector<int> g[MAXN];
tuple<Long, int, int> aristas[2 * MAXN];
int papa[MAXN][LOGN];
int maxi[MAXN][LOGN];
int prof[MAXN];

map< pii, int> M;

struct uf {
    vector<int> data;

    uf(int n) : data(n, -1) {}

    int find(int x) { return data[x] < 0? x: data[x] = find(data[x]); }

    bool unir(int a, int b) {
        int xa = find(a);
        int xb = find(b);

        if (xa == xb) return false;

        if (data[xa] > data[xb]) swap(xa, xb);
        data[xa] += data[xb], data[xb] = xa;

        return true;
    }
};

uf kruskal(MAXN);

void dfs(int u) {
    for (const auto &var : g[u]) {
        if (var != papa[u][0]) {
            papa[var][0] = u;
            maxi[var][0] = M[pii(u, var)];

            dfs(var);

            prof[var] = prof[u] + 1;
        }
    }
}

Long solve(int a, int b) {
    if (prof[a] < prof[b]) swap(a, b);
    int pesada = maxi[a][0];

    for (int salto = LOGN - 1; salto >= 0; --salto)
        if (prof[ papa[a][salto] ] >= prof[b]) {
            pesada = max(pesada, maxi[a][salto]);
            a = papa[a][salto];
        }
    
    if (a == b) return pesada;

    for (int salto = LOGN - 1; salto >= 0; --salto)
        if (papa[a][salto] != papa[b][salto]) {
            a = papa[a][salto];
            b = papa[b][salto];

            pesada = max(pesada, maxi[a][salto]);
            pesada = max(pesada, maxi[b][salto]);
        }
    
    pesada = max(pesada, maxi[a][0]);
    pesada = max(pesada, maxi[b][0]);

    return pesada;
}

Long build() {
    sort(aristas, aristas + r);

    Long total = 0;
    forn(i, r) {
        int u = get<1>(aristas[i]);
        int v = get<2>(aristas[i]);

        if (kruskal.unir(u, v)) {
            total += get<0>(aristas[i]);

            g[u].pb(v);
            g[v].pb(u);
        }
    }

    dfs(0);

    for (int salto = 1; salto < LOGN; ++salto) {
        for (int u = 0; u < n; ++u) {
            int sube = papa[u][salto - 1];

            papa[u][salto] = papa[ sube ][salto - 1];
            maxi[u][salto] = max(maxi[u][salto - 1], maxi[ sube ][salto - 1]);
        }
    }

    return total;
}

void limpia() {
    forn(i, n) g[i].clear();
    forn(i, n) prof[i] = 0;
    forn(i, n) kruskal.data[i] = -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> r) {
        forn(i, r) {
            Long a, b, c;
            cin >> a >> b >> c;
            --a, --b;

            aristas[i] = make_tuple(c, a, b);

            M[pii(a, b)] = c;
            M[pii(b, a)] = c;
        }

        Long total = build();

        int m;
        cin >> m;

        forn(it, m) {
            int u, v;
            cin >> u >> v;
            --u, --v;
            
            Long nueva  = M[pii(u, v)];
            Long pesada = solve(u, v);

            cout << total - pesada + nueva << endl;
        }
        limpia();
    }

    return 0;
}

