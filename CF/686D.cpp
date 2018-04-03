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

int const MAXN = 6 * 1000 * 100 + 7;
int const  INF = (1<<30);

int tam[MAXN];
int atras[MAXN];

struct SegTree {
    int i, d;
    SegTree *izq, *der;
    vector<pii> data;

    SegTree(int I, int D) : izq(NULL), der(NULL), i(I), d(D) {}

    ~SegTree() {
        if (izq) delete izq;
        if (der) delete der;
    }

    void build() {
        if (i == d) {
            data.eb(tam[ atras[i] ], atras[i]);
            return;
        }
 
        if (!izq) {
            int m = (i + d) >> 1;
            izq = new SegTree(i, m);
            der = new SegTree(m + 1, d);
        }
 
        izq->build();
        der->build();      

        data.resize(izq->data.size() + der->data.size());
        merge(izq->data.begin(), izq->data.end(), 
              der->data.begin(), der->data.end(), 
              data.begin());
    }

    pii centroid(int ini, int fin, pii want) {
        pii meh(INF, INF);

        if (ini <= i && d <= fin) {
            auto it = lower_bound(data.begin(), data.end(), want);
            if (it == data.end())
                return meh;

            return *it;
        }

        if (fin < i || d < ini)
            return meh;

        return izq? min(izq->centroid(ini, fin, want),
                        der->centroid(ini, fin, want)): meh;
    }
};

pair<int, int> tour[MAXN];
vector<int> arbol[MAXN];
int t;

int dfs(int u) {
    tam[u] = 1;

    atras[t] = u;
    tour[u].fi = t++;

    for (const auto &v : arbol[u])
        dfs(v), tam[u] += tam[v];
    
    atras[t] = u;
    tour[u].se = t++;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    forn(i, n - 1) {
        int v; 
        cin >> v;

        arbol[v - 1].eb(i + 1);
    }

    dfs(0);
    
    SegTree euler(0, t);
    euler.build();

    forn(i, q) {
        int v;
        cin >> v;
        --v;
        
        cout << euler.centroid(tour[v].fi, tour[v].se, pii((tam[v] + 1)/2, 0)).se + 1 << endl;
    }

    return 0;
}

