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

int data[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    forn(i, n) cin >> data[i];

    int mini = *min_element(data, data + n);
    int maxi = *max_element(data, data + n);

    if (maxi - mini < 2) {
        cout << n << endl;
        forn(i, n) cout << data[i] << ' ';
        cout << endl;
        return 0;
    }

    int a = count(data, data + n, mini);
    int b = count(data, data + n, mini + 1);
    int c = count(data, data + n, maxi);
    
    int ans;
    if (2*(b/2) >= 2*min(a, c)) {
        int quita = b/2;
        ans = n - 2*quita;

        a += quita;
        b -= 2*quita;
        c += quita;
    } else {
        int quita = min(a, c);
        ans = n - 2*quita;

        a -= quita;
        b += 2*quita;
        c -= quita;
    }
    
    cout << ans << endl;

    forn(i, a) cout << mini << ' ';
    forn(i, b) cout << mini + 1 << ' ';
    forn(i, c) cout << maxi << ' ';
    cout << endl;

    return 0;
}

