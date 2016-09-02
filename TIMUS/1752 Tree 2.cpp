#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

#define MAXN 100007
#define LN 17

vector<Long> g[MAXN];
Long padre[LN][MAXN];
Long depth[MAXN];
Long pesos[MAXN];

void dfs(int s, int parent, int d) {
	depth[s] = d;
	padre[0][s] = parent;

	for (int v : g[s]) if (depth[v] == -1)
		dfs(v, s, d + 1);
}

void init(int N) {
	for (int i = 0; i < N; ++i)
		depth[i] = -1,
		pesos[i] = 0,
		g[i].clear();
}

void Construir(int N) {
	dfs(0, -1, 0);

	for (int i = 1; i < LN; ++i)
		for (int j = 0; j < N; ++j)
			if (padre[i - 1][j] != -1)
				padre[i][j] = padre[i - 1][ padre[i - 1][j] ];
}

int main() {

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	for (int i = 0; i < q; ++i) {
		int node, d;
		cin >> node >> d;

	}
	return 0;
}
