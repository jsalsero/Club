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

int const MAXN = 5005;
const int LOGN = 18;
const int INF = 1e9;

struct SegTree {
    int i, d;
    SegTree *izq, *der;
    int val;

    SegTree(int I, int D) : i(I), d(D), 
        izq(NULL), der(NULL), val(-INF) {}

    void update(int idx, int val) {
        if (idx < i || d < idx) return;

        if (!izq) {
           int m = (i + d) / 2;
           izq = new SegTree(i, m);
           der = new SegTree(m + 1, d);
        }

        izq->update(idx, val);
        der->update(idx, val);

        val = max(izq->val, der->val);
    }

    int query(int a, int b) {
        if (b < i || d < a) return -INF;

        if (a <= i && d <= b) return val;

        return max(izq->query(a, b),
                   der->query(a, b));
    }
};

struct chain {
    // graph
    int n;
    vector< vector<int> > g;

    vector<int> tams;
    
    //lca
    vector<int> prof;
    vector<vector<int>> papa;

    chain(int nodos) : 
        n(nodos),
        papa(nodos, vector<int>(LOGN)),
        prof(nodos),
        tams(nodos),
        g(nodos)
    {}

    void dfs(int s) {
        for (const auto &var : g[s])
            if (papa[s][0] != var) {
                prof[var] = prof[s] + 1;

                dfs(var);
                tams[s] += tams[var];
            }

        tams[s]++;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}

