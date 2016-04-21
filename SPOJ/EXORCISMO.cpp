#include <bits/stdc++.h>
using namespace std;

template<class T>
struct SegTree {

    T dato; int i, d, lazy;
    SegTree* izq, *der;

    SegTree(int I, int D)
        : izq(NULL), der(NULL),
          i(I), d(D), dato(), lazy(0){}

    ~SegTree() {
        if (izq) delete izq;
        if (der) delete der;
    }

    T Construir() {
        if (i == d) return dato = T(1, 0, 0);
        int m = (i + d) >> 1;
        izq = new SegTree(i, m);
        der = new SegTree(m + 1, d);
        return dato = izq->Construir() +
                      der->Construir();
    }

    void propagate() {
        if(lazy != 0) {
            if (izq) {
                izq->lazy = (izq->lazy + lazy) % 3;
                der->lazy = (der->lazy + lazy) % 3;
            }
            while (lazy--)
                dato = dato >> 1;
            lazy = 0;
        }
    }

    T ActualizarRango(int l, int r) {
        if (r < i || d < l) return T();
        propagate();
        if (l <= i && d <= r) {
            dato = dato >> 1;
            if (izq) {
                izq->lazy = (izq->lazy + 1) % 3;
                der->lazy = (der->lazy + 1) % 3;
            }
            return dato;
        }
        return dato = izq->ActualizarRango(l, r) +
                      der->ActualizarRango(l, r);
    }

    T Query(int a, int b) {
        if (b < i || d < a) return T();
        propagate();
        if (a <= i && d <= b) return dato;
        return izq? izq->Query(a, b) +
                    der->Query(a, b): T();
    }
};

// A continuación se ejemplifica como sobrecargar
// el operador + dentro de una estructura para poder
// reutilizar el codigo del Segment Tree facilmente.
// El ejemplo sobrecarga el + por la funcion de maximo.
// Es MUY IMPORTANTE tener un constructor por defecto.

struct TRI {
    int cero, uno, dos;
    TRI() : cero(0), uno(0), dos(0) {}
    TRI(int a, int b, int c) : cero(a), uno(b), dos(c){}

    TRI operator+(const TRI &a) {
        return TRI(cero + a.cero, uno + a.uno, dos + a.dos);
    }

    TRI operator>>(int veces) {
        return TRI(dos, cero, uno);
    }
};

int main() {
    int N, Q, a, b, c;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> Q;
    SegTree<TRI> tree(0, N - 1);
    tree.Construir();

    for (int i = 0; i < Q; ++i) {
        cin >> c >> a >> b;
        if (c == 0)
            tree.ActualizarRango(a, b);
        else
            cout << tree.Query(a, b).cero << "\n";
    }
    return 0;
}
/*
4 7
1 0 3
0 1 2
0 1 3
1 0 0
0 0 3
1 3 3
1 0 3

*/
