// Escape de la cueva
// Omegaup
#include <iostream>
#include <vector>
using namespace std;

typedef int Costo;
typedef pair<int, int> Arista;

const Costo INF = 1 << 30;

struct Grafo {

    int n; bool bi;
    vector<vector<int>> ady;
    vector< pair<int,int> > tiempo;
    vector<bool> visit;
    int t;
    Grafo(int N, bool B = true)
        : n(N), bi(B), ady(N), tiempo(N), visit(N, false), t(0) {}

    void Conecta(int u, int v) {
        if (bi) ady[v].push_back(u);
        ady[u].push_back(v);
    }

    void DFS(int s) {
    	if (visit[s]) return;
    	visit[s] = true;
    	tiempo[s].first = t++;
    	for (int v : ady[s])
    		DFS(v);
    	tiempo[s].second = t++;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	Grafo g(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		g.Conecta(a - 1, b - 1);
	}
	g.DFS(0);
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		if (g.tiempo[a - 1].first  <= g.tiempo[b - 1].first &&
			g.tiempo[b - 1].second <= g.tiempo[a - 1].second)
			cout << "0\n";
		else
			cout << "1\n";
	}
	return 0;
}
/*
5 3
1 2
2 3
2 4
4 5
2 5
3 5
1 4

*/
