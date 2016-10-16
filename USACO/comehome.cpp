/*
ID: wizard.1
LANG: C++11
TASK: comehome
*/
#include <bits/stdc++.h>
using namespace std;

int const INF = 1 <<30;
typedef int Costo;
typedef pair<Costo, int> CostoNodo;

struct Grafo {
	int n;
	vector<vector<CostoNodo>> ady;
	Grafo(int N) : n(N), ady(N) {}	

	void Conecta(int u, int v, Costo c) {
		ady[v].push_back(CostoNodo(c, u));
		ady[u].push_back(CostoNodo(c, v));
	}

	vector<Costo> Dijkstra(int s) {
		vector<Costo> dist(n, INF);
		priority_queue<CostoNodo> pq;
		pq.push(CostoNodo(0, s)), dist[s] = 0;

		while (!pq.empty()) {
			Costo p = -pq.top().first;
			int u = pq.top().second; pq.pop();
			if (dist[u] < p) continue;

			for (CostoNodo arista : ady[u]) {
				int v = arista.second;
				p = dist[u] + arista.first;
				if (p < dist[v]) dist[v] = p,
					pq.push(CostoNodo(-p, v));
			}
		}
		return dist;
	}
};

int main() {
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");
	map<char, int> M;
	map<int, char> I;
	vector<pair<int, pair<int, int> >> caminos;
	int n;

	fin >> n;
	int conta = 0;
	int idx;
	for (int i = 0; i < n; ++i) {
		char a, b;
		int dist;
		fin >> a >> b >> dist;

		if (!M.count(a))
			I[conta] = a,
			M[a] 	 = conta++;

		if (!M.count(b))
			I[conta] = b,
			M[b] 	 = conta++;

		if (isupper(a) && a != 'Z') 
			idx = M[a];
		if (isupper(b) && b != 'Z')
			idx = M[b];

		caminos.push_back({M[a], {M[b], dist}});
	}

	Grafo campo(M.size());
	for (auto var : caminos)
		campo.Conecta(var.first, var.second.first, var.second.second);
	
	auto ans = campo.Dijkstra(M['Z']);
	
	for (int i = 0; i < ans.size(); ++i)
		if (isupper(I[i]) && I[i] != 'Z' && ans[idx] > ans[i])
			idx = i;

	fout << I[idx] << ' ' << ans[idx] << '\n';
	return 0;
}
