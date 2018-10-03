#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(a, b, n) for (int i = a; i < b; ++i)
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

    string cad;
    cin >> cad;

    vector< vector<int> > full;
    vector< vector<int> > half;
    

    forn(i, cad.size()) {
        if (cad[i] == '0') {
            if (half.empty())
                full.eb(i);
            else {
                vector<int> aux = half.back();
                half.pop_back();
                aux.eb(i);

                full.eb(aux);
            }
        }

        if (cad[i] == '1') {
            if (full.empty()) {
                cout << -1 << endl;
                return 0;
            } else {
                vector<int> aux = full.back();
                full.pop_back();
                aux.eb(i);

                half.eb(aux);
            }
        }
    }

    if (half.size())
        cout << -1 << endl;
    else {
        cout << full.size() << endl;
        for (const auto &sub : full) {
            cout << sub.size() << ' ';
            for (const auto &var : sub) cout << var << ' ';
            cout << endl;
        }
    }

    return 0;
}

