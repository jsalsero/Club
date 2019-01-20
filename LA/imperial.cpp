#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (Long i = 0; i < n; ++i)
#define rep(i, a, b) for (Long i = a; i < b; ++i)
#define endl '\n'
#define pii pair<Long, Long>
#define Long long long
#define fi first
#define se second
#define vi vector<Long>
using namespace std;

struct uf {
    vector<Long> p;
    uf(Long n) : p(n, -1) {}
    Long find(Long x) { return p[x] < 0 ? x: p[x] = find(p[x]); }
    bool unir(Long x, Long y) {
        Long xp = find(x), yp = find(y);
        if (xp == yp) return false;
        if (p[xp] > p[yp]) swap(xp, yp);
        p[xp] += p[yp], p[yp] = xp;
        return true;
    }
};

const Long LOGN = 17;
const Long  INF = 1e5;

struct meh {
    Long n, r;
    vector< vi > g;
    vector< tuple<Long, Long, Long> > aristas;

    vector< vi > papa;
    vector< vi > maxi;
    vi prof;

    map<pii, Long> M;

    meh(Long N, Long R) :
        g(N),
        aristas(R),
        papa(N, vi(LOGN)),
        maxi(N, vi(LOGN, -INF)),
        prof(N),
        n(N), 
        r(R)
    {}

    void dfs(Long u) {
        for (const auto &var : g[u])
            if (papa[u][0] != var) {
                papa[var][0] = u;
                maxi[var][0] = M[pii(u, var)];
                prof[var] = prof[u] + 1;

                dfs(var);
            }
    }

    Long build(Long s = 0) {
        sort(aristas.begin(), aristas.end());

        uf compo(n);
        
        Long mst = 0;
        forn(i, r) {
            Long u = get<1>(aristas[i]);
            Long v = get<2>(aristas[i]);

            if (compo.unir(u, v)) {
                mst += get<0>(aristas[i]);

                g[u].pb(v);
                g[v].pb(u);
            }
        }

        dfs(s);

        for (Long salto = 1; salto < LOGN; ++salto)
            for (Long u = 0 ; u < n; ++u) {
                Long brinca = papa[u][salto - 1];

                papa[u][salto] = papa[brinca][salto - 1];
                maxi[u][salto] = max(maxi[u][salto - 1], maxi[brinca][salto - 1]);
            }

        return mst;
    }

    Long heaviest(Long a, Long b) {
        if (prof[a] < prof[b]) swap(a, b);

        Long ans = -INF;
        Long dif = prof[a] - prof[b];

        for (Long salto = LOGN - 1; salto >= 0; --salto)
            if (dif & (1<<salto)) {
                ans = max(ans, maxi[a][salto]);
                a = papa[a][salto];
            }

        if (a == b) return ans;

        for (Long salto = LOGN - 1; salto >= 0; --salto)
            if (papa[a][salto] != papa[b][salto]) {
                ans = max(ans, maxi[a][salto]);
                ans = max(ans, maxi[b][salto]);

                a = papa[a][salto];
                b = papa[b][salto];
            }

        ans = max(ans, maxi[a][0]);
        ans = max(ans, maxi[b][0]);

        return ans;
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    Long nodos, aristas;
    while (cin >> nodos >> aristas) {
        meh ciudad(nodos + 7, aristas + 7);

        forn(i, aristas) {
            Long a, b, c;
            cin >> a >> b >> c;
            --a, --b;

            ciudad.aristas[i] = make_tuple(c, a, b);
            ciudad.M[pii(a, b)] = c;
            ciudad.M[pii(b, a)] = c;
        }

        Long mst = ciudad.build();

        Long q;
        cin >> q;

        while (q--) {
            Long a, b;
            cin >> a >> b;
            --a, --b;

            Long nueva = ciudad.M[pii(a, b)];
            cout << mst - ciudad.heaviest(a, b) + nueva << endl;
        }
    }

    return 0;
}

