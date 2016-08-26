#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

struct UF {
    int n; vector<int> padre, tam;

    UF(int N) : n(N),
        tam(N, 1), padre(N) {
        while (--N) padre[N] = N;
    }

    int raiz(int u) {
        if (padre[u]== u) return u;
        return padre[u] = raiz(padre[u]);
    }

    void Conecta(int u, int v) {
        int ru = raiz(u);
        int rv = raiz(v);
        if (ru == rv) return;
        --n; padre[ru] = rv;
        tam[rv] += tam[ru];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    while (cin >> n) {
        UF pond((2*n)*(2*n + 1));
        bool impar = true;
        int pos = 0;
        vector<bool> hor((2*n)*(2*n + 1), false);
        vector<bool> ver((2*n)*(2*n + 1), false);
        for (int i = 0; i < 2*n - 1; ++i, impar = !impar) {
            for (int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                if (c == 'H')
                    ver[pos] = ver[pos + 1] = true;
                else
                    hor[pos] = hor[pos + 2*n + 1] = true;
                pos += 2;
            }
            pos = pos + (impar ? 2 : 0); 
        }
        for (int i = 0, pos = 0; i < 2*n; ++i)
            for (int j = 0; j < 2*n + 1; ++j, pos++) {
                if (j != 2*n && !hor[pos])
                    pond.Conecta(pos, pos + 1);
                if (i + 1 != 2*n && !ver[pos])
                    pond.Conecta(pos, pos + 2*n + 1);
            }
        
        cout << pond.n - 1 << '\n';
    }
    return 0;
}
/*
3
HVH
VVV
HHH
HHH
VHV
1
H
1
V
*/ 
