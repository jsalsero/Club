#include <bits/stdc++.h>
using namespace std;

const int MAXN = 70;

int in_degree[MAXN];
vector<int> grafo[MAXN];

void AgregarArista(int u, int v) {
	grafo[u].push_back(v);
	++in_degree[v];
}

struct UnionFind {
	int nconjuntos;
	vector<int> padre;
	vector<int> tamano;

	UnionFind(int n) : nconjuntos(n),
		padre(n), tamano(n, 1) {
		for(int i = 0; i < n; ++i)
			padre[i] = i;
	}

	int Encontrar(int u) {
		if (padre[u] == u) return u;
		return padre[u] = Encontrar(padre[u]);
	}

	void Unir(int u, int v) {
		int Ru = Encontrar(u);
		int Rv = Encontrar(v);
		if (Ru == Rv) return;
		-- nconjuntos, padre[Ru] = Rv;
		tamano[Rv] += tamano[Ru];
	}

	bool MismoConjunto(int u, int v) {
		return Encontrar(u) == Encontrar(v);
	}

	int TamanoConjunto(int u) {
		return tamano[Encontrar(u)];
	}
};

int main() {
	int n,m,num;

	cin >> m >> n;
	UnionFind uf = UnionFind(m*n);

	for(int row = 0; row < n; row++) {
		for(int col = 0; col < m; col++) {
			cin >> num;
			// M*row + col
			switch(num) {
				case 1: // izq
					if(col == 0)
						continue;
					AgregarArista(M*row + col, M*row + col - 1);
					AgregarArista(M*row + col - 1, M*row + col);
				break;

				case 2: // norte
					if(row == 0)
						continue;
					AgregarArista(M*row + col, M*(row - 1) + col);
					AgregarArista(M*(row - 1) + col, M*row + col);
				break;

				case 4: // der
					if(col == m - 1)}
						continue;
					AgregarArista(M*row + col, M*row + col + 1);
					AgregarArista(M*row + col + 1, M*row + col);
				break;

				case 8: // sur
					if(row == n - 1)
						continue;
					AgregarArista(M*row + col, M*(row + 1) + col);
					AgregarArista(M*(row + 1) + col, M*row + col);
				break;

				case 6:
				
				break;

				case 3:
				break;

				case 12:
				break;

				case 9:
				break;

				case 10:
				break;

				case 5:
				break;

				case 13:
				break;

				case 11:
				break;

				case 14:
				break;

				case 7:
				break;

				case 15:
				break;
			}
		}
	}

	return 0;
}