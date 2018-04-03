#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> Arista;

struct Grafo {

    int n; bool bi;
    vector<vector<int>> ady;
    Grafo(int N, bool B = true)
        : n(N), bi(B), ady(N) {}

    void AgregarArista(int u, int v) {
        if (bi) ady[v].push_back(u);
        ady[u].push_back(v);
    }

    vector<bool> vis;
    vector<int> ordenados;
    vector<int> usando;
    bool ciclo;

    void OrdenTopologico(int u) {
        vis[u] = true;
        usando[u] = true;
        for (int v : ady[u])
            if (!vis[v]) OrdenTopologico(v);
        	else if (usando[v]) ciclo = true;
        usando[u] = false;
        ordenados.push_back(u);
    }

    void OrdenTopologico() {
        ordenados.clear();
        ciclo = false;
        vis = vector<bool>(n);
        usando = vector<int>(n);
        for (int u = 0; u < n; ++u)
            if (!vis[u]) OrdenTopologico(u);
    }
};

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	Grafo g(26, false);
	int n;

	cin >> n;
	vector<string> v(n);
	int ans = 1;
	for (int i = 0; i < n; ++i)	cin >> v[i];
	for (int i = 0; i < n - 1; ++i) {
		int j;
		for (j = 0; v[i][j] == v[i + 1][j]; ++j);
		if (j < v[i].size() && j < v[i + 1].size())
			g.AgregarArista(v[i][j] - 'a', v[i + 1][j] - 'a');
		else if (v[i].size() > v[i + 1].size()) 
			ans = 0;
	}
	g.OrdenTopologico();
	if (g.ciclo) ans = 0;

	if (ans) {
		auto orden = g.ordenados;
		for (int i = orden.size() - 1; i >= 0; --i)
			cout << char('a' + orden[i]);
		cout << "\n";
	} else
		cout << "Impossible\n";
	return 0;
}
/*
10
tourist
petr
wjmzbmr
yeputons
vepifanov
scottwu
oooooooooooooooo
subscriber
rowdark
tankengineer

*/
