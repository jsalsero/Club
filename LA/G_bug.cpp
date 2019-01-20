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

int const MAXN = 1e5 + 7;
Long MOD = 1e9 + 7;

int izq[MAXN];
int der[MAXN];
int tipo[MAXN];

Long dp_uno[MAXN][2 + 2];
int calc_uno[MAXN][2 + 2];

Long dp_cer[MAXN][2 + 2];
int calc_cer[MAXN][2 + 2];

int color;

Long cer(int n, int d);

Long uno(int nodo, int d) {
    if (nodo == -1)
        return (d == 1);

    Long &resp = dp_uno[nodo][d];
    
    if (calc_uno[nodo][d] == color)
        return resp;

    resp = 0;
    calc_uno[nodo][d] = color;

    if (tipo[nodo] != -1) { // se atora 
        if (d != tipo[nodo])  // esta atorada, solo regresa un valor
            return resp = 0;

        Long total_0_izq = (cer(izq[nodo], 0) + cer(izq[nodo], 1)) % MOD;
        Long total_1_izq = (uno(izq[nodo], 0) + uno(izq[nodo], 1)) % MOD;
        Long total_0_der = (cer(der[nodo], 0) + cer(der[nodo], 1)) % MOD;
        Long total_1_der = (uno(der[nodo], 0) + uno(der[nodo], 1)) % MOD;

        // 0 0 | 1
        // 0 1 | 1
        // 1 0 | 1
        // 1 1 | 0

        resp = (resp + total_0_izq * total_0_der) % MOD;
        resp = (resp + total_1_izq * total_0_der) % MOD;
        resp = (resp + total_0_izq * total_1_der) % MOD;
        
        return resp;
    }

    if (d == 1) { // no se atora y queremos 1 
        // 0 0 | 1
        resp = (resp + cer(izq[nodo], 0) * cer(der[nodo], 0)) % MOD;
        resp = (resp + cer(izq[nodo], 0) * uno(der[nodo], 0)) % MOD;
        resp = (resp + uno(izq[nodo], 0) * cer(der[nodo], 0)) % MOD;

        // 0 1 | 1
        resp = (resp + cer(izq[nodo], 0) * cer(der[nodo], 1)) % MOD;
        resp = (resp + cer(izq[nodo], 0) * uno(der[nodo], 1)) % MOD;
        resp = (resp + uno(izq[nodo], 0) * cer(der[nodo], 1)) % MOD;

        // 1 0 | 1
        resp = (resp + cer(izq[nodo], 1) * cer(der[nodo], 0)) % MOD;
        resp = (resp + cer(izq[nodo], 1) * uno(der[nodo], 0)) % MOD;
        resp = (resp + uno(izq[nodo], 1) * cer(der[nodo], 0)) % MOD;
    } else { // no se atora y queremos 0
        // 1 1 | 0
        resp = (resp + cer(izq[nodo], 1) * cer(der[nodo], 1)) % MOD;
        resp = (resp + cer(izq[nodo], 1) * uno(der[nodo], 1)) % MOD;
        resp = (resp + uno(izq[nodo], 1) * cer(der[nodo], 1)) % MOD;
    }

    return resp;
}

Long cer(int nodo, int d) {
    if (nodo == -1)
        return (d == 0);

    Long &resp = dp_cer[nodo][d];

    if (calc_cer[nodo][d] == color)
        return dp_cer[nodo][d];

    resp = 0;
    calc_cer[nodo][d] = color; 

    if (tipo[nodo] != -1) { // esta atorada
        if (d != tipo[nodo])
            return resp = 0;

        // 1 1 | 0
        Long total_1_izq = (uno(izq[nodo], 0) + uno(izq[nodo], 1)) % MOD;
        Long total_1_der = (uno(der[nodo], 0) + uno(der[nodo], 1)) % MOD;

        return resp = (total_1_izq * total_1_der) % MOD;
    }

    if (d == 1) {
        resp = (resp + uno(izq[nodo], 0) * uno(der[nodo], 0)) % MOD;
        resp = (resp + uno(izq[nodo], 1) * uno(der[nodo], 0)) % MOD;
        resp = (resp + uno(izq[nodo], 0) * uno(der[nodo], 1)) % MOD;
    } else
        resp = (resp + uno(izq[nodo], 1) * uno(der[nodo], 1)) % MOD;

    return resp;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    while (cin >> N) {
        forn(i, N) {
            cin >> izq[i] >> der[i] >> tipo[i];
            --izq[i]; --der[i];
        }

        color++;

        Long resp = (uno(0, 0) + cer(0, 1)) % MOD;
        cout << resp << endl;
    }

    return 0;
}

