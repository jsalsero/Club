#include <bits/stdc++.h>
using namespace std;

typedef long long Long;

#define MAXN 20007
#define LN 15

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

void init(int N, int *prof, int papa[17][MAXN]) {
	for (int i = 0; i < N; ++i)
		prof[i] = -1;
		
	for (int i = 0; i < LN; ++i)
		for (int j = 0; j < MAXN; ++j)
			papa[i][j] = -1;
}

void Construir(int s, int N, int papa[17][MAXN], int *prof) {
	init(N, prof, papa);
	dfs(s, -1, 0, papa, prof);

	for (int i = 1; i < LN; ++i)
		for (int j = 0; j < N; ++j)
			if (papa[i - 1][j] != -1)
				papa[i][j] = papa[i - 1][ papa[i - 1][j] ];
}

int solve(int node, int dist, int papa[17][MAXN], int *prof) {
	//cout << "dist actual " << dist << " from " << node + 1 << "\n";
	for (int i = LN - 1; i >= 0; --i) {
		/*
		if (papa[i][node] != -1)
			cout << "    " << papa[i][node] << " -> " << prof[ papa[i][node] ] << endl;
		*/
		if (papa[i][node] != -1 && prof[ papa[i][node] ] >= dist) {
			//cout << "  subiendo ->  " << setw(3) << papa[i][node] << endl;
			//dist -= prof[ papa[i][node] ];
			node = papa[i][node];
		}
	}
	//cout << "dist final " << prof[node] << " nodo final-> " << node << "\n";
	return node;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	int IZQ, DER;
	cin >> n >> q;

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
	Construir(idx, n, padre, depth);
	IZQ = idx;
	
	idx = 0;
	for (int i = 1; i < n; ++i)
		if (depth[idx] < depth[i])
			idx = i;
	DER = idx;
	
	Construir(idx, n, padre2, depth2);

	//cout << "(" << IZQ+1 << ", " << DER+1 << ")\n";
	for (int i = 0; i < q; ++i) {
		int node, d;
		cin >> node >> d;
		if (d > max(depth[node - 1], depth2[node - 1]))
			cout << "0\n";
		else {
			if (depth[node - 1] > depth2[node - 1]) {
				//cout << "          			         prof " << depth[node - 1] << endl;
				cout << solve(node - 1, depth[node - 1] - d, padre, depth) + 1 << '\n';
			} else {
				//cout << "          			         prof " << depth2[node - 1] << endl;
				cout << solve(node - 1, depth2[node - 1] - d, padre2, depth2) + 1 << '\n';
			}
		}
	}
	return 0;
}
