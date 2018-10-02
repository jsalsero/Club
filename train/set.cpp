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

void cambia(set<int> &hola) {
    forn(i, 23) hola.insert(i);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    set<int> hola;
    
    cambia(hola);
    for (auto var : hola) cout << var << ' '; cout << endl;

    return 0;
}

