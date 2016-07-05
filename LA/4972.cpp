#include <bits/stdc++.h>
using namespace std;

//17:32
typedef long long Long;

const double ERROR = 1e-9;
const double M_2PI = 2 * M_PI;

bool Igual(double a, double b) {
	return fabs(a - b) < ERROR;
}

struct Punto {
	double x, y;

	Punto() : x(), y() {}
	Punto(double X, double Y) : x(X), y(Y) {}

	bool operator<(const Punto& cmp) const {
		if (!Igual(x, cmp.x)) return x < cmp.x;
		return Igual(y, cmp.y)? false: y < cmp.y;
	}

	bool operator==(const Punto& cmp) const {
		return Igual(x, cmp.x) && Igual(y, cmp.y);
	}
};

Punto Trasladar(const Punto& o, const Punto& p) {
	return Punto(p.x - o.x, p.y - o.y);
}

double Cruz(const Punto& v, const Punto& w) {
	return v.x * w.y - v.y * w.x;
}

int ManoDerecha(const Punto& o, const Punto& p, const Punto& q) {
	double ccw = Cruz(Trasladar(o, p), Trasladar(o, q));
	return Igual(ccw, 0)? 0: (ccw < 0)? -1: 1;
}

struct Linea {
	Punto p, q;
	Long a, b, c;

	Linea() : p(), q(), a(), b(), c() {}

	Linea(const Punto& P, const Punto& Q)
		: p(P), q(Q), a(), b(), c() {
		if (q < p) swap(p, q);
		a = q.y - p.y;
		b = p.x - q.x;
		if (!a) c = p.y, b = -1;
		else if (!b) c = p.x, a = -1;
		else {
			c = abs(__gcd(a, b));
			a /= c, b /= c;
			c = -a*p.x - b*p.y;
		}
	}

	bool operator<(const Linea& cmp) const {
		if (!Igual(a, cmp.a)) return a < cmp.a;
		if (!Igual(b, cmp.b)) return b < cmp.b;
		return Igual(c, cmp.c)? false: c < cmp.c;
	}
};

bool PuntoEnRecta(const Punto& p, const Linea& r) {
	return !ManoDerecha(r.p, r.q, p);
}

bool PuntoEnSegmento(const Punto& p, const Linea& s) {
	return PuntoEnRecta(p, s) && !(p < s.p || s.q < p);
}

bool LineasParalelas(const Linea& l, const Linea& m) {
	return l.a == m.a && l.b == m.b;
}

bool LineasIguales(const Linea& l, const Linea& m) {
	return LineasParalelas(l, m) && Igual(l.c, m.c);
}

int IntersecRectaSegmen(const Linea& r, const Linea& s) {
	if (LineasIguales(r, s)) return -1;
	if (LineasParalelas(r, s)) return 0;
	int t1 = ManoDerecha(r.p, r.q, s.p);
	int t2 = ManoDerecha(r.p, r.q, s.q);
	return (t1 != t2)? 1: 0;
}

int InterseccionSegmentos(const Linea& s, const Linea& t) {
	int t1 = ManoDerecha(s.p, s.q, t.p);
	int t2 = ManoDerecha(s.p, s.q, t.q);

	if (t1 == t2) return t1? 0:
		(PuntoEnSegmento(s.p, t) ||
		 PuntoEnSegmento(s.q, t) ||
		 PuntoEnSegmento(t.p, s) ||
		 PuntoEnSegmento(t.q, s))? -1: 0;

	return (ManoDerecha(t.p, t.q, s.p) !=
			ManoDerecha(t.p, t.q, s.q))? 1: 0;
}

Punto PuntoInterseccion(const Linea& l, const Linea& m) {
	assert(!LineasParalelas(l, m));
	if (Igual(l.a, 0)) return Punto((double)(l.c * m.b + m.c) / -m.a, l.c);
	double y = (double)(m.a*l.c - l.a*m.c) / 
					   (m.b*l.a - m.a*l.b);
	return Punto((double)(l.c + l.b * y) / -l.a, y);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	vector< vector<int> > precios(10, vector<int>(10, 0));
	vector< vector<Linea> > caminos(10, vector<Linea>(10));
	int t = 1;
	while (cin >> n >> c && n != 0 && c != 0) {
		for (int i = 0; i < n; ++i) {
			fill(precios[i].begin(), precios[i].end(), 0);
			fill(caminos[i].begin(), caminos[i].end(), Linea());
		}

		vector<Punto> P;
		for (int i = 0; i < n; ++i) {
			double x, y;
			cin >> x >> y;
			P.push_back(Punto(x, y));
		}

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				caminos[i][j] = caminos[j][i] = Linea(P[i], P[j]);

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> precios[i][j];
			
		vector<int> A;
		for (int i = 1; i < n; i++) A.push_back(i);
		Long res = 1 << 30;

		do {
			vector<Linea> actual;
			int prev = 0;
			Long acc = 0;
			for (int i = 0; i < n - 1; prev = A[i], i++) {
				acc += precios[prev][A[i]];
				actual.push_back(caminos[prev][A[i]]);
			}
			acc += precios[A[n - 2]][0];
			actual.push_back(caminos[A[n - 2]][0]);

			set<Punto> intersec;
			for (int i = 0; i < n; ++i) {
				Punto ini = actual[i].p;
				Punto fin = actual[i].q;
				for (int j = i + 1; j < n; ++j) {
					Linea aux = actual[j];
					if (ini == aux.p || ini == aux.q || fin == aux.p || fin == aux.q) continue;
					if (InterseccionSegmentos(actual[i], actual[j]))
						intersec.insert(PuntoInterseccion(actual[i], actual[j]));					
				}
			}
			
			for (auto cruce : intersec) {
				Long k = 0;
				for (auto linea : actual)
					if (PuntoEnSegmento(cruce, linea)) k++;
				acc += ((k*(k-1))/2)*c;
			}
			res = min(res, acc);
		} while(next_permutation(A.begin(), A.end()));
		cout << t++ << ". " << res << "\n";
	}
	return 0;
}
/*
4 1 
1 2 
0 1 
2 1 
1 0 
0 1 8 3
1 0 3 9
8 3 0 2
3 9 2 0
4 100 
1 2 
0 1 
2 1 
1 0 
0 1 8 3
1 0 3 9
8 3 0 2
3 9 2 0
0 0

5 1 
-1 -1
3 -2
5 1
1 1
2 3
0 1 4 8 6
1 0 2 2 4
4 2 0 5 3 
8 2 5 0 7
6 4 3 7 0

*/
