#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long long long
#define fi first
#define se secon

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

const int MAXN = 100 * 1000 + 7;
int cub[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    int m, r, last, val;
    ordered_set s;

    while (t--) {
        cin >> m >> r;
        s.clear();

        rep(i, 1, m + 1) cub[i] = i, s.insert(i);

        last = 0;
        forn(i, r) {
            if (i) cout << ' ';

            cin >> val;
            
            cout << s.order_of_key(cub[val]);

            s.erase(cub[val]);
            cub[val] = last--;
            s.insert(cub[val]);
        }
        cout << endl;
    }

    return 0;
}

