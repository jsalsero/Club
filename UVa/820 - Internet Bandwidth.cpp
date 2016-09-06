#include <bits/stdc++.h>
using namespace std;

typedef int Flujo; // Ajustable.

typedef vector<int> Lista;
typedef pair<int, int> Par;
typedef vector<Flujo> Flujo1D;
typedef vector<Flujo1D> Flujo2D;

const Flujo FINF = 1 << 30;


struct GrafoFlujo {

    int n; vector<Lista> aristas;
    Flujo2D cap, flujo; Lista padre, dist;
    
    GrafoFlujo(int N) : dist(N), padre(N), aristas(N),
        cap(N, Flujo1D(N)), flujo(N, Flujo1D(N)), n(N) {}

    void AgregarArista(int u, int v, Flujo c) {
        //flujo[v][u] += c; // Solo dirigidas!
        cap[u][v] += c, cap[v][u] += c;
        aristas[u].push_back(v);
        aristas[v].push_back(u);
    }

    // Flujo maximo mediante Edmonds-Karp O(VE^2).

    Flujo ActualizarFlujo(int u, Flujo f) {
        int p = padre[u];
        if (p == u) return f;
        f = ActualizarFlujo(p, min(f,
            cap[p][u] - flujo[p][u]));
        flujo[p][u] += f;
        flujo[u][p] -= f;
        return f;
    }

    Flujo AumentarFlujo(int s, int t) {
        fill(padre.begin(), padre.end(), -1);
        queue<int> q; q.push(s); padre[s] = s;
        while (!q.empty()) {
            int u = q.front();
            q.pop(); if (u == t) break;
            for (int i = 0; i < aristas[u].size(); ++i) {
                int v = aristas[u][i];
                if (flujo[u][v] == cap[u][v] ||
                    padre[v] != -1) continue;
                padre[v] = u, q.push(v);
            }
        }
        if (padre[t] == -1) return 0;
        return ActualizarFlujo(t, FINF);
    }

    Flujo EdmondsKarp(int s, int t) {
        Flujo flujo_maximo = 0, f;
        while (f = AumentarFlujo(s, t))
            flujo_maximo += f;
        return flujo_maximo;
    }

    // Flujo maximo mediante Dinic O(V^2E).

    Flujo FlujoBloqueante(int u, int t, Flujo f) {
        if (u == t) return f; Flujo fluido = 0;
        for (int i = 0; i < aristas[u].size(); ++i) {
            if (fluido == f) break; int v = aristas[u][i];
            if (dist[u] + 1 > dist[v]) continue;
            Flujo fv = FlujoBloqueante(v, t,
                min(f - fluido, cap[u][v] - flujo[u][v]));
            flujo[u][v] += fv, fluido += fv;
            flujo[v][u] -= fv;
        }
        return fluido;
    }

    Flujo Dinic(int s, int t) {
        Flujo flujo_maximo = dist[t] = 0;
        while (dist[t] < INT_MAX) {
            fill(dist.begin(), dist.end(), INT_MAX);
            queue<int> q; q.push(s); dist[s] = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int i = 0; i < aristas[u].size(); ++i) {
                    int v = aristas[u][i];
                    if (flujo[u][v] == cap[u][v] ||
                        dist[v] <= dist[u] + 1) continue;
                    dist[v] = dist[u] + 1, q.push(v);
                }
            }
            if (dist[t] < INT_MAX) flujo_maximo +=
                FlujoBloqueante(s, t, FINF);
        }
        return flujo_maximo;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, caso = 1;
	while (cin >> n && n != 0) {
		int s, t, c;		
		GrafoFlujo pipes(n);
		map< pair<int, int>, int> M;
		
		cin >> s >> t >> c;
		for (int i = 0; i < c; ++i) {
			int a, b, w;
			cin >> a >> b >> w;
			M[make_pair(max(a - 1, b - 1), min(a - 1, b - 1))] += w;
		}
		for (auto var : M)
			pipes.AgregarArista(var.first.first, var.first.second, var.second);
		cout << "Network " << caso++ << "\n";
		cout << "The bandwidth is " << pipes.Dinic(s - 1, t - 1) << ".\n\n";
	}
	return 0;
}
