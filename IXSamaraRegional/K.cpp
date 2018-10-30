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

Long exp(Long a, Long n, Long m) {
    Long ans = 1;
    for (; n; n >>= 1) {
        if (n & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
    }

    return ans;
}

typedef vector<Long> vi;

struct hasher {
    vi h;
    Long b = 31, m, inv;

    hasher(const string &s, Long M) : h(s.size() + 1), m(M) {
        h[0] = 0;
        Long base = b;
        inv = exp(b, m - 2, m);

        forn(i, s.size()) {
            h[i + 1] = (s[i] * base + h[i]) % m;
            base = (base * b) % m;
        }
    }

    Long quita(int idx) {
        Long uno = h[idx - 1];
        Long dos = ((h.back() - h[idx] + m) * inv) % m;

        return (uno + dos) % m;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    hasher uno(s, 1e9 + 9);
    reverse(s.begin(), s.end());
    hasher dos(s, 1e9 + 9);

    int n = s.size();
    
    forn(i, n) {
        if (uno.quita(i + 1) == dos.quita(n - i)) {
            cout << "YES" << endl << i + 1 << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}

