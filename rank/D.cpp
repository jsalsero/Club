#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long long long
#define fi first
#define se second
using namespace std;

const int MAXN = 100 * 1000 + 7;

int estoy[MAXN];
int data[17][MAXN];
int pos[MAXN][17];
int n, m;

bool avanza() {
    bool valid = true;
    forn(i, m) valid &= (++estoy[i] < n);
    forn(i, m) valid &= (data[0][ estoy[0] ] == data[i][ estoy[i] ]);

    return valid;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    forn(i, m)
        forn(j, n) {
            int val;
            cin >> val;

            pos[val][i] = j;
            data[i][j]  = val;
        }
    
    Long ans = 0;
    int idx  = 0;

    while (idx < n) {
        int ini = data[0][idx];

        forn(i, m) estoy[i] = pos[ini][i];

        Long len = 1;
        while (avanza()) len++;
        
        ans += (len*(len + 1))/2;

        idx += len;
    }
    
    cout << ans << endl;
    return 0;
}

