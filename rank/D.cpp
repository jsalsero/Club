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

int acc[5];

void izq(vector<int> &data, int nvo) {
    int n = data.size();

    forn(i, n) {
        if (data[i] > nvo && acc[ data[i] ] > n/3 && acc[nvo] < n/3) {
            acc[data[i]]--;
            acc[nvo]++;
            data[i] = nvo;
        }
    }
}

void der(vector<int> &data, int nvo) {
    int n = data.size();

    for (int i = n - 1; i >= 0; --i) {
        if (data[i] < nvo && acc[ data[i] ] > n/3 && acc[nvo] < n/3) {
            acc[data[i]]--;
            acc[nvo]++;
            data[i] = nvo;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    string cad;

    cin >> n >> cad;

    vector<int> data(n);
    forn(i, n) data[i] = (cad[i] - '0');

    forn(i, n) acc[ data[i] ]++;

    int want = n/3;
    
    int pasado = 0;
    forn(i, 3) pasado += (acc[i] > want);

    izq(data, 0);
    izq(data, 1);
    der(data, 2);
    der(data, 1);
   
    forn(i, n) cout << data[i]; cout << endl;

    return 0;
}

