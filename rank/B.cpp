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

int const MAXN = 1009;

char data[MAXN][MAXN];
char fake[MAXN][MAXN];
//bool  vis[MAXN][MAXN];

int n, m;

/*
bool valid(int i, int j) {
    bool ans = true;

    forn(it, 3) {
        ans &= (data[i][j + it] == '#' && data[i][j + it] == data[i + 2][j + it]);
        ans &= (data[i + it][j] == '#' && data[i + it][j] == data[i + it][j + 2]);

        ans &= (data[i + 1][j + 1] == '.');
    }
    
    return ans;
}
*/

void pinta(int i, int j) {
    forn(it, 3) {
        fake[i][j + it] = fake[i + 2][j + it] = '#';
        fake[i + it][j] = fake[i + it][j + 2] = '#';
        //vis[i][j + it] = vis[i + 2][j + it] = 1;
        //vis[i + it][j] = vis[i + it][j + 2] = 1;
    }
}

bool check() {
    forn(i, n)
        forn(j, m)
            if (data[i][j] == '#' && data[i][j] != fake[i][j])
                return false;

    return true;
}

bool cuadro(int i, int j) {
    forn(it, 3) {
        if (data[i][j + it] == '.')     return false;
        if (data[i + 2][j + it] == '.') return false;

        if (data[i + it][j] == '.')     return false;
        if (data[i + it][j + 2] == '.') return false;
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
     forn(i, n)
         forn(j, m)
            cin >> data[i][j];

     forn(i, n - 2)
         forn(j, m - 2) {
            if (cuadro(i, j))
                pinta(i, j);
        }
    
    cout << (check()? "YES": "NO") << endl;
    return 0;
}

