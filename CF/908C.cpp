#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<int, int>
#define pdd pair<double, double>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;

int const MAXN = 5005;

double up2(double n) { return n * n; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    double r;
    
    cin >> n >> r;

    vector<pdd> data;
    forn(i, n) {
        double x;
        cin >> x;
        
        double y = r;
        forn(j, i) {
            double dif = up2(x - data[j].fi);

            if (dif > up2(2.0 * r)) continue;

            double ans = sqrt(4.0 * r * r - dif) + data[j].se;
            y = max(y, ans);
        }
        
        data.eb(x, y);
    }

    cout << fixed << setprecision(12);
    forn(i, n) cout << data[i].se << ' '; cout << endl;
    return 0;
}

