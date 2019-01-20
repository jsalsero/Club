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

int const MAXN = 1000*100 + 7;
int const LOGN = 17;

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



struct basura {
    int n, r;

    vector<int> g[MAXN];
    tuple<Long, int, int> aristas[MAXN];
    int papa[MAXN][LOGN];
    int maxi[MAXN][LOGN];
    int prof[MAXN];

    map< pii, int> M;

    basura(int N, int R) : n(N), r(R) {}

    void dfs(int u) {
        for (const auto &var : g[u])
            if (var != papa[u][0]) {
                papa[var][0] = u;
                maxi[var][0] = M[pii(u, var)];

                dfs(var);
                prof[u] += prof[var];
            }

        prof[u]++;
    }

    Long heaviest(int a, int b) {
        if (prof[a] < prof[b]) swap(a, b);
        int pesada = maxi[a][0];

        int dif = abs(prof[a] - prof[b]);
        for (int salto = 0; salto < LOGN; ++salto)
            if (dif & (1<<salto)) {
                pesada = max(pesada, maxi[a][salto]);
                a = papa[a][salto];
            }
        
        if (a == b) return pesada;

        for (int salto = LOGN - 1; salto >= 0; --salto)
            if (papa[a][salto] != papa[b][salto]) {
                pesada = max(pesada, maxi[a][salto]);
                pesada = max(pesada, maxi[b][salto]);

                a = papa[a][salto];
                b = papa[b][salto];
            }
        
        pesada = max(pesada, maxi[a][0]);
        pesada = max(pesada, maxi[b][0]);

        return pesada;
    }

    Long build() {
        sort(aristas, aristas + r);

        //uf kruskal(n);

        Long total = 0;
        forn(i, r) {
            int u = get<1>(aristas[i]);
            int v = get<2>(aristas[i]);
            /*

            if (kruskal.unir(u, v)) {
                total += get<0>(aristas[i]);

                g[u].pb(v);
                g[v].pb(u);
            }
            */
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
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b;
    while (cin >> a >> b) {
        basura meh(a, b);
    }
    //forn(i, 10) cout << meh.data[i] << ' '; cout << endl;

    return 0;
}

