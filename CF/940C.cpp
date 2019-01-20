#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long long long
#define fi first
#define se secon
using namespace std;

const int MAXN = 100 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    string cad;
    
    cin >> n >> k >> cad;

    set<char> alfa;
    forn(i, n) alfa.insert(cad[i]);
    
    char mini = *alfa.begin();
    char maxi = *alfa.rbegin();
    forn(ii, k - n) cad += mini;

    for (int i = k - 1; i >= 0 && k <= n; --i)
        if (cad[i] != maxi) {
            cad[i] = *alfa.upper_bound(cad[i]);
            for (int jj = i + 1; jj < cad.size(); ++jj)
                cad[jj] = mini;
            break;
        }

    cout << cad.substr(0, k) << endl;
    return 0;
}

