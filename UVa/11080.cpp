// UVa 11080 - Place the guards
#include <bits/stdc++.h>
using namespace std;
// 2 25

typedef int Costo;
typedef pair<int,int> Arista;

const Costo INF = 1 << 30;

struct Grafo {
	int n; bool bi;
	vector<vector<int>> ady;
	Grafo(int N, bool b = true)
		: n(N), bi(b), ady(N) {}

	void Conecta(int u, int v) {
		if (bi) ady[v].push_back(u);
		ady[u].push_back(v);
	}

	vector<int> color;
	bool Bicolor(int u, int c) {
		color[u] = c;
		for (int i = 0; i < ady[u].size(); ++i) {
			int v = ady[u][i];
			if (color[v] == 1 - c) continue;
			if (color[v] == c) return false;
			if (!Bicolor(v, 1 - c)) return false;
		}
		return true;
	}

	int guardias;
	bool Bicolor() {
		color = vector<int>(n, -1);
		guardias = 0;
		for (int i = 0; i < n; ++i) {
			if (color[i] == -1 &&
				!Bicolor(i, 0))
				return false;
			int blanco = 0;
			int negro = 0;	
			for (auto &nodo : color) {
				if (nodo == -1 || nodo == 2) continue;
				blanco += (nodo == 0);
				negro  += (nodo == 1);
				nodo = 2;
			}
			if (blanco > negro) swap(blanco, negro);
			if (blanco == 0 && negro == 1) guardias++;
			guardias += blanco;
		}
		return true;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {	
		int n, m;
		cin >> n >> m;
		Grafo g(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			g.Conecta(a, b);
		}
		cout << ((g.Bicolor())? g.guardias: -1) << "\n";
	}
	return 0;
}
/*
2
4 2
0 1
2 3
5 5
0 1
1 2
2 3
0 4
3 4

*/
