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

char data[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    forn(caso, t) {
        if (caso) cout << endl;
        cout << "Case #" << caso + 1 << ": ";
    
        int r, c, h, v;
        cin >> r >> c >> h >> v;
        
        forn(row, r)
            forn(col, c)
                cin >> data[row + 1][col + 1];

        //vector< vector<int> > acc(r, vector<int>(h));
        
        Long total = 0;
        rep(row, 1, r + 1) {
            rep(col, 1, c + 1) {
                total += (data[row][col] == '@');
                //acc[row][col] += (data[row][col] == '@') + acc[row][col - 1] + acc[row - 1][col]; }
            }
        }

        Long diners = (h + 1) * (v + 1);

        bool valid = (total % diners = 0);
        valid &= (total & (h + 1) == 0);
        valid &= (total & (v + 1) == 0);
        if (!valid) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        Long act = 0;
        Long hor = total / (h + 1);
        rep(row, 1, r + 1) {
            rep(col, 1, c + 1) act += (data[row][col] == '@');
            if (act == hor) {
                act = 0;

            }
        }

    }

    return 0;
}

