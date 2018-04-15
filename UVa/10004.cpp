#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Arista;

const int MAXN = 1000;

int in_degree[MAXN];
vector<int> grafo[MAXN];

void AgregarArista(int u, int v) {
	grafo[u].push_back(v);
	++in_degree[v];
}

char color[MAXN];

bool Bicolorear_(int u, int c) {
	color[u] = c;
	for (int i = 0; i < grafo[u].size(); ++i) {
		int v = grafo[u][i];
		if (color[v] == 1 - c) continue;
		if (color[v] == c) return false;
		if (!Bicolorear_(v, 1 - c)) return false;
	}
	return true;
}

bool Bicolorear(int n) {
	fill(color, color + n, -1);
	for (int i = 0; i < n; ++i)
		if (color[i] == -1 && !Bicolorear_(i, 0))
			return false;
	return true;
}

int main() {
	int N, a, b, l;

	while(cin >> N && N != 0) {
		for(int i = 0; i < N; ++i)
			grafo[i].clear();
		cin >> l;
		for(int i = 0; i < l; i++) {
			cin >> a >> b;
			AgregarArista(a, b);
			AgregarArista(b, a);
		}
		(Bicolorear(N)) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
	}
	return 0;
}