#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1 << 30;
const int MAXN = 150001;
typedef long long Long;

template<class T>
struct SegTree {
	T dato; int i, d;
	SegTree* izq, *der;

	SegTree(int I, int D) 
		: izq(NULL), der(NULL),
		  i(I), d(D), dato() {}
    
    ~SegTree() {
    	if (izq) delete izq;
    	if (der) delete der;
    }

    T Construir() {
        if (i == d) return dato = T();
        int m = (i + d) >> 1;
        izq = new SegTree(i, m);
        der = new SegTree(m + 1, d);
        return dato = izq->Construir() +
                      der->Construir();
    }

    T Actualizar(int a, T v) {
    	if (a < i || d < a) return T();
    	if (a == i && d == a) return dato = min(dato, v);
    	if (!izq) {
    		int m = (i + d) >> 1;
    		izq = new SegTree(i, m);
    		der = new SegTree(m + 1, d);
    	}
    	return dato = min(izq->Actualizar(a, v),
    				  der->Actualizar(a, v));
    }

    T Query(int a, int b) {
    	if (b < i || d < a) return T();
    	if (a <= i && d <= b) return dato;
    	return izq? min(izq->Query(a, b),
    				der->Query(a, b)): T();
    }
};

struct Melon {
	Long precio;
	Melon(Long P) : precio(P) {}
	Melon() : precio(INF) {}
	Melon operator+(const Melon& o) {
		return Melon(precio + o.precio);
	}
	bool operator<(const Melon& o) const {
		return precio < o.precio;
	}
};

int main() {
	Long N, num;

    ios_base::sync_with_stdio(0);
    cin.tie(0);

	while (cin >> N) {
		vector<Melon> V;
		vector<Long> tiempo;
		for (int i = 0; i < N; ++i) {
			cin >> num;
			V.push_back(Melon(num));
		}

		for (int i = 0; i < N; ++i) {
			cin >> num;
			tiempo.push_back(num);
		}

		SegTree<Melon> tree(0, N - 1);

        tree.Actualizar(min(tiempo[0] - 1, N - 1), V[0]);
		for (int i = 1; i < N; ++i) {
			Melon aux = tree.Query(i - 1, N - 1);
            tree.Actualizar(min(i + tiempo[i] - 1, N - 1), aux + V[i]);
		}
        Long res = tree.Query(N - 1, N - 1).precio;
        cout << res << "\n";
	}
	return 0;
}
/*
4
10 20 1 40
3 2 3 1

4
100000 100000 100000 100000
1 1 1 1 


*/
