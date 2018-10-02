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
    cin >> n;
    
    vector<int> data(n);
    forn(i, n) cin >> data[i];
    
    multiset<int> s(data.begin(), data.end());
    vector<int> otro(n - 1);
    forn(i, n - 1) {
        int aux;
        cin >> aux;
        s.erase(s.find(aux));
        otro[i] = aux;
    }
    cout << *s.begin() << endl;

    multiset<int> k(otro.begin(), otro.end());
    forn(i, n - 2) {
        int aux;
        cin >> aux;
        k.erase(k.find(aux));
    }
    cout << *k.begin() << endl;

    return 0;
}

