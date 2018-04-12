#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
using namespace std;

int const MAXN = 5005;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string cad;

    cin >> n >> cad;
    
    int ans = n;
    forn(j, n) {
        int tam = j + 1;
        int aux = n;

        if (cad.find(cad.substr(0, tam), j + 1) == j + 1)
            aux -= tam, aux++;

        ans = min(ans, aux);
    }
    
    cout << ans << endl;
    return 0;
}

