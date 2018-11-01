#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5;
const int MAXLOG = 17;

typedef long long int Long;

struct ARISTA{
	int u, v;
	Long costo;

	ARISTA(int a = 0, int b = 0, Long _costo = 0) : u(a), v(b), costo(_costo) {}

	const bool operator < (const ARISTA& otro) const{
		if(costo == otro.costo){
			if(u == otro.u){
				return v < otro.v;
			}
			return u < otro.u;
		}
		return costo < otro.costo;
	}
};

struct ARISTA_2{
	int u, v;
	Long costo;

	ARISTA_2(int a = 0, int b = 0, Long _costo = 0) : u(a), v(b), costo(_costo) {}

	const bool operator < (const ARISTA_2& otro) const{
		if(u == otro.u){
			if(v == otro.v){
				return costo < otro.costo;
			}
			return v < otro.v;
		}
		return u < otro.u;
	}
};

struct UNION_FIND{
	int padre[MAXN + 2];
	int rank[MAXN + 2];

	UNION_FIND(int N){
		for(int i = 1; i <= N; i++){
			padre[i] = i;
			rank[i] = 0;
		}
	}
	int find(int x){
		if(padre[x] != x){
			padre[x] = find(padre[x]);
		}
		return padre[x];
	}
	bool Union(int r, int s){
		r = find(r);
		s = find(s);
		if(r == s) return false;
		if(rank[r] < rank[s]){
			padre[r] = s;
		}else if(rank[s] < rank[r]){
			padre[r] = s;
		}else{
			padre[s] = r;
			rank[r]++;
		}
		return true;
	}
};
vector<pair<int, Long> > rel[MAXN + 2];
int padre[MAXN + 2][MAXLOG + 2];
int nivel[MAXN + 2];
Long mayor_arista[MAXN + 2][MAXLOG + 2];

void dfs(int nodo){
	int tam = rel[nodo].size(), sig;
	for(int i = 0; i < tam; i++){
		sig = rel[nodo][i].first;
		if(sig == padre[nodo][0]) continue;
		padre[sig][0] = nodo;
		mayor_arista[sig][0] = rel[nodo][i].second;
		nivel[sig] = nivel[nodo] + 1;
		dfs(sig);
	}
}

void conecta(int u, int v, Long costo){
	rel[u].push_back(make_pair(v, costo));
	rel[v].push_back(make_pair(u, costo));
}

Long init(int N, set<ARISTA>& aristas){
	// inicializar arreglos
	for(int i = 1; i <= N; i++){
		rel[i].clear();
	}

	// construir MST
	set<ARISTA>::iterator it = aristas.begin();
	ARISTA aux_aristas;
	UNION_FIND UnionFind(N);
	Long minimo_costo = 0;
	while(it != aristas.end()){
		aux_aristas = *it;
		int u = aux_aristas.u, v = aux_aristas.v;
		Long costo = aux_aristas.costo;

		if(UnionFind.Union(u, v)){
			conecta(u, v, costo);
			minimo_costo += costo;
		}

		it++;
	}

	// Precalcula potencias de dos
	for(int i = 1; i <= N; i++){
		for(int j = 0; j <= MAXLOG; j++){
			padre[i][j] = -1;
			mayor_arista[i][j] = 0;
		}
	}
	nivel[1] = 0;
	dfs(1);
	for(int j = 1; j <= MAXLOG; j++){
		for(int i = 1; i <= N; i++){
			int tmp_nodo = padre[i][j - 1];
			Long tmp_costo = mayor_arista[i][j - 1];
			if(tmp_nodo != -1){
				tmp_costo = max(tmp_costo, mayor_arista[tmp_nodo][j - 1]);
				tmp_nodo = padre[tmp_nodo][j - 1];
			}
			padre[i][j] = tmp_nodo;
			mayor_arista[i][j] = tmp_costo;
		}
	}
	return minimo_costo;
}

int LCA(int u, int v){
	if(nivel[u] < nivel[v]) swap(u, v);

	for(int j = MAXLOG; j >= 0; j--){
		if(padre[u][j] != -1 && nivel[padre[u][j]] >= nivel[v]){
			u = padre[u][j];
		}
	}
	if(u == v) return u;
	for(int j = MAXLOG; j >= 0; j--){
		if(padre[u][j] != -1 && padre[u][j] != padre[v][j]){
			u = padre[u][j];
			v = padre[v][j];
		}
	}
	return padre[u][0];
}

Long obten_mayor(int A, int B){
	Long mayor = 0;
	for(int j = MAXLOG; j >= 0; j--){
		if(padre[A][j] != -1 && nivel[padre[A][j]] >= nivel[B]){
			mayor = max(mayor, mayor_arista[A][j]);
			A = padre[A][j];
		}
	}
	return mayor;
}

Long obten_mayor_path(int u, int v){
	int w = LCA(u, v);
	Long mayor = max(obten_mayor(u, w), obten_mayor(v, w));
	return mayor;
}


Long obten_costo(int u, int v, set<ARISTA_2>& aristas){
	ARISTA_2 A(u, v, 0);
	set<ARISTA_2>::iterator it;
	it = aristas.lower_bound(A);
	return (*it).costo;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	while(cin >> N >> M){
		set<ARISTA> aristas;
		set<ARISTA_2> aux_costos;
		for(int i = 0; i < M; i++){
			int a, b;
			Long costo;
			cin >> a >> b;
			cin >> costo;
			aristas.insert(ARISTA(a, b, costo));
			aux_costos.insert(ARISTA_2(a, b, costo));
		}
		Long C = init(N, aristas);
		int Q;
		cin >> Q;
		while(Q--){
			int u, v;
			cin >> u >> v;
			Long P = obten_costo(u, v, aux_costos);
			Long X = obten_mayor_path(u, v);
			Long resp = C - X + P;
			cout << resp << "\n";
		}
	}

	return 0;
}
