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

int const MAXN = 100 * 1000 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    bitset<MAXN> otro;

    int t;
    cin >> t;

    forn(caso, t) {
        if (caso) cout << endl;

        //otro.reset();

        int n, l;
        cin >> n >> l;
        
        set<int> s;        
        rep(i, 1, n + 1) {
            double per = (100.0 * i)/(double)n;
            if (floor(per) != round(per))
                s.insert(i);
        }

        vector<int> data(l);
        int acc = 0;
        forn(i, l) {
            cin >> data[i];
            acc += data[i];
        }

        int disp = n - acc;
        priority_queue<pii, vector<pii>, greater<pii>> pq;


        int ans = 0;
        int mini = 3 * MAXN;

        forn(i, l) {
            auto it = s.upper_bound(data[i]);

            if (it == s.end())
                otro[i] = 1;
            else {
                int d = *it - data[i];
                mini = min(d, mini);
                //int ini = *(s.begin());

                /*
                if (ini < d && ini <= disp) {
                    double per = (100.0 * ini)/(double)n;
                    ans += round(per);

                    disp -= *(s.begin());
                }
                */

                pq.push(pii(d, i));
            }
        }

        int ini = 3*MAXN;
        if (s.size()) ini = *(s.begin());

        if (ini < mini) {
            ans += disp/ini;
            disp = 0;
        }
        
        while (!pq.empty() && disp > 0) {
            int d = pq.top().fi;
            int i = pq.top().se;
            pq.pop();
            
            int add;

            if (disp < d) {
                add = min(disp, *(s.begin()));
                disp -= add;

                double per = (100.0 * add)/(double)n;
                ans += round(per);

                continue;
            } else
                add = min(d, disp);

            disp -= add;

            data[i] += add;

            auto it = s.upper_bound(data[i]);

            if (it == s.end())
                otro[i] = 1;
            else
                pq.push(pii(*it - data[i], i));
        }
        
        forn(i, l) {
            if (otro[i]) {
                int add = min(disp, n - data[i]);
                disp -= add;

                data[i] += add;
            }
            
            //cout << data[i] << ' ';
            double per = (100.0 * data[i])/(double)n;
            ans += round(per);
        }

        cout << "Case #" << caso + 1 << ": " << ans;
    }

    return 0;
}

