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

typedef vector<int> vi;

int const MAXN = 5005;

vector<string> examen;
vi score;

void obten_puntos(int n, int m, int mask) {
    forn(i, n) {
        int acc = 0;
        for (int bit = 0; bit < m; ++bit) {
            char c = (mask & (1<<bit)) ? '1' : '0';
            acc += todo[i][bit] == c;
        }

        if (acc != score[i]) return false;
    }

    return true;
}

void pre(int n, int m, unordered_map<string, int> &cubeta) {
    forn(mask, (1<<m)) {
        obten_puntos(n, m, mask);
        cubeta[ codifica(punt, n) ]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    forn(caso, t) {
        int n, m;
        cin >> n >> m;

        //vector<string> todo(n);
        //vi score(n);

        forn(i, n) cin >> todo[i] >> score[i];

        if (m <= 15) {
            bruta(todo, score, n, m);
            continue;
        }

        vector<string> uno(n);
        vector<string> dos(n);

        forn(i, n) {
            uno[i] = todo[i].substr(0, 15);
            dos[i] = todo[i].substr(15);
        }

        unordered_map<string, int> cubeta;
        pre(segunda, n, m - 15, cubeta);

    }

    return 0;
}

