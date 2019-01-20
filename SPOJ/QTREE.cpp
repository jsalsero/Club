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
const int LOGN = 18;
const int INF = 1e9;

struct SegTree {
    int i, d;
    SegTree *izq, *der;
    vector<int> people;

    SegTree(int I, int D) : i(I), d(D), 
        izq(NULL), der(NULL) {}

    ~SegTree() {
        if (izq) delete izq;
        if (der) delete der;
    }

    void build(vector<int> &data) {
        if (i == d) {
            assert(i < data.size());
            val.eb(data[i]);
            return;
        }

        if (!izq) {
           int m = (i + d) / 2;
           izq = new SegTree(i, m);
           der = new SegTree(m + 1, d);
        }

        izq->build(data);
        der->build(data);

        for (const auto &var : izq->people) people.eb(var);
        for (const auto &var : der->people) people.eb(var);

        // reducir a 10 eltos
        int tam = min(10, people.size());
        sort(people.begin(), people.end(), greater<int>());

        while (people.size() > tam) people.pop_back();
    }

/*
    void update(int idx, int dato) {
        if (idx < i || d < idx) return;

        if (i == d) {
            val = dato;
            return;
        }

        izq->update(idx, dato);
        der->update(idx, dato);

        val = mxx(izq->val, der->val);
    }
*/

    vector<int> query(int a, int b) {
        if (b < i || d < a) return vector<int>();

        if (a <= i && d <= b) return people;

        vector<int> ans;

        for (const auto &var : izq->people) ans.eb(var);
        for (const auto &var : der->people) ans.eb(var);

        int tam = min(10, ans.size());
        sort(people.begin(), people.end(), greater<int>());

        while (ans.size() > tam) ans.pop_back();
        
        return ans;
    }
};

struct rompe {
    // graph
    int n;
    vector< vector<pii> > g;
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
        costos(nodos, -INF),
        currChain(),
        last(-1)
    {}

    void dfs(int s) {
        for (const auto &var : g[s]) {
            int nodo = var.fi;
            if (papa[s][0] != nodo) {
                prof[nodo] = prof[s] + 1;
                papa[nodo][0] = s;

                dfs(nodo);
                tams[s] += tams[nodo];
            }
        }

        tams[s]++;
    }

    void HD(int s, int peso) {
        last++;

        if (head[ currChain ] < 0)
            head[ currChain ] = s;

        myChain[s] = {currChain, chain[ currChain ].size()};
        chain[ currChain ].eb(s);
        costos[last] = peso;
        posInSeg[s]  = last;
        
        int mx = -1;
        for (const auto &var : g[s]) 
            if (prof[s] < prof[var.fi])
                if (mx < 0 || tams[var.fi] > tams[mx])
                    mx = var.fi , peso = var.se;

        if (mx != -1)
            HD(mx, peso);

        for (const auto &var : g[s])
            if (prof[s] < prof[var.fi] && var.fi != mx) {
                currChain++;
                HD(var.fi, var.se);
            }
    }

    void build(int s) {
        dfs(s);
        HD(s, -INF);

        arbol.build(costos);
        
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

    int query_up(int bajo, int alto) {
        int ans = -INF;
    
        while (true) {
            int aChain = myChain[alto].fi;
            int bChain = myChain[bajo].fi;

            if (bChain == aChain) {
                if (alto == bajo) break; // no hay arista entre los nodos

                ans = mxx(ans, arbol.query(posInSeg[alto], posInSeg[bajo]));
                break;
            }

            ans = mxx(ans, arbol.query(posInSeg[ head[ bChain ] ], posInSeg[bajo]));
            bajo = head[ bChain ];
            bajo = papa[bajo][0];
        }

        return ans;
    }

    int query(int u, int v) {
        int lca = low(u, v);

        return mxx(query_up(u, lca),
                   query_up(v, lca));
    }

    void update(int idx, int val) {
        int nodo = aristas[idx].fi;

        if (prof[ aristas[idx].fi ] < prof[ aristas[idx].se ])
            nodo = aristas[idx].se;

        arbol.update(posInSeg[ nodo ], val);
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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        rompe arbol(n);

        forn(i, n - 1) {
            int a, b, c;
            cin >> a >> b >> c;
            --a, --b;

            arbol.g[a].pb({b, c});
            arbol.g[b].pb({a, c});

            arbol.aristas[i] = {a, b};
        }

        arbol.build(0);

        while (true) {
            string cad;
            int a, b;

            cin >> cad;
            if (cad[0] == 'D') break;

            cin >> a >> b;

            if (cad[0] == 'Q') cout << arbol.query(a - 1, b - 1) << endl;
            if (cad[0] == 'C') arbol.update(a - 1, b);
        }
    }

    return 0;
}
