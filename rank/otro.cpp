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
int const INF = 100 * 1000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> data(n);
    map<int, int> row;

    forn(i, n) cin >> data[i];
    
    int ancho = -1;

    forn(i, n - 1) {
        if (data[i] == data[i + 1]) {
            cout << "NO" << endl;
            return 0;
        }

        if (abs(data[i] - data[i + 1]) == 1) {
            if (row.find(data[i]) != row.end() && row.find(data[i + 1]) != row.end()) {
                if (row[ data[i] ] != row[ data[i + 1] ]) {
                    cout << "NO" << endl;
                    return 0;
                }
            } else {
                int nivel = max(row[ data[i] ], row[ data[i + 1] ]); 
                if (nivel == -INF)
                    nivel = 0;
                row[ data[i] ] = row[ data[i + 1] ] = nivel;
            }
            
            cout << "	" << data[i] << " -> " << row[ data[i] ] << endl;
            cout << "	" << data[i + 1] << " -> " << row[ data[i + 1] ] << endl;
            continue;
        }
        
        int dif = abs(data[i] - data[i + 1]);

        if (row.find(data[i]) != row.end() && row.find(data[i + 1]) != row.end()) {
            if (abs(row[ data[i] ] - row[ data[i + 1] ]) != 1) {
                cout << "NO" << endl;
                return 0;
            }
        } else {
            int nivel = max(row[ data[i] ], row[ data[i + 1] ]); 
            if (nivel == -INF)
                nivel = 0;

            if (data[i] < data[i + 1])
                row[ data[i] ] = nivel - 1, row[ data[i + 1] ] = nivel;
            else
                row[ data[i] ] = nivel, row[ data[i + 1] ] = nivel - 1;
        }

        cout << data[i] << " -> " << row[ data[i] ] << endl;
        cout << data[i + 1] << " -> " << row[ data[i + 1] ] << endl;

        if (ancho != -1) {
            if (ancho != dif) {
                cout << "NO" << endl;
                return 0;
            }
        } else
            ancho = dif;
    }
    
    cout << "YES" << endl;
    if (ancho == -1)
        cout << 1000 * 1000 * 1000 << ' ' << 1000 * 1000 * 1000 << endl;
    else
        cout << 1000 * 1000 * 1000 << ' ' << ancho << endl;

    return 0;
}
