#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
#define MAXN 200007
#define LN 20

vector<Long> g[MAXN];

//We use the array pa[i][j] for determining 
//the 2^i. parent of the vertex j
Long pa[LN][MAXN];
Long depth[MAXN];
Long pesos[MAXN];

void dfs(Long s, Long parent, Long d){
    depth[s] = d;
    pa[0][s] = parent;

    for (int v : g[s])
        if (depth[v] == -1) 
            dfs(v, s, d + 1);
}

Long LCA(Long u, Long v) {
    if(depth[u] < depth[v]) swap(u, v);

    //search for a new v vertex
    for (int i = LN; i >= 0; --i)
        if (depth[u] - (1<<i) >= depth[v])
            u = pa[i][u];

    if(u == v) return u; //if u and v are the same, we are done

    //now find the lowest common ancestor
    for (int i = LN; i >= 0; --i) {
        if (pa[i][u] != -1 && pa[i][u] != pa[i][v]) {
            u = pa[i][u];
            v = pa[i][v];
        }
    }
    return pa[0][u];
}

void init() {
    for (int i = 0; i < MAXN; ++i)
        depth[i] = -1, pesos[i] = 0;
    
    for (int i = 0; i < LN; ++i)
    for (int j = 0; j < MAXN; ++j)
        pa[i][j] = -1;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    Long n,q; 

    while (cin >> n && n != 0) {
        init();
        for (int i = 1; i < n; ++i) {
            Long a, t;
            cin >> a >> t;
            g[a].push_back(i);
            g[i].push_back(a);
            pesos[i] += pesos[a] + t;
            //pesos[a] += pesos[i] + t;
        }
        
        dfs(0, -1, 0);

        //Fill the pa array
        for (int i = 1; i < LN; ++i)
            for (int j = 0; j < n; ++j)
                if (pa[i - 1][j] != -1)
                    pa[i][j] = pa[i - 1][ pa[i - 1][j] ];

        cin >> q;
        for (int i = 0; i < q; ++i) {
            Long u, v;
            cin >> u >> v;
            cout << pesos[u] + pesos[v] - 2 * pesos[LCA(u, v)] << " ";
            //cout << pesos[u] << " " << pesos[v] << " -> " << 2 * pesos[LCA(u, v)] << "\n";
        }
        cout << "\n";
    }
    return 0;
}
/*
6 4
3 1
1 2
1 0
0 4
4 5

3 2
3 5
1 0
4 2


6
0 8
1 7
1 9
0 3
4 2
4
2 3
5 2
1 4
0 3
2
0 1
2
1 0
0 1
6
0 1000000000
1 1000000000
2 1000000000
3 1000000000
4 1000000000
1
5 0
0
*/
