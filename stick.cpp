#include <bits/stdc++.h>
#define endl '\n'
#define Long long long
#define forn(i, n) for(int i = 0; i < n; ++i)
#define rep(i,a,b) for(int i = a; i < b; ++i)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
using namespace std;

const int MAXN = 1e5;
const int INF = (1 << 28);

vi hijos[MAXN + 2];
int hermano[MAXN + 2];

bool calc_stick[MAXN + 2];
int dp_stick[MAXN + 2];

bool calc[MAXN + 2][2 + 2][2 + 2];
int dp[MAXN + 2][2 + 2][2 + 2];

int stick(int nodo);
int pecho(int nodo);
int cadera(int nodo);
int f(int nodo, int extr, int cad);

int f(int nodo, int extr, int cad) {
    if (nodo == -1) {
        if (extr > 0 || cad > 0) return -INF;
        return 0;
    }

    if (calc[nodo][extr][cad])
        return dp[nodo][extr][cad];

    calc[nodo][extr][cad] = true;
    int resp = 0, aux;

    //nada especial
    aux = f(hermano[nodo], extr, cad);
    aux += max(stick(nodo), pecho(nodo) + 1);
    resp = max(resp, aux);

    //asignar extremidad
    if (extr > 0) {
        aux = f(hermano[nodo], extr - 1, cad);
        aux += stick(nodo);
        resp = max(resp, aux);
    }

    //asignar cadera
    if (cad > 0) {
        aux = f(hermano[nodo], extr, cad - 1);
        aux += cadera(nodo);
        resp = max(resp, aux);
    }

    dp[nodo][extr][cad] = resp;
    return resp;
}

int cadera(int nodo) {
    if (hijos[nodo].size() < 2) return -INF;
    return f(hijos[nodo][0], 2, 0);
}

int pecho(int nodo) {
    if (hijos[nodo].size() < 3) return -INF;
    return f(hijos[nodo][0], 2, 1);
}

int stick(int nodo){
    if (calc_stick[nodo])
        return dp_stick[nodo];

    calc_stick[nodo] = true;
    dp_stick[nodo] = 0;
    
    for (const auto& sig : hijos[nodo])
        dp_stick[nodo] += max(stick(sig), pecho(sig) + 1);
    
    return dp_stick[nodo];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    fill(hermano, hermano + N + 1, -1);
    rep(i, 2, N+1){
        int p;
        cin >> p;
        if(!hijos[p].empty()){
            hermano[hijos[p].back()] = i;
        }
        hijos[p].pb(i);
    }
    cout << stick(1) << endl;

    return 0;
}

