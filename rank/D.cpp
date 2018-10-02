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
    
    vector<Long> alfa(26);
    forn(i, 26) cin >> alfa[i];

    string cad;
    cin >> cad;
    
    int n = cad.size();
    vector<Long> acc(n);
    forn(i, n) {
        acc[i] = alfa[ (cad[i] - 'a') ];
        if (i) acc[i] += acc[i - 1];
    }
    
    map< pair<char, Long>, Long > M;
    Long ans = 0;
    
    rep(i, 0, n) {
        if (i)
            ans += M[ make_pair(cad[i], acc[i - 1]) ];
        M[ make_pair(cad[i], acc[i]) ]++;
    }

    cout << ans << endl;
    return 0;
}

