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

bool isvowel(char c) {
    if (c == 'a') return true;
    if (c == 'e') return true;
    if (c == 'i') return true;
    if (c == 'o') return true;
    if (c == 'u') return true;
    return false;
}

int dist(string & cad, int ini) {
    int len = 0;
    ini++;

    while (ini < cad.size()) {
        if (isvowel(cad[ini]))
            return len;

        ++len;
        ++ini;
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string cad;
    while (cin >> cad) {
        int n = cad.size();

        int vocales = 0;
        forn(i, n) vocales += (isvowel(cad[i]));
        
        if (!vocales) {
            cout << 1 << endl;
            continue;
        }

        if (!isvowel(cad[0])) {
            cout << 0 << endl;
            continue;
        }

        if (vocales == 1) {
            cout << n << endl;
            continue;
        }

        int idx = 0;
        vector<int> ans;

        while (idx < n) {
            if (isvowel(cad[idx])) {
                int val = dist(cad, idx);
                if (val != -1)
                    ans.pb(val);
            }

            idx++;
        }

        cout << ans[ans.size()/2] + 1 << endl;
    }

    return 0;
}

