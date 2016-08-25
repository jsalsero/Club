#include <bits/stdc++.h>
using namespace std;

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
        cout << n << " -> " << pond.n << endl;
        bool impar = true;
        int pos = 0;
        vector<char> last;
        for (int i = 0; i <= 2*n - 1; ++i, impar = !impar) {
            for (int j = 0; j < n; ++j) {
                char c;
                cin >> c;
                if (i == 2*n - 1)
                    last.push_back(c);
                if (impar) { // impar (i,2j - 1)
                    if (c == 'H') {
                        pond.Conecta(pos, pos + 1);
                        if (j != n - 1)
                            pond.Conecta(pos + 1, pos + 2);
                    } else {
                        pond.Conecta(pos, pos + 2*n + 1);
                        if (j != n - 1)
                            pond.Conecta(pos + 1, pos + 1 + 2*n + 1);
                    }
                } else { // par  (i,2j)
                    pond.Conecta(pos, pos + 1);                 
                    if (c == 'H')
                        pond.Conecta(pos + 1, pos + 2);
                    else {
                        pond.Conecta(pos, pos + 2*n + 1);
                        if (j != n - 1)
                            pond.Conecta(pos + 1, pos + 1 + 2*n + 1);
                    }
                }
                pos += 2;
            }
            pos--;
        }
        pond.Conecta(pos, pos + 1);                 

        for (int i = 0; i < last.size() - 1; ++i) {
            if (last[i] == 'H')
                pond.Conecta(pos + 1, pos + 2);
            else {
                pond.Conecta(pos, pos + 2*n + 1);
                if (pos != 2*n)
                    pond.Conecta(pos + 1, pos + 1 + 2*n + 1);
            }
            pos += 2;
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
