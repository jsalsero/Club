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
#define TRI tuple<Long, Long, Long>
using namespace std;

const int MAXN = 100 * 1000 + 7;

Long sq(Long a) { return a*a; }

void TODO(set<TRI> &s) {
    cout << "   " << s.size() << endl;
    for (auto var : s) {
        cout << "   ";
        cout << "(" << get<0>(var) << ", " << get<1>(var) << ")"
             << " -> " << get<2>(var) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    Long L, C, N;
    while (cin >> L >> C >> N) {
        set< TRI > s;
        map<Long, Long> acc;

        s.insert(make_tuple(0, L - 1, 1));
        acc[1] = L;

        forn(i, N) {
            Long p, x, a, b;
            cin >> p >> x >> a >> b;

            Long uno = a + sq(acc[p]);
            Long dos = a + sq(acc[p] + b);

            uno %= L;
            dos %= L;

            Long ini_query = min(uno, dos);
            Long fin_query = max(uno, dos);

            auto it = s.upper_bound(make_tuple(ini_query, L + 1, C + 1));
            if (it != s.begin()) --it;

            vector< TRI > borra, pon;

            Long IZQ = get<0>(*it);
            Long DER = get<1>(*it);
            Long img = get<2>(*it);
            
            if (IZQ <= ini_query && fin_query <= DER) { // contengo todo el rango
                s.erase(it);

                if (IZQ < ini_query) s.insert(make_tuple(IZQ, ini_query - 1, img));

                acc[img] -= (fin_query - ini_query + 1);
                acc[x]   += (fin_query - ini_query + 1);
                s.insert(make_tuple(ini_query, fin_query, x));

                if (fin_query < DER) s.insert(make_tuple(fin_query + 1, DER, img));

                continue;
            }
            
            // inicio
            if (IZQ < ini_query) // queda un pedazo
                pon.pb(make_tuple(IZQ, ini_query - 1, img));

            borra.pb(*it);
            ++it;

            acc[img] -= (DER - ini_query + 1);
            acc[x]   += (DER - ini_query + 1);

            while (it != s.end()) { // mitad
                IZQ = get<0>(*it);
                DER = get<1>(*it);
                img = get<2>(*it);

                if (fin_query <= DER) break;

                borra.pb(*it);

                acc[img] -= (DER - IZQ + 1);
                acc[x]   += (DER - IZQ + 1);
                
                ++it;
            }

            pon.pb(make_tuple(ini_query, fin_query, x));
            
            // final
            if (fin_query < DER) // queda un pedazo
                pon.pb(make_tuple(fin_query + 1, DER, img));

            borra.pb(*it);

            acc[img] -= (fin_query - IZQ + 1);
            acc[x]   += (fin_query - IZQ + 1);

            for (const auto &var : borra) s.erase(var);
            for (const auto &var : pon)   s.insert(var);
        }

        Long maxi = 1;
        for (const auto &c : acc)
            maxi = max(maxi, c.se);

        cout << maxi << endl;
    }

    return 0;
}

