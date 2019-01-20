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
#define vi vector<int>
using namespace std;

int const MAXN = 1e5 + 7;
const int LOGN = 17;

vi g[MAXN];

int papa[MAXN][LOGN];
int prof[MAXN];

vi people[MAXN][LOGN];

void merge(vi &a, vi &b) {
    a.insert(a.end(), b.begin(), b.end());
    sort(a.begin(), a.end());

    if (a.size() > 10) a.resize(10);
}

void dfs(int s) {
    for (const auto &var : g[s])
        if (papa[s][0] != var) {
            papa[var][0] = s;
            prof[var] = prof[s] + 1;

            dfs(var);
        }
}

void build(int n) {
    dfs(0);

    for (int salto = 1; salto < LOGN; ++salto)
        for (int u = 0; u < n; ++u) {
            int brinca = papa[u][salto - 1];
            if (brinca < 0) continue;

            papa[u][salto] = papa[brinca][salto - 1];

            people[u][salto] = people[u][salto - 1];
            merge(people[u][salto], people[brinca][salto - 1]);
        }
}

void print(vi &a) { 
    cout << "   ";
    for (const auto &var : a) cout << var << ' '; cout << endl;
}

vi lca(int a, int b) {
    if (prof[a] < prof[b]) swap(a, b);

    vi ans;
    
    int dif = abs(prof[a] - prof[b]);
    for (int bit = 0; bit < LOGN; ++bit)
        if (dif & (1<<bit)) {
            merge(ans, people[a][bit]);
            a = papa[a][bit];
        }

    if (a == b) {
        merge(ans, people[a][0]);
        return ans;
    }
    
    for (int salto = LOGN - 1; salto >= 0; --salto) {
        if (papa[a][salto] != papa[b][salto]) {
            merge(ans, people[a][salto]);
            merge(ans, people[b][salto]);

            a = papa[a][salto];
            b = papa[b][salto];
        }
    }

    merge(ans, people[a][0]);
    merge(ans, people[b][0]);
    merge(ans, people[ papa[a][0] ][0]);

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
/*
    forn(i, MAXN)
    forn(j, LOGN)
        papa[i][j] = -1;
*/

    int n, m, q;
    cin >> n >> m >> q;

    forn(i, n - 1) {
        int a, b;
        cin >> a >> b;
        --a, --b;

        g[a].eb(b);
        g[b].eb(a);
    }

    forn(i, m) {
        int idx;
        cin >> idx;
        
        if (people[idx - 1][0].size() < 10)
            people[idx - 1][0].eb(i + 1);
    }

    forn(i, n) sort(people[i][0].begin(),
                    people[i][0].end());

    build(n);

    forn(i, q) {
        int a, b, tam;
        cin >> a >> b >> tam;
        --a, --b;

        auto meh = lca(a, b);
        tam = min(tam, (int)meh.size());

        cout << tam << ' ';
        forn(ii, tam) cout << meh[ii] << ' '; cout << endl;
    }

    return 0;
}

