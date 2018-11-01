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

int r, c, h, v;
char data[107][107];

bool valid(int row, int col) {
    int aa = 0, bb = 0, cc = 0, dd = 0;

    rep(i, 0, row)
        rep(j, 0, col)
            aa += (data[i][j] == '@');

    rep(i, 0, row)
        rep(j, col, c)
            bb += (data[i][j] == '@');

    rep(i, row, r)
        rep(j, 0, col)
            cc += (data[i][j] == '@');

    rep(i, row, r)
        rep(j, col, c)
            dd += (data[i][j] == '@');

    //if (row == 2)
        //cout << a << ' ' << b << ' ' << c << ' ' << d << endl;
    
    return (aa == bb && bb == cc && cc == dd);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    forn(caso, t) {
        if (caso) cout << endl;
        cout << "Case #" << caso + 1 << ": ";
    
        cin >> r >> c >> h >> v;
        
        forn(row, r)
            forn(col, c)
                cin >> data[row][col];
        
        bool ans = false;
        rep(row, 1, r) {
            if (ans) break;
            rep(col, 1, c) if (valid(row, col)) {
                ans = true;
                break;
            }
        }
    
        if (ans)
            cout << "POSSIBLE";
        else 
            cout << "IMPOSSIBLE";
    }

    return 0;
}

