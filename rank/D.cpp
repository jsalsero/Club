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

int const MAXN = 1005;
int const INF = 1e9;
    
int n, m, s, t;
vector<int> g[MAXN];

bitset<MAXN> vis;

void bfs(vector<int> &dist, int s) {
    queue<int> q;
    q.push(s);

    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (const auto &v : g[u]) if (!vis[v]) {
            dist[v] = min(dist[v], dist[u] + 1);

            vis[v] = true;
            q.push(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<pii> edge;
    cin >> n >> m >> s >> t;

    --s, --t;

    forn(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        
        if (u > v) swap(u, v);
        edge.insert(pii(u, v));

        g[u].eb(v);
        g[v].eb(u);
    }

    vector<int> home(n, INF);
    vector<int> work(n, INF);
    
    vis.reset();
    vis[s] = true;
    bfs(home, s);

    vis.reset();
    vis[t] = true;
    bfs(work, t);

    int ans = 0;
    int best = home[t];
    forn(i, n) {
        rep(j, i + 1, n) {
            if (edge.find(pii(i, j)) != edge.end()) continue;

            int nuevo = INF;
            nuevo = min(nuevo, (home[i] + work[j] + 1));
            nuevo = min(nuevo, (home[j] + work[i] + 1));
            
            ans += (nuevo >= best);
        }
    }
    
    cout << ans << endl;
    return 0;
}

