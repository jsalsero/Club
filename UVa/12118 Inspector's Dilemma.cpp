#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct UF {
    int n; vector<int> padre, tam;

    UF(int N) : n(N),
        tam(N, 1), padre(N) {
        while (--N) padre[N] = N;
    }

    int Raiz(int u) {
        if (padre[u] == u) return u;
        return padre[u] = Raiz(padre[u]);
    }

    bool SonConexos(int u, int v) {
        return Raiz(u) == Raiz(v);
    }

    void Unir(int u, int v) {
        int ru = Raiz(u);
        int rv = Raiz(v);
        if (ru == rv)   return;
        --n, padre[ru] = rv;
        tam[rv] += tam[ru];
    }

    int Tamano(int u) {
        return tam[Raiz(u)];
    }

    // No. de conjuntos con tam > 1
    int islas() {
        set<int> S;
        for (int i = 0; i < padre.size(); i++)
            S.insert(Raiz(i));
        int ans = 0;
        for (auto var : S)
            if (Tamano(var) > 1)
                ans++;
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int v, e, t, caso = 1;
    while (cin >> v >> e >> t) {
        if (v == 0 && e == 0 && t == 0)
            break;
        cout << "Case " << caso++ << ": ";
        if (e == 0) {
            cout << "0\n";
            continue;
        }

        UF cities(v);
        vector<int> degree(v, 0), odds(v, 0);

        for (int i = 0; i < e; ++i) {
            int a, b;
            cin >> a >> b;
            cities.Unir(a - 1, b - 1);
            degree[a - 1]++;
            degree[b - 1]++;
        }
        
        for (int i = 0; i < v; ++i)
            if (degree[i]&1)
                odds[cities.Raiz(i)]++;
        
        int ans = e + cities.islas() - 1;
        for (int i = 0; i < v; ++i) {
            if (odds[i] >= 4)
                ans += odds[i]/2 - 1;
        }
        cout << t * ans << "\n";
    }
    return 0;
}
/*
5 3 100
1 2
1 3
4 5
4 4 100
1 2
1 4
2 3
3 4
0 0 0

*/
