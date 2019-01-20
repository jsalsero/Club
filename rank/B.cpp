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

    int n, k;
    cin >> n >> k;    

    set< pii > s;
    forn(i, n) {
        int val;
        cin >> val;

        s.insert({val, i});
    }

    vector< set<int> > llevo(k);
    vector<int> ans(n);
    
    while (s.size()) {
        forn(color, k) {
            if (s.empty()) break;

            auto it = s.begin();
            int val = (*it).fi;
            int idx = (*it).se;

            if (llevo[color].find(val) != llevo[color].end()) {
                cout << "NO" << endl;
                return 0;
            }

            llevo[color].insert(val);

            s.erase(it);
            ans[idx] = color + 1;
        }
    }
    
    cout << "YES" << endl;
    forn(i, n) cout << ans[i] << ' ';
    cout << endl;
    return 0;
}

