#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

#define MAXN 20007
#define LN 17

vector<int> g[MAXN];

int padre[LN][MAXN];
int depth[MAXN];

int padre2[LN][MAXN];
int depth2[MAXN];

void dfs(int s, int parent, int d, int papa[17][MAXN], int *prof) {
	prof[s] = d;
	papa[0][s] = parent;

	for (int v : g[s]) if (prof[v] == -1)
		dfs(v, s, d + 1, papa, prof);
}

int LCA(int u, int v, int *prof) {
	if (prof[u])
}

void init(int N, int *prof) {
	for (int i = 0; i < N; ++i)
		prof[i] = -1;
}

void initPadre(int N) {
	for (int i = 0; i < LN; ++i)
		for (int j = 0; j < MAXN; ++j)
			padre[i][j] = padre2[i][j] = -1;
}

void Construir(int s, int N, int papa[17][MAXN], int *prof) {
	dfs(s, -1, 0, papa, prof);

	for (int i = 1; i < LN; ++i)
		for (int j = 0; j < N; ++j)
			if (papa[i - 1][j] != -1)
				papa[i][j] = papa[i - 1][ papa[i - 1][j] ];
}

int solve(int node, int dist, int papa[17][MAXN], int *prof) {
	for (int i = LN - 1; i >= 0; --i)
		if (prof[node] - (1<<i) > dist)
			node = papa[i][node];
	return node;
}

int main() {
	int n, q;
	cin >> n >> q;
	initPadre(n);
	init(n, depth);
	init(n, depth2);

	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
		
	Construir(0, n, padre, depth);
	int idx = 0;
	for (int i = 1; i < n; ++i)
		if (depth[idx] < depth[i])
			idx = i;
	init(n, depth);
	Construir(idx, n, padre, depth);

	idx = 0;
	for (int i = 1; i < n; ++i)
		if (depth[idx] < depth[i])
			idx = i;

	Construir(idx, n, padre2, depth2);

	for (int i = 0; i < q; ++i) {
		int node, d;
		cin >> node >> d;
		if (d > max(depth[node - 1], depth2[node - 1]))
			cout << "0\n";
		else {
			if (depth[node - 1] > depth2[node - 1]) {
				cout << solve(node - 1, depth[node - 1] - d, padre, depth) << '\n';
			} else {
				cout << solve(node - 1, depth2[node - 1] - d, padre2, depth2) << '\n';
			}
		}
	}
	return 0;
}
