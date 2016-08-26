#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30;
typedef long long Long;
struct Grafo {
	int n; bool bi;
	int diam;
	vector<vector<int>> ady;
	Grafo(int N, bool B = true)
		: n(N), bi(B), ady(N), diam(0) {}

	void Conecta(int u, int v) {
		if (bi) ady[v].push_back(u);
		ady[u].push_back(v);
	}

	vector<int> BFS(int s) {
		queue<int> q;
		vector<int> d(n, INF);
		q.push(s), d[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int v : ady[u])
				if (d[u] + 1 < d[v])
					d[v] = d[u] + 1,
				q.push(v);
		}
		return d;
	}

	vector<int> distancias() {
		auto pr = BFS(0);
		int lejos = -1;
		int raiz;
		for (int i = 0; i < pr.size(); ++i)
			if (lejos < pr[i])
				lejos = pr[i], raiz = i;

		diam = lejos;
		auto d = BFS(raiz);
		lejos = -1;
		for (int i = 0; i < d.size(); ++i)
			if (lejos < d[i])
				lejos = d[i], raiz = i;
		
		auto d2 = BFS(raiz);
		
		vector<int> ans(n);
		for (int i = 0; i < n; i++)
			ans[i] = max(d[i], d2[i]);
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, Q;
	while (cin >> N >> Q) {
		Grafo blue(N), red(Q);
		for (int i = 1; i < N; ++i) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			blue.Conecta(a, b);
		}
		for (int i = 1; i < Q; ++i) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			red.Conecta(a, b);
		}
		
		vector<int> IZQ = blue.distancias();
		vector<int> DER = red.distancias();
		sort(DER.begin(), DER.end());
		int diam1 = blue.diam;
		int diam2 = red.diam;
		
		vector<int> acumula(DER.size() + 7);
		for (int i = 0; i < DER.size(); ++i)
			acumula[i + 1] = acumula[i] + DER[i];

		Long acc = 0;
		int diametroG = max(diam1, diam2);
		for (auto var : IZQ) {
			int idx = (upper_bound(DER.begin(), DER.end(), diametroG - var - 1) - DER.begin());		
			//cout << "  " << idx << endl;
			acc += idx*(diametroG) + (acumula[DER.size()] - acumula[idx]) + DER.size() - idx + var*(DER.size() - idx); 
		}
		cout << fixed;
		cout << setprecision(3);
		cout << acc/((double)N*Q) << '\n';
		//cout << endl << endl;
	}
	return 0;
}
/*
4 5
1 2
2 3
4 2
2 3
3 4
4 1
4 5

1 5
1 2
2 3
3 4
4 5

*/
