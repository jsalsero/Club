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

int const MAXN = 5005;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    
    vector<int> data(n);
    forn(i, n) cin >> data[i];

    sort(data.begin(), data.end());
    
    int idx = 0;
    int ans = 0;
    int it  = 0;
    bool yo = true;

    while (it++ < 1e9 && idx < n) {
        if (yo) {
            data[idx] -= x;

            if (data[idx] <= 0)
                ans++, idx++;
        } else {
            data[idx] += y;

            if (x <= y)
                idx++;
        }

        yo = !yo;
    }

    cout << ans << endl;
    return 0;
}

