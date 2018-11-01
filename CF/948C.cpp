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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Long> v(n), t(n), acc(n);

    forn(i, n) cin >> v[i]; 
    forn(i, n) {
        cin >> t[i]; 
        acc[i] = t[i];

        if (i) acc[i] += acc[i - 1];
    }
    
    vector<Long> pilas(n + 7);
    vector<Long> sobra(n + 7);
    forn(i, n) {
        int m;
        int izq = i, der = n;

        Long before = (i ? acc[i - 1] : 0);

        while (izq < der) {
            m = (izq + der) / 2;

            if (acc[m] < v[i] + before)
                izq = m + 1;
            else
                der = m;
        }

        if (i < m && acc[m] < v[i] + before) {
            pilas[i]++;
            pilas[m]--;
        }

        sobra[m + 1] += v[i] - acc[m - 1];
    }

    forn(i, n) {
        if (i) cout << ' ';
        cout << pilas[i] * t[i] + sobra[i];
    }
    cout << endl;

    return 0;
}

