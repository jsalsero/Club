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

int const MAXN = 10000 + 7;
const int LOGN = 18;

vector<pii> g[MAXN];

int prof[MAXN];
Long peso[MAXN];
int papi[MAXN][LOGN];

void dfs(int s = 0) {
    for (const auto &var : g[s]) {
        int nodo  = var.fi;
        int costo = var.se;

        if (papi[s][0] == nodo) continue;

        prof[nodo] = prof[s] + 1;
        peso[nodo] += peso[s] + costo;
        papi[nodo][0] = s;

        dfs(nodo);
    }
}

void LIMPIA() {
    forn(i, MAXN) {
        g[i].clear();
        prof[i] = 0;
        peso[i] = 0;

        forn(j, LOGN)
            papi[i][j] = 0;
    }
}

void build(int n) {
    dfs();

    rep(salto, 1, LOGN)
        forn(nodo, n) {
            int brinca = papi[nodo][salto - 1];
            papi[nodo][salto] = papi[brinca][salto - 1];
        }
}

int sube(int a, int len) {
    forn(bit, LOGN)
        if (len & (1<<bit))
            a = papi[a][bit];

    return a;
}

int low(int a, int b) {
    if (prof[a] < prof[b]) swap(a, b);

    a = sube(a, prof[a] - prof[b]);

    if (a == b) return a;

    for (int salto = LOGN - 1; salto >= 0; --salto) {
        if (papi[a][salto] != papi[b][salto]) {
            a = papi[a][salto];
            b = papi[b][salto];
        }
    }

    return papi[a][0];
}

Long dist(int a, int b) {
    return peso[a] + peso[b] - 2LL*peso[low(a, b)];
}

int go(int a, int b, int k) {
    int lca = low(a, b);

    if (k <= prof[a] - prof[lca] + 1) {
        --k;
        return sube(a, k);
    } else {
        int dif = prof[b] - prof[lca];
        k -= (prof[a] - prof[lca] + 1);
        dif -= k;

        return sube(b, dif);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    forn(caso, t) {
        LIMPIA();

        int n;
        cin >> n;

        forn(i, n - 1) {
            Long a, b, c;
            cin >> a >> b >> c; 
            --a, --b;

            g[a].pb({b, c});
            g[b].pb({a, c});
        }

        build(n);

        string op;
        while (cin >> op) {
            if (op == "DONE") break;

            if (op[0] == 'D') {
                int a, b;
                cin >> a >> b;
                --a, --b;

                cout << dist(a, b) << endl;
            } else {
                int a, b, k;
                cin >> a >> b >> k;
                --a, --b;

                cout << 1 + go(a, b, k) << endl;
            }
        }

        cout << endl;
    }

    return 0;
}

