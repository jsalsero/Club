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

int val[300];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    val['q'] = 9;
    val['r'] = 5;
    val['b'] = 3;
    val['n'] = 3;
    val['p'] = 1;
    val['k'] = 0;
    
    vector<string> data(8);
    forn(i, 8) cin >> data[i];
    
    int black = 0;
    int white = 0;

    forn(i, 8) {
        forn(j, 8) {
            char letra = data[i][j];
            if (letra == '.') continue;

            if (isupper(letra))
                black += val[ tolower(letra) ];
            else
                white += val[ letra ];
        }
    }

    if (white == black)
        cout << "Draw" << endl;
    else
        cout << (white > black? "Black": "White") << endl;

    return 0;
}

