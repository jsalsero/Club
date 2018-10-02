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

int const MAXN = 300;
int const INF = 3*MAXN;

set<int> s;

int ans; 
int data[MAXN];

int n, l;
int ini;

int cool = -1;


void dp(int idx, int k) {
    if (idx == n || !k) {
        double per = (100.0 * (double)data[i])/(double)n;
        ans += round(per);

        if (ini != INF) {
            double per = (100.0 * (double)ini)/(double)n;
            ans += (k/ini) * round(ini);
        }

        cool = max(cool, ans);
    }
    
    auto it = s.upper_bound(data[idx]);
    if (it == s.end())
        dp(idx + 1, k);
    else {
        int dif = *it - data[idx];

        if (dif <= k) {
            int prev = data[idx];
            data[idx] = *it;

            dp(idx + 1, k - dif)

            data[idx] = prev;
        }
            dp(idx + 1, k);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    forn(caso, t) {
        if (caso) cout << endl;

        cin >> n >> l;
        
        s.clear();

        rep(i, 1, n + 1) {
            double per = (100.0 * (double)i)/((double)n);
            if (floor(per) != round(per))
                s.insert(i);
        }

        int acc = 0;
        forn(i, l) {
            cin >> data[i];
            acc += data[i];
        }

        ini = INF;
        if (s.size()) ini = *(s.begin());

        ans = 0;
        dp(0, n - acc);

        cout << "Case #" << caso + 1 << ": " << cool;
    }

    return 0;
}

