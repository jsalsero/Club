#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (Long i = 0; i < n; ++i)
#define rep(a, b, n) for (int i = a; i < b; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long long long
#define fi first
#define se secon
using namespace std;

const int MAXN = 100 * 1000 + 7;

int data[MAXN];

template<class T>
struct SegTree {
    int i, d;
    int lazy;
    SegTree *izq, *der;
    T dato;

    SegTree(int I, int D) : lazy(), i(I), d(D), izq(NULL), der(NULL), dato() {}

    ~SegTree() {
        if (izq) delete izq;
        if (der) delete der;
    }

    void build() {
        if (i == d) {
            dato = T(data[i]);
            return;
        }

        int m = (i + d) >> 1;
        izq = new SegTree(i, m);
        der = new SegTree(m + 1, d);

        izq->build();
        der->build();

        dato = izq->dato + der->dato;
    }

    void propagate() {
        dato.inv(lazy, d - i + 1);

        if (izq) {
            izq->lazy ^= lazy;
            der->lazy ^= lazy;
        }

        lazy = 0;
    }

    void update(int a, int b, int v) {
        propagate();
        if (d < a || b < i) return;

        if (a <= i && d <= b) {
            dato.inv(v, d - i + 1);

            if (izq) {
                izq->lazy ^= v;
                der->lazy ^= v;
            }

            return;
        }

        izq->update(a, b, v);
        der->update(a, b, v);

        dato = izq->dato + der->dato;
    }

    T query(int a, int b) {
        if (d < a || b < i) return T();
        propagate();

        if (a <= i && d <= b) return dato;

        if (!izq) return T();

        T ans(0);
        ans = izq->query(a, b) + ans;
        ans = der->query(a, b) + ans;

        return ans;
    }
};

int MAXX = 20;
struct sum {
    vector<int> cub;
    int tam;

    sum() : cub(MAXX) {}

    sum(int n) : cub(MAXX) {
        forn(i, MAXX)
            cub[i] = ((n & (1LL<<i)) > 0LL);
    }

    void inv(int a, int tam) {
        forn(i, MAXX)
            if ((a & (1<<i)) > 0)
                cub[i] = tam - cub[i];
    }

    sum operator+(const sum &a) {
        sum ans(0);
        forn(i, MAXX)
            ans.cub[i] = (cub[i] + a.cub[i]);

        return ans;
    }

    Long toNum() {
        Long ans = 0;
        forn(i, MAXX)
            ans += cub[i] * (1LL<<i); 
    
        return ans;
    }
};

int n, m, tipo, a, b, x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    forn(i, n) cin >> data[i];

    SegTree<sum> T(0, n - 1);
    T.build();

    cin >> m;
    while (m--) {
        cin >> tipo >> a >> b;
        --a, --b;

        if (tipo == 1)
            cout << T.query(a, b).toNum() << endl;
        else
            cin >> x, T.update(a, b, x);
    }

    return 0;
}

