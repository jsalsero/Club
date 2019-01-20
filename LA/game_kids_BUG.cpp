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

const Long MOD = 21092013LL;

const int MAXN = 1e4;
const int MAXG = 50;

vi rel[MAXN + 2];
int L[MAXN + 2];
int H[MAXN + 2];
Long cant[MAXN + 2];

int vivo[MAXN + 2];
int color;
int tam_sub[MAXN + 2];
Long sum_prod[MAXN + 2];

Long resp[MAXG + 2];

void conecta(int a, int b) {
    rel[a].push_back(b);
    rel[b].push_back(a);
}

void limpia() {
    forn(i, MAXN)
        rel[i].clear();
}

void inicia_arbol(int N, int g) {
    forn(i, N) {
        cant[i] =  H[i]/g;
        cant[i] -= (L[i] + g - 1)/g;
        cant[i]++;
    }
}

void dfs(int nodo, int padre) {
    tam_sub[nodo] = 1;

    for (const auto &sig : rel[nodo]) {
        if (sig == padre || vivo[sig] == color)
            continue;

        dfs(sig, nodo);
        tam_sub[nodo] += tam_sub[sig];
    }
}

int encuentra_centroid(int nodo, int padre, int limite) {
    for (const auto &sig : rel[nodo]) {
        if (sig == padre || vivo[sig] == color)
            continue;

        if (2 * tam_sub[sig] > limite)
            return encuentra_centroid(sig, nodo, limite);
    }
    return nodo;
}

void obten_productos(int nodo, int padre){
    sum_prod[nodo] = 0;

    for (const auto &sig : rel[nodo]) {
        if (sig == padre || vivo[sig] == color)
            continue;

        obten_productos(sig, nodo);
        sum_prod[nodo] += sum_prod[sig];
        sum_prod[nodo] %= MOD;
    }

    sum_prod[nodo] *= cant[nodo];
    sum_prod[nodo] %= MOD;
    sum_prod[nodo] += cant[nodo];
    sum_prod[nodo] %= MOD;
}

Long resuelve(int nodo) {
    dfs(nodo, nodo);
    nodo = encuentra_centroid(nodo, nodo, tam_sub[nodo]);

    obten_productos(nodo, nodo);
    
    Long sum_otros = 0; 
    for (const auto& sig : rel[nodo]) {
        if (vivo[sig] == color)
            continue;
        sum_otros = (sum_otros + sum_prod[sig]) % MOD;
    }

    Long resp = sum_prod[nodo];
    for (const auto& sig : rel[nodo]) {
        if (vivo[sig] == color)
            continue;

        sum_otros = (sum_otros + MOD - sum_prod[sig]) % MOD;
        Long aux1 = sum_otros;
        Long aux2 = sum_prod[sig];
        Long aux = (aux1 * aux2) % MOD;
        resp = (resp + aux) % MOD;
    }
    
    vivo[nodo] = color;
    for (const auto& sig : rel[nodo])
        if (vivo[sig] != color)
            resp = (resp + resuelve(sig)) % MOD;

    return resp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    forn(caso, T) {
        cout << "Case "<< caso + 1 << ":" << endl;
        limpia();

        int N;
        cin >> N;
        forn(i, N - 1) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            conecta(a, b);
        }

        forn(i, N) cin >> L[i];
        forn(i, N) cin >> H[i];

        for(int g = 50; g >= 1; g--){
            inicia_arbol(N, g);

            color++;
            resp[g] = resuelve(0);

            for(int j = 2 * g; j <= 50; j += g)
                resp[g] = (resp[g] + MOD - resp[j]) % MOD;
        }

        rep(i, 1, 50+1)
            cout << i << ": " << resp[i] << endl;
    }

    return 0;
}

