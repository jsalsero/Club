#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define endl '\n'
<<<<<<< HEAD
#define pii pair<int, int>
=======
#define pii pair<Long, Long>
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
#define Long long long
#define fi first
#define se second
using namespace std;

<<<<<<< HEAD
const int MAXN = 100 * 1000 + 7;
const int LOGN = 18;
=======
struct uf {
    vector<int> padre;

    uf(int N) : padre(N) {
        while (--N) padre[N] = N;
    }

    int find(int u) { 
        if (padre[u] == u) return u;
        return padre[u] = find(padre[u]);
    }

    bool unir(int a, int b) {
        int xa = find(a);
        int xb = find(b);

        if (xa == xb) return false;
    
        padre[xa] = xb;
        return true;
    }
};

const int MAXN = 2000 * 1000 + 7;
const int LOGN = 21;
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0

int n, r;

vector<int> g[MAXN];
<<<<<<< HEAD
tuple<Long, int, int> aristas[2 * MAXN];
=======
tuple<Long, int, int> aristas[MAXN];
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
int papa[MAXN][LOGN];
int maxi[MAXN][LOGN];
int prof[MAXN];

map< pii, int> M;

<<<<<<< HEAD
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

=======
void limpia() {
    M.clear();
    forn(i, n + 5) {
        g[i].clear();
        prof[i] = 0;
        fill(papa[i], papa[i] + LOGN, 0);
        fill(maxi[i], maxi[i] + LOGN, 0);
    }
}

void dfs(int u, int p) {
    papa[u][0] = p;
    prof[u] = prof[p] + 1;

    for (const auto &var : g[u]) {
        if (var != p) {
            //papa[var][0] = u;
            maxi[var][0] = M[pii(u, var)];
            //prof[var] = prof[u] + 1;

            dfs(var, u);
        }
    }
}

/*
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
void dfs(int u) {
    for (const auto &var : g[u]) {
        if (var != papa[u][0]) {
            papa[var][0] = u;
            maxi[var][0] = M[pii(u, var)];
<<<<<<< HEAD

            dfs(var);

            prof[var] = prof[u] + 1;
        }
    }
}
=======
            prof[var] = prof[u] + 1;

            dfs(var);
        }
    }
}
*/
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0

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
<<<<<<< HEAD
            a = papa[a][salto];
            b = papa[b][salto];

            pesada = max(pesada, maxi[a][salto]);
            pesada = max(pesada, maxi[b][salto]);
=======
            pesada = max(pesada, maxi[a][salto]);
            pesada = max(pesada, maxi[b][salto]);

            a = papa[a][salto];
            b = papa[b][salto];
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
        }
    
    pesada = max(pesada, maxi[a][0]);
    pesada = max(pesada, maxi[b][0]);

    return pesada;
}

Long build() {
    sort(aristas, aristas + r);

<<<<<<< HEAD
=======
    uf kruskal(n);

>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
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

<<<<<<< HEAD
    dfs(0);
=======
    dfs(0, 0);
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0

    for (int salto = 1; salto < LOGN; ++salto) {
        for (int u = 0; u < n; ++u) {
            int sube = papa[u][salto - 1];

            papa[u][salto] = papa[ sube ][salto - 1];
            maxi[u][salto] = max(maxi[u][salto - 1], maxi[ sube ][salto - 1]);
        }
    }

    return total;
}

<<<<<<< HEAD
void limpia() {
    forn(i, n) g[i].clear();
    forn(i, n) prof[i] = 0;
    forn(i, n) kruskal.data[i] = -1;
}

=======
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> r) {
<<<<<<< HEAD
=======
        assert(n <= 1e5);
        assert(r <= 2e5);

>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
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
<<<<<<< HEAD
            int u, v;
=======
            Long u, v;
>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
            cin >> u >> v;
            --u, --v;
            
            Long nueva  = M[pii(u, v)];
            Long pesada = solve(u, v);

            cout << total - pesada + nueva << endl;
        }
<<<<<<< HEAD
=======

>>>>>>> 90aed97eaff97ff07139c6102ba883f43c234de0
        limpia();
    }

    return 0;
}

