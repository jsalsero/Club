#include <bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define forn(i, n) for (int i = 0; i < n; ++i)
#define rep(i, a, b) for (int i = a; i < b; ++i)
#define endl '\n'
#define pii pair<int, int>
#define Long __int128
#define fi first
#define se second
using namespace std;

const int MAXN = 1e5;

string toDecimal(Long num, Long den) {
    string decimal = to_string(num/den) + '.';
    if (num % den == 0)
        return decimal += "0";

    Long rem = num % den;
    unordered_set<Long> rept;
    vector<Long> digit, R;

    while (rem && !rept.count(rem)) {
        rept.insert(rem);
        R.pb(rem);
        rem *= 10;
        digit.pb(rem / den);
        rem %= den;
    }

    for (int i = 0; i < digit.size(); ++i) {
        if (rem && R[i] == rem)
            decimal += '(';
        decimal += (digit[i] + '0');
    }

    if (rem)
        decimal += ')';

    return decimal;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    forn(asdf, T) {
    	Long a, b, n;
    	cin >> a >> b >> n;

        string cad = toDecimal(a, b);
        
        Long pre = 0;
        int idx = 2;
        Long len_pre = 0;
        while (idx < cad.size() && len_pre < n) {
            if (cad[idx] == '(') {
                idx++;
                break;
            }

            pre += (cad[idx] - '0');
            ++idx;
            len_pre++;
        }

        n -= len_pre;

        if (!n || idx == cad.size()) { // NO HAY PERIODO
            cout << pre << endl; 
            continue;
        }

        // TENEMOS PERIODO
        Long periodo = 0;
        Long len_per = 0;
        Long ini_per = idx;
        while (idx < cad.size() - 1) {
            periodo += (cad[idx] - '0');
            ++idx;
            len_per++;
        }

        Long ans = pre;
        Long div = n/len_per;

        ans += periodo * div;

        n -= len_per*div;

        Long kk = ini_per;
        while (n) {
            ans += (cad[kk] - '0');
            kk++;
            n--;
        }
        
        cout << ans << endl;
    }

    return 0;
}

