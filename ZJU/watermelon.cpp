// 14 15
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1000000000;

template<class T>
struct SegTree {
	T dato, lazy; int i, d;
	SegTree* izq, *der;

	SegTree(int I, int D) 
		: izq(NULL), der(NULL),
		  i(I), d(D), dato(), lazy(0) {}
    
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
    	if (a < i || d < a) return dato;
    	if (a == i || d == a) return dato = min(dato, v);
    	if (!izq) {
    		int m = (i + d) >> 1;
    		izq = new SegTree(i, m);
    		der = new SegTree(m + 1, d);
    	}
    	return dato = min(izq->Actualizar(a, v),
    				  der->Actualizar(a, v));
    }

    void propagate() {
    	if (lazy.precio != 0) {
    		dato = min(dato, lazy);
    		if (izq) {
    			izq->lazy = min(izq->lazy, lazy);
    			der->lazy = min(der->lazy, lazy);
    		}
    		lazy = 0;
    	}
    }

    T ActualizarRango(int a, int b, T v) {
    	propagate();
    	if (b < i || d < a) return T();
    	if (a <= i && d <= b) {
    		dato = min(dato, v);
    		if (izq) {
    			izq->lazy = min(izq->lazy, lazy);
    			der->lazy = min(der->lazy, lazy);
    		}
    		return dato;
    	}
    	return dato = min(izq->ActualizarRango(a, b, v),
    				  der->ActualizarRango(a, b, b));
    }

    T Query(int a, int b) {
    	if (b < i || d < a) return T();
    	propagate();
    	if (a <= i && d <= b) return dato;
    	return izq? min(izq->Query(a, b),
    				der->Query(a, b)): T();
    }
};

struct Melon {
	int precio;
	Melon(int P) : precio(P) {}
	Melon() : precio(INF) {}
	Melon operator+(const Melon& o) {
		return Melon(precio + o.precio);
	}
	bool operator<(const Melon& o) const {
		return precio < o.precio;
	}
};

int main() {
	int N, num;
	while (cin >> N) {
		vector<Melon> V;
		vector<int> tiempo;
		for (int i = 0; i < N; ++i) {
			cin >> num;
			V.push_back({num});
		}
		for (int i = 0; i < N; ++i) {
			cin >> num;
			tiempo.push_back(num);
		}

		SegTree<Melon> tree(0, N - 1);
		tree.Construir();

		for (int i = 0; i < N; ++i) {
			int aux = tree.Query(i, i).precio;
			cout << "valor actual " << aux << endl;
			if (aux == INF)
				tree.ActualizarRango(i, min(N - 1, i + tiempo[i] - 1), V[i]);
				//tree.Actualizar(i, V[i]);
			else				
				tree.ActualizarRango(i, min(N - 1, i + tiempo[i] - 1), V[i] + aux);
				//tree.Actualizar(i, V[i] + aux);
		}
		for (int i = 0; i < N; i++)
			cout << tree.Query(i, i).precio << endl;
		cout << endl << endl << endl;
		cout << tree.Query(N - 1, N - 1).precio;
	}
	return 0;
}
/*
4
10 20 1 40
3 2 3 1

*/
