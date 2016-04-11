// 22 05
#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 30;

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

	T Actualizar(int a, T v) {
		if (a < i || d < a) return dato;
		if (a == i && d == a) return dato = v;
		if (!izq) {
			int m = (i + d) >> 1;
			izq = new SegTree(i, m);
			der = new SegTree(m + 1, d);
		}
		return dato = izq->Actualizar(a, v) +
					  der->Actualizar(a, v);
	}

	T Query(int a, int b) {
		if (b < i || d < a) return T();
		if (a <= i && d <= b) return dato;
		return izq? izq->Query(a, b) +
					der->Query(a, b): T();
	}
};

struct MaxInt {
	int d; MaxInt(int D) : d(D) {}
	MaxInt() : d(INF) {}
	MaxInt operator+(const MaxInt& o) {
		return MaxInt(min(d, o.d));
	}
};

int main() {
	int N, num;
	vector<int> V;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> N) {
		V.clear();
		SegTree<MaxInt> tree(0, N);

		for (int i = 0; i < N; ++i) {
			cin >> num;
			V.push_back(num);
			tree.Actualizar(i, MaxInt(num) );
		}

		vector<int> D;
		if (V[0] > V[1]) D.push_back(0);		
		for (int i = 1; i < N - 1; i++)
			if (V[i - 1] < V[i] && V[i] > V[i + 1]) D.push_back(i);
		if (V[N - 2] < V[N - 1]) D.push_back(N - 1);
		
int der[N];
der[N - 1] = -1;
for (int i = N - 2; i >= 0; i--) {
	der[i] = i + 1;
	while (der[i] != -1 && V[i] >= V[ der[i] ])
		der[i] = der[ der[i] ];
}

		int izq[N];
		izq[0] = -1;
		for (int i = 1; i < N; i++) {
			izq[i] = i - 1;
			while (izq[i] != -1 && V[i] >= V[ izq[i] ])
				izq[i] = izq[ izq[i] ];
		}	

		vector<int> R;
		for (int i = 0; i < D.size(); i++) {
			int a = izq[ D[i] ];
			int b = der[ D[i] ];

			if ((a == -1 || V[ D[i] ] - tree.Query(a, D[i]).d >= 150000) &&
				(b == -1 || V[ D[i] ] - tree.Query(D[i], b).d >= 150000))
				R.push_back(D[i] + 1);
		}
		
		for (int i = 0; i < R.size(); i++) {
			cout << R[i];
			if (i != R.size() - 1)
				cout << " ";
		}
		cout << "\n";
	}
	return 0;
}
/*
5
0 10000 100000 884813 0
7
0 100000 0 200000 180000 200000 0
5
300000 0 700000 0 1000000

*/
