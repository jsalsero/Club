// 6044 - Unique Path
// Live archive
#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef int Costo;
typedef pair<int, int> Arista;
const Costo INF = 1 << 30;

struct Grafo {
	int n; bool bi;
	vector<vector<int>> ady;
	Grafo(int N, bool B = true)
		: n(N), bi(B), ady(N) {}

	void Conecta(int u, int v) {
		if (bi) ady[v].push_back(u);
		ady[u].push_back(v);
	}

	int tiempo;
    vector<int> label, low;
    vector<Arista> puentes;    // <- Resultado
    vector<bool> articulacion; // <- Resultado

    int PuentesArticulacion(int u, int p) {
        label[u] = low[u] = ++tiempo;
        int hijos = 0;
        for (int v : ady[u]) {
            if (v == p) continue;
            if (!label[v]) { ++hijos;
                PuentesArticulacion(v, u);
                if (label[u] < low[v])
                    puentes.push_back(Arista(u, v));
                if (label[u] <= low[v])
                    articulacion[u] = true;
                low[u] = min(low[u], low[v]);
            }
            low[u] = min(low[u], label[v]);
        }
        return hijos;
    }

    void PuentesArticulacion() {
        low = vector<int>(n);
        label = vector<int>(n);
        tiempo = 0, puentes.clear();
        articulacion = vector<bool>(n);
        for (int u = 0; u < n; ++u)
            if (!label[u]) articulacion[u] =
                PuentesArticulacion(u, u) > 1;
    }
};

struct UF {
	int n; vector<int> padre, tam;

	UF(int N) : n(N),
		tam(N, 1), padre(N) {
			while (--N) padre[N] = N;
	}

	int Raiz(int u) {
		if (padre[u] == u) return u;
		return padre[u] = Raiz(padre[u]);
	}

	bool SonConexos(int u, int v) {
		return Raiz(u) == Raiz(v);
	}

	void Unir(int u, int v) {
		int Ru = Raiz(u);
		int Rv = Raiz(v);
		if (Ru == Rv) return;
		--n, padre[Ru] = Rv;
		tam[Rv] += tam[Ru];
	}

	int Tamano(int u) {
		return tam[Raiz(u)];
	}

    vector<Long> Raices(int tam){
        vector<Long> root;
        for( Long i = 0 ; i < padre.size() ; ++i )
            if(padre[i] == i)
            	root.push_back(Tamano(i));
                //root.push_back(i);
        return root;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T, caso = 1;
	cin >> T;
	while (T--) {
		int n, m;
		cin >> n >> m;
		Grafo g(n);
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			g.Conecta(--a, --b);
		}

		g.PuentesArticulacion();

        set<pair<int,int>> S;
        for (auto p : g.puentes) {
        	S.insert(p);
        	S.insert(make_pair(p.second, p.first));
        }

        queue<int> q;
        vector<bool> visit(n, false);
		UF componentes(n);

        for (int i = 0; i < n; ++i) {
        	if (visit[i]) continue;
	        q.push(i), visit[i] = true;
	        while (!q.empty()) {
	            int u = q.front(); q.pop();
	            visit[u] = true;
	            for (int v : g.ady[u]) {
	            	if (S.find(make_pair(u, v)) != S.end()) continue;
	            	componentes.Unir(u, v);
	                if (!visit[v]) q.push(v);
	            }
	        }
	    }

	    UF bosque(n);
		for (auto p : g.puentes) {
			int ini = p.first;
			int fin = p.second;
			if (componentes.Tamano(ini) > 1 || componentes.Tamano(fin) > 1)
				continue;
			//cout << ini << " - " << fin << endl;
			bosque.Unir(ini, fin);
		}

		Long res = 0;
		auto arboles = bosque.Raices(n);
		for (auto ar : arboles) {
			res += (ar*(ar - 1))/2;
		}
		cout << "Case #" << caso++ << ": " << res << "\n";
	}
	return 0;
}
/*
4
7 6
1 2
1 3
2 4
3 4
4 5
5 6

5 4
1 2
2 3
2 4
4 5

4 4
1 2
2 3
3 4
4 1

8 8
1 2
2 3
2 4
2 5
3 4
5 6
6 7
6 8

*/
