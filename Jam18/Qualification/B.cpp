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

    int t;
    cin >> t;

    forn(caso, t) {
        if (caso) cout << endl;

        int n;
        cin >> n;

        vector<int> data(n), ord(n);
        forn(i, n) cin >> data[i], ord[i] = data[i];

        vector<Long> odd;
        vector<Long> even;

        for (int i = 0; i < n; i += 2) even.eb(data[i]);
        for (int i = 1; i < n; i += 2)  odd.eb(data[i]);

        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());

        for (int i = 0, idx = 0; idx < even.size(); i += 2, idx++) data[i] = even[idx];
        for (int i = 1, idx = 0; idx <  odd.size(); i += 2, idx++) data[i] =  odd[idx];

        sort(ord.begin(), ord.end());
        
        /*
        cout << endl;
        forn(i, n) cout << data[i] << ' '; cout << endl;
        forn(i, n) cout << ord[i] << ' '; cout << endl;
        cout << endl;
        */
    
        int ans = -1;
        forn(i, n) if (data[i] != ord[i]) {
            ans = i;
            break;
        }

        cout << "Case #" << caso + 1 << ": ";
        if (ans < 0)
            cout << "OK";
        else
            cout << ans;
    }

    return 0;
}

