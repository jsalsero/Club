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

const double EPS = 1e-9;

double a, b, c;

double f(double r) {
    return -a*r*r + b*r + c;
}

double tope() {
    double izq = 0, der = 1e14;

    forn(it, 100) {
        double m = (izq + der)/2.0;

        if (f(m) < f(m + EPS))
            izq = m + EPS;
        else
            der = m;
    }

    return f(izq);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    forn(caso, t) {
        int n;
        cin >> n;

        cin >> a >> b >> c;

        double maxi = tope();
        int ans = 1;

        forn(i, n - 1) {
            cin >> a >> b >> c;

            double aux = tope();
            if (aux > maxi) {
                maxi = aux;
                ans = i + 2;
            }
        }

        cout << ans << endl;
    }

    return 0;
}

