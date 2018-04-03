#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

struct BIT {
	vector<int> tree;
	BIT(int n) : tree(n + 1) {}

	void Actualizar(int i, int v) {
		while (i < tree.size()) {
			tree[i] += v;
			i += i & -i;
		}
	}

	Long Query(int i) {
		Long sum = 0;
		while (i > 0) {
			sum += tree[i];
			i -= i & -i;
		}
		return sum;
	}
};

struct Grafo {
	int n; bool bi;
	vector<vector<int>> ady;
	vector<pair<int, int>> tiempo;
	vector<int> nivel;
	vector<bool> vis;
	int t;
	Grafo(int N, bool B = true)
		: n(N), bi(B), ady(N), vis(N, false), tiempo(N), t(1),
		  nivel(N) {}

	void Conecta(int u, int v) {
		if (bi) ady[v].push_back(u);
		ady[u].push_back(v);
	}

	void DFS(int s, int dep) {
		tiempo[s].first = t++;
		vis[s] = true;
		nivel[s] = dep;
		for (int node : ady[s])
			if (!vis[node])
				DFS(node, dep + 1);
		tiempo[s].second = t++;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	BIT acc(n);
	vector<int> v(n);
	Grafo arbol(n);

	for (int i = 0; i < n; ++i)
		cin >> v[i];
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		arbol.Conecta(a - 1, b - 1);
	}
	arbol.DFS(0, 0);

	for (int i = 0; i < m; ++i) {
		int oper, node;
		cin >> oper;
		if (oper == 1) {
			int val;
			cin >> node >> val;
			node--;
			if (arbol.nivel[node]&1)
				acc.Actualizar(arbol.tiempo[node].first, val),
				acc.Actualizar(arbol.tiempo[node].second, -val);
			else
				acc.Actualizar(arbol.tiempo[node].first, -val),
				acc.Actualizar(arbol.tiempo[node].second, val);			
		} else {
			cin >> node;
			node--;
			if (arbol.nivel[node]&1)
				cout << v[node] - acc.Query(arbol.tiempo[node].first) << '\n';
			else
				cout << v[node] + acc.Query(arbol.tiempo[node].first) << '\n';
		}
	}
	return 0;
}
/*
5 5
1 2 1 1 2
1 2
1 3
2 4
2 5
1 2 3
1 1 2
2 1
2 2
2 4

*/
