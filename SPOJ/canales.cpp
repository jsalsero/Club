#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;

int const MAXN = 5005;
const int LOGN = 17;
const int INF = 1e9;

struct SegTree {
    int i, d;
    SegTree *izq, *der;
    int dato;

    SegTree(int I, int D) : i(I), d(D), 
        izq(NULL), der(NULL), dato() {}

    ~SegTree() {
        if (izq) delete izq;
        if (der) delete der;
    }

    void build() {
        if (i == d)
            return;

        if (!izq) {
           int m = (i + d) / 2;
           izq = new SegTree(i, m);
           der = new SegTree(m + 1, d);
        }

        izq->build(severla, data);
        der->build(severla, data);
    }

    int query(int a, int b) {
        if (b < i || d < a) return 0;

        if (a <= i && d <= b) return dato;

        int ans = 0;

        ans += izq->query(a, b);
        ans += der->query(a, b);
        
        return ans;
    }
};

struct rompe {
    // graph
    int n;
    vector< vector<int> > g;
    vector<pii> aristas;
   
    //lca
    vector<int> prof;
    vector<vector<int>> papa;
    
    SegTree arbol;
    vector<int> tams;
    vector<int> head;
    vector<pii> myChain;
    vector<vector<int>> chain;
    vector<int> posInSeg;
    int currChain;

    vector<int> costos;

    int last;
 
    rompe(int nodos) : 
        n(nodos),
        g(nodos),
        aristas(nodos),

        prof(nodos),
        papa(nodos, vector<int>(LOGN)),

        arbol(0, nodos - 1),
        tams(nodos),
        head(nodos, -1),
        myChain(nodos),
        chain(nodos),
        posInSeg(nodos),
        severla(nodos), 
        costos(nodos, -INF),
        currChain(),
        last(-1)
    {}

    void dfs(int s) {
        for (const auto &nodo : g[s]) {
            if (papa[s][0] != nodo) {
                prof[nodo] = prof[s] + 1;
                papa[nodo][0] = s;

                dfs(nodo);
                tams[s] += tams[nodo];
            }
        }

        tams[s]++;
    }

    void HD(int s) {
        last++;

        if (head[ currChain ] < 0)
            head[ currChain ] = s;

        myChain[s] = {currChain, chain[ currChain ].size()};
        chain[ currChain ].pb(s);
        posInSeg[s] = last;
        
        int mx = -1;
        for (const auto &var : g[s]) 
            if (prof[s] < prof[var])
                if (mx < 0 || tams[var] > tams[mx])
                    mx = var;

        if (mx != -1)
            HD(mx);

        for (const auto &var : g[s])
            if (prof[s] < prof[var] && var != mx) {
                currChain++;
                HD(var);
            }
    }

    void build(int s, vector<vector<int>> &banda) {
        dfs(s);
        HD(s);
        
        for (int u = 0; u < n; ++u) {
            for (int salto = 1; salto < LOGN; ++salto) {
                int brinca = papa[u][salto - 1];
                papa[u][salto] = papa[brinca][salto - 1];
            }
        }
    }

    int low(int a, int b) {
        if (prof[a] < prof[b]) swap(a, b);
        
        for (int salto = LOGN - 1; salto >= 0; --salto)
            if (prof[ papa[a][salto] ] >= prof[b])
                a = papa[a][salto];

        if (a == b) return a;

        for (int salto = LOGN - 1; salto >= 0; --salto) {
            if (papa[a][salto] != papa[b][salto]) {
                a = papa[a][salto];
                b = papa[b][salto];
            }
        }

        return papa[a][0];
    }

    set<int> query_up(int bajo, int alto) {
        set<int> ans;
    
        while (true) {
            int aChain = myChain[alto].fi;
            int bChain = myChain[bajo].fi;

            if (bChain == aChain) {
                //assert(posInSeg[alto] <= posInSeg[bajo]);

                for (const auto &var: arbol.query(posInSeg[alto], posInSeg[bajo]))
                    ans.insert(var);
                
                break;
            }

            for (const auto &var: arbol.query(posInSeg[ head[ bChain ] ], posInSeg[bajo]))
                ans.insert(var);

            bajo = head[ bChain ];
            bajo = papa[bajo][0];
        }

        return ans;
    }

    set<int> query(int u, int v) {
        int lca = low(u, v);

        auto ans = query_up(u, lca);

        for (const auto &var : query_up(v, lca))
            ans.insert(var);

        return ans;
    }

    void print() {
        for (int idx = 0; idx < chain.size(); ++idx) {
            if (!chain[idx].size()) break;
            cout << idx << ": ";
            for (const auto &var : chain[idx])
                cout << var << ' ';
            cout << endl;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    rompe grafo(n);

    forn(i, n) {
        int a, b;
        cin >> a >> b;
        a--, --b;

        grafo.g[a].pb(b);
        grafo.g[b].pb(a);
    }

    while (m--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        --a, --b;

        if (op == 'P') {// inundar
            grafo.update(a, b);
        } else {
            cout << grafo.query(a, b) << endl;
        }
    }


    return 0;
}

