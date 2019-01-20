#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define fi first
#define se second
#define pii pair<int, int>
#define endl '\n'
#define Long long long
#define pb push_back
#define vi vector<Long>
using namespace std;

const int MAXN = 1000 * 100 + 7;

bool can(Long L, Long W, Long a, Long b, Long c, Long d) {
	if (a > L || b > W)           return false;
	if (a + c <= L && d <= b)     return true;
	if (c <= a && b + d <= W)     return true;
	if (a + c <= L && b + d <= W) return true;

	return false;
}

bool solve(vi &tam, vi &uno, vi &dos) {
	forn(i, 8) {
		if (i & 1) swap(tam[0], tam[1]);
		if (i & 2) swap(uno[0], uno[1]);
		if (i & 4) swap(dos[0], dos[1]);

		if (can(tam[0], tam[1],
				uno[0], uno[1],
				dos[0], dos[1]))
			return true;

		if (i & 1) swap(tam[0], tam[1]);
		if (i & 2) swap(uno[0], uno[1]);
		if (i & 4) swap(dos[0], dos[1]);
	}

    return false;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie();

	vi tam(2);
	vi uno(2);
	vi dos(2);

	forn(i, 2) cin >> tam[i];
	forn(i, 2) cin >> uno[i];
	forn(i, 2) cin >> dos[i];

    cout << (solve(tam, uno, dos) || solve(tam, dos, uno) ? "YES" : "NO") << endl;

	return 0;
}

