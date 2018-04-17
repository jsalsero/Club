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
    
    queue<int> full;
    queue<int> half;

    vector<int> ans(cad.size());

    forn(i, cad.size()) {
        if (cad[i] == '0') {
            if (half.empty()) {
                full.push(i);
                ans[i] = -1;
            } else {
                int prev = half.front();
                half.pop();

                ans[i] = prev;
                full.push(i);
            }
        }

        if (cad[i] == '1') {
            if (full.empty()) {
                cout << -1 << endl;
                return 0;
            }

            int prev = full.front();
            full.pop();

            ans[i] = prev;
            half.push(i);
        }
    }

    if (!half.empty())
        cout << -1 << endl;
    else {
        vector< vector<int> > all;
        while (!full.empty()) {
            vector<int> aux;

            int prev = ans[full.front()];
            aux.eb(full.front());
            full.pop();

            while (prev != -1) {
                aux.eb(prev);
                prev = ans[prev];
            }
            all.eb(aux);
        }
        
        cout << all.size() << endl;
        for (const auto &set : all) {
            cout << set.size() << ' ';
            for (int i = set.size() - 1; i >= 0; --i) cout << set[i] + 1 << ' ';
            cout << endl;
        }
    }

    return 0;
}

