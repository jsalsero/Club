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

int const MAXN = 1000 * 100 + 7;

vector<int> g[MAXN];
bitset<MAXN> vis;
int deg[MAXN];

int acc;

bool dfs(int u, int p) {
    vis[u] = 1;
    acc++;

    for (const auto &v : g[u]) {
        if (v == p) continue;
        if (vis[v]) return true;
        vis[v] = 1;
        dfs(v, u);
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int k, w;
    while (cin >> k >> w && k) {
        map<int, int> M;
        int idx = 0;
        vis.reset();

        forn(i, MAXN) deg[i] = 0;
        forn(i, MAXN) g[i].clear();

        set<pii> S;

        forn(i, w) {
            int a, b;
            cin >> a >> b;

            if (a > b) swap(a, b);

            if (M.find(a) == M.end()) M[a] = idx++;
            if (M.find(b) == M.end()) M[b] = idx++;

            S.insert(pii(M[a], M[b]));
        }

        for (const auto &edge : S) {
            int a = edge.fi;
            int b = edge.se;

            g[a].eb(b);
            g[b].eb(a);

            deg[a]++;
            deg[b]++;
        }

        bool ans = true;
        forn(i, idx) {
            ans &= (deg[i] <= 2);
            acc = 0;
            if (!vis[i])
                if (dfs(i, -1) && acc != k)
                    ans = false;
        }

        cout << (ans? 'Y': 'N') << endl;
    }

    return 0;
}

