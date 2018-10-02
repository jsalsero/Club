#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
using namespace std;

int const MAXN = 100 * 1000 + 7;
int const INF = 3*MAXN;

int n, l;
int porc(int p) {
    double val = (100.0*p)/(double)n;
    return round(val);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    forn(caso, t) {
        if (caso) cout << endl;
        
        cin >> n >> l;
        
        set<int> s;        
        rep(i, 1, n + 1) {
            double per = (100.0 * (double)i)/((double)n);
            if (floor(per) != round(per))
                s.insert(i);
        }

        vector<int> data(l);
        int acc = 0;
        forn(i, l) {
            cin >> data[i];
            acc += data[i];
        }
        
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        forn(i, l) {
            if (s.find(data[i]) != s.end()) continue;

            auto it = s.upper_bound(data[i]);
            if (it != s.end())
                pq.push(pii(*it - data[i], i));
        }
        
        int ini = INF;
        if (s.size()) ini = *(s.begin());

        pq.push(pii(ini, -1));
        
        int ans = 0;
        int sobra = n - acc;

        while (!pq.empty() && sobra) {
            int d = pq.top().fi;
            int i = pq.top().se;
            pq.pop();

            int add = min(sobra, d);
            sobra -= add;

            if (i < 0) {
                ans += porc(add);
                pq.push(pii(ini, -1));
                continue;
            }

            data[i] += add;
        }

        forn(i, l) ans += porc(data[i]);
        
        cout << "Case #" << caso + 1 << ": " << ans;
    }

    return 0;
}

