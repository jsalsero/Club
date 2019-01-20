#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;
 
int const MAXN = 1e6 + 107;
const int LOGN = 18;
const int INF = 1e7;
 
int n;
vector<pii> g[MAXN];
pii aristas[MAXN];
 
int prof[MAXN];
int papa[MAXN][LOGN];
 
int tams[MAXN];
int head[MAXN];
int myChain[MAXN];
int posInSeg[MAXN];
int currChain;
 
int costos[MAXN];
int last;
 
void limpia(int len) {
	forn(i, len) {
		g[i].clear();
		prof[i] = 0;
		tams[i] = 0;
 
		head[i] = -1;
 
		costos[i] = -INF;
 
		forn(j, LOGN)
			papa[i][j] = 0;
	}
 
	currChain = 0;
	last = -1;
}
 
struct SegTree {
	int i, d;
	SegTree *izq, *der;
	int val;
 
	SegTree(int I, int D) : i(I), d(D), 
		izq(NULL), der(NULL), val(-INF) {}
 
	~SegTree() {
		if (izq) delete izq;
		if (der) delete der;
	}
 
	void build() {
		if (i == d) {
			val = costos[i];
			return;
		}
 
		if (!izq) {
		   int m = (i + d) / 2;
		   izq = new SegTree(i, m);
		   der = new SegTree(m + 1, d);
		}
 
		izq->build();
		der->build();
 
		val = max(izq->val, der->val);
	}
 
	void update(int idx, int dato) {
		if (idx < i || d < idx) return;
 
		if (i == d) {
			val = dato;
			return;
		}
 
		izq->update(idx, dato);
		der->update(idx, dato);
 
		val = max(izq->val, der->val);
	}
 
	int query(int a, int b) {
		if (b < i || d < a) return -INF;
 
		if (a <= i && d <= b) return val;
 
		return max(izq->query(a, b),
				   der->query(a, b));
	}
};
 
SegTree *st;
 
	void dfs(int s) {
		for (const auto &var : g[s]) {
			int nodo = var.fi;
			if (papa[s][0] != nodo) {
				prof[nodo] = prof[s] + 1;
				papa[nodo][0] = s;
 
				dfs(nodo);
				tams[s] += tams[nodo];
			}
		}
 
		tams[s]++;
	}
 
	void HD(int s, int peso) {
		last++;
 
		if (head[ currChain ] < 0)
			head[ currChain ] = s;
 
		myChain[s] = currChain;
		posInSeg[s]  = last;
		costos[last] = peso;
		
		int mx = -1;
		for (const auto &var : g[s]) 
			if (prof[s] < prof[var.fi])
				if (mx < 0 || tams[var.fi] > tams[mx])
					mx = var.fi , peso = var.se;
 
		if (mx != -1)
			HD(mx, peso);
 
		for (const auto &var : g[s])
			if (prof[s] < prof[var.fi] && var.fi != mx) {
				currChain++;
				HD(var.fi, var.se);
			}
	}
 
	void build(int s) {
		dfs(s);
		HD(s, -INF);

		st = new SegTree(0, last);
		st->build();
		
        for (int salto = 1; salto < LOGN; ++salto) {
            for (int u = 0; u < n; ++u) {
				int brinca = papa[u][salto - 1];
				papa[u][salto] = papa[brinca][salto - 1];
			}
		}
	}
 
	int low(int a, int b) {
		if (prof[a] < prof[b]) swap(a, b);
		
		for (int salto = LOGN - 1; salto >= 0; --salto)
			if (prof[ papa[a][salto] ] >= prof[b])
				a = papa[a][salto];
 
		if (a == b) return a;
 
		for (int salto = LOGN - 1; salto >= 0; --salto) {
			if (papa[a][salto] != papa[b][salto]) {
				a = papa[a][salto];
				b = papa[b][salto];
			}
		}
 
		return papa[a][0];
	}
 
	int query_up(int bajo, int alto) {
		int ans = -INF;
		int aChain = myChain[alto];
	
		while (true) {
			int bChain = myChain[bajo];
 
			if (bChain == aChain) {
				if (alto == bajo) break; // no hay arista entre los nodos
 
				ans = max(ans, st->query(posInSeg[alto] + 1, posInSeg[bajo]));
				break;
			}
 
			ans = max(ans, st->query(posInSeg[ head[ bChain ] ], posInSeg[bajo]));
			bajo = head[ bChain ];
			bajo = papa[bajo][0];
		}
 
		return ans;
	}
 
	int query(int u, int v) {
		int lca = low(u, v);
 
		return max(query_up(u, lca),
				   query_up(v, lca));
	}
 
	void update(int idx, int val) {
		int nodo = aristas[idx].fi;
 
		if (prof[ nodo ] < prof[ aristas[idx].se ])
			nodo = aristas[idx].se;
 
		st->update(posInSeg[ nodo ], val);
	}
 
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin >> t;
 
	while (t--) {
		cin >> n;
		
		limpia(n);
 
		forn(i, n - 1) {
			int a, b, c;
			cin >> a >> b >> c;
			--a, --b;
 
			g[a].pb({b, c});
			g[b].pb({a, c});
 
			aristas[i] = {a, b};
		}
 
		build(0);
 
		while (true) {
			string cad;
			int a, b;
 
			cin >> cad;
			if (cad[0] == 'D') break;
 
			cin >> a >> b;
 
			if (cad[0] == 'Q') cout << query(a - 1, b - 1) << endl;
			if (cad[0] == 'C') update(a - 1, b);
		}
 
        if (st) delete st;
	}
 
	return 0;
}
 
