#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < n; ++i)
#define fi first 
#define se second
#define pb push_back
#define pii pair<int, int>
#define Long long long
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; ++i)
using namespace std;

const int MAXN = 1e5 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    int l, r;
    vector<int> jiji(n);
    
    l = r = 0;
    rep(i, 1, n) {
        if (r >= i)
            jiji[i] = min(jiji[i - l], r - i + 1);

        while (jiji[i] + i < n && s[jiji[i]] == s[jiji[i] + i])
            jiji[i]++;

        if (i + jiji[i] - 1 > r)
            l = i, r = i + jiji[i] - 1;
    }

    set<int> maxi;
    rep(i, 1, n) {
        if (jiji[i] + i == n)
            maxi.insert(jiji[i]);
        
        if (maxi.size() > 2)
            maxi.erase(maxi.begin());
    }
    
    if (maxi.size()) {
        int mini = *maxi.begin();
        int cont = 0;
        forn(i, n) cont += (jiji[i] >= mini);

        cout << mini << ' ' << cont << endl;

        forn(i, n)
            if (cont > 1 && jiji[i] == mini) {
                forn(iii, jiji[i])
                    cout << s[i + iii];
                cout << endl;

                return 0;
            }
    }

    cout << "Just a legend" << endl;
    return 0;
}

