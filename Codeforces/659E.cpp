#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct union_find {
	vector<int> p; union_find(int n) : p(n, -1) { }
	int find(int x) { return p[x] < 0? x: p[x] = find(p[x]); }
	bool unir(int x, int y) {
		int xp = find(x), yp = find(y);
		if (xp == yp) return false;
		if (p[xp] > p[yp]) swap(xp, yp);
		p[xp] += p[yp], p[yp] = xp;
		return true;
	}
	int size(int x) { return -p[find(x)]; }
};

typedef int Costo;

vector<bool> vis;

struct Grafo {
	int n; bool bi;
	vector<vector<int>> ady;
	Grafo(int N, bool B = true)
		: n(N), bi(B), ady(N) {}

	void Conecta(int u, int v) {
		if (bi) ady[v].push_back(u);
		ady[u].push_back(v);
	}

	bool dfs(int u, int p) {
		bool ans = false;
		vis[u]   = true;
		for (int v : ady[u]) {
			if (v == p) continue;
			if (vis[v])
				ans = true;
			else
				ans |= dfs(v, u);
		}
		return ans;
	}
};

int main() {
	int n, m;

	cin >> n >> m;
	
	Grafo city(n);
	union_find uf(n);
	vis.assign(n, false);

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		city.Conecta(a - 1, b - 1);
		uf.unir(a - 1, b - 1);
	}

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (vis[i]) continue;
		ans += !city.dfs(i, -1);
	}

	cout << ans << endl;
	return 0;
}
