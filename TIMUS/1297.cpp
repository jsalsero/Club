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

string add(const string &s) {
    string res = "^#";
    forn(i, s.size()) res.pb(s[i]), res.pb('#');

    res += "$";
    return res;
}

string man(const string &s) {
    if (s.empty()) return s;

    string ns = add(s);
    int mx, id;
    int len = ns.length();

    vector<int> p(len);
    mx = id = 0;

    rep(i, 1, len - 1) {
        if (i < mx)
            p[i] = min(p[id - (i - id)], mx - i);
        else
            p[i] = 0;

        while (ns[i + p[i] + 1] == ns[i - p[i] - 1])
            p[i]++;

        if (p[i] + i > mx) {
            mx = p[i] + i;
            id = i;
        }
    }

    mx = id = 0;
    rep(i, 1, len - 1)
        if (p[i] > mx) {
            mx = p[i];
            id = i;
        }
    
    int left = (id - p[id])/2;
    return s.substr(left, p[id]);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    
    cout << man(s) << endl;
    return 0;
}

