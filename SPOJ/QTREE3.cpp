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

int const MAXN = 100 * 1000 + 7;

const int INF = 1e8 + 7;

struct seg {
    seg *izq, *der;
    int ini, fin;
    int dato;

    seg(int I, int F) : 
        ini(I), fin(F),
        izq(NULL), der(NULL),
        dato(INF)
        {}

    void build() {
        if (ini == fin)
            return;

        int m = (ini + fin)/2;
        izq = new seg(ini, m);
        der = new seg(m + 1, fin);

        izq->build();
        der->build();
    }

    int query(int a, int b) {
        if (b < ini || fin < a)
            return INF;

        if (a <= ini && fin <= b)
            return dato;

        return min(izq->query(a, b),
                   der->query(a, b));
    }

    void update(int idx, int val) {
        if (idx < ini || fin < idx) return;

        if (ini == fin) {
            dato = val;
            return;
        }

        izq->update(idx, val);
        der->update(idx, val);

        dato = min(izq->dato, der->dato);
    }
};

struct rompe {
    vector< vector<int> > g;

    vector<int> tam;
    vector<int> prof;
    vector< vector<int> > papi;

    vector<int> head;
    vector<int> myChain;
    vector<int> posInSeg;
    int currChain;
    int last;
    
    seg *tree;

    rompe(int nodos) : 
        g(nodos),
        tam(nodos),
        prof(nodos),
        papi(nodos, vector<int>(17)),
        head(nodos, -1),
        myChain(nodos),
        posInSeg(nodos),
        currChain(),
        last(-1)
        {}

    void dfs(int s = 0) {
        tam[s] = 1;

        for (const auto &var : g[s]) {
            if (papi[s][0] != var) {
                papi[var][0] = s;
                prof[var] = prof[s] + 1;

                dfs(var);

                tam[s] += tam[var];
            }
        }
    }

    void heavy(int s = 0) {
        last++;

        if (head[ currChain ] < 0)
            head[ currChain ] = s;

        myChain[s] = currChain;
        posInSeg[s] = last;

        int mx = -1;

        for (const auto &var : g[s])
            if (prof[var] > prof[s])
                if (mx == -1 || tam[mx] < tam[var])
                    mx = var;

        if (mx != -1)
            heavy(mx);

        for (const auto &var : g[s])
            if (prof[var] > prof[s] && var != mx) {
                currChain++;
                heavy(var);
            }
    }

    void build() {
        dfs();
        heavy();

        tree = new seg(0, last);
        tree->build();
    }

    int query_up(int bajo, int alto) {
        int ans = INF;
        int aChain = myChain[alto];

        while (true) {
            int bChain = myChain[bajo];

            if (aChain == bChain) {
                //cout << "   " << posInSeg[alto] << ' ' << posInSeg[bajo] << endl;
                ans = min(ans, tree->query(posInSeg[alto], posInSeg[bajo]));
                break;
            }

            ans = min(ans, tree->query(posInSeg[head[ bChain ]], posInSeg[bajo]));
            bajo = papi[ head[bChain] ][0];
        }

        return ans;
    }

    void update(int idx) {
        int pos = idx;
        idx = posInSeg[idx];
        
        if (tree->query(idx, idx) >= INF)
            tree->update(idx, pos);
        else
            tree->update(idx, INF);
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    rompe grafo(n + 7);

    forn(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        grafo.g[a].pb(b);
        grafo.g[b].pb(a);
    }

    grafo.build();

    forn(kk, q) {
        int op, idx;
        cin >> op >> idx;
        --idx;

        if (!op)
            grafo.update(idx);
        else {
            int ans = grafo.query_up(idx, 0);
            cout << (ans >= INF ? -1 : 1 + ans) << endl;
        }
    }

    return 0;
}

