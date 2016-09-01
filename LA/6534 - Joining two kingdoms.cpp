#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<30;
typedef long long Long;
struct Grafo {
	Long n; bool bi;
	Long diam;
	vector<vector<Long>> ady;
	Grafo(Long N, bool B = true)
		: n(N), bi(B), ady(N), diam(0) {}

	void Conecta(Long u, Long v) {
		if (bi) ady[v].push_back(u);
		ady[u].push_back(v);
	}

	vector<Long> BFS(Long s) {
		queue<Long> q;
		vector<Long> d(n, INF);
		q.push(s), d[s] = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (Long v : ady[u])
				if (d[u] + 1 < d[v])
					d[v] = d[u] + 1,
				q.push(v);
		}
		return d;
	}

	vector<Long> distancias() {
		auto pr = BFS(0);
		Long lejos = -1;
		Long raiz;
		for (Long i = 0; i < pr.size(); ++i)
			if (lejos < pr[i])
				lejos = pr[i], raiz = i;

		auto d = BFS(raiz);
		lejos = -1;
		for (Long i = 0; i < d.size(); ++i)
			if (lejos < d[i])
				lejos = d[i], raiz = i;
		
		diam = lejos;
		auto d2 = BFS(raiz);
		
		vector<Long> ans(n);
		for (Long i = 0; i < n; i++)
			ans[i] = max(d[i], d2[i]);
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Long N, Q;
	while (cin >> N >> Q) {
		Grafo blue(N), red(Q);
		for (Long i = 1; i < N; ++i) {
			Long a, b;
			cin >> a >> b;
			a--, b--;
			blue.Conecta(a, b);
		}
		for (Long i = 1; i < Q; ++i) {
			Long a, b;
			cin >> a >> b;
			a--, b--;
			red.Conecta(a, b);
		}
		
		vector<Long> IZQ = blue.distancias();
		vector<Long> DER = red.distancias();
		sort(DER.begin(), DER.end());
		Long diam = blue.diam;
		Long diam2 = red.diam;
		
		vector<Long> acumula(DER.size() + 7);
		for (Long i = 0; i < DER.size(); ++i)
			acumula[i + 1] = acumula[i] + DER[i];

		double acc = 0;
		diam = max(diam, diam2);
		for (auto var : IZQ) {
			Long idx = (upper_bound(DER.begin(), DER.end(), diam - var - 1) - DER.begin());
			acc += idx*(diam) + acumula[Q] - acumula[idx] + Q - idx + var*(Q - idx); 
		}
		double ans = ((double)acc) / ((double)(((double)N) * ((double) Q )));
		cout << fixed << setprecision(3) << ans << '\n';
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
