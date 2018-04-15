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
    
    int n;
    string cad;
    cin >> n >> cad;
    
    int ans = n;
    int i = 0;
    while (i < n - 1) {
        if (cad[i] == 'U' && cad[i + 1] == 'R')      ans--, i++;
        else if (cad[i] == 'R' && cad[i + 1] == 'U') ans--, i++;
        i++;
    }
    
    cout << ans << endl;
    return 0;
}

