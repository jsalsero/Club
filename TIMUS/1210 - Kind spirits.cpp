#include <bits/stdc++.h>
using namespace std;

typedef int Costo;
typedef pair<int, int> Arista;

const Costo INF = 1 << 30;

typedef pair<Costo, int> CostoNodo;
typedef pair<Costo, Arista> Ponderada;

struct GrafoPonderado {
	int n; bool bi;
	vector<vector<CostoNodo>> ady;
	GrafoPonderado(int N, bool B)
		: n(N), bi(B), ady(N) {}

	void Conecta(int u, int v, Costo c) {
		if (bi) ady[v].push_back(CostoNodo(c, u));
		ady[u].push_back(CostoNodo(c, v));
	}

	vector<Costo> dist;

	bool Bellman(int s) {
		queue<int> q;
		vector<bool> en_cola(n);
		vector<int> procesado(n);
		dist = vector<Costo>(n, INF);
		q.push(s), dist[s] = 0;

		while (!q.empty()) {
			int u = q.front();
			q.pop(), en_cola[u] = false;
			if (++procesado[u] == n) return true;
			for (CostoNodo arista : ady[u]) {
				int v = arista.second;
				Costo p = arista.first;
				if (dist[u] + p < dist[v]) {
					if (!en_cola[v]) q.push(v);
					dist[v] = dist[u] + p;
					en_cola[v] = true;
				}
			}
		}
		return false;
	}
};

int main() {
	int n;
	cin >> n;
	GrafoPonderado universe(100, false);

	int actual = 1;
	int prev = 0;
	int check;
	for (int j = 0; j < n; ++j) {
		int planets;
		cin >> planets;
		if (j == n - 1)
			check = planets;
		for (int i = 0; i < planets; ++i) {
			int pos;
			while (cin >> pos && pos != 0) {
				int costo;
				cin >> costo;
				universe.Conecta(actual - prev - i - pos, actual, costo);
			}
			actual++;
		}
		char c;
		if (j != n - 1)
			cin >> c;
		prev = n;
		cout << "asdf";
	}
	bool cycle = universe.Bellman(0);
	int ans = INF;
	for (int i = check; i < actual; ++i)
		ans = min(ans, universe.dist[i]);
	cout << ans << '\n';
	return 0;
}
