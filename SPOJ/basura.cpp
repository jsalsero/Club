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

void meh() {
    static int juancho = 0;
    juancho++;
    
    cout << juancho << endl;
    if (juancho > 10) return;
    meh();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    meh();
    cout << endl;
    meh();

    vector< vector<pii> > data;

    return 0;
}

