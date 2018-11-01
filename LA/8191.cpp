#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long long long
#define fi first
#define se second
#define TRI tuple<int, int, int>
using namespace std;

const int MAXN = 100 * 1000 + 7;

Long sq(Long a) { return a*a; }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    Long L, C, N;
    while (cin >> L >> C >> N) {
        set< TRI > s;
        map<int, int> acc;

        s.insert(make_tuple(0, L - 1, 1));
        acc[1] = L;

        forn(i, N) {
            int p, x, a, b;
            cin >> p >> x >> a >> b;

            int uno = a + sq(acc[p]);
            int dos = a + sq(acc[p] + b);

            uno %= L;
            dos %= L;

            int izq = min(uno, dos);
            int der = max(uno, dos);

            auto it = s.upper_bound(make_tuple(izq, L + 1, C + 1));
            if (it != s.begin()) --it;

            vector< TRI > borra, pon;

            auto tres = *it;
            int ini = get<0>(tres);
            int fin = get<1>(tres);
            int img = get<2>(tres);

            if (ini <= izq && der <= fin) {
                s.erase(it);
                int rango_img = fin - ini + 1;

                M[img] -= rango_img;

                if (ini < izq) s.insert(make_tuple(ini, izq - 1, img)), M[img] += (izq - ini);

                s.insert(make_tuple(izq, der, x));
                M[x] += (der - izq + 1);

                if (der < fin) s.insert(make_tuple(der + 1, fin, img)), M[img] += (fin - der);
                continue;
            }

            if (ini < izq) {
                pon.pb(make_tuple(ini, izq - 1, img));
                M[img] -= (fin - der);
                M[x]   += (fin - der);
            }

            while (it != s.end() && fin < der) {
                borra.pb(tres);

                ++it;
                ini = get<0>(tres);
                fin = get<1>(tres);
                img = get<2>(tres);

                M[img] -= (fin - ini + 1);
                M[x]   += (fin - ini + 1);
            }

            if (der < fin) {
                pon.pb(make_tuple(der + 1, fin, x));
                M[img] -= (izq - ini);
                M[x]   += (izq - ini);
            }

            for (const auto &var : borra) s.erase(var);
            for (const auto &var : pon)   s.insert(var);
        }
    
        int maxi = 1;
        for (const auto &c : acc)
            maxi = max(maxi, c.se);

        cout << maxi << endl;
    }

    return 0;
}

