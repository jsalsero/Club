#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
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

    vector<int> val(100);
    iota(val.begin() + '0', val.begin() + '9' + 1,  0);
    iota(val.begin() + 'A', val.begin() + 'Z' + 1, 10);

    //rep(i, '0', '9' + 1) cout << val[i] << ' ';
    //rep(i, 'A', 'Z' + 1) cout << val[i] << ' ';

    string cad;
    cin >> cad;
    int n = cad.size();

    char ini = *max_element(cad.begin(), cad.end());

    rep(base, max(val[ini], 2), 37) {
        int acc = 0;
        int pot = 1;

        forn(i, n) {
            acc += val[ cad[n - i - 1] ] * pot;
            acc %= (base - 1);

            pot *= base;
            pot %= (base - 1);
        }

        if (!acc) {
            cout << base << endl;
            return 0;
        }
    }

    cout << "No solution." << endl;
    return 0;
}

